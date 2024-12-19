#include <stdio.h>
#include <stdlib.h>

int main(){
    // 定義節點結構
    struct Node {
        int value;
        struct Node *next;
    };

    // 創建新節點
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for(int i=0;i<20;i++){
        struct Node *a = malloc(sizeof(struct Node));
        a->value = i;
        a->next = NULL;

        if(head == NULL){
            head = a;
            tail = a;
        }else{
            tail->next = a;
            tail = a;
        }
    }

    // 列印結果 a
    struct Node *current = head;
    printf("Original Linked List\n");
    while(current != NULL){
        printf("[%d] -> ",current->value);
        current = current->next;
    }
    printf("NULL\n");

    // 拆成兩個 Linked List

    // 創建新節點 (b)
    struct Node *b_head = NULL;
    struct Node *b_tail = NULL;
    current = head;

    while(current != NULL){
        if((current->value %2)==1){
            struct Node *b = malloc(sizeof(struct Node));
            b->value = current->value;
            b->next = NULL;

            if(b_head == NULL){
                b_head = b;
                b_tail = b;
            }else{
                b_tail->next = b;
                b_tail = b;
            }
        }
        current = current->next;
    }

    // 列印結果 b
    current = b_head;
    printf("Odd Linked List\n");
    while(current != NULL){
        printf("[%d] -> ",current->value);
        current = current->next;
    }
    printf("NULL\n");

    // 創建新節點 (c)
    struct Node *c_head = NULL;
    struct Node *c_tail = NULL;
    current = head;

    while(current != NULL){
        if((current->value %2)==0){
            struct Node *c = malloc(sizeof(struct Node));
            c->value = current->value;
            c->next = NULL;

            if(c_head == NULL){
                c_head = c;
                c_tail = c;
            }else{
                c_tail->next = c;
                c_tail = c;
            }
        }
        current = current->next;
    }

    // 列印結果 c
    current = c_head;
    printf("Even Linked List\n");
    while(current != NULL){
        printf("[%d] -> ",current->value);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}