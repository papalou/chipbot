#!/bin/sh

if [ ! -e "source/libcommon" ]; then
	echo "Clone libcommon"
	git clone https://github.com/papalou/libcommon.git source/libcommon
fi

echo "All done"
exit 0
