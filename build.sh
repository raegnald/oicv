#!/bin/sh

set -e

folder=$1

if [ $folder ]; then
  gcc $folder/main.c -o $folder/main.out &&
  $folder/main.out
else
  echo "Specify folder, e.g. ./build.sh canguros/ "
fi
