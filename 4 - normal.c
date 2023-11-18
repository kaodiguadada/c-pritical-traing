#include<stdio.h>

#define MAX_VERTEX_NUM 10

typedef struct{
    int vexs[MAX_VERTEX_NUM]; // ����һ�����飬�����洢ͼ�Ķ���
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // ����һ����ά���飬�����洢ͼ�ı�
    int vexNum, arcNum; // ��������������������¼ͼ�Ķ������ͱ���
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
    return j; // ���ض��� v �������е�λ�ã���������ڣ����� -1
}

void createAdjMatrix(adjMatrix *G,int a[], int b[][2], int vexNum, int arcNum){
    int i,j,k;
    int c1,c2;
    G->vexNum = vexNum;
    G->arcNum = arcNum;
    //��ʼ��
    for(i = 0;i<G->vexNum;i++){
        for(j = 0;j<G->vexNum;j++){
            G->arcs[i][j] = 0; // ���ߵ�Ȩֵ����Ϊ 0
        }
    }
    //���붥��
    for(i = 0;i<G->vexNum;i++){
        G->vexs[i] = a[i]; // �������ֵ��������
    }
    //�����
    for(k = 0;k<G->arcNum;k++){
        c1 = b[k][0];
        c2 = b[k][1];
        i = locateAdjMatrix(G, c1);
        j = locateAdjMatrix(G, c2);
        if(i != -1 && j != -1){
            G->arcs[i][j] = 1; // ����������㶼���ڣ����ߵ�Ȩֵ��Ϊ 1
            G->arcs[j][i] = 1; // ��Ϊ������ͼ�����ԶԳ�λ��Ҳ��Ϊ 1
        }
    }
}

// ����ҳ�����ͼ�����Ľڵ�ĺ���
int findCenter(adjMatrix *G, int degrees[]){
    int i, j;
    int center = -1; // ����һ��������������¼���Ľڵ��ֵ����ʼΪ -1
    for (i = 0; i < G->vexNum; i++) { // �������еĶ���
        degrees[i] = 0; // ��ÿ������Ķ�����ʼ��Ϊ 0
        for (j = 0; j < G->vexNum; j++) { // �������еĶ���
            if (G->arcs[i][j] == 1) { // �����������֮���б�
                degrees[i]++; // ���ӵ�ǰ����Ķ���
            }
        }
        if (degrees[i] == G->vexNum - 1) { // �����ǰ����Ķ������ڶ�������һ��˵�������Ľڵ�
            center = G->vexs[i]; // �������Ľڵ��ֵ
            break; // ����ѭ��
        }
    }
    return center; // �������Ľڵ��ֵ
}

int main(){
    adjMatrix graph;
    int a1[4] = {1,2,3,4};
    int b1[][2] = {{1,2},{2,3},{4,2}};
    createAdjMatrix(&graph,a1,b1,4,3); // ���ݸ����Ķ���ͱߣ�����һ������ͼ
    int d1[4] = {0}; // ����һ�����飬�����洢ÿ������Ķ���
    printf("���룺edges = [[1,2],[2,3],[4,2]]\n");
    printf("�����%d\n",findCenter(&graph,d1)); // ���ú������ҳ�����ͼ�����Ľڵ㣬����ӡ���
    int a2[5] = {1,2,3,4,5};
    int b2[][2] = {{1,2},{5,1},{1,3},{1,4}};
    createAdjMatrix(&graph,a2,b2,5,4); // ���ݸ����Ķ���ͱߣ�������һ������ͼ
    int d2[5] = {0}; // ����һ�����飬�����洢ÿ������Ķ���
    printf("���룺edges = [[1,2],[5,1],[1,3],[1,4]]\n");
    printf("�����%d\n",findCenter(&graph,d2)); // ���ú������ҳ�����ͼ�����Ľڵ㣬����ӡ���
    return 1;
}
