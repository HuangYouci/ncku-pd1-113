#include <stdio.h>

int main(){
	int n, r = 0;
	// 
	int b;
	scanf("%d %d",&n,&b);

	r = b;

	while (n>0){
		// printf("Step 1, n=%d, r=%d\n",n,r);
		r *= 10;
		// printf("Step 2, r=%d\n",r);
		r += n%10;
		// printf("Step 3, n%%10=%d, r=%d\n",n%10,r);
		n /= 10;
		// printf("Step 4, n=%d\n", n);
	}

	printf("%d\n",r);
	return 0;

	
}
