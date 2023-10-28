#!/bin/bash

g++ -std=c++11 -stdlib=libc++ $1/$2.cpp -o $1/$2
./$1/$2