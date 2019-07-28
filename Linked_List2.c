//201300960 김한용
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

void printList(Node *list) {

	Node *p;
	
	p = list;
	if (p->data == NULL) {
		printf("NULL LIST");
	}
	while (p) {         
			printf("[%s]", p->data);     
			p = p->link;
			if (p != NULL) {
				printf("->");
			}
			else {
				break;
			}
	}
	printf("\n");
}

Node *addLastNode(Node *list, Node *p) {

	Node * cur=list;
	Node * temp=list;

	if (list == NULL) {
		list = p;
		return list;
	}
	else
		while (temp -> link != NULL) {
			temp = temp ->link;
		}
	temp->link = p;
	return cur;
	
}

void freeList(Node *list) {
	Node *p;
	while (list != NULL) {
		p = list;
		list = list->link;
		free(p);
	}
}

void main() {
	Node *list = NULL;
	
	printList(list);
	list = addFirstNode(list, newNode("Wed"));
	printList(list);
	list = addFirstNode(list, newNode("Tue"));
	printList(list);
	list = addFirstNode(list, newNode("Mon"));
	printList(list);
	
	list = addLastNode(list, newNode("Thu"));
	printList(list);
	list = addLastNode(list, newNode("Fri"));
	printList(list);

	freeList(list);
	
}
