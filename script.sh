o#!/bin/bash

echo "Enter number:"
read num

if [ $num -gt 0 ]
then
  echo "Positive"
else
  echo "Negative or Zero"
fi
