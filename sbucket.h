#ifndef SBUCKET_H
#define SBUCKET_H

struct snode* init_sbucket(struct sonde* sbucket);
struct snode* add_sbucket(struct snode * snew, struct snode * sbucket);
struct snode* find_s(struct snode* sbucket_arr,char * sartist, char * sname);

void print_single_letter(struct snode* sbucket_arr,char letter);
void print_single_artist(struct snode* sbucket,char* artist_name);
void print_whole_lib(struct snode* sbucket);

struct snode* rm_song(struct snode* sbucket, char* artist, char* song);
void shuffle(struct snode* sbucket);

//       V   helpers     V

struct snode* first_sbucket(struct snode* sbucket, int start);
struct snode* last_sbucket(struct snode* sbucket, int end);
void swap(struct snode* prts, int i1, int i2);
char chri(char c);


#endif
