all:controller

BUILD_FOLDER_PATH="../controller_build/"

controller:libcommon
	if [ ! -e $(BUILD_FOLDER_PATH) ]; then mkdir -p $(BUILD_FOLDER_PATH); fi
	cd $(BUILD_FOLDER_PATH) && qmake "../controller/"
	cd $(BUILD_FOLDER_PATH) && $(MAKE)

libcommon:
	cd ../libcommon/ && $(MAKE) 

clean:
	echo "Clean build folder"
	if [ -e $(BUILD_FOLDER_PATH) ]; then rm -rf $(BUILD_FOLDER_PATH); fi

.PHONY:all\
controller\
libcommon\
clean
