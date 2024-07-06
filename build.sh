#!/bin/bash

set -e

pushd tool
make
popd

pushd kpayload
make
popd

pushd installer
make
popd

rm -f ps4-hen-vtx.bin
cp installer/installer.bin ps4-hen-vtx.bin
