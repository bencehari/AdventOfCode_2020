#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

#define TEST 0

void a(void);
void b(void);

int main(int argc, char** argv) {
	a();
	b();
}

void a() {
	int depart = atoi(input[0]);
	int inputLen = strlen(input[1]);
	char* idsRaw = malloc(inputLen);
	int index = 0;

	char isNum = 0;
	int idCount = 0;
	for (int i = 0; i < inputLen; i++) {
		if (input[1][i] >= '0' && input[1][i] <= '9') {
			idsRaw[index++] = input[1][i];
			isNum = 1;
		}
		else if (input[1][i] == ',') {
			if (isNum) {
				idsRaw[index++] = input[1][i];
				idCount++;
				isNum = 0;
			}
		}
		else {
			isNum = 0;
		}

		if (i == inputLen - 1 && isNum) idCount++;
	}
	idsRaw[index] = '\0';

	int ids[idCount];
	int a = 0;
	char* token = strtok(idsRaw, ",");
	while (token != NULL) {
		ids[a++] = atoi(token);
		token = strtok(NULL, ",");
	}
	free(idsRaw);

	int diffs[idCount];
	for (int i = 0; i < idCount; i++) diffs[i] = 0;

	int act = 0;
	int leastDiffIndex = 0;
	for (int i = 0; i < idCount; i++) {
		while (act <= depart) {
			act += ids[i];
		}

		diffs[i] = act - depart;
		act = 0;
		if (diffs[i] < diffs[leastDiffIndex]) leastDiffIndex = i;
	}

	printf("Result: %d\n-----------\n", (ids[leastDiffIndex] * diffs[leastDiffIndex]));
}

void b() {
#if TEST == 1
	int testInputIndex = -1;
next:
	testInputIndex++;
#endif

#if TEST == 1
	int inputLen = strlen(testInputs[testInputIndex]);
#else
	int inputLen = strlen(input[1]);
#endif
	char* idsRaw = malloc(inputLen);
	int index = 0;

	char isNum = 0;
	int idCount = 0;
	int departTime = 0;
	for (int i = 0; i < inputLen; i++) {
#if TEST == 1
		if (testInputs[testInputIndex][i] >= '0' && testInputs[testInputIndex][i] <= '9') {
#else
		if (input[1][i] >= '0' && input[1][i] <= '9') {
#endif
#if TEST == 1
			idsRaw[index++] = testInputs[testInputIndex][i];
#else			
			idsRaw[index++] = input[1][i];
#endif
			
			isNum = 1;
		}
#if TEST == 1
		else if (testInputs[testInputIndex][i] == ',') {
#else
		else if (input[1][i] == ',') {
#endif
			if (isNum) {
#if TEST == 1
				idsRaw[index++] = testInputs[testInputIndex][i];
#else
				idsRaw[index++] = input[1][i];
#endif
				
				idCount++;
				isNum = 0;

				char tmp[4];
				sprintf(tmp, "%d", departTime);
				for (int j = 0; j < strlen(tmp); j++) {
					idsRaw[index++] = tmp[j];
				}
				idsRaw[index++] = ',';
			}

			departTime++;
		}
		else {
			isNum = 0;
		}

		if (i == inputLen - 1 && isNum) {
			idCount++;

			char tmp[4];
			sprintf(tmp, "%d", departTime);
			idsRaw[index++] = ',';
			for (int j = 0; j < strlen(tmp); j++) {
				idsRaw[index++] = tmp[j];
			}
		}
	}
	idsRaw[index] = '\0';

	int ids[idCount];
	int departs[idCount];
	char isIdOrIndex = 0;
	int a = 0;
	char* token = strtok(idsRaw, ",");
	while (token != NULL) {
		if (!isIdOrIndex) {
			ids[a] = atoi(token);
			isIdOrIndex = 1;
		}
		else {
			departs[a++] = atoi(token);
			isIdOrIndex = 0;
		}
		token = strtok(NULL, ",");
	}
	free(idsRaw);

	unsigned long act = 0;
	unsigned long per = 1;
	for (int i = 0; i < idCount; i++) {
		while ((act + departs[i]) % ids[i] != 0) {
			act += per;
		}
		per *= ids[i];
	}

	printf("Result: %lu\n", act);
#if TEST == 1
	if (testInputIndex < 4) goto next;
#endif
}
