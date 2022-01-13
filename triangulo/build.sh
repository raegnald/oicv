#!/bin/sh

set -xe

gcc main.c -o main.out -lm
./main.out