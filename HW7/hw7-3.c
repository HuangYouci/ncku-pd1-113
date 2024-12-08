#include <stdio.h>
#include <string.h>

void ParsingData(char command[21], char string1[21], char string2[21]){
    // string [a][a][ ][=][ ][b][b][\0]
    int len = strlen(command);
    // printf("[hw7-3.c] len: %d\n",len);
    int progress = 0;
    // 0 = for string1
    // 1 = for string2
    int copyingLocation = 0;
    string2[0] = '\0';
    for(int i = 0 ; i < len ; i++){
        // printf("[hw7-3.c] loop, i: %d, progress: %d\n",i,progress);
        if(progress == 0){
            string1[copyingLocation] = command[i];
            // printf("[hw7-3.c] string1[%d] is now %c (%c)\n",copyingLocation,command[i],string1[copyingLocation]);
            if(string1[copyingLocation] == ' '){
                // printf("[hw7-3.c] string1[%d] ended at command[%d].\n",copyingLocation,i);
                string1[copyingLocation] = '\0';
                copyingLocation = -1;
                i += 3;
                progress = 1;
                // printf("[hw7-3.c] string1 is %s\n",string1);
                // printf("[hw7-3.c] Pass next to string2. Now, copyingLocation: %d, i: %d, progress: %d\n",copyingLocation,i,progress);
            }
            copyingLocation++;
        }
        if(progress == 1){
            string2[copyingLocation] = command[i];
            // printf("[hw7-3.c] string2[%d] is now %c (%c)\n",copyingLocation,command[i],string2[copyingLocation]);
            copyingLocation++;
        }
    }
    // printf("[hw7-3.c] string2 is %s\n",string2);
}