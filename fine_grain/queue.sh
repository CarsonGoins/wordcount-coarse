#!/bin/bash

RESULTDIR=result/
h=`hostname`
THREADS="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16"

if [ -f "./main" ]; then
  if [ ! -e .passed ];
  then
      echo "You must pass all test before submitting job"
      exit 1
  fi

  if [ ! -d "./result" ];
  then
      mkdir "./result"
  fi
  for thread in ${THREADS}; do
	sbatch --partition=Centaurus --chdir=`pwd` --export=THREAD=${thread} --time=01:00:00 --ntasks=1 --cpus-per-task=${thread} --mem=100G --job-name=mod3fine ./bench.sh
  done

else
  echo -e "\nERROR!\nUnable to benchmark!\nYou must compile first with \"make\""
fi
