#!/bin/sh
find . -type d -o -type f | wc -l |  sed 's/ //g'
