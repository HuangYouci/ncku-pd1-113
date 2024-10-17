#include <stdio.h>
#include <limits.h>

int main(){
	long long a, b;
	scanf("%lld %lld",&a,&b);
	
	// Judge if a is positive or negative
	
	if (a > 0)
	{
		// a is positive
		// judge if b is positive or negative
		if (b > 0)
		{
			// b is positive
			// a(p)+b(p) may overflow
			if (b > (9223372036854775807-a)){
				// b is bigger than a to overflow
				printf("Yes\n");
			}else{	
				// b is smaller than a to overflow
				printf("No\n");
			}
		}else
		{
			// b is negative
			printf("No\n");
			// a(p)+b(n) will never overflow
		}
	}
	else
	{
		// a is negative
		if (b > 0)
		{
			// b is positive
			printf("No\n");
			// a(n)+b(p) will never overflow
		}
		else
		{
			// b is negative
			if (b < (LLONG_MIN - a))
			{
				printf("Yes\n");
			}else
			{
				printf("No\n");
			}
		}
	}

	return 0;
}
