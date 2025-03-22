#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화
void init_stack(StackType* s)
{
	s->top = -1;
}

//공백 상태 검출
int is_empty(StackType* s)
{
	return (s->top == -1);
}

//포화 상태 검출
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

//삭제
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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

	printf("문자열을 입력하세요: ");
	scanf("%s", str);

	if (is_palindrome(str))
		printf("%s는 회문입니다.\n", str);
	else
		printf("%s는 회문이 아닙니다.\n", str);

	return 0;
}