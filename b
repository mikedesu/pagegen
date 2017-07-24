#!/bin/bash

PAGESDIR="./pages"
OUTDIR="./test"
INEXT="md" # infile extension
OUTEXT="html" # outfile extension
FOOTERFILE="footer.html"
SITE="pagegen v0.1"
STYLEGAJSHEADER="style_gajs_header.txt"
KEYWORDS="keywords.txt"

buildpage() {
    for var in "$@"
    do
        ./a.out "$SITE" $var $STYLEGAJSHEADER $KEYWORDS > $OUTDIR/$var.$OUTEXT 
        #echo $?
        if [ $? -eq 0 ]; then
            pandoc $PAGESDIR/$var.$INEXT -t html >> $OUTDIR/$var.$OUTEXT 
            cat $FOOTERFILE >> $OUTDIR/$var.$OUTEXT 
            echo "Page $var built"
        else
            echo "Error in last command. Exiting"
        fi
        done
}

buildpage $@

