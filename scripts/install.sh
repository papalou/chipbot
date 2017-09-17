#!/bin/sh

install_binary () {
	if [ ! -e "./release/" ]; then
		echo "Error: No release folder, Abort"
		exit -1
	fi

	echo "Install binary"
	sudo cp -af ./release/chipbot_bot /usr/bin/chipbot_bot
	sudo cp -af ./release/chipbot_controller /usr/bin/chipbot_controller
}

install_bot () {
	echo "Install bot in progress..."

	install_binary
}

install_controller () {
	echo "Install controller in progress..."

	install_binary
}

case $1 in
	"controller")
		install_controller
	;;

	"bot")
		install_bot
	;;

	*)
		echo "Invalid option exit"
		exit 0
	;;
esac

exit 0
