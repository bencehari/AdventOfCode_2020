#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void a(int rows, int rowLen);
void b(int rows, int rowLen);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	int rowLen = strlen(input[0]);

	printf("Rows: %d\n", len);
	printf("Row length: %d\n", rowLen);

	a(len, rowLen);
	b(len, rowLen);
}

void a(int rows, int rowLen) {
	int trees = 0;

	for (int x = 0, y = 0; x < rows; x++) {
		if (input[x][y] == '#') {
			trees++;
		}

		y += 3;
		if (y >= rowLen) y -= rowLen;
	}

	printf("Trees: %d\n------------\n", trees);
}

void b(int rows, int rowLen) {
	int slopesLen = (sizeof slopes) / (sizeof slopes[0]);
	slopesLen /= 2;

	int results[slopesLen];
	for (int i = 0; i < slopesLen; i++) results[i] = 0;

	for (int i = 0; i < slopesLen; i++) {
		int xStep = slopes[i * 2];
		int yStep = slopes[(i * 2) + 1];
		int trees = 0;

		for (int x = 0, y = 0; x < rows; x += xStep) {
			if (input[x][y] == '#') {
				trees++;
			}

			y += yStep;
			if (y >= rowLen) y -= rowLen;
		}

		results[i] = trees;
	}

	int endResult = results[0];
	printf("1 run: %d\n", results[0]);

	for (int i = 1; i < slopesLen; i++) {
		printf("%d run: %d\n", (i + 1), results[i]);
		endResult *= results[i];
	}

	printf("End result: %d\n", endResult);
}
