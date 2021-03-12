# Foundation Package Manager
# spine_install
# Developed by Brett. (https://github.com/notronaldmcdonald)

# variables

home = Dir.home

# repository targets
# USER - if you wish to add a repository, use this format.
core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/pkgs"
live = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/live/pkgs"

# begin script

eval(File.read(".target.txt"), binding)
puts "Welcome!"
puts "You requested: #{target}."
puts "Select a repository to download from:"
puts "1) core (#{core})"
puts "2) live (#{live})"
# user can add more lines to this list
puts "Choose repository by entering the number."
target_repo = gets
target_repo = target_repo.chomp
puts "You chose: #{target_repo}"
# user can add more elsif blocks here
if target_repo == 1
  puts "Trying to get #{target} from core."
  system("curl #{core}/#{target}.tar.gz -o #{home}/.fpm/install/#{target}.tar.gz")
  puts "try unpack"
  system("tar -xzvf #{home}/.fpm/install/#{target}.tar.gz #{home}/.fpm/install")
  puts "If there was no errors, the package should have been unpacked."
  puts "try transfer"
  eval(File.read("fpkgd"), binding)
  puts "package base is #{base}"
  system("cp #{home}/.fpm/install/#{base} #{home}/.fpm/pkgs/#{base}")
  puts "If all went well, your package should be installed. If you haven't already, add #{home}/.fpm/pkgs to your PATH variable."
elsif target_repo == 2
  puts "Trying to get #{target} from live."
  system("curl #{live}/#{target}.tar.gz -o #{home}/.fpm/install/#{target}.tar.gz")
  puts "try unpack"
  system("tar -xzvf #{home}/.fpm/install/#{target}.tar.gz #{home}/.fpm/install")
  puts "If there was no errors, the package should have been unpacked."
  puts "try transfer"
  eval(File.read("fpkgd"), binding)
  puts "package base is #{base}"
  system("cp #{home}/.fpm/install/#{base} #{home}/.fpm/pkgs/#{base}")
  puts "If all went well, your package should be installed. If you haven't already, add #{home}/.fpm/pkgs to your PATH variable."
else
  puts "unknown repo. exiting."
  abort "nonexistent repo."
end
puts "fpm_spine: cleanup"
puts "Cleaning install directory..."
system("rm -f #{home}/.fpm/install/*")
puts "done."
