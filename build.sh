#!/bin/bash
#Build environment
echo "Building Sources"
cd src
make clean
make
cd ..
echo "Building App"
cd examples
make clean
make
cd ..
