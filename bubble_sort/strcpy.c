#include <stdio.h>
#include <string.h>

int main(void){
	char des[] = "abc";	
	char src[] = "src";
	char *a = des;
	//用char a[]声明，在后面加\0,指针则没有
	char *b = src;
	strcpy(a, b);
	printf("a=%s\n", a);
	return 0;
}
