#!/bin/bash
ROOT_SOURCE_DIR=`pwd`

# Initialize git submodules
if [ ! -d $ROOT_SOURCE_DIR/libzmq ]; then
	git submodule init --recursive
else
	git submodule update
fi

# Build libzmq if not build yet
if [ ! -f $ROOT_SOURCE_DIR/libzmq/build/lib/*.so ]; then
	echo "building libzmq"
	cd $ROOT_SOURCE_DIR/libzmq
	mkdir build
	cd build
	cmake ../
	make
	cd $ROOT_SOURCE_DIR
fi

# Copy essential files into folder
if [ ! -d $ROOT_SOURCE_DIR/dbuild ]; then
	mkdir dbuild
	cp -r libzmq/build/lib dbuild/
fi

cd dbuild
cmake -DCMAKE_BUILD_TYPE=Debug ../
make
patchelf --set-rpath ./lib examplebin
