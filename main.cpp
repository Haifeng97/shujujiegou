#include <iostream>

//单链表
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

void printList(LNode *C);

//带头结点，多输出一个 *&是c++写法，c通不过
void createList(LNode *&C, int a[], int n) {
    LNode *s, *r;
    int i;
    C = (LNode *) malloc(sizeof(LNode));
    C->next = NULL;
    C->data = n;
    r = C;
    for (i = 0; i < n; i++) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void printList(LNode *C) {
    LNode *r = C;
    int i = 1;
    while (r) {
        printf("No%d data is %d\n", i, r->data);
        r = r->next;
        i++;
    }
    printf("print ends");
}

void findAndDelete(LNode *C, int x) {
    LNode *p, *q;
    p = C;
    while (p->next) {
        if (p->next->data == x) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

void mergeSort(LNode *A, LNode *B, LNode *&C) {
    LNode *p = A, *q = B;
    C = (LNode *) malloc(sizeof(LNode));
    C->data = p->data + q->data;
    C->next = NULL;
    LNode *r = C, *m;
    while (p->next && q->next) {
        if (p->next->data > q->next->data) {
            m = (LNode *) malloc(sizeof(LNode));
            m->data = q->next->data;
            q = q->next;
            r->next = m;
            r = r->next;
        } else {
            m = (LNode *) malloc(sizeof(LNode));
            m->data = p->next->data;
            p = p->next;
            r->next = m;
            r = r->next;
        }
    }
    r->next = NULL;
    if (p->next) {
        r->next = p->next;
    } else if (q->next) {
        r->next = q->next;
    }
}

int main() {
    LNode *list = (LNode *) malloc(sizeof(LNode));
    list->data = 1234;
    list->next = NULL;
//    printf("%d", list->data);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 15, 1, 5, 15, 15, 15, 15, 185, 1, 854, 185};
//    createList(list, a, 21);
//    findAndDelete(list, 15);
    int b[] = {1, 3, 5, 7, 9};
    int c[] = {2, 4, 6, 8, 10, 12, 14};
    LNode *sortA = (LNode *) malloc(sizeof(LNode));
    LNode *sortB = (LNode *) malloc(sizeof(LNode));
    sortA->next = NULL;
    sortB->next = NULL;
    createList(sortA, b, 5);
    createList(sortB, c, 7);
    mergeSort(sortA, sortB, list);
    printList(list);
    return 0;
}
