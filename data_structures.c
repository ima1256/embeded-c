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

// Inicializa la lista vacía ( done )
void initList(LinkedList *list);

// Agrega un nodo al final de la lista ( done )
void addNode(LinkedList *list, int value);

// Inserta un nodo al inicio de la lista ( done )
void insertAtFront(LinkedList *list, int value);

// Inserta un nodo en una posición específica (0-based) ( done )
int insertAtPosition(LinkedList *list, int value, int position);

// Elimina el primer nodo con el valor dado ( done )
int removeNode(LinkedList *list, int value);

// Elimina todos los nodos con un valor dado ( done )
int removeAllNodes(LinkedList *list, int value);

// Busca el primer nodo con un valor dado ( done )
Node* searchNode(LinkedList *list, int value);

// Devuelve el nodo anterior al nodo con el valor dado (NULL si no existe o es el primero) ( done )
Node* getPreviousNode(LinkedList *list, int value);

// Devuelve el nodo en una posición específica (0-based) ( done )
Node* getNodeAt(LinkedList *list, int position);

// Devuelve el número de elementos de la lista ( done  )
int getListSize(LinkedList *list);

// Imprime todos los elementos de la lista ( done )
void printList(LinkedList *list);

// Libera todos los nodos de la lista ( done )
void freeList(LinkedList *list);

// Invierte el orden de la lista ( done )
void reverseList(LinkedList *list);

// Crea una copia de la lista y devuelve un puntero a ella
LinkedList* copyList(LinkedList *list);

// Ordena la lista de menor a mayor
void sortList(LinkedList *list);

// Une otra lista al final de esta lista ( done )
void appendList(LinkedList *list, LinkedList *other);

// Elimina nodos duplicados de la lista
void removeDuplicates(LinkedList *list);

Node* getPreviousNode(LinkedList *list, int value) {

	Node *node = list->first;
	Node *prev = NULL;

	while(node) {

		if (node->value == value) return prev;

		prev = node;
		node = node->next;

	}

	return NULL;

}

//this function returns 1 if the conditions are met and -1 otherwise
int check_list_position(LinkedList *list, int position) {

	if (list->num_elems < 0) return -1;
	//the position is erroneous
	if (!(position >= 0 && position < list->num_elems)) return -1; 

	return 1;
	
}


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

void initList(LinkedList *list) {
	list->first = NULL;
	list->last = NULL;
	list->num_elems = 0;
}

LinkedList *create_list(void) {

	LinkedList *list = malloc(sizeof(LinkedList));
	initList(list);
	return list;

}

void print_list(LinkedList *list) {

	if (list->num_elems == 0) {
		printf("La lista no tiene elementos");
	} else {

		Node *node = NULL;
		node = list->first;

		while(node) {

			printf("%d ", node->value);

			node = node->next;
			
		}


	}

	printf("\n");

}

//Search a node through the linked list 
Node* searchNode(LinkedList *list, int value) {

	Node *node = list->first;

	while(node) {
		if (node->value == value) return node;
		node = node->next;
	}

	return NULL;

}

//it removes the first node with the given value or nothing otherwise
int removeAllNodes(LinkedList *list, int value) {

	Node *node = list->first; 
	Node *previous = NULL;
	int removed = 0;

	while (node) {

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
			Node *aux = node;
			node = node->next;
			free(aux);
			list->num_elems -= 1;
		} else {
			previous = node;
			node = node->next;
		}

	}

	return removed;

}

//it removes the first node with the given value or nothing otherwise
int removeNode(LinkedList *list, int value) {

	Node *node = list->first; 
	Node *previous = NULL;

	while (node) {

		if (node->value == value) {

			//eliminar el node
			if (list->num_elems == 1) {

				list->first = NULL;
				list->last = NULL;

			} else if ( node == list->first) {

				list->first = list->first->next;
				
			} else if ( node == list->last) {

				previous->next = NULL;
				list->last = previous;

			} else {

				previous->next = node->next;

			}

			free(node);
			list->num_elems -= 1;

			return 1;

		}

		previous = node;
		node = node->next;

	}

	return 0;

}

void free_list(LinkedList *list) {

	Node *node = list->first;

	while(node) {
		Node *aux = node;
		node = node->next;
		free(aux);
	}

	list->first = list->last = NULL;
	list->num_elems = 0;

}

void insertAtFront(LinkedList *list, int value) {

	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->next = list->first;
	list->first = node;

	if (list->num_elems == 0) 
		list->last = node;

	list->num_elems += 1;

}

//if the position is not compatible with the list we return -1
//if the value is correctly inserted we return 1
int insertAtPosition(LinkedList *list, int value, int position) {

	//the list size is erroneous
	if (list->num_elems < 0) return -1;
	//the position is erroneous
	if (!(position >= 0 && position < list->num_elems)) return -1; 

	if (position == 0) insertAtFront(list, value);
	else if (position == (list->num_elems - 1)) addNode(list, value);
	else {
		Node *node = list->first;
		Node *previous = NULL;
		int counter = 0;

		while(node && counter < position) {

			previous = node;
			node = node->next;
			counter += 1;

		}

		Node *new_node = malloc(sizeof(Node));
		new_node->value = value;
		new_node->next = node;

		previous->next = new_node;
	}

	return 1;

}

int removeNodePointers(LinkedList *list, int value) {

	Node **pp = &list->first;

	printf("pp %p\n", pp);
	printf("*pp %p\n", *pp);

	while(*pp) {

		if ((*pp)->value == value) {

			Node *node = *pp;

			*pp = node->next;

			free(node);

			return 1;

		}

		pp = &(*pp)->next;

	}

	return 0;

}

//reverse list normal sin punteros a punteros
void reverseList(LinkedList *list) {

	//A -> B -> C -> D   D -> C -> B -> A
	Node *current = list->first;
	Node *prev = NULL;

	while ( current ) {

		Node *aux = current->next;
		current->next = prev;
		prev = current;
		current = aux;

	}

	list->first = prev;

}

//reverse list con punteros a punteros 
void reverseListPointers(LinkedList *list) {

	Node **current = &(list->first);
	Node *prev = NULL;

	while ( *current ) {

		Node *aux = (*current)->next;
		(*current)->next = prev; 
		prev = *current;
		*current = aux;

	}

	list->first = prev;

}

//añadir la segunda lista al final
void appendList(LinkedList *list, LinkedList *other) {

	list->num_elems += other->num_elems;
	list->last->next = other->first;

}

//eliminar deplicados con punteros a punteros, we wait to have a hash table
void removeDuplicates(LinkedList *list) {



}

Node* getNodeAt(LinkedList *list, int position) {

	if (!check_list_position(list, position)) return NULL;

	Node *node = list->first;
	int counter = 0;

	while( node ) {

		if ( counter == position ) return node;
	
		node = node->next;
		counter += 1;

	}

	return NULL;

}

// Devuelve el número de elementos de la lista
int getListSize(LinkedList *list) {

	Node *node = list->first;
	int counter = 0;

	while ( node ) {
		counter += 1;	
		node = node->next;
	} 

	return counter;

}

int tests2() {

	LinkedList *list = create_list();

	for (int i = 0; i < 10; i++) addNode(list, i);

	int size = getListSize(list);

	print_list(list);

	int position = 2;
	Node *node = getNodeAt(list, position);

	printf("Node value at position %d of list with size %d: %d\n", 
		position, 
		size,
	 	node->value
	 );

	LinkedList *other = create_list();

	for (int i = 0; i < 10; i++) addNode(other, i*2);

	appendList(list, other);

	print_list(list);

	// Node *previous = getPreviousNode(list, 8);

	// printf("%d\n", previous->value);

	return 0;

}

void tests1() {

	LinkedList *list = create_list(); 

	print_list(list);

	for (int i = 0; i < 3; i++)
		addNode(list, i+1);

	print_list(list);

	for (int i = 0; i < 3; i++) {
		addNode(list, 1);
	}

	print_list(list);

	insertAtPosition(list, 19, 0);

	print_list(list);

	reverseListPointers(list);

	print_list(list);

	printf("numero de elementos = %d\n", list->num_elems);

	removeAllNodes(list, 1);

	print_list(list);

	Node *node = searchNode(list, 2);

	if (node && node->next) printf("%d\n", node->next->value);

	insertAtFront(list, 9);

	print_list(list);

	printf("numero de elementos = %d\n", list->num_elems);

	free_list(list);

	addNode(list, 1);
	removeNode(list, 1);

	print_list(list);

	printf("Puntero list->first: %p\n", (void *)(list->first));
	printf("Puntero list->last: %p\n", (void *)(list->last));

	free_list(list);
}

int main(int argc, char* argv[]) {

	tests2();

	return 0;

}