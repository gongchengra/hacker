#include <stdio.h>
#include <stdlib.h>
#define MVNum 100 // 最大顶点数
#define Maxint 32767
typedef char VertexType;
typedef int Adjmatrix;
typedef enum { FALSE, TRUE } boolean; // 定义布尔型
typedef struct {
    VertexType vexs[MVNum];       // 顶点数组，类型假定为char型
    Adjmatrix arcs[MVNum][MVNum]; // 邻接矩阵，假定为int型
} MGraph;
int D1[MVNum], P1[MVNum];
int D[MVNum][MVNum], P[MVNum][MVNum];
void CreateMGraph(
    MGraph G, int n,
    int e) { // 采用邻接矩阵表示法构造有向网G, n、e表示图的当前顶点数和边数
    int i, j, k, w;
    for (i = 1; i <= n; i++) // 输入顶点信息
        G.vexs[i] = (char)i;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            G.arcs[i][j] = Maxint; // 初始化邻接矩阵
    printf("输入%d条边的i、j及w：\n", e);
    for (k = 1; k <= e; k++) { // 读入e条边，建立邻接矩阵
        scanf("%d,%d,%d", &i, &j, &w);
        G.arcs[i][j] = w;
    }
    printf("有向图的存储结构建立完毕！\n");
}

void Dijkstra(
    MGraph G, int v1,
    int n) { // 用Dijkstra算法求有向图G的v1顶点到其他顶点v的最短路径P[v]及其权D[v]
    // 设G是有向网的邻接矩阵，若边<i,j>不存在，则G[i][j]=Maxint
    // S[v]为真当且仅当v∈S,即已求得从v1到v的最短路径
    int D2[MVNum], P2[MVNum];
    int v, i, w, min;
    boolean S[MVNum];
    for (v = 1; v <= n; v++) { // 初始化S和D
        S[v] = FALSE;          // 置空最短路径终点集
        D2[v] = G.arcs[v1][v]; // 置初始的最短路径值
        if (D2[v] < Maxint)
            P2[v] = v1; // v1是v的前趋(双亲)
        else
            P2[v] = 0; // v无前趋
    }                  // end_for
    D2[v1] = 0;
    S[v1] = TRUE; // S集初始时只有源点，源点到源点的距离为0
    // 开始循环，每次求得v1到某个v顶点的最短路径，并加v到S集中
    for (i = 2; i < n; i++) { // 其余n-1个顶点
        min = Maxint;
        for (w = 1; w <= n; w++)
            if (!S[w] && D2[w] < min) {
                v = w;
                min = D2[w];
            } // w顶点离v1顶点更近
        S[v] = TRUE;
        for (w = 1; w <= n; w++) // 更新当前最短路径及距离
            if (!S[w] &&
                (D2[v] + G.arcs[v][w] < D2[w])) { // 修改D2[w]和P2[w],w∈V-S
                D2[w] = D2[v] + G.arcs[v][w];
                P2[w] = v;
            } // End_if
    }         // End_for
    printf("路径长度 路径\n");
    for (i = 1; i <= n; i++) {
        printf("%5d", D2[i]);
        printf("%5d", i);
        v = P2[i];
        while (v != 0) {
            printf("<-%d", v);
            v = P2[v];
        }
        printf("\n");
    }
}

void Floyd(MGraph G, int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) // 设置路径长度D和路径path初值
        for (j = 1; j <= n; j++) {
            if (G.arcs[i][j] != Maxint)
                P[i][j] = j; // j是i的后继
            else
                P[i][j] = 0;
            D[i][j] = G.arcs[i][j];
        }
    for (k = 1; k <= n; k++) {
        // 做k次迭代,每次均试图将顶点k扩充到当前求得的从i到j的最短路径P[i][j]上
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j]; // 修改长度
                    P[i][j] = P[i][k];
                }
            }
    }
}

int main() {
    MGraph G;
    int n, e, v, w, k;
    int xz = 1;
    printf("输入图中顶点个数和边数n,e：");
    scanf("%d,%d", &n, &e);
    CreateMGraph(G, n, e); // 建立图的存储结构
    while (xz != 0) {
        printf("******求城市之间的最短路径******\n");
        printf("============================\n");
        printf("1.求一个城市到所有城市的最短路径\n");
        printf("2.求任意的两个城市之间的最短路径\n");
        printf("============================\n");
        printf(" 请选择：1 或 2，选择 0 退出 ：");
        scanf("%d", &xz);
        if (xz == 2) {
            Floyd(G, n); // 调用费洛伊德算法
            printf(" 输入源点(或称起点)和终点：v,w ：");
            scanf("%d,%d", &v, &w);
            k = P[v][w]; // k为起点v的后继顶点
            if (k == 0)
                printf("顶点 %d 到 %d 无路径！\n", v, w);
            else {
                printf("从顶点%d到%d的最短路径是：%d", v, w, v);
                while (k != w) {
                    printf("→%d", k); // 输出后继顶点
                    k = P[k][w];      // 继续找下一个后继顶点
                }
                printf("→%d", w); // 输出终点w
                printf(" 路径长度：%d\n", D[v][w]);
            }
        } else if (xz == 1) {
            printf("求单源路径，输入源点 v ：");
            scanf("%d", &v);
            Dijkstra(G, v, n); // 调用迪杰斯特拉算法
        }
    }
    printf("结束求最短路径，再见！\n");
}
