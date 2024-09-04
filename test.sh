#!/bin/bash

cd test        # 进入 build 目录
mkdir build
cd build
cmake ..
cmake --build .
ctest