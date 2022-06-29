#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    int height;
    char *data;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;

Tree *T_Add(Tree *, char *, int );
Tree *rec(Tree* );
int del(Tree *, int );
Tree *find(Tree *, int );
Tree *max(Tree *);
void clear(Tree *);

