#! /bin/sh

cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build
cd out/build ; make