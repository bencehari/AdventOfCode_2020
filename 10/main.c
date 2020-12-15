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

int cmpfunc (const void * a, const void * b) {
	return (*(int*)a - *(int*)b);
}

void a(int len) {
	int adapters[len];
	for (int i = 0; i < len; i++) adapters[i] = input[i];

	printf("---------------\n");

	qsort(adapters, len, sizeof (int), cmpfunc);

	int diff[3];
	for (int i = 0; i < 3; i++) diff[i] = 0;
	diff[adapters[0] - 1]++;

	for (int i = 1; i < len; i++) {
		diff[adapters[i] - adapters[i - 1] - 1]++;
	}
	diff[2]++;

	printf("Result: %d\n-----------\n", diff[0] * diff[2]);
}

void b(int length) {
	// as soon as I have time to figure it out
}
