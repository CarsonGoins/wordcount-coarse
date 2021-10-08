#!/bin/bash

if [ -f "./main" ]; then
	sbatch --partition=Centaurus --chdir=`pwd` --time=01:00:00 --ntasks=1 --cpus-per-task=1 --mem=100G --job-name=mod3seq ./bench.sh
else
  echo -e "\nERROR!\nUnable to benchmark!\nYou must compile first with \"make\""
fi
