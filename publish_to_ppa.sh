#!/bin/bash

# This script is meant to be run manually

set -ex

cd "$( dirname "${BASH_SOURCE[0]}" )"

git clean -xffd
rm -rf ../cdb_*
debuild -S -sa
VERSION=$(head -1 debian/changelog | awk '{print $2}' | sed 's/[()]//g')
dput ppa:nbelakovski/cdb ../cdb_${VERSION}_source.changes

