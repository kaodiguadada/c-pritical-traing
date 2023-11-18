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
    // �������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӷ���
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // ��������ָ��odd��even���ֱ�ָ���һ���ڵ�͵ڶ����ڵ�
    ListNode* odd = head;
    ListNode* even = head->next;
    // ����even�ĳ�ʼ�ڵ㣬������������
    ListNode* evenHead = even;
    // ��odd��evenָ��սڵ�ʱ��ֹͣ����
    while (odd->next != NULL && even->next != NULL) {
        // ��oddָ����һ�������ڵ㣬��even��next
        odd->next = even->next;
        // ��odd�ƶ����ýڵ�
        odd = odd->next;
        // ��evenָ����һ��ż���ڵ㣬��odd��next
        even->next = odd->next;
        // ��even�ƶ����ýڵ�
        even = even->next;
    }
    // �������ڵ��β�����ӵ�ż���ڵ��ͷ��
    odd->next = evenHead;
    // ������ż�����ͷ�ڵ�
    return head;
}

int main(){
	int a[] = {1,2,3,4,5};
	LinkList L1 = createLinkList(a,5);
	printf("���룺head = ");
	printLinkList(L1);
	LinkList L2 = oddEvenList(L1);
	printf("�����");
	printLinkList(L2);
	int b[] = {2,1,3,5,6,4,7};
	LinkList L3 = createLinkList(b,7);
	printf("���룺head = ");
	printLinkList(L3);
	LinkList L4 = oddEvenList(L3);
	printf("�����");
	printLinkList(L4);
}
