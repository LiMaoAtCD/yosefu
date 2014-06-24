//
//  main.c
//  yosefu
//
//  Created by AlienLi on 14-6-24.
//  Copyright (c) 2014年 AlienLi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

typedef int ElementType;

typedef struct node{
    ElementType item;
    struct node *next;
}Node;

typedef struct node *List;


List Create(List head,int num,int index)
{
    head = (List)malloc(sizeof(Node));
    head->item = 0;
    head->next =NULL;
    List p =NULL;
    for (int i = 0; i<num -1; i++) {
        p = (List)malloc(sizeof(Node));
        p->item = i+1;
        p->next = head->next;
        head->next = p;
        if (i == 0) {
            p->next = head;
        }
    }
    for (int j=1; j<index; j++) {
        head = head ->next;
    }

    return head;
    
}

List deleteElement(List head,int index)
{
    if (head ==NULL) {
        return head;
    }else{
        List temp = head;
        List preTemp = NULL;
        for (int i = 0; i<index; i++) {
            preTemp =temp;
            temp = temp ->next;
            
        }
        preTemp->next =temp->next ;
        free(temp);
        printf("free success\n");
        temp = preTemp;
        return temp;
    }
}

void VisitList(List p)
{
    
    if (p != NULL) {
        printf("m->value:%d\n",p->item);
        
        List temp =p;
        while (p->next != temp) {
            p = p->next;
            printf("m->value:%d\n",p->item);
        }
        
        
    }else{
        printf("p is NULL");
    }
}

void YoSeFu(int n,int m,int k)
{
    List head;
    
    head = Create(head, n, m);
    
//    for (int i = m; i >0; i--) {
//        deleteElement(head, k);
//        VisitList(head);
//        printf("free %d times\n",m-i);
//    }
    
    while (head->next != head) {
        
        head = deleteElement(head, k);
        VisitList(head);
    }
    
    
}






int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    n个人，围成一圈，从m个人开始，数到k。
    int n =10;
    int m = 2;
    int k =3 ;
    YoSeFu(n,m,k);
    
    return 0;
}
