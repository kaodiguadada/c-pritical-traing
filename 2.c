#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* stk;
    int stkSize;
    int stkCapacity;
} Stack;

Stack* stackCreate(int cpacity) {
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}

void stackPop(Stack* obj) {
    obj->stkSize--;
}

int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

int stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

void stackFree(Stack* obj) {
    free(obj->stk);
    obj->stkSize = 0;
}

// 基于两个栈完成以下队列代码
typedef struct {
	Stack* inStack;
    Stack* outStack
}MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *ret=malloc(sizeof (MyQueue));// 为MyQueue结构体分配内存
    ret->inStack= stackCreate(100);
    ret->outStack= stackCreate(100);
    return ret;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x); // 将元素x压入inStack中
}

int myQueuePop(MyQueue* obj) {
	if(stackEmpty(obj->outStack)){
        while(!stackEmpty(obj->inStack)){
            stackPush(obj->outStack , stackTop(obj->inStack));
            stackPop(obj->inStack);
        }
    }
    int ret = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
	if(stackEmpty(obj->outStack)){
        while(!stackEmpty(obj->inStack)){
            stackPush(obj->outStack, stackTop(obj->inStack));
            stackPop(obj->inStack);
        }
    }
    return stackTop(obj->outStack);
}

int myQueueEmpty(MyQueue* obj) {
	return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}

void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}

int main(){
	int i;
	int x;
	MyQueue *q;
	q = myQueueCreate();
	
	printf("入队：");
	for(i = 1; i<=5; i++){
		printf("%d ", i);
		myQueuePush(q, i);
	}
	printf("\n");
	printf("当前队头为：");
	x = myQueuePeek(q);
	printf("%d\n", x);
	printf("出队：");
	x = myQueuePop(q);
	printf("%d\n", x);
	printf("当前队头为：");
	x = myQueuePeek(q);
	printf("%d\n", x);
	printf("出队：");
	while(!myQueueEmpty(q)){
		x = myQueuePop(q);
		printf("%d ", x);
	}
	printf("\n");
	printf("当前队列是否为空：%d\n",myQueueEmpty(q));
	printf("入队：");
	for(i = 1; i<=5; i++){
		printf("%d ", i);
		myQueuePush(q, i);
	}
	printf("\n");
	printf("当前队列是否为空：%d\n",myQueueEmpty(q));
	printf("队列清空！\n");
	myQueueFree(q);
	printf("当前队列是否为空：%d\n",myQueueEmpty(q));
	printf("\n");
    free(q);
	return 0;
}
