#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);
    float floatValue = *(float*)&N;
    printf("%.23e\n", floatValue);
    return 0;
}
