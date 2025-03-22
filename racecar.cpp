#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ
void init_stack(StackType* s)
{
	s->top = -1;
}

//���� ���� ����
int is_empty(StackType* s)
{
	return (s->top == -1);
}

//��ȭ ���� ����
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//����
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

//����
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

int is_palindrome(const char* in)
{
	StackType s;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n / 2; i++)
		push(&s, in[i]);

	int j;
	if (n % 2 == 0)
		j = n / 2;
	else
		j = n / 2 + 1;

	for (i = j; i < n; i++) {
		if (is_empty(&s))
			return 0;

		if (pop(&s) != in[i])
			return 0;
	}
	return 1;
}
int main(void)
{
	char str[MAX_STACK_SIZE];

	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%s", str);

	if (is_palindrome(str))
		printf("%s�� ȸ���Դϴ�.\n", str);
	else
		printf("%s�� ȸ���� �ƴմϴ�.\n", str);

	return 0;
}