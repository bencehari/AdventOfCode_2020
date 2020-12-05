#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void a(int len);
void b(int len);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	a(len);
	b(len);
}

void a(int len) {
	int maxId = 0;

	for (int i = 0; i < len; i++) {
		int min = 0;
		int max = 127;

		int j = 0;
		for (; j < 6; j++) {
			if (input[i][j] == 'F') {
				max = min + ((max - min) * .5);
			}
			// input[i][j] == 'B'
			else {
				min = min + ((max - min) * .5) + 1;
			}
		}

		int fRow = input[i][j++] == 'F' ? min : max;
		min = 0;
		max = 7;

		for (; j < 9; j++) {
			if (input[i][j] == 'L') {
				max = min + ((max - min) * .5);
			}
			// input[i][j] == 'R'
			else {
				min = min + ((max - min) * .5) + 1;
			}
		}
		min = input[i][j] == 'L' ? min : max;

		max = fRow * 8 + min;
		if (max > maxId) maxId = max;

		// printf("Act seat ID: %d\n", max);
	}

	printf("Max seat ID: %d\n-----------\n", maxId);
}

int cmpfunc(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

void b(int len) {
	int seatIDs[len];

	for (int i = 0; i < len; i++) {
		int min = 0;
		int max = 127;

		int j = 0;
		for (; j < 6; j++) {
			if (input[i][j] == 'F') {
				max = min + ((max - min) * .5);
			}
			// input[i][j] == 'B'
			else {
				min = min + ((max - min) * .5) + 1;
			}
		}

		int fRow = input[i][j++] == 'F' ? min : max;
		min = 0;
		max = 7;

		for (; j < 9; j++) {
			if (input[i][j] == 'L') {
				max = min + ((max - min) * .5);
			}
			// input[i][j] == 'R'
			else {
				min = min + ((max - min) * .5) + 1;
			}
		}
		min = input[i][j] == 'L' ? min : max;

		seatIDs[i] = fRow * 8 + min;
	}

	qsort(seatIDs, len, sizeof(int), cmpfunc);

	for (int i = 0; i < len - 1; i++) {
		if ((seatIDs[i + 1] != seatIDs[i] + 1) && (seatIDs[i + 1] == seatIDs[i] + 2)) {
			printf("Missing seatID: %d\n", seatIDs[i] + 1);
			break;
		}
	}
}
