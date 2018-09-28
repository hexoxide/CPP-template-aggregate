rm -rf build/
mkdir build
cd build
cmake ../
make lib
make bin
make tests
make test
valgrind --leak-check=full --show-leak-kinds=all bin/bin
