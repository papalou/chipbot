all:bot

BUILD_FOLDER_PATH="../bot_build/"

bot:libcommon
	if [ ! -e $(BUILD_FOLDER_PATH) ]; then mkdir -p $(BUILD_FOLDER_PATH); fi
	cd $(BUILD_FOLDER_PATH) && qmake "../bot/"
	cd $(BUILD_FOLDER_PATH) && $(MAKE)

libcommon:
	cd ../libcommon/ && $(MAKE) 

clean:
	echo "Clean build folder"
	if [ -e $(BUILD_FOLDER_PATH) ]; then rm -rf $(BUILD_FOLDER_PATH); fi

.PHONY:all\
bot\
libcommon\
clean
