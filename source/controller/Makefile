all:controller

SHADOW_BUILD_PATH="../controller_shadow_build/"

controller:libcommon
	if [ ! -e $(SHADOW_BUILD_PATH) ]; then mkdir -p $(SHADOW_BUILD_PATH); fi
	cd $(SHADOW_BUILD_PATH) && qmake "../controller/"
	cd $(SHADOW_BUILD_PATH) && $(MAKE)

libcommon:
	cd ../libcommon/ && $(MAKE) 

clean:
	echo "Clean build folder"
	if [ -e $(SHADOW_BUILD_PATH) ]; then rm -rf $(SHADOW_BUILD_PATH); fi

.PHONY:all\
controller\
libcommon\
clean
