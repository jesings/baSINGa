#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "snode.h"
struct snode* make_snode(char* song_name, char* artist_name){
    struct snode* new_snode = malloc(sizeof(struct snode));
    strcpy(new_snode->name,song_name);
    strcpy(new_snode->artist,artist_name);
    return new_snode;
}
struct snode* add_front(struct snode* head, struct snode* to_insert){
    to_insert->next = head;
    return to_insert;
}
struct snode* add_alph(struct snode* head, struct snode* to_insert){
    if(!head) 
        return add_front(head,to_insert);
    struct snode* working = head->next;
    struct snode* prev = head;
    while(1){
        if(!working){
            prev->next = to_insert;
            to_insert->next = NULL; 
            break;
        }
        if(!strcmp(working->artist,to_insert->artist)){
            if(strcmp(working->name,to_insert->name)<0){
                prev = working;
                working = working -> next;
                continue;
            }
            else{
                prev->next = to_insert;
                to_insert->next = working;
                break;
            }
        }
        if(strcmp(working->artist,to_insert->artist)<0){
            prev = working;
            working = working -> next;
            continue;
        }
        prev->next = to_insert;
        to_insert->next = working;
        break;
    }
    return head;
}
void print_lib(struct snode* head){
    printf("song: %s, artist: %s \n",head->name,head->artist);
    if(head->next)
        print_lib(head->next);
}
struct snode* find_song_an(char* artist, char* songname, struct snode* node){
    if(!node) return NULL;
    if(!strcmp(node->artist,artist)&&!strcmp(node->name,songname))
        return node;
    return find_song_an(artist,songname,node->next);
}
struct snode* find_song_a(char* artist, struct snode* node){
    if(!node) return NULL;
    if(!strcmp(node->artist,artist))
        return node;
    return find_song_a(artist,node->next);
}
int len(struct snode* head){
    if(head) return 1 + len(head->next);
    return 0;
}
struct snode* rand_song(struct snode* head){
    int i = rand()%len(head);
    for(;i>0;i--){
        head = head->next;
    }
    return head;
}
void remove_snode(struct snode* to_remove, struct snode* head){
    struct snode* prev;
    while(head){
        if(head==to_remove){
            if(prev) prev->next = head;
            free(to_remove);
            break;
        }
        prev = head;
        head = head->next;
    }
    printf("element not found in list\n");
}
void remove_slist(struct snode* head){
    if(head->next)
        remove_slist(head->next);
    free(head);
}
