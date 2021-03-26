# package build/install script
# use as an example
def install()
  base = "primefinder"
  homedir = Dir.home
  puts "install #{base}"
  system("cp #{home}/.fpm/install/#{base} #{homedir}/.fpm/pkgs/#{base}")
  puts "copied #{base} to package folder"
end

install()
