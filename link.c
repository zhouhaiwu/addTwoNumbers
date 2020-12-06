#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//int num[] = {2, 4, 3};
//int num2[] = {5, 6, 4};

int num[] =  {9,9,9,9,9,9,9};
int num2[] = {9,9,9,9};

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int i = 0;
    
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *temp3;
    struct ListNode *c;
    struct ListNode *c1;


    struct ListNode *temp4 = l1;
    struct ListNode *temp5 = l2;
    int j = 0, k = 0;

    int num = 1;
    int num1 = 1;
    int flag = 0;

    printf("EEE\n");
    while(temp4->next != NULL) {
        ++num;
        temp4 = temp4->next;
    }

    while(temp5->next != NULL) {
        ++num1;
        temp5 = temp5->next;
    }

    printf("num:%d\n", num);
    printf("num1:%d\n", num1);

    int num2 = 0;

    if (num1 >= num) {
        num2 = num1;
    }
    else {
        num2 = num;
    }

    //struct ListNode *c=(struct ListNode*)malloc(sizeof(struct ListNode));
    //if ((temp1 == NULL) || (temp2 == NULL)) {
        //return NULL;
    //}
    int flagtemp1 = 0, flagtemp2 = 0;
    
    for(i=0; i < num2; i++) {
        if(i == 0) {
            c1=(struct ListNode*)malloc(sizeof(struct ListNode));
            printf("temp1->val:%d\n", temp1->val);
            printf("temp2->val:%d\n", temp2->val);
            c1->val = temp1->val + temp2->val;
            if (num2 == 1) {
                c1->next = NULL;
                return c1;
            }
            if (num2 > 1) {
                if (c1->val >= 10) {
                    c1->val = c1->val - 10;
                    j = i;
                    k = 1;
                }
                //c1->val = j + k;
                printf("i:%d\n", i);
                printf("c->val:%d\n", c1->val);
                temp1 = temp1->next;
                temp2 = temp2->next;
                printf("**************\n");
                temp3 = c1;
            }
        }
        else {
            c=(struct ListNode*)malloc(sizeof(struct ListNode));
            printf("i:%d\n", i);
            printf("k:%d\n", k);
            //printf("temp1->val:%d\n", temp1->val);
            //printf("temp2->val:%d\n", temp2->val);
            if ((i == (j + 1)) && (k == 1) && (flag == 0)) {
                k = 0;
                flag = 1;
                if ((temp1 == NULL) && (temp2 == NULL)) {
                    c1->next = NULL;
                    break;
                }
                if (temp1 == NULL) {
                    flagtemp1 = 1;
                    c->val = temp2->val + 1;
                    printf("temp1 == NULL : c->val\n", c->val);
                }
                if (temp2 == NULL) {
                    flagtemp2 = 1;
                    printf("temp1->val:%d\n", temp1->val);
                    printf("c->val:%d\n", c->val);
                    c->val = temp1->val + 1;
                    printf("temp2 == NULL : c->val:%d\n", c->val);
                }
                if ((temp1 != NULL) && (temp2 != NULL) ) {
                    c->val = temp1->val + temp2->val + 1;
                    printf("c->val:%d\n", c->val);
                }
                if(c->val >= 10) {
                    printf("j:%d\n", j);
                    j = i;
                    k = 1;
                    c->val = c->val - 10;
                }
            }

            if ((k == 0) && (flag == 0)) {
                flag = 1;
                printf("KKKK\n");
                if ((temp1 == NULL) && (temp2 == NULL)) {
                    printf("K1K1K1\n");
                    c1->next = NULL;
                    break;
                }
                if (temp1 == NULL) {
                    c->val = temp2->val;
                }
                if (temp2 == NULL) {
                    c->val = temp1->val;
                }
                if ((temp1 != NULL) && (temp2 != NULL)) {
                    printf("AAA\n");
                    printf("temp1->val:%d\n", temp1->val);
                    printf("temp2->val:%d\n", temp2->val);
                    //c->val = 0;
                    //printf("c->val:%d\n", c->val);
                    c->val = temp1->val + temp2->val;
                    printf("c->val:%d\n", c->val);
                }
                if(c->val >= 10) {
                    printf("CCC\n");
                    j = i;
                    k = 1;
                    c->val = c->val - 10;
                }
            }

            if ((i == (num2 - 1)) && (k == 1) && (flag == 0)) {
                flag = 1;
                k = 0;
                if ((temp1 == NULL) && (temp2 == NULL)) {
                    c1->next = NULL;
                    break;
                }
                printf("i:%d\n", i);
                printf("j:%d\n", j);

                if (temp1 == NULL)
                    c->val = temp2->val + 1;
                if (temp2 == NULL)
                    c->val = temp1->val + 1;
                if ((temp1 != NULL) && (temp2 != NULL)) {
                    c->val = temp1->val + temp2->val + 1;
                    printf("BBB\n");
                }
                if (c->val > 10) {
                    c->val = c->val - 10;
                    c->next = NULL;
                    temp3->next=c;
                    temp3=temp3->next;
                    c=(struct ListNode*)malloc(sizeof(struct ListNode));
                    c->val = 1;
                    c->next = NULL;
                    temp3->next=c;
                    temp3=temp3->next;
                    break;
                }
            }
            if ((i == (num2 - 1)) && (k == 0) && (flag == 0)) {
                flag = 1;
                if ((temp1 == NULL) && (temp2 == NULL)) {
                    c1->next = NULL;
                    break;
                }

                if (temp1 == NULL)
                    c->val = temp2->val;
                if (temp2 == NULL)
                    c->val = temp1->val;
                if ((temp1 != NULL) && (temp2 != NULL)) {
                    c->val = temp1->val + temp2->val;
                    printf("BBB\n");
                }
                if (c->val > 10) {
                    c->val = c->val - 10;
                    c->next = NULL;
                    temp3->next=c;
                    temp3=temp3->next;
                    c=(struct ListNode*)malloc(sizeof(struct ListNode));
                    c->val = 1;
                    c->next = NULL;
                    temp3->next=c;
                    temp3=temp3->next;
                    break;
                }
            }
            //c->val = j + k;
            flag = 0;
            printf("c->val:%d\n", c->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
            c->next = NULL;
            temp3->next=c;
            temp3=temp3->next;
        }
    }

    return c1;
}

int main() {

    int i = 0;
    struct ListNode *temp1;
    struct ListNode *temp2;
    struct ListNode *a;
    struct ListNode *a1;
    struct ListNode *b;
    struct ListNode *b1;

    /*a1=(struct ListNode*)malloc(sizeof(struct ListNode));
    a1->val=0;
    printf("a->val:%d\n", a1->val);
    temp1 = a1;

    b1=(struct ListNode*)malloc(sizeof(struct ListNode));
    b1->val=0;
    temp2 = b1;*/

    /*[9,9,9,9,9,9,9]
    [9,9,9,9]*/
    for (i=0; i<7; i++) {
        //创建节点并初始化
        //a=(struct ListNode*)malloc(sizeof(struct ListNode));
        //a->val=num[i];
        //printf("a->val:%d\n", a->val);
        if (i == 0) {
            a1=(struct ListNode*)malloc(sizeof(struct ListNode));
            a1->val=num[i];
            printf("a->val:%d\n", a1->val);
            temp1 = a1;
            //a1->next=NULL;
        }
        else {
            a=(struct ListNode*)malloc(sizeof(struct ListNode));
            a->val=num[i];
            printf("a->val:%d\n", a->val);
            a->next=NULL;
            //建立新节点与直接前驱节点的逻辑关系
            temp1->next=a;
            temp1=temp1->next;
        }
    }
    for (i=0; i<4; i++) {
     //创建节点并初始化
        //b=(struct ListNode*)malloc(sizeof(struct ListNode));
        //b->val=num2[i];
        //printf("b->val:%d\n", b->val);
        if (i == 0) {
            b1=(struct ListNode*)malloc(sizeof(struct ListNode));
            b1->val=num2[i];
            printf("b->val:%d\n", b1->val);
            temp2 = b1;
            //b1->next=NULL;
        }
        else {
            b=(struct ListNode*)malloc(sizeof(struct ListNode));
            b->val=num2[i];
            printf("b->val:%d\n", b->val);
            b->next=NULL;
            //建立新节点与直接前驱节点的逻辑关系
            temp2->next=b;
            temp2=temp2->next;
        }
    }

    /*struct ListNode *temp4 = a1;
    for(i=0; i<3; i++) {
        //struct ListNode *temp = p4;
        printf("i:%d\n", i);
        printf("temp4:%d\n", temp4->val);
        temp4 = temp4->next;
    }
    struct ListNode *temp5 = b1;
    for(i=0; i<3; i++) {
        //struct ListNode *temp = p4;
        printf("temp5:%d\n", temp5->val);
        temp5 = temp5->next;
    }
    printf("*****************\n");*/
    struct ListNode *p4;
    //p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    p4 = addTwoNumbers(a1, b1);
    struct ListNode *temp = p4;
    printf("===================\n");
    //printf("temp:%d\n", temp->val);

    for(i=0; i<7; i++) {
        //struct ListNode *temp = p4;
        printf("i:%d\n", i);
        printf("temp:%d\n", temp->val);
        temp = temp->next;
    }
    return 0;
}