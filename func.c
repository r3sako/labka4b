#include "func.h"

void clear(Tree *tree) {

    if (tree == NULL)
	return;
    clear(tree->left);
    clear(tree->right);
    clear(tree);
}

int getInt(int *pn)
{
	const char *errmsg = "";
	int n;
	do{
		puts(errmsg);
		errmsg = "Illegal integer; enter once more";
		n = scanf("%d", pn);
		if (n < 0)
			return 0;
		scanf("%*[^\n]");
		scanf("%*c");
	} while (n == 0);
	return 1;
}


int dialog(const char *msgs[], int N)
{
	const char *errmsg = "";
	int rc;
	int i, n;

	do{
		puts(errmsg);
		errmsg = "You are wrong. Repeat, please!";

		for (i = 0; i < N; ++i)
			puts(msgs[i]);
		puts("Make your choice: --> ");

		n = getInt(&rc);
		if (n == 0)
			rc = 0;
	} while (rc < 0 || rc >= N);

	return rc;
}

