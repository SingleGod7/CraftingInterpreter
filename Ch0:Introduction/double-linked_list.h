#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct a listNode;
struct a{
	listNode* pre;
	listNode* next;
	char* content;
};

typedef struct {
	listNode* headPoint;
	int len;
}list;

list* InitDulList();
void DisplayList(list* x);
void Insert(int i, list* x, char* string);
int Find(list* x, char* string);
char* Delete(int i, list* x);
