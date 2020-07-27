#include <iostream>

#define maxItem 100

typedef struct BTNode{
    int data;
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTNode;

void generateATree(BTNode *&T){
//    BTNode *A = (BTNode *) malloc(sizeof(BTNode));
    T = (BTNode *) malloc(sizeof(BTNode));
    BTNode *B = (BTNode *) malloc(sizeof(BTNode));
    BTNode *C = (BTNode *) malloc(sizeof(BTNode));
    BTNode *D = (BTNode *) malloc(sizeof(BTNode));
    BTNode *E = (BTNode *) malloc(sizeof(BTNode));
    BTNode *F = (BTNode *) malloc(sizeof(BTNode));
    BTNode *G = (BTNode *) malloc(sizeof(BTNode));
//    BTNode *nodes[] = {T, B, C, D, E, F, G};
    BTNode *nodes[] = {T, B, C, D, E};
    T->lchild = B;
    T->rchild = C;
    B->lchild = D;
    B->rchild = E;
//    C->lchild = F;
//    C->rchild = G;
    C->lchild = NULL;
    C->rchild = NULL;
    D->lchild = NULL;
    D->rchild = NULL;
    E->lchild = NULL;
    E->rchild = NULL;
//    F->lchild = NULL;
//    F->rchild = NULL;
//    G->lchild = NULL;
//    G->rchild = NULL;
    int i;
    for (i = 0; i < 7; i++) {
        nodes[i]->data = i + 1;
    }
}

void visit(BTNode *T){
    printf("%d\n", T->data);
}

void preOrder(BTNode *T){
    if (T) {
        visit(T);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

void inOrder(BTNode *T){
    if (T) {
        inOrder(T->lchild);
        visit(T);
        inOrder(T->rchild);
    }
}

void postOrder(BTNode *T) {
    if (T) {
        postOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}

void preOrderNoRecursive(BTNode *T){
    BTNode *stack[maxItem];
    BTNode *p;
    int top = -1;
    stack[++top] = T;
    while (top > -1) {
        p = stack[top--];
        visit(p);
        if (p->rchild) {
            stack[++top] = p->rchild;
        }
        if (p->lchild) {
            stack[++top] = p->lchild;
        }
    }
}

void inOrderNoRecursive(BTNode *T){
    if (T) {
        BTNode *stack[maxItem];
        BTNode *p;
        int top = -1;
        p = T;
        while (top != -1 || p) {
            while (p) {
                stack[++top] = p;
                p = p->lchild;
            }
            if (top > -1) {
                p = stack[top--];
                visit(p);
                p = p->rchild;
            }
        }
    }
}

void postOrderNoRecursive(BTNode *T) {
    BTNode *stack1[maxItem];
    BTNode *stack2[maxItem];
    BTNode *p;
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = T;
    while (top1 > -1) {
        p = stack1[top1--];
        stack2[++top2] = p;
        if (p->lchild) {
            stack1[++top1] = p->lchild;
        }
        if (p->rchild) {
            stack1[++top1] = p->rchild;
        }
    }
    while (top2 > -1) {
        visit(stack2[top2--]);
    }
}

BTNode * test(BTNode *T){
    return T;
}

int main(){
    BTNode *T;
    generateATree(T);
//    preOrder(T);
//    printf("--------------------------\n");
////    inOrder(T);
//    printf("--------------------------\n");
    postOrder(T);
    printf("--------------------------\n");
//    preOrderNoRecursive(T);
//    inOrderNoRecursive(T);
    postOrderNoRecursive(T);
    return 0;
};