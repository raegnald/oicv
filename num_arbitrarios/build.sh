#!/bin/sh

set -xe
c
gcc main.c -o bignum.out -lm
./bignum.out