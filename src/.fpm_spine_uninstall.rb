# Foundation Package Manager
# spine_uninstall
# Developed by Brett. (https://github.com/notronaldmcdonald)

# dependency

Bundler.require(:default)

# some variables

home = Dir.home
mode = "r"

# begin script

targetstore = File.open("/tmp/.target.txt", mode)
target = targetstore.read
puts "fpm_spine: ruby script".green
puts "fpm_spine: uninstall".red
puts "fpm_spine: read package list".yellow
system("cat #{home}/.fpm/pkgs/pkglist.txt | grep -w #{target} > /tmp/.output.tmp")
checkfile = File.size("/tmp/.output.tmp")
sleep(1)
if checkfile != "0"
  puts "fpm_spine: uninstall: package exists".green
  puts "fpm_spine: uninstall: remove? [Y/n] ".yellow
  removeconfirm = gets
  removeconfirm = removeconfirm.chomp
  if removeconfirm == "n"
    puts "fpm_spine: uninstall: user denied."
    abort "fpm_spine: fatal: uninstall failed (user aborted)".red
  else
    puts "fpm_spine: uninstall: removing package...".yellow
    system("rm -f #{home}/.fpm/pkgs/#{target}")
    puts "fpm_spine: uninstall: package should be removed.".green
  end
else
  puts "fpm_spine: uninstall: package not found.".blue
  abort "fpm_spine: fatal: package not found.".red
end
puts "fpm_spine: done.".green
