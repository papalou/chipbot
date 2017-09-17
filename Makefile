all:release

RELEASE_PATH="./source/release/"
CONTROLLER_SRC_PATH="./source/controller/"
BOT_SRC_PATH="./source/bot/"
LIBCOMMON_PATH="./source/libcommon/"

release:controller bot
	if [ -e $(RELEASE_PATH) ]; then rm -rf $(RELEASE_PATH); fi
	mkdir -p $(RELEASE_PATH)
	cp ./source/controller_build/chipbot_controller $(RELEASE_PATH)
	cp ./source/bot/chipbot_receiver $(RELEASE_PATH)

controller:
	cd $(CONTROLLER_SRC_PATH) && $(MAKE)

bot:
	cd $(BOT_SRC_PATH) && $(MAKE)

libcommon:
	cd $(LIBCOMMON_PATH) && $(MAKE)

clean:
	if [ -e $(RELEASE_PATH) ]; then rm -rf $(RELEASE_PATH); fi
	cd $(CONTROLLER_SRC_PATH) && $(MAKE) clean
	cd $(BOT_SRC_PATH) && $(MAKE) clean
	cd $(LIBCOMMON_PATH) && $(MAKE) clean

dev_env:
	echo "Create dev environement"
	./scripts/make_env.sh

install_controller:
	echo "Install controller"
	./scripts/install.sh "controller"

install_bot:
	echo "Install bot"
	./scripts/install.sh "bot"

.PHONY:all\
release\
controller\
bot\
libcommon\
clean\
env\
install_controller\
install_bot
