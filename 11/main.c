#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void a(int rowLen, int colLen);
void b(int rowLen, int colLen);

int main(int argc, char** argv) {
	int rowLen = (sizeof input) / (sizeof input[0]);
	int colLen = strlen(input[0]);

	a(rowLen, colLen);
	b(rowLen, colLen);
}

void a(int rowLen, int colLen) {
	char seats0[rowLen][colLen];
	char seats1[rowLen][colLen];
	for (int row = 0; row < rowLen; row++) {
		for (int col = 0; col < colLen; col++) {
			seats0[row][col] = seats1[row][col] = input[row][col];
		}
	}

	char (*t0)[colLen];
	char (*t1)[colLen];
	for (int changed = 1, step = 0; changed == 1; step++) {
		changed = 0;

		if (step % 2 == 0) {
			t0 = seats0; t1 = seats1;
		}
		else {
			t0 = seats1; t1 = seats0;
		}

		for (int row = 0; row < rowLen; row++) {
			for (int col = 0; col < colLen; col++) {
				int xMin = -1; int xMax = 2;
				int yMin = -1; int yMax = 2;

				if (row == 0) yMin = 0;
				else if (row == rowLen - 1) yMax = 1;
				if (col == 0) xMin = 0;
				else if (col == colLen - 1) xMax = 1;

				int occupied = 0;
				for (int x = xMin; x < xMax; x++) {
					for (int y = yMin; y < yMax; y++) {
						if (x == 0 && y == 0) continue;
						if (t0[row + y][col + x] == '#') {
							occupied++;
						}
					}
				}

				switch (t0[row][col]) {
					case 'L': {
						if (occupied == 0) {
							t1[row][col] = '#';
							changed = 1;
						}
						else {
							t1[row][col] = 'L';
						}
						break;
					}
					case '#': {
						if (occupied >= 4) {
							t1[row][col] = 'L';
							changed = 1;
						}
						else {
							t1[row][col] = '#';
						}
						break;
					}
				}
			}
		}
	}

	int res = 0;
	for (int row = 0; row < rowLen; row++) {
		for (int col = 0; col < colLen; col++) {
			if (t1[row][col] == '#') res++;
		}
	}

	printf("Occupied seats: %d\n-----------\n", res);
}

void b(int rowLen, int colLen) {
	char seats0[rowLen][colLen];
	char seats1[rowLen][colLen];
	for (int row = 0; row < rowLen; row++) {
		for (int col = 0; col < colLen; col++) {
			seats0[row][col] = seats1[row][col] = input[row][col];
		}
	}

	char (*t0)[colLen];
	char (*t1)[colLen];
	for (int changed = 1, step = 0; changed == 1; step++) {
		changed = 0;

		if (step % 2 == 0) {
			t0 = seats0; t1 = seats1;
		}
		else {
			t0 = seats1; t1 = seats0;
		}

		for (int row = 0; row < rowLen; row++) {
			for (int col = 0; col < colLen; col++) {
				int occupied = 0;
				for (int x = col - 1; x >= 0; x--) {
					if (t0[row][x] == 'L') break;
					else if (t0[row][x] == '#') { occupied++; break; }
				}
				for (int x = col + 1; x < colLen; x++) {
					if (t0[row][x] == 'L') break;
					else if (t0[row][x] == '#') { occupied++; break; }
				}
				for (int y = row - 1; y >= 0; y--) {
					if (t0[y][col] == 'L') break;
					else if (t0[y][col] == '#') { occupied++; break; }
				}
				for (int y = row + 1; y < rowLen; y++) {
					if (t0[y][col] == 'L') break;
					else if (t0[y][col] == '#') { occupied++; break; }
				}
				
				for (int x = col - 1, y = row - 1; x >= 0 && y >= 0; x--, y--) {
					if (t0[y][x] == 'L') break;
					else if (t0[y][x] == '#') { occupied++; break; }
				}
				for (int x = col + 1, y = row - 1; x < colLen && y >= 0; x++, y--) {
					if (t0[y][x] == 'L') break;
					else if (t0[y][x] == '#') { occupied++; break; }
				}
				for (int x = col - 1, y = row + 1; x >= 0 && y < rowLen; x--, y++) {
					if (t0[y][x] == 'L') break;
					else if (t0[y][x] == '#') { occupied++; break; }
				}
				for (int x = col + 1, y = row + 1; x < colLen && y < rowLen; x++, y++) {
					if (t0[y][x] == 'L') break;
					else if (t0[y][x] == '#') { occupied++; break; }
				}

				switch (t0[row][col]) {
					case 'L': {
						if (occupied == 0) {
							t1[row][col] = '#';
							changed = 1;
						}
						else {
							t1[row][col] = 'L';
						}
						break;
					}
					case '#': {
						if (occupied >= 5) {
							t1[row][col] = 'L';
							changed = 1;
						}
						else {
							t1[row][col] = '#';
						}
						break;
					}
				}
			}
		}

		/*printf("Step: %d\n", step);
		for (int row = 0; row < rowLen; row++) {
			for (int col = 0; col < colLen; col++) {
				printf("%c", t1[row][col]);
			}
			printf("\n");
		}
		printf("--------------\n");*/
	}

	int res = 0;
	for (int row = 0; row < rowLen; row++) {
		for (int col = 0; col < colLen; col++) {
			if (t1[row][col] == '#') res++;
		}
	}

	printf("Occupied seats: %d\n", res);
}
