#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

void a(int len, long* target);
void b(int len, long target);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	long ret = 0;
	
	a(len, &ret);
	b(len, ret);
}

void a(int len, long* target) {
	int preamble = 25;

	for (int i = preamble; i < len; i++) {
		char valid = 0;
		for (int j = i - preamble; j < i - 1; j++) {
			for (int k = j + 1; k < i; k++) {
				if ((input[j] != input[k]) && (input[j] + input[k] == input[i])) {
					valid = 1;
					break;
				}
			}
			if (valid == 1) break;
		}
		if (valid == 0) {
			printf("First invalid value: %ld\n-----------\n", input[i]);
			*target = input[i];
			return;
		}
	}
}

void b(int len, long target) {
	int minIndex = 0;
	int maxIndex = 0;

	long sum = 0;

restart:
	sum = 0;
	for (int i = minIndex; i < len; i++) {
		sum += input[i];
		if (sum == target) {
			maxIndex = i;
			break;
		}
		else if (sum > target) {
			minIndex++;
			goto restart;
		}
	}

	long minValue = 43905084442604;
	long maxValue = 0;
	for (int i = minIndex; i <= maxIndex; i++) {
		if (input[i] < minValue) minValue = input[i];
		else if (input[i] > maxValue) maxValue = input[i];
	}

	printf("Reult: %ld\n", (minValue + maxValue));
}
