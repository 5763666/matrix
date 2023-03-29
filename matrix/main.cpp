#include <stdlib.h>
#include <stdio.h>
int main() {
	int row, col, terms, i, j;
	int** matrix, ** transpose;

	// 입력 받을 행렬의 크기 입력
	printf("Enter the number of rows and columns, the number of non-zero terms : ");
	scanf_s("%d %d %d", &row, &col, &terms);


	// 입력 받은 행렬의 크기에 맞게 메모리 할당
	matrix = (int**)malloc(row * sizeof(int*));
	transpose = (int**)malloc(col * sizeof(int*));
	for (i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(col * sizeof(int));
	}
	for (i = 0; i < col; i++) {
		transpose[i] = (int*)malloc(row * sizeof(int));
	}

	// 입력 받을 행렬 요소 입력
	printf("\nEnter the row, column, and value paris in order:\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf_s("%d", &matrix[i][j]);
		}
	}

	// 전치행렬 생성
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			transpose[i][j] = matrix[j][i];
		}
	}

	// 전치행렬 출력
	printf("\nThe transposed matrix is:\n");
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			printf("%d ", transpose[i][j]);
		}
		printf("\n");
	}

	// 동적 메모리 할당 해제
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