#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	char arr[][5] = {"q", "w", "e", "r", "a", "s", "d", "f"};
	int i, j;
	char *t;
	int len = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i < len; i++)
		printf("%s\t", arr[i]);
	printf("\n");
	for(i = 0; i < (len - 1); i++){
		for(j = 0; j < (len - i - 1); j++){
			if(strcmp(arr[j], arr[j+1]) > 0){
				t = malloc(sizeof(arr[j]));
				strcpy(t, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], t);
				free(t);
			}	
		}
	}
	for(i = 0; i < len; i++)
		printf("%s\t", arr[i]);
	printf("\n");
	return 0;
}
