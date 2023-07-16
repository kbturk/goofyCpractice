# Chapter 5

## Useful Programs
* `psort` - sorts text alphabetically
    * use: `a.exe < file`

* `psortpro` - uses pointers to sort lines in text files. There are several flags that can be set:
    `-n`: numeric sort (will also sort lines)
    `-r`: reverse sort
    `-f': case insensitive
    * use: `a.exe -r -n -f < file`

* `expr` - command line reverse Polish Notation Calculator
    * use: `a.exe 3 4 +`

* `cDays` - a bunch of small functions which convert dates around

* `entab` & `detab` in `tabs\ex5-11` - takes a list of tab spacings as input. Uses a default [8] if it runs out of tab listings.
    * use: `entab (or detab) 1 2 3 4 9 8 5 < {document} > {document}`
