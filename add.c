#include "func.h"

Tree *T_Add(Tree* proot, char* data, int key){
	if (proot == NULL) {

            Tree *new = malloc(sizeof(Tree));
            new->key = key;
            new->left = new->right = NULL;
	    new->data = data;
            new->height = 1;

            return new;
        }
	if (key > proot->key){
		proot->right = T_Add(proot->right, data, key);
	}
	else if (key < proot->key){
		proot->left = T_Add(proot->left, data, key);
	}
        else{
            proot->data = data;
	}

	return rec(proot);
}


