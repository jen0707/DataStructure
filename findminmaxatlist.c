#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode
{
	element data;
	struct ListNode* link;
} ListNode;

// error 정의
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 삽입 연산 (head)
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;
	return head;
}
// 방문 연산 (출력)
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("NULL \n");
}

// 최소 최댓값 찾기
void MinMaxfromList(ListNode* head)
{
	int min = head->data;
	int max = head->data;

	for (ListNode* p = head->link; p != NULL; p = p->link) {
		if (p->data < min)
		{
			min = p->data;
		}
		if (p->data > max)
		{
			max = p->data;
		}
	}

	printf("min : %d\n", min);
	printf("MAX : % d\n", max);
}

// 테스트 프로그램
int main(void)
{

	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);

	MinMaxfromList(head);

	return 0;
}
