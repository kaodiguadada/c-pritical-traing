#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode, *LinkList;

ListNode* createLinkList(int a[], int n){
	LinkList L;
	ListNode *r;
	ListNode *node;
	int i;
	if(n<=0){
		return NULL;
	}
	L=(LinkList)malloc(sizeof(ListNode));
	L->val = a[0];
	L->next = NULL;
	r = L;
	for(i=1;i<n;i++){
		node = (ListNode *)malloc(sizeof(ListNode));
		node->val = a[i];
		node->next = NULL;
		r->next = node;
		r = node;
	}
	return L;
}

void printLinkList(LinkList p){
	printf("[");
    while (p) {
        printf("%d",p->val);
        p=p->next;
        if(p!=NULL) printf(",");
    }
    printf("]");
    printf("\n");
}

// 完成对链表进行插入排序的函数
LinkList insertionSortList(ListNode *head) {
        // 如果链表为空或者只有一个节点，直接返回
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 创建一个新的空链表，用一个哨兵节点方便操作
        struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->val = 0; // 哨兵节点的值可以任意设置，不影响排序
        dummy->next = NULL; // 新链表的头节点初始化为NULL
        // 从原链表中依次取出每个节点
        while (head != NULL) {
            // 保存当前节点的下一个节点，防止断链
            struct ListNode* next = head->next;
            // 从新链表的头节点开始，找到插入位置的前一个节点
            struct ListNode* prev = dummy;
            while (prev->next != NULL && prev->next->val < head->val) {
                prev = prev->next;
            }
            // 将当前节点插入到新链表中
            head->next = prev->next;
            prev->next = head;
            // 继续处理下一个节点
            head = next;
        }
        // 返回新链表的头节点，跳过哨兵节点
        return dummy->next;
}


int main(){
	int a[] = {4,2,1,3};
	LinkList L1 = createLinkList(a,4);
	printf("输入：head = ");
	printLinkList(L1);
	LinkList L2 = insertionSortList(L1);
	printf("输出：");
	printLinkList(L2);
	int b[] = {-1,5,3,4,0};
	LinkList L3 = createLinkList(b,5);
	printf("输入：head = ");
	printLinkList(L3);
	LinkList L4 = insertionSortList(L3);
	printf("输出：");
	printLinkList(L4);
	return 0;
}
