all:release

release:controller bot
	if [ -e ./release ]; then rm -rf ./release/; fi
	mkdir ./release/
	cp ./controller/chipbot_controller ./release/
	cp ./bot/chipbot_receiver ./release/

controller:libcommon
	cd controller && $(MAKE)

bot:libcommon
	cd bot && $(MAKE)

libcommon:
	cd libcommon && $(MAKE)

clean:
	if [ -e ./release ]; then rm -rf ./release/; fi
	cd controller && $(MAKE) clean
	cd bot && $(MAKE) clean
	cd libcommon && $(MAKE) clean

dev_env:
	echo "Create dev environement"
	./scripts/make_env.sh

.PHONY:all\
release\
controller\
bot\
libcommon\
clean\
env\
