#!/bin/bash

# This script is meant to be run manually

set -ex

cd "$( dirname "${BASH_SOURCE[0]}" )"

git clean -xffd
rm -rf ../cdb_*
debuild -S -sa
dput -f ppa:nbelakovski/cdb ../cdb_0.1.0_source.changes

