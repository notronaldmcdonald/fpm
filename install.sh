#!/usr/bin/env bash
# Linux install script for FPM 2.
# Developed by Brett. (https://github.com/notronaldmcdonald)

# Requires foundation-base.
if [ -e ~/foundation/foundation-base ]; then
  source ~/foundation/foundation-base
else
  echo "Foundation not installed."
  echo "Installing."
  mkdir $HOME/foundation
  curl https://raw.githubusercontent.com/notronaldmcdonald/bash-scripts/master/foundation/foundation-base -o $HOME/foundation/foundation-base
  curl https://raw.githubusercontent.com/notronaldmcdonald/bash-scripts/master/foundation/foundation-extra -o $HOME/foundation/foundation-extra
  source $HOME/foundation/foundation-base
fi

# begin script

echo "${YELLOW}==> ${RESET}Start installation script."
echo "${YELLOW}install: get with curl"
echo "${RESET}"
mkdir ~/.fpm/
mkdir ~/.fpm/.install2/
curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/src/fpm2.cpp -o $HOME/.fpm/.install2/fpm2.cpp
curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/src/.fpm_spine_install_fpm.py -o $HOME/.fpm/.install2/.fpm_spine_install_fpm.py
curl https://raw.githubusercontent.com/notronaldmcdonald/fpm/core/src/release-info -o $HOME/.fpm/release-info
g++ $HOME/.fpm/.install2/fpm2.cpp -o $HOME/.fpm/.install2/a.out
mv $HOME/.fpm/.install2/a.out $HOME/.fpm/.install2/fpm
echo "${LIGHTBLUE}install: request privilege escalation to access /usr/local/bin${RESET}"
sudo mv $HOME/.fpm/.install2/fpm /usr/local/bin/fpm
sudo mv $HOME/.fpm/.install2/.fpm_spine_install_fpm.py /usr/local/bin/.fpm_spine_install_fpm.py
echo "${BRIGHTGREEN}install: stop execution${RESET}"
