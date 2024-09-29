#include <stdio.h>

int main(){
	long long input;
	scanf("%lld",&input);
	int a,b,c,d,e;
	char n;
	scanf("NCKU%d%c%d%c%d%c%d%c%d",&a,&n,&b,&n,&c,&n,&d,&n,&e);
	printf("\"%d\" \"%d\" \"%d\" \"%d\" \"%d\"\n",a,b,c,d,e);
	return 0;
}
