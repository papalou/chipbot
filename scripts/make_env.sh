#!/bin/sh

if [ ! -e "libcommon" ]; then
	echo "Clone libcommon"
	git clone https://github.com/papalou/libcommon.git
fi

echo "All done"
exit 0
