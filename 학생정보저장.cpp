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
	
	printf("저장할 학생 수를 입력하시오: ");
	scanf("%d", &N);

	arr = (struct Student*)malloc(N * sizeof(struct Student));

	if (arr == NULL) {
		fprintf(stderr, "can't allocate memory\n");
		exit(1);
	}

	for (int i = 0; i < N; i++) {
		printf("학생 %d의 이름 입력 : ", i+1); scanf("%s", arr[i].name);
		printf("학생 %d의 나이 입력 : ", i+1); scanf("%d", &arr[i].age);
		printf("학생 %d의 성적 입력 : ", i+1); scanf("%f", &arr[i].score);
	}

	printf("\n\n--- 학생 정보 출력 ---\n");
	for (int i = 0; i < N; i++) {
		printf("학생 %d : 이름 = %s, 나이 = %d, 성적 = %f \n", i+1, arr[i].name, arr[i].age, arr[i].score);
	}

	free(arr);
	return 0;
}
