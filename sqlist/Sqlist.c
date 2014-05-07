#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INIT_LENGTH 10
#define SQLIST_OK 1
#define SQLIST_ERROR -1
#define SQLISTINCREMENT 10

//int (*c)(int, int);声明一个指针
//c = &compare; 让这个指针
//容易分不清函数和函数指针的区别，两个变量

struct Sqlist {
	int *base;
	int list_length;
	int list_size;
};

int compare(int a, int b){
	return a == b;
}

void FreeSqlist(struct Sqlist *l){
	free(l->base);
}

int LocateElem(struct Sqlist *l, int e, int (*compare)(int, int)){
	int i = 1;
	int *p = l->base;
	for(; (i <= l->list_length) && (!(*compare)(*p++, e)); i++);
	if(i <= l->list_length) return i;
	return 0;
}

int InitSqlist(struct Sqlist *l){
	if((l->base = (int *)malloc(sizeof(int) * INIT_LENGTH)) == NULL){
		return -1;	
	}
	l->list_length = 0;
	l->list_size = INIT_LENGTH;
	return 1;
}

int SqlistDelete(struct Sqlist *l, int i){
	if(i < 1 || i > l->list_length) return SQLIST_ERROR;
	int index = i - 1,
		end = l->list_length - 1;
	for(; index < end; index++)
		*(l->base + index) = *(l->base + index + 1);
	l->list_length--;
	return SQLIST_OK;
}
int InsertSqlist(struct Sqlist *l, int i, int value){//在i之前插入一个元素
	if(i < 1 || i > (l->list_length + 1)) return SQLIST_ERROR;
	if(l->list_length >= l->list_size){
		int *newbase = (int *)realloc(l->base, 
				(l->list_length + SQLISTINCREMENT)
				* sizeof(int));
		if(newbase == NULL) exit(-1);
		l->base = newbase;
		l->list_size += SQLISTINCREMENT;
	}//存储区不够时，重新分配更大的空间
	int index = l->list_length;
	for(; index >= i; index--)
		*(l->base + index) = *(l->base + index - 1);
	*(l->base + i - 1) = value;
	l->list_length++;
	return SQLIST_OK;
}

void DisplaySqlist(struct Sqlist *l){
	if(l->list_length == 0){
		printf("this list is empty \n");
		return;
	}
	printf("length of this list is %d\n", l->list_length);
	printf("size of this list is %d\n", l->list_size);
	int i =0,
		len = l->list_length;
	for(; i < len; i++)
		printf("list[%d] = %d\n", i, *(l->base + i));
}

int main(void){
	struct Sqlist l;
	InitSqlist(&l);
	int i;
	for(i = 0; i < 10; i++){
		InsertSqlist(&l, 1, rand());
	}
	printf("before insert:\n");
	DisplaySqlist(&l);
	InsertSqlist(&l, 5, 20);
	printf("after insert:\n");
	DisplaySqlist(&l);
	SqlistDelete(&l, 4);
	printf("after delete:\n");
	DisplaySqlist(&l);
	int ele = 20;
	printf("locate element : %d\n", ele);
	int (*c)(int, int);
	c = &compare;
	printf("index of ele is : %d\n", LocateElem(&l, ele, c));
	FreeSqlist(&l);
	return 0;
}

