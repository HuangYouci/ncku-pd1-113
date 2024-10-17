#include <stdio.h>

int main(){
	int n, c, k;
	scanf("%d %d %d",&n , &c, &k);
	int order[100] = {0};

	int transform;

	// printf("Default: n %d, c %d, k %d\n",n,c,k);

	for(int current=0; current < c; current++){
		// printf("Now: current %d\n",current);
		transform = current % n;
		// printf("Current %% %d is %d\n",n, current%n);
		// printf("Transform %d\n", transform);


		if (current >= n){
			transform = n - transform - 1;
			// printf("Transform Updated: %d\n",transform);
		}	
			
		order[transform]++;
		// printf("Order[%d] plus 1, now is %d\n",transform,order[transform]);
	} 

	printf("%d\n",order[k-1]);
	return 0;
}
