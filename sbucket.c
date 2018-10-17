#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "snode.h"
#include "linked_slist.h"

struct snode* init_sbucket(struct sonde* sbucket) {
  for(int i = 0; i < 26; sbucket[i++] = NULL);
  return sbucket;
}

struct snode * add_sbucket(struct snode * snew, struct snode * sbucket) {
  if ('a' <= tolower(*snew->artist)  && tolower(*snew->artist) <= 'z') {
    sbucket[tolower(*snew->artist) - 'a'] = add_alph(snew, sbucket[tolower(*snew->artist) - 'a'] - 1);
  } else {
    sbucket[26] = add_alph(snew, sbucket[26] - 1);
  }
  return snew;
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
void swap(struct snode* prts, int i1, int i2) {
  tmp = prts[i1];
  prts[i1] = prts[i2];
  prts[i2] = tmp;
}
void shuffle(struct snode* sbucket) {
  l = len(sbucket, NULL);
  struct snode ptrs[l];

  // init ptrs
  
  for(int i l; i > 0; i--) {
    
  }
}
