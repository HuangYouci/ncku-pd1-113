#include <stdio.h>
#include <string.h>

// 除錯：testmode 1 官方指定 / 2 個人測試

char output[21];

char* ProcessingCommand(char string1[51][21], char string2[51][21], char *testcase, int command_cnt, int testmode){
    strcpy(output,testcase);
    int len = strlen(output);
    // [len] 測試資料的長度
    if(testmode == 2) printf("[1] 測資長度（len）：%d\n",len);
    if(testmode == 2) printf("[1] 初始測資資料：%s\n",output);
    
    int completed = 1;
    
    while(completed){

        completed = 0;

        for(int i = 0 ; i < command_cnt ; i++){
            // [i] 目前正在檢查第 i 個指令（總共 command_cnt 個）
            //
            // 要針對 output 這個字串做檢查，他有 len 長度。
            // 執行每一個指令（指令是把 string1[command_cnt] 替換成 string2[command_cnt]

            //
            if(testmode == 2) printf("[ 2] 目前的測資資料：%s\n",output);
            if(testmode == 2) printf("[ 2] 目前正在檢查第 %d / %d 個指令（i / command_cnt）\n",i+1,command_cnt);
            if(testmode == 2) printf("[ 2] 尋找：%s（string1[%d]）\n",string1[i],i);
            if(testmode == 2) printf("[ 2] 取代：%s（string2[%d]）\n",string2[i],i);

            int checkLen = (strlen(string1[i]));
            if(testmode == 2) printf("[  3] string1[%d] 的長度為 %d（checkLen）\n",i,checkLen);
            // [checkLen]: 要查詢替換的詞語長度（不包含 \0）
            // 例如 happy = 5字符(6-1)

            char compareArray[checkLen];
            // [compareArray]: 建立一個 checkLen 長度的比較序列

            for(int j = 0 ; j < checkLen ; j++){
                compareArray[j] = string1[i][j];
            }
            // 將 compareArray 複製 string1
            // 例如 happy = [h][a][p][p][y]
            if(testmode == 2) printf("[  3] compareArray 現在是 %s（應與 string1[%d] 同為 %s）\n",compareArray,i,string1[i]);

            int checkProgress = 0;
            // [checkProgress] 代表現在檢查到第幾個字了

            for(int j = 0 ; j < len ; j++){
                // 開始自 output 檢查有無符合 compareArray 的詞組
                // 從 output 的長度（不包含 \0）開始逐步檢查
                // 自 [j] 到 len-1 的長度
                if(testmode == 2) printf("[  3] 開始自 output[%d] （j）檢查有無符合 compareArray 的詞組\n",j);
                if(testmode == 2) printf("[   4] 目前詞組完成度 %d/%d（checkProgress/checkLen）\n",checkProgress,checkLen);
                if(testmode == 2) printf("[   4] 資料：%c\n",output[j]);
                if(testmode == 2) printf("[   4] 對比：%c\n",compareArray[checkProgress]);

                if(output[j] == compareArray[checkProgress]){
                    if(testmode == 2) printf("[    5] %c 符合 %c！（output[%d]/compareArray[%d]）\n",output[j],compareArray[checkProgress],j,checkProgress);
                    // 如果現在這格 [j] 符合要查的比較序列第 [checkProgress] 格
                    checkProgress++;
                    // 則條件符合，可以繼續查
                }else{
                    checkProgress = 0;
                    if(testmode == 2) printf("[    5] %c 不符合 %c！（output[%d]/compareArray[%d]）\n",output[j],compareArray[checkProgress],j,checkProgress);
                    // 如果現在這格 [j] 不符合要查的比較序列：本串都不算，從 0 開始記
                    if(output[j] == compareArray[0]){
                        checkProgress = 1;
                        if(testmode == 2) printf("[     6] 但是 %c 和 compareArray[0] 一樣都是 %c\n",output[j],compareArray[0]);
                    }
                    // 如果剛好這一格 output[j] 是比較序列的新開頭 compareArray[0] 則讓進度往前
                }
                if(testmode == 2) printf("[   4] 比較完後的詞組完成度：%d/%d（checkProgress/checkLen)\n",checkProgress,checkLen);

                if(checkProgress == checkLen){
                    // 如果都相符，例如 [h][a][p][p][y]，現在的 progress (6)大於總長度(5)，代表完全符合
                    // 若每一個都相符，表示這一串剛好等於 string1，可以準備替換
                    // 把那一串刪掉，然後保留地一行做 '_' 代表可以替換成string2

                    completed = 1;

                    if(testmode == 2) printf("[    5] 詞組完成度已滿 %d/%d（checkProgress/checkLen），可進行替換\n",checkProgress,checkLen);
                    output[j-(checkProgress-1)] = '_';
                    if(testmode == 2) printf("[    5] 完成在 %d 格，詞組第一格在 %d 格\n",j,j-(checkProgress-1));
                    if(testmode == 2) printf("[    5] 目前的測資資料：%s\n",output);

                    for(int k = 0; k < (checkProgress-1) ; k++){
                        if(testmode == 2) printf("[     6] 目前是第 %d 格，操作第 %d 格為「-」\n",j,(j-k));
                        // checkProgress 代表比較的總長度（多一個），所以把他扣回來
                        // 例如 happy，就會是 6。扣一個代表他連續五個都一樣
                        // 將這五個弄成「-」
                        output[j-k] = '-';
                    }
                    if(testmode == 2) printf("[    5] 目前測資資料：%s\n",output);

                    // 作業要求（印出來），目前是像是 _--ccccc
                    // 把_變成string2，把-刪掉
                    if(testmode == 1){
                        for(int tm = 0; tm < 51; tm++){
                            if(output[tm] == '_'){
                                printf("%s",string2[i]);
                            } else if(output[tm] == '-') {
                                ;
                            } else {
                                printf("%c",output[tm]);
                            }
                            if(output[tm] == '\0') break;
                        }
                        printf("\n");
                    }
                }
            }

            if(testmode == 2) printf("[ 2] 本輪指令初步比對完成（尋找與取代）。\n");
            if(testmode == 2) printf("[ 2] 目前測資資料：%s\n",output);
            if(testmode == 2) printf("[ 2] 現在要把「-」刪掉\n");

            // 比較結束，現在應該把這個指令若有變化的弄成 _---- 的樣式。
            // 找到 「-」後，左移其他在後面的字串
            for(int j = 0; j < len ; j++){
                while(output[j] == '-'){
                    for(int k = j ; k < len ; k++){
                        output[k] = output[k+1];
                    }
                }
            }
            if(testmode == 2) printf("[  3] 目前測資資料：%s\n",output);

            if(testmode == 2) printf("[ 2] 現在要把「_」替換成 %s（string2）\n",string2[i]);
            // 再來是把 _ 插入 string2。
            // 例如 aaaa_bb_bb
            int addLen = strlen(string2[i])-1;
            // [addLen]: 代表 string2 的長度（不包含 '\0'）且扣掉（_），所以會減一
            if(testmode == 2) printf("[  3] string2[%d] %s 的長度是 %d（已扣掉1）\n", i, string2[i], addLen);
            
            // 遇到 _ 時要把後面的加上 addLen 位
            for(int j = 0; j < len; j++){
                if(testmode == 2) printf("[   4] 現在進入找「_」，目前在第 %d/%d 位（目標：%c）\n", j+1, len, output[j]);
                if(output[j] == '_'){
                    // 找到「_」
                    if(testmode == 2) printf("[    5] 找到「_」了！在第 %d 位，我要把這後面的都加上 %d 格（addLen）\n",j,addLen);
                    if(testmode == 2) printf("[    5] 現在從最後一位，第 %d（len）位開始，到 %d（j+1）的都加上 %d（addLen）格\n",len,j+1,addLen);

                    // 如果 addLen 正常(>0)
                    for(int k = len; k > j && addLen != -1 ; k--){
                        // 從 len（最後一格）開始
                        // 搬到 j+1 格
                        if(testmode == 2) printf("[     6] 現在把 %d 格（%c）增加 %d 格搬到 %d 格\n",k,output[k],addLen,k+addLen);
                        output[k+addLen] = output[k];
                    }

                    if(testmode == 2) printf("[   4] 搬家後的測資是 %s\n",output);
                    if(testmode == 2) printf("[   4] 接著要把「_」替換成 string2（%s）\n",string2[i]);

                    for(int k = 0; k < (addLen+1) ; k++){
                        // addLen != -1
                        if(testmode == 2) printf("[    5] 目前把 output[%d] 改成 string2[%d][%d]：%c\n",k+j,i,k,string2[i][k]);
                        output[k+j] = string2[i][k];
                        // 把它搬進去
                    }
                }
            }

            if(testmode == 2) printf("[ 2] 本指令執行完畢：目前測資資料：%s\n",output);
            // 就變成 aaaahappybbhappybb 了

            // 當 addLen = -1 的特別判定
            for(int j = 0 ; j < len && addLen == -1 ; j++){
                for(int k = 0 ; k < len ; k++){
                    if(output[k] == '_'){
                        char temppp = output[k];
                        output[k] = output[k+1];
                        output[k+1] = temppp;
                    }
                }
            }
        }

    }
    return output;
}