#include <stdio.h>

struct employee
{
	char name[20];
	char number[20];
	int info;
};

int main()
{
	struct employee arr[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("종업원 이름, 주민등록번호, 급여정보 : ");
		scanf_s("%s, %s, %d", &arr[i].name, &arr[i].number, &arr[i].info);
	};

	for (i = 0; i < 3; i++)
		printf("%s, %s, %d", arr[i].name, arr[i].number, arr[i].info);
	return 0;
}