#include<stdio.h>

#define MAX_VERTEX_NUM 10

typedef struct{
    int vexs[MAX_VERTEX_NUM]; // 定义一个数组，用来存储图的顶点
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 定义一个二维数组，用来存储图的边
    int vexNum, arcNum; // 定义两个整数，用来记录图的顶点数和边数
}adjMatrix;

int locateAdjMatrix(adjMatrix *G, int v){
    int i;
    int j = -1;
    for(i = 0;i<G->vexNum;i++){
        if(G->vexs[i] == v){
            j = i;
            break;
        }
    }
    return j; // 返回顶点 v 在数组中的位置，如果不存在，返回 -1
}

void createAdjMatrix(adjMatrix *G,int a[], int b[][2], int vexNum, int arcNum){
    int i,j,k;
    int c1,c2;
    G->vexNum = vexNum;
    G->arcNum = arcNum;
    //初始化
    for(i = 0;i<G->vexNum;i++){
        for(j = 0;j<G->vexNum;j++){
            G->arcs[i][j] = 0; // 将边的权值都设为 0
        }
    }
    //读入顶点
    for(i = 0;i<G->vexNum;i++){
        G->vexs[i] = a[i]; // 将顶点的值存入数组
    }
    //读入边
    for(k = 0;k<G->arcNum;k++){
        c1 = b[k][0];
        c2 = b[k][1];
        i = locateAdjMatrix(G, c1);
        j = locateAdjMatrix(G, c2);
        if(i != -1 && j != -1){
            G->arcs[i][j] = 1; // 如果两个顶点都存在，将边的权值设为 1
            G->arcs[j][i] = 1; // 因为是无向图，所以对称位置也设为 1
        }
    }
}

// 完成找出星型图的中心节点的函数
int findCenter(adjMatrix *G, int degrees[]){
    int i, j;
    int center = -1; // 定义一个整数，用来记录中心节点的值，初始为 -1
    for (i = 0; i < G->vexNum; i++) { // 遍历所有的顶点
        degrees[i] = 0; // 将每个顶点的度数初始化为 0
        for (j = 0; j < G->vexNum; j++) { // 遍历所有的顶点
            if (G->arcs[i][j] == 1) { // 如果两个顶点之间有边
                degrees[i]++; // 增加当前顶点的度数
            }
        }
        if (degrees[i] == G->vexNum - 1) { // 如果当前顶点的度数等于顶点数减一，说明是中心节点
            center = G->vexs[i]; // 更新中心节点的值
            break; // 跳出循环
        }
    }
    return center; // 返回中心节点的值
}

int main(){
    adjMatrix graph;
    int a1[4] = {1,2,3,4};
    int b1[][2] = {{1,2},{2,3},{4,2}};
    createAdjMatrix(&graph,a1,b1,4,3); // 根据给定的顶点和边，创建一个星型图
    int d1[4] = {0}; // 定义一个数组，用来存储每个顶点的度数
    printf("输入：edges = [[1,2],[2,3],[4,2]]\n");
    printf("输出：%d\n",findCenter(&graph,d1)); // 调用函数，找出星型图的中心节点，并打印结果
    int a2[5] = {1,2,3,4,5};
    int b2[][2] = {{1,2},{5,1},{1,3},{1,4}};
    createAdjMatrix(&graph,a2,b2,5,4); // 根据给定的顶点和边，创建另一个星型图
    int d2[5] = {0}; // 定义一个数组，用来存储每个顶点的度数
    printf("输入：edges = [[1,2],[5,1],[1,3],[1,4]]\n");
    printf("输出：%d\n",findCenter(&graph,d2)); // 调用函数，找出星型图的中心节点，并打印结果
    return 1;
}
