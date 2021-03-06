#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "snode.h"
#include "linked_slist.h"

struct snode* first_sbucket(struct snode* sbucket[], int start) {
  struct snode* out = NULL;
  for (int i = start; i < 27 && !(out = sbucket[i]); i++);
  return out;
}

struct snode* last_sbucket(struct snode* sbucket[], int end) {
  struct snode* out = NULL;
  for (int i = end; i >= 0 && !(out = sbucket[i]); i--);
  return out;
}

struct snode* first_letter(struct snode* start, char l) {
  for(;start && chri(*start->artist) - chri(l); start = start->next);
  return start;
}

void init_sbucket(struct snode* sbucket[]) {
  for(int i = 0; i < 27; sbucket[i++] = NULL);
}

struct snode* add_sbucket(struct snode* sbucket[], char* sname, char* sartist) {
  struct snode* snew = make_snode(sname, sartist);
  struct snode* e = last_sbucket(sbucket, chri(*sartist) - 1);
  sbucket[chri(*sartist)] =  first_letter(add_alph(e ? e : sbucket[chri(*sartist)], snew), *sartist);
  if (!snew->next)
    snew->next = first_sbucket(sbucket, chri(*sartist) + 1);
  return snew;
}

struct snode* find_s(struct snode* sbucket[], char* sname, char* sartist) {
  return find_song_an(sartist, sname, sbucket[chri(*sartist)]);
}

void print_whole_lib(struct snode* sbucket[]) {
  print_lib(first_sbucket(sbucket, 0));
  printf("\n");
}

void print_single_letter(struct snode* sbucket[], char letter) {
  for(struct snode* sletter = sbucket[chri(letter)]; sletter && chri(letter) == chri(*sletter->artist); sletter = sletter->next)
    printf("song: %s, artist: %s \n", sletter->name, sletter->artist);
}

void print_single_artist(struct snode* sbucket[], char* artist_name) {
  for(struct snode* startist = find_song_a(artist_name, sbucket[chri(*artist_name)]);startist && !cistrcmp(startist->artist, artist_name); startist = startist->next)
    printf("song: %s, artist: %s \n", startist->name, startist->artist);  
}

void swap(struct snode* prts[], int i1, int i2) {
  struct snode* tmp = prts[i1];
  prts[i1] = prts[i2];
  prts[i2] = tmp;
}

void rm_song(struct snode* sbucket[], char* song, char* artist) {
  char ti = chri(*artist);
  struct snode* e = last_sbucket(sbucket, ti - 1);
  struct snode* tr = find_song_an(artist, song, sbucket[ti]);
  if (tr)
    sbucket[ti] =  first_letter(remove_snode(tr, e ? e : sbucket[ti]), *artist);
  else
    printf("how rude, this song doesnt exist!!\n");
}

void shuffle(struct snode* sbucket[]) {
  struct snode * tmp = first_sbucket(sbucket, 0);
  int l = len(tmp);
  struct snode* ptrs[l];
  for (int i = 0; ptrs[i++] = tmp; tmp = tmp->next);
  for(int i = l - 1; i >= 0; i--) {
    swap(ptrs, i, rand() % (i + 1));
    printf("song: %s, artist: %s \n", ptrs[i]->name, ptrs[i]->artist);
  }
}
void rm_sbuckets(struct snode* sbucket[]){
  remove_slist(first_sbucket(sbucket,0));
}
