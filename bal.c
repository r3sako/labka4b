#include "func.h"

void fix(Tree *root) {
    int left_h, right_h;

    if (root->left != NULL)
	left_h = root->left->height;
    else
	left_h = 0;

    if (root->right != NULL)  
	right_h = root->right->height;
    else 
	right_h = 0;

    if (right_h > left_h) 
	root->height = left_h + 1;
    else 
	root->height = right_h + 1;
}

Tree* r_rout(Tree* tree){
        Tree* proot = tree->left;
        tree->left = proot->right;
        proot->right = tree;
        proot->parent = NULL;
        proot->right->parent = proot;

        if (proot->right->left != NULL) 
        	proot->right->left->parent = proot->right;

        fixx(tree);
        fixx(proot);
        return proot;
}

Tree* l_rout(Tree* tree){
        Tree* proot = tree->right;
        tree->right = tree->left;
        proot->left = tree;
        proot->parent = NULL;
        proot->left->parent = proot;
        if (proot->left->right != NULL)
        	proot->left->right->parent = proot->left;

        fixx(tree);
        fixx(proot);
        return proot;
}

int fixx(Tree* proot) {
    int left_h, right_h;

    if (proot->left != NULL)  
	left_h = proot->left->height;
    else 
	left_h = 0;

    if (proot->right != NULL)  
	right_h = proot->right->height;
    else 
	right_h = 0;

    return (right_h - left_h);
}

Tree *rec(Tree *proot) {
        fix(proot);

        if (fixx(proot) == -2) {
        	 if (fixx(proot->left) > 0)
                        proot->left = l_rout(proot->left);
                proot = r_rout(proot);
                return proot;
        }


        if (fixx(proot) == 2) {
                if (fixx(proot->right) < 0)
                        proot->right = r_rout(proot->right);
        	proot = l_rout(proot);
        	return proot;
        }

        return proot;
}

