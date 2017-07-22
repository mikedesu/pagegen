# pagegen

### Before Use:

1. Run `make`.
2. Create a file to hold the following:
    - Your style.css
    - Your Google Analytics (or whatever)
    - Your site header (which will show up on every page generated)
3. Create a file that contains, one per line, each keyword you would like to appear in the meta keywords tag.
4. Configure the file `b`.

```
PAGESDIR="./pages"
OUTDIR="./test"
INEXT="md" # infile extension
OUTEXT="html" # outfile extension
FOOTERFILE="footer.html" # file containing footer
SITE="evildojo v0.1"
STYLEGAJSHEADER="style_gajs_header.txt"
KEYWORDS="keywords.txt"
```
5. List the pages that you'd like to build, one per line, excluding output extension (so, just the base filename), in the file `pages.txt`. 
6. Make sure that you have the program [pandoc](https://pandoc.org/) installed on your system.
7. Configure the file `up`

```
FLAGS="-av --progress"
FILES="test/*.html"
USER="user"
SERVER="0.1.2.3"
LOCATION="/home/user/www/."
```

-----

### Tools

```
./b
./build_entire_site
./m
./q
./up
```

1. b
    - build
    - builds an individual page
    - usage: `./b index`
2. build\_entire\_site 
    - build entire site
    - builds each page listed in pages.txt
    - usage: `./build_entire_site` 
3. m
    - markdownurl
    - allows for quick generation of a timestamp and markdown-formatted hyperlink
    - usage: `./m https://www.google.com`
4. q
    - quickupdate
    - allows for scripted quick page building and directory rsync
    - usage: `./q`
5. up
    - up
    - rsyncs the html output directory with the designated endpoint
    - usage: `./up`
