#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode n0 = { 0, NULL, NULL };
TreeNode n1 = { 1, NULL, &n0 };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n7 = { 3, NULL, NULL };
TreeNode n8 = { 100, NULL, NULL };
TreeNode n4 = { 25, &n8, &n7 };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };

TreeNode* root = &n6;

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root) {
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
}

int count_non_leaf_nodes(TreeNode* node) {
	if (node == NULL) return 0;
	if (node->left == NULL && node->right == NULL) return 0;
	return 1 + count_non_leaf_nodes(node->left) + count_non_leaf_nodes(node->right);
}

TreeNode* search(TreeNode* node, int value) {
	if (node == NULL) return NULL;
	if (node->data == value) return node;

	TreeNode* found = search(node->left, value);
	if (found != NULL) return found;
	return search(node->right, value);
}

int main(void) {
	// 문제 1: 비단말 노드 수 세기
	int count = count_non_leaf_nodes(root);
	printf("비단말 노드 수 = %d\n", count);

	// 문제 2: 값 검색 테스트
	printf("특정 값을 정하시오: ");
	int target;
	scanf_s("%d", &target);
	TreeNode* result = search(root, target);
	if (result != NULL)
		printf("값 %d 발견: 노드 주소 = %p\n", target, (void*)result);
	else
		printf("값 %d 발견되지 않음\n", target);

	return 0;

}
