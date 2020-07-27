#include <iostream>

#define maxItem 50

typedef struct {
    int no;
//    char info;
} VertexType;

typedef struct {
    VertexType vex[maxItem];
    int edges[maxItem][maxItem];
    int n, v;
} MGraph;

typedef struct ArcNode {
    int adjVex;
    struct ArcNode *nextArc;
} ArcNode;

typedef struct {
//    char data;
    ArcNode *firstArc;
} VNode;

typedef struct {
    VNode adjList[maxItem];
    int n, v;
} AGraph;

void generateAMGraph(MGraph *&G){
    G = (MGraph *) malloc(sizeof(MGraph));
    G->n = 6;
    G->v = 8;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            G->edges[i][j] = 0;
        }
    }
    G->edges[0][1] = 1;
    G->edges[0][4] = 1;
    G->edges[2][3] = 1;
    G->edges[2][5] = 1;
    G->edges[3][1] = 1;
    G->edges[3][2] = 1;
    G->edges[3][4] = 1;
    G->edges[4][5] = 1;
}

void generateAAGraph(AGraph *&G){
    G = (AGraph *) malloc(sizeof(AGraph));
    G->n = 6;
    G->v = 8;
    VNode *vertexes[50];
    ArcNode *arcs[50];
    for (int i = 0; i < 6; i++) {
        G->adjList[i] = *(VNode *) malloc(sizeof(VNode));
    }
    ArcNode *a = (ArcNode *) malloc(sizeof(ArcNode));
    ArcNode *b = (ArcNode *) malloc(sizeof(ArcNode));
    b->adjVex = 4;
    b->nextArc = NULL;
    a->adjVex = 1;
    a->nextArc = b;
    G->adjList[0].firstArc = a;

    G->adjList[1].firstArc = NULL;

    a = (ArcNode *) malloc(sizeof(ArcNode));
    b = (ArcNode *) malloc(sizeof(ArcNode));
    b->adjVex = 5;
    b->nextArc = NULL;
    a->adjVex = 3;
    a->nextArc = b;
    G->adjList[2].firstArc = a;

    a = (ArcNode *) malloc(sizeof(ArcNode));
    b = (ArcNode *) malloc(sizeof(ArcNode));
    ArcNode *c = (ArcNode *) malloc(sizeof(ArcNode));
    c->adjVex = 4;
    c->nextArc = NULL;
    b->adjVex = 1;
    b->nextArc = c;
    a->adjVex = 0;
    a->nextArc = b;
    G->adjList[3].firstArc = a;

    a = (ArcNode *) malloc(sizeof(ArcNode));
    a->adjVex = 5;
    a->nextArc = NULL;
    G->adjList[4].firstArc = a;

    G->adjList[5].firstArc = NULL;
}

int visit[maxItem];

void Visit(AGraph *G, int n){
    printf("%d\n", n);
}

void initVisit(){
    for (int i = 0; i < maxItem; i++) {
        visit[i] = 0;
    }
}

void dfs(AGraph *G, int n) {
    ArcNode *p;
    visit[n] = 1;
    Visit(G, n);
    p = G->adjList[n].firstArc;
    while (p) {
        if (visit[p->adjVex] == 0) {
            dfs(G, p->adjVex);
        }
        p = p->nextArc;
    }
}

void Dfs(AGraph *G) {
    for (int i = 0; i < G->n; i++) {
        if (visit[i] == 0) {
            dfs(G, i);
        }
    }
}

void bfs(AGraph *G, int n){
    ArcNode *p;
    int que[maxItem];
    for (int i = 0; i < maxItem; i++) {
        que[i] = 0;
    }
    int front = 0, rear = 0;
    visit[n] = 1;
    Visit(G, n);
    rear = (rear + 1)% maxItem;
    que[rear] = n;
    while (rear != front) {
        front = (front + 1)%maxItem;
        p = G->adjList[que[front]].firstArc;
        while (p) {
            if (visit[p->adjVex] == 0) {
                Visit(G, p->adjVex);
                visit[p->adjVex] = 1;
                rear = (rear + 1) % maxItem;
                que[rear] = p->adjVex;
            }
            p = p->nextArc;
        }
    }
}

void Bfs(AGraph *G){
    for (int i = 0; i < G->n; ++i) {
        if (visit[i] == 0) {
            bfs(G, i);
        }
    }
}

int main(){
    AGraph *G;
    generateAAGraph(G);
    initVisit();
    Dfs(G);
    initVisit();
    Bfs(G);
    return 0;
}