#!/bin/bash

set -e

echo "building {"

cd ${BUILD_DIR}

# rm -rf ${BIN_DIR}/*

meson ${BIN_DIR}
ninja -C ${BIN_DIR}

chmod -R a+rw ${BIN_DIR}

echo "} building"
