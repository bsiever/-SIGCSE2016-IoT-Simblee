#!/bin/sh
rm -f ./SIGCSE.zip
cd ..
zip -r SIGCSE.zip SIGCSE -x ./SIGCSE/.git**\*                                                               
mv SIGCSE.zip ./SIGCSE
