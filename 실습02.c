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

// 특정 데이터 값 찾기
ListNode* delete_node(ListNode* head, element value)
{
	ListNode* prev = NULL;
	ListNode* x = head;

	while (x != NULL)
	{
		if (x->data == value)
		{
			if (prev == NULL)
			{
				head = x->link;
			}
			else
			{
				prev->link = x->link;
			}
			free(x);
			return head;
		}
		prev = x;
		x = x->link;
	}

		error("값을 찾을 수 없음");
}

element value;

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

	printf("삭제할 값을 입력하시오: ");
	scanf_s("%d", &value);

	head = delete_node(head, value);
	print_list(head);

	return 0;
}
