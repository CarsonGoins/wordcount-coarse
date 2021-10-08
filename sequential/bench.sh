#!/bin/bash

RESULTDIR=result/
h=`hostname`

if [ "$h" = "gal-i1.uncc.edu"  ];
then
    echo Do not run this on the headnode of the cluster, use qsub!
    exit 1
fi

if [ ! -d ${RESULTDIR} ];
then
    mkdir ${RESULTDIR}
fi

echo running on ${h}
echo seq: starting bench at $(date)

./main filelist.txt the 1000000 2>${RESULTDIR}/sequential  >/dev/null

echo seq: ending bench at $(date)
