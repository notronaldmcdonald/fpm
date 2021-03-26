# Foundation Package Manager
# spine_install
# Developed by Brett. (https://github.com/notronaldmcdonald)

# dependencies

require 'fileutils'
require 'colorize'

# variables

home = Dir.home
op_sys = RUBY_PLATFORM

# repository targets
# USER - if you wish to add a repository, use this format.
core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs"
live = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/live/pkgs"
mode = "r"
# target = "nnn" - this was a developer testing piece and it can be ignored.

# begin script

targetfile = File.open("/tmp/.target", mode)
target = targetfile.read
puts "Welcome!".green
puts "You requested: #{target}."
puts "Select a repository to download from:".yellow
puts "1) core (#{core})"
puts "2) live (#{live})"
# user can add more lines to this list
puts "Choose repository by entering the number.".yellow
target_repo = gets
target_repo = target_repo.chomp
puts "You chose: #{target_repo}"
# user can add more elsif blocks here
if target_repo == "1"
  puts "Trying to get #{target} from core.".blue
  system("curl #{core}/#{target}.tar.gz -o #{home}/.fpm/install/#{target}.tar.gz")
  puts "Verifying package intergrity..."
  system("sha256sum #{home}/.fpm/install/#{target}.tar.gz > /tmp/fpm_checksum")
  system("curl -fs #{core}/index/#{target}.hash -o /tmp/#{target}.hash")
  solid = FileUtils.identical?("/tmp/fpm_checksum", "/tmp/#{target}.hash")
  if solid == "false"
    puts "Unable to verify package integrity."
    puts "Install anyways? [y/N]"
    disregardcheck = gets
    disregardcheck = disregardcheck.chomp
    if disregardcheck == "y"
      puts "Disregard integrity check and try unpack".red
    else
      puts "Cancelling..."
      puts "Cleanup directories..."
      system("rm -f #{home}/.fpm/install/*")
      system("rm -f /tmp/fpm_* /tmp/*.hash")
      abort "fpm: fatal: package integrity could not be verified."
    end
  else
    puts "Package solid".green
  end
  puts "try unpack".blue
  system("tar -xzvf #{home}/.fpm/install/#{target}.tar.gz -C #{home}/.fpm/install")
  puts "If there was no errors, the package should have been unpacked.".yellow
  puts "try transfer".blue
  sleep(1)
  system("cp #{home}/.fpm/install/#{target} #{home}/.fpm/pkgs/#{target}")
  puts "If all went well, your package should be installed. If you haven't already, add #{home}/.fpm/pkgs to your PATH variable.".green
elsif target_repo == "2"
  puts "Note: packages in the 'live' repository are not subject to integrity checks.".red
  puts "This is because the code is often updated frequently and isn't intended to be mainstream."
  puts "Trying to get #{target} from live.".yellow
  system("curl #{live}/#{target}.tar.gz -o #{home}/.fpm/install/#{target}.tar.gz")
  puts "try unpack".blue
  system("tar -xzvf #{home}/.fpm/install/#{target}.tar.gz #{home}/.fpm/install")
  puts "If there was no errors, the package should have been unpacked.".yellow
  puts "try transfer".blue
  eval(File.read("fpkgd"), binding)
  system("cp #{home}/.fpm/install/#{target} #{home}/.fpm/pkgs/#{target}")
  puts "If all went well, your package should be installed. If you haven't already, add #{home}/.fpm/pkgs to your PATH variable.".green
else
  puts "unknown repo. exiting."
  abort "nonexistent repo.".red
end
targetfile.close
puts "fpm_spine: cleanup"
puts "Cleaning install directory..."
system("rm -f #{home}/.fpm/install/*")
puts "adding an entry to pkglist..."
system("echo #{target} >> #{home}/.fpm/pkgs/pkglist.txt")
puts "done.".green
