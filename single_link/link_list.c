#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINK_ERROR -1
#define LINK_OK 1

struct LNode{
	int data;
	struct LNode *next;
};
struct LinkList{
	struct LNode *head;	
	int length;
};

int Init_Link(struct LinkList *l){
	l->length = 0;
	l->head = malloc(sizeof(struct LNode));
	if(l->head == NULL)
		return LINK_ERROR;
	l->head->next = NULL;
	return LINK_OK;
}
int Locate_Link(struct LinkList *l, int index, int *e){
	if(index < 0 || index >= l->length)
		return LINK_ERROR;
	int i = 0;
	struct LNode *p = l->head;
	for(; i <= index; i++)
		p = p->next;
	*e = p->data;
	return LINK_OK;
}
int Delete_Link(struct LinkList *l, int index){
	if(index < 0 || index > l->length)
		return LINK_ERROR;
	int i = 0, len = index - 1;
	struct LNode *p = l->head;
	for(; i <= len; i++)
		p = p->next;
	struct LNode *ln = p->next->next;
	free(p->next);
	p->next = ln;
	l->length--;
}
void Free_Link(struct LinkList *l){
	struct LNode *p = l->head;
	while(p->next != NULL){
		free(p->next);
		p = p->next;
	}
}
int Insert_Link(struct LinkList *l, int index, int value){
	if(index < 0 || index > l->length)
		return LINK_ERROR;
	int i = 0, len = index - 1;
	struct LNode *p = l->head;
	for(; i <= len; i++)
		p = p->next;
	struct LNode *ln = p->next;
	p->next = (struct LNode *)malloc(sizeof(struct LNode));
	p->next->data = value;
	p->next->next = ln;
	l->length++;
	return 0;
}
void Display_Link(struct LinkList *l){
	if(l->length == 0){
		printf("this linkList is empty\n");
		return;
	}
	int i = 0, len = l->length;
	struct LNode *p = l->head->next;
	while(i < len){
		printf("link[%d] = %d\n", i, p->data);
		p = p->next;
		i++;
	}
}


int main(void){
	struct LinkList l;
	if(Init_Link(&l) < 0)
		printf("InitError\n");
	int i = 0;
	for(; i < 10; i++)
		Insert_Link(&l, 0, rand());
	printf("before inset \n");
	Display_Link(&l);
	Insert_Link(&l, 5, 20);
	printf("after inset \n");
	Display_Link(&l);
	int ele;
	Locate_Link(&l, 6, &ele);
	printf("link[5] = %d\n", ele); 
	printf("before delete \n");
	Display_Link(&l);
	Delete_Link(&l, 5);
	printf("after delete \n");
	Display_Link(&l);
	Free_Link(&l);
}
