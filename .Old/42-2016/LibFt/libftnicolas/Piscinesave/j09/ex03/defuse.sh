#!/bin/sh
touch -A -000001 bomb.txt | stat -t %x -t %s -f %a bomb.txt
