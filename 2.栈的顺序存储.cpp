

#include<stdio.h>
#include<stdlib.h>
typedef int E;

typedef struct Stack {
	E* array;
	int capacity;
	int top;
}*ArrayStack;

int initStack(ArrayStack stack) {
	stack->array = (E*)malloc(sizeof(E) * 10);
	if (stack->array == NULL)	return 0;
	stack->capacity = 10;
	stack->top = -1;
	return 1;
}

int pushStack(ArrayStack stack, E element) {
	if (stack->top + 1 == stack->capacity) { //栈满扩容（top是从0开始计的，而capascity是从1开始）
		int newcapacity = stack->capacity + (stack->capacity >> 2);
		E* newarray = (E*)realloc(stack->array, sizeof(E) * newcapacity);
		if (newarray == NULL)	return 0;
		stack->array = newarray;
		stack->capacity = newcapacity;
		return 1;
	}
	stack->top++;
	stack->array[stack->top] = element;
	return 1;
}

int isEmpty(ArrayStack stack) { //判空
	return stack->top == -1;
}

E popStack(ArrayStack stack) {  //返回栈顶元素
	return stack->array[stack->top--];
}

void printStack(ArrayStack stack) {
	for (int i = 0; i < stack->top + 1; i++) {//top是直接指向栈顶元素，所以要注意
		printf("%d  ", stack->array[i]);
	}
	printf("\n");
}

int main() {
	struct Stack stack;
	initStack(&stack);
	for (int i = 0; i < 15; i++) {
		pushStack(&stack, i * 100);
	}
	printStack(&stack);
	while (!isEmpty(&stack)) {
		printf("%d  ", popStack(&stack));
	}
	return 0;
}



