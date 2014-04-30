#include <stdio.h>

void print_arr(int arr[]){	//定义时可以int[] a / int a[] ;做参数不行
	int i, len;
	len = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i < len; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(void){
	int arr[] = {10, 40, 5, 16, 2, 20000, 1000};
	int i, j, t;
	int len = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i < 7; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	for(i = 0; i < (len - 1); i++){
		for(j = 0; j < (len - i - 1); j++){
			if(arr[j] > arr[j+1]){
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t;
			}	
		}
	}
	for(i = 0; i < 7; i++)
		printf("%d\t", arr[i]);
	printf("\n");
	return 0;
}
