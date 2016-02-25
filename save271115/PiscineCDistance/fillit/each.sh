#!/bin/bash

for i in $(seq 4 5 109)
do
	head -n $i yolo > tests/$((($i + 1) / 5))
done
