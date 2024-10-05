#include <stdio.h>

int main(){
	long long input;
	scanf("%lld",&input);
	long long int a,b,c,d,e;
	char n;
	scanf("NCKU%lld%c%lld%c%lld%c%lld%c%lld",&a,&n,&b,&n,&c,&n,&d,&n,&e);
	printf("\"%lld\" \"%lld\" \"%lld\" \"%lld\" \"%lld\"\n",a,b,c,d,e);
	return 0;
}
