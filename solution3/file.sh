#!/bin/bash


exec < test.txt

dd if=/dev/stdin bs=1 count=5 skip=3 2>/dev/null

echo -e '\n'

