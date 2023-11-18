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

ListNode* oddEvenList(ListNode* head) {
    // 如果链表为空或只有一个节点，直接返回
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // 定义两个指针odd和even，分别指向第一个节点和第二个节点
    ListNode* odd = head;
    ListNode* even = head->next;
    // 保存even的初始节点，用于最后的连接
    ListNode* evenHead = even;
    // 当odd或even指向空节点时，停止遍历
    while (odd->next != NULL && even->next != NULL) {
        // 将odd指向下一个奇数节点，即even的next
        odd->next = even->next;
        // 将odd移动到该节点
        odd = odd->next;
        // 将even指向下一个偶数节点，即odd的next
        even->next = odd->next;
        // 将even移动到该节点
        even = even->next;
    }
    // 将奇数节点的尾部连接到偶数节点的头部
    odd->next = evenHead;
    // 返回奇偶链表的头节点
    return head;
}

int main(){
	int a[] = {1,2,3,4,5};
	LinkList L1 = createLinkList(a,5);
	printf("输入：head = ");
	printLinkList(L1);
	LinkList L2 = oddEvenList(L1);
	printf("输出：");
	printLinkList(L2);
	int b[] = {2,1,3,5,6,4,7};
	LinkList L3 = createLinkList(b,7);
	printf("输入：head = ");
	printLinkList(L3);
	LinkList L4 = oddEvenList(L3);
	printf("输出：");
	printLinkList(L4);
}
