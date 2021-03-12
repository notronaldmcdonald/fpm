# FPM 2.0.0
# Installation Script
# Developed by Brett. (https://github.com/notronaldmcdonald)

# variables

core = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/core"
live = "https://raw.githubusercontent.com/notronaldmcdonald/fpm/live"
home = Dir.home

# begin script

puts "Welcome to the FPM2 install script!"
puts "This script handles the installation of the Foundation Package Manager for versions 1.9.9+"
puts "To begin, what branch would you like to install from?"
puts "core: stable, tested, release versions of the software."
puts "live: whatever is currently in fpm/live. absolutely no guarantee it will work, can only install source."
target_branch = gets
target_branch = target_branch.chomp
puts "Target branch set to #{target_branch}."
puts "Checking for existing install..."
if(File.exist?("/usr/local/bin/fpm"))
  puts "The software appears to already be installed on the system. Update? [Y/n]"
  answer = gets
  answer = answer.chomp
  if answer == "n"
    puts "User refused install."
    abort "Exit script: User aborted."
  else
    if target_branch == "core"
      puts "Downloading..."
      system("curl #{core}/.bin/fpm2_nix -o fpm")
      system("curl #{core}/src/.fpm_glasses.rb -o /usr/local/bin/.fpm_glasses.rb")
      system("curl #{core}/src/.fpm_spine_install.py -o /usr/local/bin/.fpm_spine_install.py")
      system("curl #{core}/src/.fpm_spine_uninstall.py -o /usr/local/bin/.fpm_spine_uninstall.py")
      system("cp fpm /usr/local/bin/fpm")
    else
      puts "Downloading..."
      system("curl #{live}/.bin/fpm2_nix -o fpm")
      system("curl #{live}/src/.fpm_glasses.rb -o /usr/local/bin/.fpm_glasses.rb")
      system("curl #{live}/src/.fpm_spine_install.py -o /usr/local/bin/.fpm_spine_install.py")
      system("curl #{live}/src/.fpm_spine_uninstall.py -o /usr/local/bin/.fpm_spine_uninstall.py")
      system("cp fpm /usr/local/bin/fpm")
    end
  end
else
  puts "Download? [Y/n]"
  answer = gets
  answer = answer.chomp
  if answer == "n"
    puts "User refused."
    abort "Exit script: User aborted."
  else
    if target_branch == "core"
      puts "Downloading..."
      system("curl #{core}}/.bin/fpm2_nix -o fpm")
      system("curl #{core}}/src/.fpm_glasses.rb -o /usr/local/bin/.fpm_glasses.rb")
      system("curl #{core}}/src/.fpm_spine_install.py -o /usr/local/bin/.fpm_spine_install.py")
      system("curl #{core}}/src/.fpm_spine_uninstall.py -o /usr/local/bin/.fpm_spine_uninstall.py")
      system("cp fpm /usr/local/bin/fpm")
    else
      puts "Downloading..."
      system("curl #{live}/.bin/fpm2_nix -o fpm")
      system("curl #{live}/src/.fpm_glasses.rb -o /usr/local/bin/.fpm_glasses.rb")
      system("curl #{live}/src/.fpm_spine_install.py -o /usr/local/bin/.fpm_spine_install.py")
      system("curl #{live}/src/.fpm_spine_uninstall.py -o /usr/local/bin/.fpm_spine_uninstall.py")
      system("cp fpm /usr/local/bin/fpm")
    end
  end
end
puts "Done."
