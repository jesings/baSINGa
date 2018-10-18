#include <stdlib.h>
#include <stdio.h>
#include "linked_slist.h"
#include "sbucket.h"
#include "snode.h"
int main(){

  printf("=============== linked list functions ======================\n\n");
  struct snode* head = NULL;
  head = add_alph(head, make_snode("All Star", "Smash Mouth"));
  head = add_alph(head,make_snode("Ra Ra Rasputin", "Boney M."));
  head = add_alph(head,make_snode("Moskau", "Dschinghis Khan"));
  head = add_alph(head,make_snode("Bazinga", "Theodore Peters"));
  head = add_alph(head, make_snode("Decades of Synthetic Tears", "Benson Goldman"));
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
  head = remove_slist(head);


  
  printf("============= music library functions =================\n");
  struct snode* sbucket[27];
  init_sbucket(sbucket);
  printf("adding values to sbucket:\n");
  add_sbucket(make_snode("Several Species of Small Furry Animals Gathered Together in a Cave and Grooving with a Pict", "Pink Floyd"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Tarkus", "Emerson, Lake & Palmer"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Metropolis--Part I: \"The Miracle and the Sleeper\"", "Dream Theater"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("The Sound of Muzak", "Porcupine Tree"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("When the Levee Breaks", "Led Zeppelin"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("When the Levee Breaks", "Perfect Circle"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("21st Century Schizoid Man", "21st Century Schizoid Band"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Pigs On the Wing (Part 1)", "PINK FLOYD"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("pIGS oN tHE wING (pART 2)", "pINK fLOYD"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Pigs (Three Different Ones)", "pink floyd"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Racecar", "Periphery"), sbucket);
  print_whole_lib(sbucket);
  add_sbucket(make_snode("Mr. Invisible", "Thank You Scientist"), sbucket);

  print_whole_lib(sbucket);
  printf("\n\n");
  shuffle(sbucket);
  
  return 0;
}

