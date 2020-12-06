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
	int qCount = 26;
	int totalAnswers[qCount];
	int groupAnswers[qCount];
	for (int i = 0; i < qCount; i++) {
		totalAnswers[i] = groupAnswers[i] = 0;
	}

	for (int i = 0; i < len; i++) {
		if (input[i][0] == '\0') {
			for (int j = 0; j < qCount; j++) {
				totalAnswers[j] += groupAnswers[j];
				groupAnswers[j] = 0;
			}
			continue;
		}

		for (int j = 0; j < strlen(input[i]); j++) {
			int index = input[i][j] - 97;
			groupAnswers[index] = 1;
		}
	}

	int total = 0;
	for (int i = 0; i < qCount; i++) {
		total += totalAnswers[i];
	}

	printf("Total anyone yes: %d\n-----------\n", total);
}

void b(int len) {
	int qCount = 26;
	int totalAnswers[qCount];
	int groupAnswers[qCount];
	for (int i = 0; i < qCount; i++) {
		totalAnswers[i] = groupAnswers[i] = 0;
	}

	int groupMemberCount = 0;
	for (int i = 0; i < len; i++) {
		if (input[i][0] == '\0') {
			for (int j = 0; j < qCount; j++) {
				totalAnswers[j] += ((groupAnswers[j] == groupMemberCount) ? 1 : 0);
				groupAnswers[j] = 0;
			}
			groupMemberCount = 0;

			continue;
		}

		groupMemberCount++;

		for (int j = 0; j < strlen(input[i]); j++) {
			int index = input[i][j] - 97;
			groupAnswers[index]++;
		}
	}

	int total = 0;
	for (int i = 0; i < qCount; i++) {
		total += totalAnswers[i];
	}

	printf("Total everyone yes: %d\n-----------\n", total);
}
