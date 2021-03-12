# Foundation Package Manager
# spine_uninstall
# Developed by Brett. (https://github.com/notronaldmcdonald)

# some variables

home = Dir.home
mode = "r"

# begin script

targetstore = File.open("/tmp/.target.txt", mode)
target = targetstore.read
puts "fpm_spine: ruby script"
puts "fpm_spine: uninstall"
puts "fpm_spine: read package list"
system("cat #{home}/.fpm/pkgs/pkglist.txt | grep -w #{target} > /tmp/.output.tmp")
checkfile = File.size("/tmp/.output.tmp")
sleep(1)
check = checkfile
if check == "#{target}"
  puts "fpm_spine: uninstall: package exists"
  puts "fpm_spine: uninstall: remove? [Y/n] "
  removeconfirm = gets
  removeconfirm = removeconfirm.chomp
  if removeconfirm == "n"
    puts "fpm_spine: uninstall: user denied."
    abort "fpm_spine: fatal: uninstall failed (user aborted)"
  else
    puts "fpm_spine: uninstall: removing package..."
    system("rm -f #{home}/.fpm/pkgs/#{target}")
    puts "fpm_spine: uninstall: package should be removed."
  end
else
  puts "fpm_spine: uninstall: package not found."
  abort "fpm_spine: fatal: package not found."
end
puts "fpm_spine: done."
