#include <sys/timeb.h>
#include <stdio.h>


int main(void){
	struct timeb tb, te;
	int i, j, n;
	long t;//毫秒数
	double sum, sumTemp, x;		//x是总数， n是除数
	printf("请输入x和n:");
	scanf("%lf%d", &x, &n);
	ftime(&tb);
	for(i = 1; i <= n; i++){
		sumTemp = 1;
		for(j = 1; j <= i; j++)
			sumTemp = (-sumTemp/x);
		sum += sumTemp;
	}
	ftime(&te);
	t = (te.time - tb.time) * 1000 + (te.millitm - tb.millitm);
	printf("sum = %lf, 所用时间%ld毫秒\n", sum, t);
	return 0;
}
