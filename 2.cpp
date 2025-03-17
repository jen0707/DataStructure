#include <stdio.h>
#include <stdlib.h>

struct Student {
	char name[50];
	int age;
	float score;
};

int main()
{
	int N;
	struct Student* arr;
	
	printf("������ �л� ���� �Է��Ͻÿ�: ");
	scanf("%d", &N);

	arr = (struct Student*)malloc(N * sizeof(struct Student));

	if (arr == NULL) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	for (int i = 0; i < N; i++) {
		printf("�л� %d�� �̸� �Է� : ", i+1); scanf("%s", arr[i].name);
		printf("�л� %d�� ���� �Է� : ", i+1); scanf("%d", &arr[i].age);
		printf("�л� %d�� ���� �Է� : ", i+1); scanf("%f", &arr[i].score);
	}

	printf("\n\n--- �л� ���� ��� ---\n");
	for (int i = 0; i < N; i++) {
		printf("�л� %d : �̸� = %s, ���� = %d, ���� = %f \n", i+1, arr[i].name, arr[i].age, arr[i].score);
	}

	free(arr);
	return 0;
}