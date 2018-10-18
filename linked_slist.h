#ifndef SLIST_H
#define SLIST_H
char chri(char c);
char cistrcmp(char* all, char* star);
struct snode* make_snode(char* song_name, char* artist_name);
struct snode* add_front(struct snode* head, struct snode* to_insert);
struct snode* add_alph(struct snode* head, struct snode* to_insert);
struct snode* find_song_an(char* artist, char* songname, struct snode* node);
struct snode* find_song_a(char* artist, struct snode* node);
void print_lib(struct snode* head);
struct snode* rand_song(struct snode* head);
int len(struct snode* head);
struct snode* remove_snode(struct snode* to_remove, struct snode* head);
struct snode* remove_slist(struct snode* head);
#endif
