#!/bin/sh
rm -f ./SIGCSE.zip
cd ..
zip -r SIGCSE.zip SIGCSE -x ./SIGCSE/.git**\* -x ./SIGCSE/Makelib.sh                                                               
mv SIGCSE.zip ./SIGCSE
