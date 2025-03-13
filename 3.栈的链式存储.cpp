#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct LNode {
	E element;
	struct LNode* next;
}*Node;

void initStack(Node head) {
	head->next = NULL;
}

int isEmpty(Node head) {
	if (head->next != NULL)	return 0;
	return 1;
}

int pushStack(Node head, E element) {
	Node node = (Node)malloc(sizeof(struct LNode));
	if (node == NULL) return 0;
	node->element = element;
	node->next = head->next;
	head->next = node;
	return 1;
}

E popStack(Node head) {
	Node p = head->next;
	E e = p->element;
	head->next = p->next;
	free(p);
	return e;
}

void printStack(Node head) {
	Node p = head->next;
	while (p != NULL) {
		printf("%d ", p->element);
		p = p->next;
	}
	printf("\n");
}

int main() {
	struct LNode head;
	initStack(&head);

	for (int i = 1; i < 10; i++) {
		pushStack(&head, i * 10);
	}
	printStack(&head);

	while (!isEmpty(&head)) {
		printf("%d ", popStack(&head));
	}

	return 0;
}