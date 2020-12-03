#include <stdio.h>

#include "input.h"

void a(int len);
void b(int len);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	a(len);
	b(len);
}

void a(int len) {
	int done = 0;
	
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (input[i] + input[j] == 2020) {
				printf("%d, %d -> %d\n------------\n", input[i], input[j], (input[i] * input[j]));
				done = 1;
				break;
			}
		}
		if (done == 1) break;
	}
}

void b(int len) {
	int done = 0;

	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			int tmp = input[i] + input[j];
			if (tmp < 2020) {
				for (int k = j + 1; k < len; k++) {
					if (tmp + input[k] == 2020) {
						printf("%d, %d, %d -> %d\n", input[i], input[j], input[k], (input[i] * input[j] * input[k]));
						done = 1;
						break;
					}
				}
			}

			if (done == 1) break;
		}
		if (done == 1) break;
	}
}
