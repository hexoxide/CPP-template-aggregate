# ZeroMQ-travis

## Installing dependencies

* Debian / Ubuntu
`sudo apt install cmake cmake-data g++ gcc gfortran \
debianutils build-essential make patch sed \
libx11-dev libxft-dev libxext-dev libxpm-dev libxmu-dev \
libglu1-mesa-dev libgl1-mesa-dev \
libncurses5-dev curl libcurl4-openssl-dev bzip2 libbz2-dev gzip unzip tar \
subversion git xutils-dev flex bison lsb-release python-dev \
libc6-dev-i386 libxml2-dev wget libssl-dev libkrb5-dev \
automake autoconf libtool`

* Manjaro / Arch
`sudo pacman -S make cmake gcc gcc-fortran`

* CentOS 7.5
`sudo yum install make cmake gcc gcc-fortran patch sed \
libX11-devel libXft-devel libXpm-devel libXext-devel \
libXmu-devel mesa-libGLU-devel mesa-libGL-devel ncurses-devel \
curl curl-devel bzip2 bzip2-devel gzip unzip tar \
expat-devel subversion git flex bison imake redhat-lsb-core python-devel \
libxml2-devel wget openssl-devel krb5-devel \
automake autoconf libtool which`

### Recommend installation

```
wget -O arch-4.16-fairsoft.tar.xz https://dancloud.dantalion.nl/index.php/s/scX8os9v4avHBCK/download
wget -O arch-4.16-fairroot.tar.xz https://dancloud.dantalion.nl/index.php/s/cV3tvqDJWZ22bwQ/download
sudo mkdir /var/fairsoft /var/fairroot
sudo tar -xf arch-4.16-fairsoft.tar.xz -C /
sudo tar -xf arch-4.16-fairroot.tar.xz -C /
```

### Manual FairSoft installation

```
git clone https://github.com/FairRootGroup/FairSoft
cd FairSoft
./configure.sh
```

### Manual FairRoot installation

```
git clone https://github.com/FairRootGroup/FairRoot
cd FairRoot
export SIMPATH=/var/fairsoft
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX="/var/fairroot" ../
make
make install
```

## Problems, Hurdles & Solutions

### FairRoot
FairRoot is a massive framework with a lot of dependencies and therefor introduces many problems. A breakdown of individual problems and possible solutions will allow to thoroughly overcome the hurdles that this framework introduces.

#### Compiling the entire FairRoot stack takes around 4 hours on a modern octocore i7 with 16gb of ram and 32gb of swap.
Creating precompiled packages build for a predetermined path. These packages can then be downloaded and extracted seriously cutting down compilation time. This solution might not be ideal for a real deployment but are more then excellent for TravisCI testing.

The precompiled FairRoot package requires around 5.5gb of disc space which is substantial for an Travis environment but luckily far below the limit imposed on disc space. Archiving the entire 5.5gb data set might be unreasonable due to the large amount of time it would take for Travis to unarchive it. However the package exists of around 250k of files which makes downloading each individual file require an unreasonable amount of time as well. Archiving the package using an archive format which does not compress the files (Tape ARchive tar) is likely the ideal solution.

#### Compiling FairRoot takes around 25gb of working memory
Investigate if using aws, kubernetes or another cloud solution with scalable memory can be used to build FairRoot. If these cloud solutions are unavailable at this scale Corne has a workstation at home which can be accessed remotely which has 32gb of working memory excluding swap.

## Libraries & Tools

- Cmake 2.8.1
- GCC 4.8 with c++ and fortran
- Boost 1.53
- FairSoft
- FairRoot

## Technologies

- Github + projects & milestones
- Travis-CI 
- Docker

### Online resources

- (Code Conventions)[https://github.com/AliceO2Group/CodingGuidelines]
- (TravisCI hardware specifications)[https://docs.travis-ci.com/user/reference/overview/]
- (Shared vs Static libraries)[https://stackoverflow.com/questions/2649334/difference-between-static-and-shared-libraries]

### Helpful tools

- `objdump -p BINARY` Show required libraries and their paths also works on .so files
- `ldd BINARY` show required libraries, if they could be located and if so where they are located
- `patchelf --set-rpath 'DIRECTORY' BINARY` Change RPATH / RUNPATH for binary, can be set to relative part and to multiple paths using `:` #powerful