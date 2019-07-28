#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
	char data[20];
	struct _Node* link;
} Node;

Node *newNode(char data[]) {
	Node *p = (Node*)malloc(sizeof(Node));
	strcpy(p->data, data);
	p->link = NULL;
	return p;
}

Node *addFirstNode(Node *list, Node *p) {
	p->link = list;
	return p;
}

void main() {
	Node *list = NULL;

	list = addFirstNode(list, newNode("Wed"));
	list = addFirstNode(list, newNode("Tue"));
	list = addFirstNode(list, newNode("Mon"));
}
