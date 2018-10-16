#include <stdlib.h>
#include <stdio.h>
#include "linked_slist.h"
#include "snode.h"
int main(){
    // struct snode* head = make_snode("All Star","Smash Mouth");
    // head = add_front(head,make_snode("Ra Ra Rasputin","Boney M."));
    // head = add_alph(head,make_snode("Moskau","Dschinghis Khan"));
    // head = add_alph(head,make_snode("Bazinga","Theodore Peters"));
    
    struct snode* head = make_snode("All Star","Smash Mouth");
    head = add_front(head,make_snode("Nyan Cat","Nyan Cat"));
    head = add_alph(head,make_snode("Look at this Graph","Nickelback"));
    head = add_alph(head,make_snode("Bazinga","Theodore Peters"));
    print_lib(head);
    printf("Finding Bazinga by Theodore Peters:\n");
    print_lib(find_song_an("Theodore Peters","Bazinga",head));
    printf("Finding Bazinga with only artist name:\n");
    print_lib(find_song_a("Theodore Peters",head));
    printf("Removing a random song:\n");
    head = remove_snode(rand_song(head),head);
    printf("List result:\n");
    print_lib(head);
    printf("Freeing whole list:\n");
    remove_slist(head);

    return 0;
}

