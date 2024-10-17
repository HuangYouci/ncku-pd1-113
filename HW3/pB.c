#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	int great = 0;
	if (a != 1 && b != 1 && c != 1){
		great = -1;
		printf("1 ");}
	if (a != 2 && b != 2 && c != 2){
		great = -1;
		printf("2 ");}
	if (a != 3 && b != 3 && c != 3){
		great = -1;
		printf("3");}
	if (great == 0){
		printf("Oh, Fried Shrimp. you're amazing!\n");
	}else{
		printf("\n");
	}
	return 0;
}
