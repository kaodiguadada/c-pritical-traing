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

// ��ɶ�������в�������ĺ���
LinkList insertionSortList(ListNode *head) {
        // �������Ϊ�ջ���ֻ��һ���ڵ㣬ֱ�ӷ���
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // ����һ���µĿ�������һ���ڱ��ڵ㷽�����
        struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->val = 0; // �ڱ��ڵ��ֵ�����������ã���Ӱ������
        dummy->next = NULL; // �������ͷ�ڵ��ʼ��ΪNULL
        // ��ԭ����������ȡ��ÿ���ڵ�
        while (head != NULL) {
            // ���浱ǰ�ڵ����һ���ڵ㣬��ֹ����
            struct ListNode* next = head->next;
            // ���������ͷ�ڵ㿪ʼ���ҵ�����λ�õ�ǰһ���ڵ�
            struct ListNode* prev = dummy;
            while (prev->next != NULL && prev->next->val < head->val) {
                prev = prev->next;
            }
            // ����ǰ�ڵ���뵽��������
            head->next = prev->next;
            prev->next = head;
            // ����������һ���ڵ�
            head = next;
        }
        // �����������ͷ�ڵ㣬�����ڱ��ڵ�
        return dummy->next;
}


int main(){
	int a[] = {4,2,1,3};
	LinkList L1 = createLinkList(a,4);
	printf("���룺head = ");
	printLinkList(L1);
	LinkList L2 = insertionSortList(L1);
	printf("�����");
	printLinkList(L2);
	int b[] = {-1,5,3,4,0};
	LinkList L3 = createLinkList(b,5);
	printf("���룺head = ");
	printLinkList(L3);
	LinkList L4 = insertionSortList(L3);
	printf("�����");
	printLinkList(L4);
	return 0;
}
