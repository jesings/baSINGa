#include <stdlib.h>
#include <stdio.h>
#include "linked_slist.h"
#include "sbucket.h"
#include "snode.h"
int main() {

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
  add_sbucket(sbucket, "Several Species of Small Furry Animals Gathered Together in a Cave and Grooving with a Pict", "Pink Floyd");
  add_sbucket(sbucket, "Tarkus", "Emerson, Lake & Palmer");
  add_sbucket(sbucket, "Metropolis--Part I: \"The Miracle and the Sleeper\"", "Dream Theater");
  add_sbucket(sbucket, "The Sound of Muzak", "Porcupine Tree");
  add_sbucket(sbucket, "When the Levee Breaks", "Led Zeppelin");
  add_sbucket(sbucket, "When the Levee Breaks", "Perfect Circle");
  add_sbucket(sbucket, "21st Century Schizoid Man", "21st Century Schizoid Band");
  add_sbucket(sbucket, "Pigs On the Wing (Part 1)", "PINK FLOYD");
  add_sbucket(sbucket, "pIGS oN tHE wING (pART 2)", "pINK fLOYD");
  add_sbucket(sbucket, "Pigs (Three Different Ones)", "pink floyd");
  add_sbucket(sbucket, "Racecar", "Periphery");
  add_sbucket(sbucket, "Mr. Invisible", "Thank You Scientist");
  print_whole_lib(sbucket);
  printf("\n\n");
  printf("printing letter:\n");
  print_single_letter(sbucket, '?');
  printf("and again...\n");
  print_single_letter(sbucket, 'p');
  printf("printing artist:\n");
  print_single_artist(sbucket, "pInK fLoYd");

  printf("Mr. Invisible's been found...\n");
  
  struct snode* song = find_s(sbucket, "Mr. Invisible", "Thank You Scientist");
  printf("found song... %s by %s\n", song->name, song->artist);


  printf("removing perfect circle\n");
  rm_song(sbucket, "When the Levee Breaks", "Perfect Circle");
  printf("here is the entire library and letter bin entry minus that song...\n\n");
  print_whole_lib(sbucket);
  print_single_letter(sbucket, 'p');

  printf("\n\ngetting you that truly random and epic shuffling of all of your songs.............\n\n");

  shuffle(sbucket);

  printf("removing first and last songs...\n");
  rm_song(sbucket, "Metropolis--Part I: \"The Miracle and the Sleeper\"", "Dream Theater");
  rm_song(sbucket, "21st Century Schizoid Man", "21st Century Schizoid Band");

  print_whole_lib(sbucket);
  
  rm_sbuckets(sbucket);
  
  return 0;
}

