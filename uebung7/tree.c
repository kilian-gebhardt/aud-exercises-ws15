#include <stdio.h>
#include <stdlib.h>

typedef struct node * tree;
struct node {
	int key;
	tree left, right;
};

/* erzeugt neuen Baumknoten, gegeben
   einen Wert und zwei Teilbäume */
tree comp(int key, tree left, tree right){
	tree root = malloc(sizeof(*root));
	root->key = key;
	root->left = left;
	root->right = right;
	return root;
}

/* erzeugt Blattknoten */
tree leaf(int key){
	return comp(key, NULL, NULL);
}

void print_tree_rec(tree t, unsigned n){
	unsigned i;
	if (t == NULL)
		return;
	else {
		for (i = 0; i < n; i++)
			printf("  ");
		printf("└─%d\n", t->key);
		print_tree_rec(t->left, n+1);
		print_tree_rec(t->right, n+1);
	}
}
void print_tree(tree t){
	print_tree_rec(t, 0);
}

int leafprod(tree t){
	if (t == NULL)
		return 1;
	else if (t->left == NULL && t->right == NULL)
		return t->key;
	else /*if (t->left != NULL || t->right != NULL)*/
		return leafprod(t->left) * leafprod(t->right);
}

int evenSumRec(tree t, int n){
	if (t == NULL)
		return 0;
	else if (n % 2 == 0)
		return t->key 
			+ evenSumRec(t->left, n+1)
			+ evenSumRec(t->right, n+1);
	else
		return evenSumRec(t->left, n+1)
			+ evenSumRec(t->right, n+1);
}

int evenSum(tree t){
	return evenSumRec(t,0);
}


int main(){
	tree t = comp(5
		,comp(7
			,leaf(2)
			,leaf(3)
			)
		,leaf(3)
		);
	print_tree(t);
	printf("leafprod: %d\n", leafprod(t));
	printf("evenSum:  %d\n", evenSum(t));
	return 0;
}