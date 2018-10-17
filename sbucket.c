#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "snode.h"
#include "linked_slist.h"

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

struct snode * find_s(struct snode* sbucket_arr,char * sartist, char * sname) {
  return find_song_an(sartist,sname,sbucket_arr[tolower(sartist[0])-'a']);
}

void print_single_letter(struct snode* sbucket_arr,char letter){
    print_slist(sbucket_arr[tolower(letter)-'a']);
}
void print_single_artist(struct snode* sbucket_arr,char* artist_name){
    
}

void print_whole_lib(struct snode* sbucket_arr){
    for(int i = 0;i<27;i++)
        print_slist(sbucket_arr[i]);
}
