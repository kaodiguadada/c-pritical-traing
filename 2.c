#include<stdio.h> // 引入标准输入输出头文件 
#include<stdlib.h> // 引入标准库头文件

typedef struct { // 定义一个结构体类型，表示栈 
int* stk; // 栈的数组 
int stkSize; // 栈的大小 
int stkCapacity; // 栈的容量 
} Stack;

Stack* stackCreate(int cpacity) { // 创建一个栈，参数为栈的容量 
Stack* ret = malloc(sizeof(Stack)); // 为栈分配内存空间 
ret->stk = malloc(sizeof(int) * cpacity); // 为栈的数组分配内存空间 
ret->stkSize = 0; // 初始化栈的大小为0 
ret->stkCapacity = cpacity; // 初始化栈的容量为参数值 
return ret; // 返回栈的指针 
}

void stackPush(Stack* obj, int x) { // 向栈中压入一个元素，参数为栈的指针和元素值 
obj->stk[obj->stkSize++] = x; // 将元素值赋给栈顶位置，并将栈的大小加一 
}

void stackPop(Stack* obj) { // 从栈中弹出一个元素，参数为栈的指针 
obj->stkSize–; // 将栈的大小减一 
}

int stackTop(Stack* obj) { // 查看栈顶的元素，参数为栈的指针 
return obj->stk[obj->stkSize - 1]; // 返回栈顶位置的元素值 
}

int stackEmpty(Stack* obj) { // 判断栈是否为空，参数为栈的指针 
return obj->stkSize == 0; // 如果栈的大小为0，返回真，否则返回假 
}

void stackFree(Stack* obj) { // 释放栈的内存空间，参数为栈的指针 
free(obj->stk); // 释放栈的数组的内存空间 
obj->stkSize = 0; // 将栈的大小置为0 
}

// 基于两个栈完成以下队列代码 
typedef struct { // 定义一个结构体类型，表示队列 
Stack* inStack; // 入队栈 
Stack* outStack; // 出队栈 
}MyQueue;

MyQueue* myQueueCreate() { // 创建一个队列 
MyQueue *ret=malloc(sizeof (MyQueue)); // 为队列分配内存空间 
ret->inStack= stackCreate(100); // 为入队栈分配内存空间，并初始化容量为100 
ret->outStack= stackCreate(100); // 为出队栈分配内存空间，并初始化容量为100 
return ret; // 返回队列的指针 
}

void myQueuePush(MyQueue* obj, int x) { // 向队列中入队一个元素，参数为队列的指针和元素值 
stackPush(obj->inStack, x); // 将元素值压入入队栈中 
}

int myQueuePop(MyQueue* obj) { // 从队列中出队一个元素，参数为队列的指针 
if(stackEmpty(obj->outStack)){ // 如果出队栈为空 
while(!stackEmpty(obj->inStack)){ // 当入队栈不为空时 
stackPush(obj->outStack , stackTop(obj->inStack)); // 将入队栈的栈顶元素压入出队栈中 
stackPop(obj->inStack); // 将入队栈的栈顶元素弹出 
} 
} 
int ret = stackTop(obj->outStack); // 获取出队栈的栈顶元素值，作为返回值 
stackPop(obj->outStack); // 将出队栈的栈顶元素弹出 
return ret; // 返回出队的元素值 
}

int myQueuePeek(MyQueue* obj) { // 查看队列的队首元素，参数为队列的指针 
if(stackEmpty(obj->outStack)){ // 如果出队栈为空 
while(!stackEmpty(obj->inStack)){ // 当入队栈不为空时 
stackPush(obj->outStack, stackTop(obj->inStack)); // 将入队栈的栈顶元素压入出队栈中 
stackPop(obj->inStack); // 将入队栈的栈顶元素弹出 
} 
}
return stackTop(obj->outStack); // 返回出队栈的栈顶元素值，即队首元素值 
}

int myQueueEmpty(MyQueue* obj) { // 判断队列是否为空，参数为队列的指针 
return stackEmpty(obj->inStack) && stackEmpty(obj->outStack); // 如果入队栈和出队栈都为空，返回真，否则返回假 
}

void myQueueFree(MyQueue* obj) { // 释放队列的内存空间，参数为队列的指针 
stackFree(obj->inStack); // 释放入队栈的内存空间 
stackFree(obj->outStack); // 释放出队栈的内存空间 
}

int main(){ // 主函数 
	int i; // 定义一个整型变量，用于循环 
	int x; // 定义一个整型变量，用于存储队列操作的结果 
	MyQueue *q; // 定义一个队列的指针 
	q = myQueueCreate(); // 创建一个队列，并将指针赋给q

printf("入队："); // 打印提示信息
for(i = 1; i<=5; i++){ // 循环5次
	printf("%d ", i); // 打印入队的元素值
	myQueuePush(q, i); // 将元素值入队
}
printf("\n"); // 换行
printf("当前队头为："); // 打印提示信息
x = myQueuePeek(q); // 获取队首元素值
printf("%d\n", x); // 打印队首元素值
printf("出队："); // 打印提示信息
x = myQueuePop(q); // 出队一个元素
printf("%d\n", x); // 打印出队的元素值
printf("当前队头为："); // 打印提示信息
x = myQueuePeek(q); // 获取队首元素值
printf("%d\n", x); // 打印队首元素值
printf("出队："); // 打印提示信息
while(!myQueueEmpty(q)){ // 当队列不为空时
	x = myQueuePop(q); // 出队一个元素
	printf("%d ", x); // 打印出队的元素值
}
printf("\n"); // 换行
printf("当前队列是否为空：%d\n",myQueueEmpty(q)); // 打印队列是否为空的结果
printf("入队："); // 打印提示信息
for(i = 1; i<=5; i++){ // 循环5次
	printf("%d ", i); // 打印入队的元素值
	myQueuePush(q, i); // 将元素值入队
}
printf("\n"); // 换行
printf("当前队列是否为空：%d\n",myQueueEmpty(q)); // 打印队列是否为空的结果
printf("队列清空！\n"); // 打印提示信息
myQueueFree(q); // 释放队列的内存空间
printf("当前队列是否为空：%d\n",myQueueEmpty(q)); // 打印队列是否为空的结果
printf("\n"); // 换行
free(q); // 释放队列的指针
return 0; // 返回0，表示程序正常结束

}
