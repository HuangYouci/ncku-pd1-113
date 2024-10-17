#include <stdio.h>
#include <limits.h>

int main(){
	long long a, b;
	scanf("%lld %lld",&a,&b);

	if ( a == LLONG_MIN && b == LLONG_MIN) {
	printf("-18446744073709551616\n");
	}else if ( a > 0 && b > 0){
		// 2 p
		unsigned long long ans;
		ans = a + b;
		printf("%llu\n",ans);
	} else if ( a < 0 && b < 0){
		// 2 n
		a = -a;
		b = -b;
		unsigned long long ans;
		ans = a + b;
		printf("-%llu\n", ans);
	} else {
		// 1 p 1 n
		long long ans;
		ans = a + b;
		printf("%lld\n", ans);
	}
	return 0;
}
