#include "func.h"

Tree *find(Tree *tree, int key) {
    Tree *tmp = tree;

    while (tmp != NULL) {

        if (key > tmp->key) {
            tmp = tmp->right;
        }
	else if (key < tmp->key) {
            tmp = tmp->left;
        }
	else
            return tmp;
    }

    return NULL;
}

Tree *max(Tree *tree) {

    if (tree == NULL)
	return NULL;

    Tree *tmp = tree;
    Tree *ptr = tree;

    while (tmp != NULL) {
        ptr = tmp;
        tmp = tmp->right;
    }

    return ptr;
}
