#!/bin/sh
cat /etc/passwd |
grep -v "^#" |
awk "NR%2==0" |
cut -d ':' -f 1 |
rev |
sort |
tac |
awk "NR>=${FT_LINE1:-7} && NR<=${FT_LINE2:-15}" |
tr '\n' ',' |
sed 's/,/, /g' |
sed 's/, $/./'