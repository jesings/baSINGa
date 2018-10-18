#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "snode.h"

char cistrcmp(char* all, char* star) {
  for (;*all && tolower(*all) == tolower(*star); all++, star++);
  return (unsigned char)tolower(*all) - (unsigned char)tolower(*star);
}

struct snode* make_snode(char* song_name, char* artist_name){
  struct snode* new_snode = malloc(sizeof(struct snode));
  strcpy(new_snode->name,song_name);
  strcpy(new_snode->artist,artist_name);
  return new_snode;
}

struct snode* add_front(struct snode* head, struct snode* to_insert){
    if(!to_insert) return NULL;
    to_insert->next = head;
    return to_insert;
}

struct snode* add_alph(struct snode* head, struct snode* to_insert){
  int cmpnum = cistrcmp(head->artist, to_insert->artist);
  if (!to_insert || !head || cmpnum < 0 || (!cmpnum && cistrcmp(head->name, to_insert->name) < 0)) 
    return add_front(head, to_insert);
  struct snode* prev = head;
  for (;prev->next; prev = prev->next) {
    int cmpnum = cistrcmp(prev->next->artist, to_insert->artist);
    if (cmpnum < 0 || (!cmpnum && cistrcmp(prev->next->name, to_insert->name) < 0))
      break;
  }
  to_insert->next = prev->next;
  prev->next = to_insert;
}

void print_lib(struct snode* head){
    if(!head) return;
    printf("song: %s, artist: %s \n",head->name,head->artist);
    if(head->next)
        print_lib(head->next);
}

struct snode* find_song_an(char* artist, char* songname, struct snode* node){
    if(!node) return NULL;
    if(!strcmp(node->artist,artist)&&!cistrcmp(node->name,songname))
        return node;
    return find_song_an(artist,songname,node->next);
}

struct snode* find_song_a(char* artist, struct snode* node){
    //note: seg faults on invalid input
    if(!node) return NULL;
    if(!strcmp(node->artist,artist))
        return node;
    return find_song_a(artist,node->next);
}

int len(struct snode* head) {
    if(head) return 1 + len(head->next);
    return 0;
}

struct snode* rand_song(struct snode* head){
    if(!head) return NULL;
    int i = rand()%len(head);
    for(;i>0;i--){
        head = head->next;
    }
    return head;
}

struct snode* remove_snode(struct snode* to_remove, struct snode* head){
    struct snode* prev;
    struct snode* first = head;
    while(head){
        if(head==to_remove){
            if(prev) prev->next = head->next;
            if(to_remove==first) first = first->next;
            free(to_remove);
            return first;
        }
        prev = head;
        head = head->next;
    }
    printf("element not found in list\n");
    return NULL;
}

void remove_slist(struct snode* head){
    if(!head) return;
    struct snode* delet_next = head->next;
    free(head);
    remove_slist(delet_next);
}
