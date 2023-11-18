#include<stdio.h> // 引入标准输入输出头文件，用于打印和读取数据
#include<stdlib.h> // 引入标准库头文件，用于动态内存分配和释放

typedef struct BTNode{ // 定义一个结构体类型，表示二叉树的结点
    int val; // 结点的值
    struct BTNode *left; // 结点的左孩子指针
    struct BTNode *right; // 结点的右孩子指针
}BiNode, *BiTree; // 给结构体类型起一个别名BiNode，以及一个指针类型别名BiTree


BiNode* createBiTree(int a[], int i, int n){ // 定义一个函数，用于根据数组a创建一棵二叉树，i表示当前结点在数组中的下标，n表示数组的长度
    if (a[i] == -1 || (i > n)) // 如果当前结点的值是-1，或者下标超出了数组的范围，表示该结点为空，返回NULL
        return NULL;
    BiNode* T = (BiNode*)malloc(sizeof(BiNode)); // 否则，为该结点分配内存空间，并将其地址赋给T
    T->val = a[i]; // 将数组中的值赋给结点的val域
    T->left = createBiTree(a, 2 * i, n); // 递归地创建左子树，左孩子在数组中的下标是当前下标的两倍
    T->right = createBiTree(a, 2 * i+1, n); // 递归地创建右子树，右孩子在数组中的下标是当前下标的两倍加一
    return T; // 返回创建好的结点
}

// 完成路径之和函数
int hasPathSum(BiNode *root, int sum) { // 定义一个函数，用于判断一棵二叉树是否存在一条从根结点到叶子结点的路径，使得路径上的结点值之和等于给定的sum
    if(root == NULL) // 如果根结点为空，返回0，表示不存在这样的路径
        return 0;
    if (root->left == NULL && root->right == NULL) { // 如果根结点是叶子结点，即没有左右孩子
        return sum == root->val; // 判断sum是否等于根结点的值，如果相等，返回1，表示存在这样的路径，否则返回0
    }
    return hasPathSum(root->left, sum - root->val) || // 如果根结点不是叶子结点，递归地判断左子树是否存在一条路径，使得路径上的结点值之和等于sum减去根结点的值，或者
           hasPathSum(root->right, sum - root->val); // 递归地判断右子树是否存在一条路径，使得路径上的结点值之和等于sum减去根结点的值，如果左右子树中有任意一棵存在这样的路径，返回1，否则返回0

}

int main(){ // 定义主函数，用于测试路径之和函数
    //判断主函数是层序给出结点，实现方法大概率通过单只深度遍历计算。
    BiNode *T1,*T2,*T3; // 定义三个二叉树的指针变量
    int a1[] = {0,5,4,8,11,-1,13,4,7,2,-1,-1,-1,1}; // 定义一个数组，用于存储第一棵二叉树的结点值，-1表示空结点
    T1 = createBiTree(a1, 1, 13); // 调用createBiTree函数，根据数组a1创建一棵二叉树，并将其根结点的地址赋给T1
    printf("输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22\n"); // 打印输入的二叉树和目标和
    if(hasPathSum(T1,22)){ // 调用hasPathSum函数，判断二叉树T1是否存在一条路径，使得路径上的结点值之和等于22
        printf("输出：true\n"); // 如果存在，打印输出true
    }else{
        printf("输出：false\n"); // 如果不存在，打印输出false
    }
    int a2[] = {0,1,2,3}; // 定义一个数组，用于存储第二棵二叉树的结点值
    T2 = createBiTree(a2, 1, 3); // 调用createBiTree函数，根据数组a2创建一棵二叉树，并将其根结点的地址赋给T2
    printf("输入：root = [1,2,3], targetSum = 5\n"); // 打印输入的二叉树和目标和
    if(hasPathSum(T2,5)){ // 调用hasPathSum函数，判断二叉树T2是否存在一条路径，使得路径上的结点值之和等于5
        printf("输出：true\n"); // 如果存在，打印输出true
    }else{
        printf("输出：false\n"); // 如果不存在，打印输出false
    }
    int a3[] = {0}; // 定义一个数组，用于存储第三棵二叉树的结点值
    T3 = createBiTree(a3, 1, 3); // 调用createBiTree函数，根据数组a3创建一棵二叉树，并将其根结点的地址赋给T3
    printf("输入：root = [], targetSum = 0\n"); // 打印输入的二叉树和目标和
    if(hasPathSum(T3,0)){ // 调用hasPathSum函数，判断二叉树T3是否存在一条路径，使得路径上的结点值之和等于0
        printf("输出：true\n"); // 如果存在，打印输出true
    }else{
        printf("输出：false\n"); // 如果不存在，打印输出false
    }
    return 0; // 主函数结束，返回0
}
