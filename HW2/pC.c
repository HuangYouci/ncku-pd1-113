#include <stdio.h>
#include <string.h>

int main(){
	char input1[100],input2[100];
	while (1) {
		printf("Enter the name of file to read from:\n");
		fgets(input1, sizeof(input1), stdin);
		input1[strcspn(input1, "\n")] = 0;

		if (strcmp(input1, "exit") == 0) {
			break;
		}

		FILE *iE = fopen(input1, "r");

		if (iE == NULL){
			continue;
		}

		printf("Enter the name of the file to write the output to:\n");
		fgets(input2, sizeof(input2), stdin);
		input2[strcspn(input2, "\n")] = 0;

		// do something

		FILE *rtp, *otp;
		rtp = fopen(input1, "r");
		otp = fopen(input2, "w");
		int a, b, c, d;
		fscanf(rtp, "%d %d %d %d", &a, &b, &c, &d);
		fclose(rtp);
		fprintf(otp, "%d/%d\n", (a*d+b*c), (b*d));
		fclose(otp);
	}

	return 0;
}
