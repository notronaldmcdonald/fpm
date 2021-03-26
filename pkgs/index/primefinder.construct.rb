# package build/install script
# use as an example
base = "primefinder"
homedir = Dir.home

def install()
  puts "install #{base}"
  system("cp #{base} #{homedir}/.fpm/pkgs/#{base}")
  puts "copied #{base} to package folder"
end
