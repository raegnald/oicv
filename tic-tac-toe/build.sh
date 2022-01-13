#!/bin/sh

set -xe

gcc main.c -o tic_tac_toe.out -lm
./tic_tac_toe.out