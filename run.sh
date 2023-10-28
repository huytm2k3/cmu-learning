#!/bin/bash

g++ -std=c++11 -stdlib=libc++ $1/$2.cpp -o ./build/$2
./build/$2