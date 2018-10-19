#ifndef SNODE_H
#define SNODE_H
struct snode {
    char name[100];
    char artist[100];
    struct snode *next;
};
#endif
