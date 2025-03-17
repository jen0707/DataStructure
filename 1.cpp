#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int* arr;

	printf("���� �迭�� ũ�⸦ �Է��Ͻÿ�: ");
	scanf_s("%d", &N);

	arr = (int*)malloc(N * sizeof(int));

	if (arr == NULL) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	printf("�迭 ����:");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	free(arr);
	return 0;
}
	


