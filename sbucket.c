#include <stdlib.h>
#include <stdio.h>
#include "snode.h"
#include "sbucket.h"

struct snode * add_sbucket(struct snode * snew, struct snode * sbucket) {
  if ('a' <= snew->artist  && snew->artist <= 'z') {
    sbucket[snew->artist - 'a'] = add_alph(snew, sbucket[snew->artist - 'a']);
  } else if ('A' <= snew->artist && snew->artist <= 'Z') {
    sbucket[snew->artist - 'A'] = add_alph(snew, sbucket[snew->artist - 'A']);
  } else {
    sbucket[26] = add_alph(snew, sbucket[26]);
  }
  return sbucket;
}

struct snode * find_s(char * sartist, char * sname) {
  
}


