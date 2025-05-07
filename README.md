# Component *MessageSource*
This repo consists of component *MessageSource*. It is a part of example application *[broker](https://github.com/slawomir-niespodziany/diff_broker)* which demonstrates the use of *[diff](https://github.com/slawomir-niespodziany/diff)* framework. 

## Description
*MessageSource* generates messages intended for sending to another system. It requires two *ILink* implementations: one as the primary link for sending generated messages and the other as a backup. It implements *IProcessable* interface, to perform internal operations when called from executing thread.

<p align="center"><a href="include/MessageSource.h"><img src="img/MessageSource.png" alt="MessageSource interface"/></a></p>

## Prerequisites
The example has been prepared and tested on Ubuntu 22.04 and Ubuntu 24.04. That being said, you only need *gcc* and *cmake* to build and install this component. The recent versions (incl. *cmake 4.0.1*) can be downloaded using following commands. 
```
sudo apt -y install build-essential
sudo snap install cmake --classic
```

## Build, Installation, Testing
*MessageSource* component requires *[iprocessable](https://github.com/slawomir-niespodziany/diff_broker_iprocessable)* and *[ilink](https://github.com/slawomir-niespodziany/diff_broker_ilink)* interfaces to be available in CMake registry. Please refer to their repos for installation guides.

#### Install & test by script
Run the following command from component directory to build, install and test it.
```
./build.sh
```

#### Build & install by hand
Run the following commands from component directory to build (incl. tests) and install it manually. 
```
cmake -Bbuild -DCMAKE_EXPORT_PACKAGE_REGISTRY=ON
cmake --build build
```

#### Test by hand
Tests are run in isolation from other components. The following command, executed from component directory, runs the built tests.
```
ctest --test-dir build/test
```
