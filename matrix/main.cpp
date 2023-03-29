#include <stdlib.h>
#include <stdio.h>
int main() {
	int row, col, terms, i, j;
	int** matrix, ** transpose;

	// �Է� ���� ����� ũ�� �Է�
	printf("Enter the number of rows and columns, the number of non-zero terms : ");
	scanf_s("%d %d %d", &row, &col, &terms);


	// �Է� ���� ����� ũ�⿡ �°� �޸� �Ҵ�
	matrix = (int**)malloc(row * sizeof(int*));
	transpose = (int**)malloc(col * sizeof(int*));
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(col * sizeof(int));
	}
	for (i = 0; i < col; i++) {
		transpose[i] = (int*)malloc(row * sizeof(int));
	}

	// �Է� ���� ��� ��� �Է�
	printf("\nEnter the row, column, and value paris in order:\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}

	// ��ġ��� ����
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			transpose[i][j] = matrix[j][i];
		}
	}

	// ��ġ��� ���
	printf("\nThe transposed matrix is:\n");
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}

	// ���� �޸� �Ҵ� ����
	for (i = 0; i < row; i++) {
		free(matrix[i]);
	}
	for (i = 0; i < col; i++) {
		free(transpose[i]);
	}
	free(matrix);
	free(transpose);

	return 0;
}