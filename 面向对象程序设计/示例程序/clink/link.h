#ifndef LINK_H
#define LINK_H

typedef struct Node {
    int data;
    struct Node * next;
} TNode;

typedef TNode * TLink;
typedef void (*TNodeProcessor)(int x);

void initLink(TLink* head);
void del(TLink* head, unsigned int idx);
void insert(TLink* head, int x, unsigned int idx);
void append(TLink* head, int x);
TNode* getNodeAt(TLink head, unsigned int idx);
void clear(TLink* head);
void Trail(TLink head, TNodeProcessor);

#endif // LINK_H
