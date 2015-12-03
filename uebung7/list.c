#include <stdio.h>
#include <stdlib.h>

typedef struct element * list;
struct element {
	int value;
	list next;
};

/* Einfügen eines Elements am Beginn einer 
   bestehenden Liste. */
list cons(int value, list l){
	list new_head;
	new_head = malloc(sizeof(*new_head));
	new_head->value = value;
	new_head->next = l;
	return new_head;
}

void print_list(list l){
	int first = 1;
	printf("[");

	while (l != NULL) {
		if (first)
			first = 0;
		else 
			printf(", ");
		printf("%d", l->value);
		l = l->next;
	}
	printf("]\n");
}

int sum(list h){
	int s = 0;
	/* solange nicht Listenende erreicht */
	while (h != NULL){
		s = s + h->value;
		h = h->next;
	}
	return s;
}

int sum_rec(list l){
	if (l == NULL)
		return 0;
	else 
		return l->value + sum_rec(l->next);
}

void rmEvens(list * h){
	list tmp; 
	while (*h != NULL) {
		if ((*h)->value % 2 == 0){
			tmp = *h;
			*h = (*h)->next;
			free(tmp);
		} 
		else
			h = &((*h)->next);
	}
}

int main() {
	list my_list = cons(8,
				   cons(2,
				   cons(3,
				   cons(5,
				   cons(2,
				   cons(4,
				   NULL))))));
	print_list(my_list);
	printf("summe: %d\n", sum_rec(my_list));
	rmEvens(& my_list);
	print_list(my_list);
	return 0;
}