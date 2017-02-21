#include "link.h"
#include <stdlib.h>

void initLink(TLink* head)
{
    if(head != NULL) {
        clear(head);
    }
}

void del(TLink* head, unsigned int idx)
{
    TNode* p = *head;
    TNode* p1 = NULL;
    p = * head;
    while((idx > 0) && (p != NULL)) {
        p1 = p;
        p = p->next;
        idx--;
    }
    if(p != NULL) {
        if(p1 == NULL) {
            *head = *head->next;
        } else {
            p1->next = p->next;
        }
        free(p);
    }
}

void insert(TLink* head, int x, unsigned int idx)
{

}

void append(TLink* head, int x)
{
    TNode* p = *head;
    TNode* tmp = (TNode*)malloc(sizeof(TNode));
    tmp->data = x;
    tmp->next = NULL;
    if(p == NULL) {
        *head = tem;
    } else {
        while(p->next != NULL) p = p->next;
        p->next = tmp;
    }
}

TNode* getNodeAt(TLink head, unsigned int idx)
{
    TNode* p = head;
    while((idx > 0) && (p != NULL)) {
        p = p->next;
        idx--;
    }
    return p;
}

void clear(TLink* head)
{
    if(*head == NULL) return;
    clear(*head->next);
    free(*head);
    *head = NULL;
}

