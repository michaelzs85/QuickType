#!/bin/bash

cd
echo `ls`
echo `pwd`
mkdir build
cd build 
echo `pwd`
cmake ../QuickType
cmake --build . -- -j2
echo `ls`
cd unittests
ctest

