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
