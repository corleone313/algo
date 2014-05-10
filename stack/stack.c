#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_OK 1
#define STACK_ERROR -1
#define INIT_LENGTH 10
#define STACK_INCREMENT 10
#define STACK_EMPTY 0

struct Stack{
	int *bottom;
	int *top;
	int length;
	int size;
};

int InitStack(struct Stack *s){
	if((s->bottom = (int *)malloc(sizeof(int)*INIT_LENGTH)) == NULL)
		return STACK_ERROR;
	s->top = s->bottom;
	s->length = 0;
	s->size = INIT_LENGTH;
	return STACK_OK;
}

int PushStack(struct Stack *s, int value){
	if(s->length >= s->size){
		int new_size = sizeof(int)*((s->size) + STACK_INCREMENT);
		int *new_bottom = realloc(s->bottom, new_size);
		s->bottom = new_bottom;
		if(s->bottom == NULL)
			return STACK_ERROR;
		s->top = (s->bottom + s->length);
		s->size += STACK_INCREMENT;
	}
	*(++s->top) = value;
	s->length++;		
	return STACK_OK;
}

int PopStack(struct Stack *s, int *ele){
	if(s->length < 1)
		return STACK_EMPTY;
	*ele = *(s->top--);
	s->length--;
	return STACK_OK;
}

void DisplayStack(struct Stack *s){
	int ele;
	while(PopStack(s, &ele) > 0)
		printf("stack[%d] is : %d\n", s->length, ele);
}

int main(void){
	struct Stack s;
	InitStack(&s);
	int i = 0;
	for(; i < 10; i++){
		if(PushStack(&s, i) < 0){
			printf("Push Error \n");
			return -1;
		}
	}
	DisplayStack(&s);
	free(s.bottom);
}
