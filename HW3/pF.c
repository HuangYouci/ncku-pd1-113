#include <stdio.h>

int main(){
	int m, k=0, t, c=0;
	scanf("%d", &m);
	while (k<=m){
		scanf("%d",&t);
		k += t;
		c++;
	}

	printf("Fried Pork!!!!\n%d\n",c);
	return 0;
}
