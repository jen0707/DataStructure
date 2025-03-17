#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}; Node;

int main() {
	struct Node* num;
	num = (struct Node*)malloc(2 * sizeof(struct Node));

	if (num == NULL) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	num->data = 10;
	(num+1)->data = 20;

	num->next = (num+1);
	(num + 1)->next = NULL;

		printf("두 번째 노드의 데이터 : %d\n", num->next->data);

    free(num);
	return 0;
}