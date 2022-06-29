#include "func.h"

void outputTree(char* prefix, Tree* node, int isLeft) {

    if (node) {
        printf("%s", prefix);
        if (isLeft) printf("├──");
        else printf("└──");

        printf("%d(%s)\n", node->key, node->data);

        char* addition;
        if (isLeft) addition = "│   ";
        else addition = "    ";

        int srclen = (int) strlen(prefix);
        int dstlen = (int) strlen(addition);
        char* m = (char*) calloc(srclen+dstlen+1, sizeof(char));
        memcpy(m, prefix, srclen+1);
        memcpy(m+srclen, addition, dstlen+1);

        outputTree(m, node->left, 1);
        outputTree(m, node->right, 0);

        free(m);
    }
}

int main() {
    Tree *root = NULL;

    root = T_Add(root, "Vasya", 20);
    root = T_Add(root, "Vanya", 16);
    root = T_Add(root, "Petya", 14);
    root = T_Add(root, "Vova", 13);

    printf("Find! : %s\n\n", find(root,16)->data);
    printf("Max node : %d %s\n\n", max(root)->key, max(root)->data);

    outputTree("", root, 0);
    clear(root);
    return 0;
}

