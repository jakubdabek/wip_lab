#!/bin/bash
find -name Makefile | xargs sed -i 's/^.*include.*$/CC = clang\nCFLAGS = -Wall --pedantic -std=c11\n\n/'
