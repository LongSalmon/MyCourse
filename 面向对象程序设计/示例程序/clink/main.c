#include <stdio.h>
#include "link.h"

void printData(int x) {
    printf("%4d", x);
}

int main()
{
    int i;
    TNode*  p;
    TLink iLink=NULL;
    initLink(&iLink);
    for(i = 0; i < 20; i++) {
        append(&iLink, i);
    }
    insert(&iLink, 100, 0);
    insert(&iLink, 101, 1);
    insert(&iLink, 102, 22);
    insert(&iLink, 103, 6);
    insert(&iLink, 104, 32);

    printf("{");
    Trail(iLink, printData);
    printf("}");
    printf("\n%4d", (p = getNodeAt(iLink, 2)) == NULL ? -1 : p->data);
    printf("\n%4d", (p = getNodeAt(iLink, 0)) == NULL ? -1 : p->data);
    printf("\n%4d", (p = getNodeAt(iLink, 21)) == NULL ? -1 : p->data);
    clear(&iLink);
    return 0;
}
