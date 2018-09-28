#/bin/bash
yum update -y
yum install -y gcc g++ gcc-c++ cmake doxygen valgrind cmake autoconf automake uuid-devel pkgconfig libtool make git boost-devel wget
wget http://download.fedoraproject.org/pub/epel/6/x86_64/epel-release-6-8.noarch.rpm
rpm -ivh epel-release-6-8.noarch.rpm
wget http://download.zeromq.org/zeromq-4.0.3.tar.gz
tar xzvf zeromq-4.0.3.tar.gz
cd zeromq-4.0.3
gcc --version
g++ --version
./configure
make
make install
echo /usr/local/lib > /etc/ld.so.conf.d/local.conf
ldconfig
cd ..
git clone https://github.com/zeromq/cppzmq.git
cp cppzmq/zmq.hpp /usr/include
git clone $REPO_URL
cd "$(\ls -1dt ./*/ | head -n 1)" # cd into most recently changed directory ;)
mkdir build
cd build
cmake ../
make lib
make bin
make tests
make test
valgrind --leak-check=full --show-leak-kinds=all bin/bin