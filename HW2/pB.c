#include <stdio.h>

int main(int argc, char *argv[]){
	int a, b, c, d;
	FILE *ifp, *ofp;
	ifp = fopen(argv[1],"r");
	ofp = fopen("answer.txt", "w");
	fscanf(ifp, "%d", &a);
	fscanf(ifp, "%d", &b);
	fscanf(ifp, "%d", &c);
	fscanf(ifp, "%d", &d);
	fclose(ifp);
	// 上面是讀取檔案 (testing_input.txt) 的四個數值
	// 接著將答案輸入進去檔案 (answer.txt)
	// 不用最簡化：直接輸出
	fprintf(ofp, "%d/%d\n",(a*d+c*b),(b*d));
	fclose(ofp);
	return 0;
}
