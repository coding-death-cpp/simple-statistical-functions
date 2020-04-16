#!/bin/bash

set -e

echo "testing {"

cd ${BIN_DIR}
meson test

chmod -R a+rw ${BIN_DIR}

echo "} testing"
