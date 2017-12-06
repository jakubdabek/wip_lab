#!/bin/bash
find -name Makefile | xargs sed -i 's/clean all/all clean/'
