#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct {
	int num_elems;
	Node *first;
	Node *last;
} LinkedList;

void addNode(LinkedList *list, int value) {

	Node *node = malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;

	if (list->num_elems == 0) {
		list->first = node; 
		list->last = node;
	} else {
		list->last->next = node;
		list->last = node;
	}

	list->num_elems += 1;

}

LinkedList *create_list(void) {

	LinkedList *list = malloc(sizeof(LinkedList));
	list->first = NULL;
	list->last = NULL;
	list->num_elems = 0;
	return list;

}

void print_list(LinkedList *list) {

	if (list->num_elems == 0) {
		printf("La lista no tiene elementos");
	} else {

		Node *node = NULL;

		node = list->first;

		while(node) {

			if (node->value) printf("%d ", node->value);

			node = node->next;
			
		}

	}

	printf("\n");

}

//it removes the first node with the given value or nothing otherwise
void removeNode(LinkedList *list, int value, int all) {

	Node *node = list->first; 
	Node *previous = NULL;
	int removed = 0;

	while (node && node->value && !(!all && removed)) {

		removed = 0;
		if (node->value == value) {

			//eliminar el siguiente node
			if ( node == list->first) {

				list->first = list->first->next;
				
			} else if ( node == list->last) {

				previous->next = NULL;
				list->last = previous;

			} else {

				previous->next = node->next;

			}

			removed = 1;

		}

		if (removed) {
			node = node->next;
		} else {
			previous = node;
			node = node->next;
		}


	}

}


int main(int argc, char* argv[]) {

	LinkedList *list = create_list(); 

	print_list(list);

	for (int i = 0; i < 3; i++)
		addNode(list, i+1);

	print_list(list);

	for (int i = 0; i < 3; i++) {
		addNode(list, 1);
	}

	for (int i = 0;)

	removeNode(list, 1, 1);

	print_list(list);

}