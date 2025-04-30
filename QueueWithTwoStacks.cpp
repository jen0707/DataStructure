#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s); //초기화
int is_empty(StackType* s); //공백상태검출
int is_full(StackType* s); //포화상태검출
void push(StackType* s, element item); //삽입
element pop(StackType* s); //삭제
void stack_in_push(StackType* stack_in, element item); //enqueue
element stack_out_pop(StackType* stack_in, StackType* stack_out); //dequeue

int main()
{
	StackType stack_in, stack_out;
	init_stack(&stack_in);
	init_stack(&stack_out);
	
	stack_in_push(&stack_in, 10);
	stack_in_push(&stack_in, 20);
	stack_in_push(&stack_in, 30);

	printf("%d\n", stack_out_pop(&stack_in, &stack_out));
	printf("%d\n", stack_out_pop(&stack_in, &stack_out));
	
	stack_in_push(&stack_in, 40);

	printf("%d\n", stack_out_pop(&stack_in, &stack_out));
	printf("%d\n", stack_out_pop(&stack_in, &stack_out));
}

void init_stack(StackType* s)
{
	s->top = -1;
}

int is_empty(StackType* s)
{
	return (s->top == -1);
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

void stack_in_push(StackType* stack_in, element item)
{
	push(stack_in, item);
}

element stack_out_pop(StackType* stack_in, StackType* stack_out)
{
	if (is_empty(stack_out))
		while (!is_empty(stack_in)) {
			push(stack_out, pop(stack_in));
		}
	return pop(stack_out);
}
