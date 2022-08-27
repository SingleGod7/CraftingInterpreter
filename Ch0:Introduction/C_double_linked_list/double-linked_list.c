#include "double-linked_list.h"

//Init a double-linked list
list* InitDulList() {
	list* x = (list*) malloc(sizeof(list));
	x->len = 0;
	x->headPoint = (listNode*) malloc(sizeof(listNode));
	x->headPoint->pre = NULL;
	x->headPoint->next = NULL;
	x->headPoint->content = "-,- :Head Pointer\n        |   \n        V   \n";
	return x;
}

void DisplayList(list* x) {
	listNode* cur = x->headPoint;
	printf("%s", x->headPoint->content);
	for (int i = 0; i < x->len - 1; i++) {
		cur = cur->next;
		printf("%.4d:%s\n        |   \n        V   \n", i, cur->content);
	}
	
	if (x->len > 0) {
		cur = cur->next;
		printf("%.4d:%s\n",x->len, cur->content);
	}
}

//test for string equals
bool equals(char* x, char* y) {
	int lenx = 0;
	int leny = 0;

	for (int i = 0; x[i] != '\0'; i++) {
		lenx++;
	}

	for (int i = 0; x[i] != '\0'; i++) {
		leny++;
	}

	if (lenx != leny) {
		return false;
	}

	for (int i = 0; x[i] != '\0'; i++) {
		if (x[i] != y[i]) return false;
	}
	return true;
}

//insert an element at index i
void Insert(int i, list* x, char* string) {
	if (i < 0 || i > x->len) {
		printf("invaild index");
		return;
	}
	
	listNode* currentNode = x->headPoint;
	listNode* insertNode = (listNode*) malloc(sizeof(listNode));
	insertNode->content = string;
	insertNode->pre = NULL;
	insertNode->next = NULL;

	while(i > 0) {
		currentNode = currentNode->next;
		i--;
	}

	if (i == x->len) {
		currentNode->next = insertNode;
		insertNode->pre = currentNode;
	} else {
		insertNode->next = currentNode->next;
		currentNode->next = insertNode;
		currentNode->next->pre = currentNode;
		insertNode->pre = currentNode;
	}
	x->len++;	
}

int Find(list *x, char* string) {
	listNode* currentNode = x->headPoint;
	int count = 0;
	while(currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (equals(string, currentNode->content)) {
			return count;
		} else {
			count++;
		}
	}
	return -1;
}

char* Delete(int i, list* x) {
	if (i > x->len - 1 || i < 0) return NULL;
	listNode* currentNode = x->headPoint;
	currentNode = currentNode->next;

	int j = i;
	while( j > 0 ) {
		currentNode = currentNode->next;
		j--;
	}

	if (i == x->len - 1) {
		char* a = currentNode->content;
		currentNode->pre->next = NULL;
		x->len--;
		return a;
	} else {
		currentNode->pre->next = currentNode->next;
		currentNode->next->pre = currentNode->pre;
		x->len--;
		return currentNode->content;
	}
}
		

