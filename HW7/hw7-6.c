#include <stdio.h>
#include <string.h>

char output[1000]; // 最終輸出結果

char* ProcessingCommand(char string1[51][21], char string2[51][21], char *testcase, int command_cnt, int testmode) {
    strcpy(output, testcase); // 初始化輸出為測資
    int completed = 1; // 記錄是否還需要進行替換

    while (completed) {
        completed = 0; // 假設沒有進行替換

        // 從上到下執行替換
        for (int i = 0; i < command_cnt; i++) {
            char *pos = strstr(output, string1[i]);
            // 查找第一個匹配字串的位置

            if (pos) {
                completed = 1;

                // 暫存匹配前後的字串
                char before[1000], after[1000];
                strncpy(before, output, pos - output); // 匹配前的部分
                before[pos - output] = '\0'; // 添加結束符號
                strcpy(after, pos + strlen(string1[i])); // 匹配後的部分

                // 構建新的輸出字串
                sprintf(output, "%s%s%s", before, string2[i], after);

                // 顯示當前進度
                if (testmode == 1) {
                    printf("%s\n", output);
                }

                break;
                // 完成一次替換後回到指令的開頭
            }
        }
    }

    return output; // 返回最終結果
}