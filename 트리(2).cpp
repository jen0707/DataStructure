#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	int id;
	char name[20];
	struct Student* left;
	struct Student* right;
}Student;

// 학생 정보 추가
Student* insert(Student* root, int id, const char* name) {
	if (root == NULL) {
		Student* newNode = (Student*)malloc(sizeof(Student));
		newNode->id = id;
		strcpy(newNode->name, name);
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if (id < root->id)
		root->left = insert(root->left, id, name);
	else if (id > root->id)
		root->right = insert(root->right, id, name);
	else
		printf("학번 %d가 이미 존재합니다.\n", id);
	return root;
}

// 학생 정보 탐색
Student* search(Student* root, int id) {
	if (root == NULL) return NULL;
	if (root->id == id) return root;
	else if (id < root->id)
		return search(root->left, id);
	else
		return search(root->right, id);
}

// 전체 출력
void inorder(Student* root) {
	if (root == NULL) return;
	inorder(root->left);
	printf("학번: %d, 이름: %s\n", root->id, root->name);
	inorder(root->right);
}

// 학생 정보 삭제
Student* delete_(Student* root, int id) {
	if (root == NULL) return NULL;
	if (id < root->id)
		root->left = delete_(root->left, id);
	else if (id > root->id)
		root->right = delete_(root->right, id);
	else {
		if (root->left == NULL) {
			Student* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Student* temp = root->left;
			free(root);
			return temp;
	}

	Student* succ = root->right;
	while (succ->left != NULL)
		succ = succ->left;

	root->id = succ->id;
	strcpy(root->name, succ->name);

	root->right = delete_(root->right, succ->id);
	}
	return root;

}

int main(void) {
	Student* root = NULL;
	int choice, id;

	// 예시 데이터
	root = insert(root, 202104, "이**");
	root = insert(root, 202102, "박**");
	root = insert(root, 202101, "김**");
	root = insert(root, 202107, "최**");
	root = insert(root, 202103, "정**");
	root = insert(root, 202106, "한**");
	root = insert(root, 202105, "오**");


	while (1) {
		printf("\n==== 학생 정보 시스템 ====\n");
		printf("(1) 학생 정보 탐색\n");
		printf("(2) 학생 정보 삭제\n");
		printf("(3) 전체 출력\n");
		printf("(0) 종료\n");
		printf("선택 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			printf("학번 입력: ");
			scanf("%d", &id);
			Student* found = search(root, id);
			if (found != NULL)
				printf("검색 결과: 학번:%d, 이름: %s\n", found->id, found->name);
			else
				printf("해당 학번 없음.\n");
			break;
		}
		case 2:
			printf("삭제할 학번 입력: ");
			scanf("%d", &id);
			root = delete_(root, id);
			printf("학번 %d 삭제 완료.\n", id);
			break;

		case 3:
			printf("--- 전체 학생 목록 (오름차순) --- \n");
			inorder(root);
			break;

		case 0:
			printf("프로그램 종료\n");
			exit(0);

		default:
			printf("잘못된 선택입니다.\n");
		}
	}

	return 0;
}
