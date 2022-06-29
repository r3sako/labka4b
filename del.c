#include "func.h"

int T_Del(Tree *proot, int key) {

    Tree *del = find(proot, key);

    if (del == NULL)
	return 1;

    Tree *chan = max(del->left);
    Tree *par = NULL;

    if (chan == NULL) {
        par = del->parent;

        if ((par->left != NULL) && (par->left->key == del->key)) {
            par->left = NULL;
        }

        if ((par->right != NULL) && (par->right->key == del->key)) {
            par->right = NULL;
        }
        free(del);
    } else {
        par = chan->parent;
        par->right = chan->left;
	del->data = chan->data;
        del->key = chan->key;
        free(chan);
    }

    par = rec(par);
    return 0;
}
