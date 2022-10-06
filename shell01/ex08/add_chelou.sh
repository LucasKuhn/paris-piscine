#!/bin/sh

A=$(echo $FT_NBR1 | tr "'\\\\\"?\!" "01234") # FT_NBR1 translated
B=$(echo $FT_NBR2 | tr "mrdoc" "01234") # FT_NBR2 translated
C=$(echo "obase=13; ibase=5; ($A+$B)" | bc) # A+B sum
D=$(echo $C | tr "0123456789ABC" "gtaio luSnemf") # C translated

echo $D