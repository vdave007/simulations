#!/bin/bash

# for arg in "$@"
# do
#     echo "$arg"
# done

echo "$1"
mkdir runs

COUNTER=50

while [  $COUNTER -lt 950 ]; do
    echo The counter is $COUNTER
    ./simulation $COUNTER > runs/$COUNTER.txt
    let COUNTER=COUNTER+50 
done