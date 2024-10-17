#include <stdio.h>

int main(){
	int a, b, c, winnings = 0;
	scanf("%d-%d-%d", &a, &b, &c);

	if(a < b){
	//	printf("+50");
		winnings += 50;}

	if ((a+b) <c){
	//	printf("+150");
		winnings += 150;}

	if (a == c ){
	//	printf("+100");
		winnings += 100;}

	if (a == b && b ==c){
	//	printf("+300");
		winnings += 300;}

	printf("%d\n",winnings);

	return 0;
}
