# Foundation Package Manager makefile
init:
	echo "begin make"
	make build
build:
	echo "compile main binary"
	g++ ./src/fpm2.cpp -o ./.bin/fpm2_nix
	echo "compiled main binary"
	echo "compile install_head"
	g++ ./src/.installation/fpm2_install_head.cpp -o ./src/.installation/install_fpm
	echo "compiled install_head"
	echo "package installer"
	tar -czvf install_scripts.tar.gz ./src/.installation/install_fpm ./src/.installation/install_nix.rb
	echo "packaged installer"
	echo "move installer out of repo"
	mv install_scripts.tar.gz ../install_scripts.tar.gz
	echo "cleaning up..."
	rm ./src/.installation/install_fpm
	echo "finished making fpm"
# EOF
