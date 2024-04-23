#!/bin/bash

for dir in $(find . -type f -name Makefile); do
    dir=$(dirname $dir)
    make -C $dir fclean
done