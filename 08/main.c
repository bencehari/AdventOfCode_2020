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
	char instructions[len];
	for (int i = 0; i < len; i++) instructions[i] = 0;

	int res = 0;
	int index = 0;

	while (1) {
		if (instructions[index] == 1) break;
		else instructions[index] = 1;

		int l = strlen(input[index]) + 1;
		char row[l];
		memcpy(row, input[index], l);

		char* inst = strtok(row, " ");
		char* svalue = strtok(NULL, " ");

		int multiplier = svalue[0] == '+' ? 1 : -1;
		int value = atoi(svalue + 1);

		if (strncmp(inst, "acc", 3) == 0) {
			res += value * multiplier;
			index++;
		}
		else if (strncmp(inst, "jmp", 3) == 0) {
			index += value * multiplier;
		}
		else if (strncmp(inst, "nop", 3) == 0) {
			index++;
		}
	}

	printf("Result: %d\n-----------\n", res);
}

void b(int len) {
	char instructions[len];
	int lastChanged = -1;

restart:
	for (int i = 0; i < len; i++) instructions[i] = 0;
	int res = 0;
	int index = 0;
	int changed = 0;

	lastChanged++;

	while (1) {
		if (index == len) break;

		if (instructions[index] == 1) goto restart;
		else instructions[index] = 1;

		int l = strlen(input[index]) + 1;
		char row[l];
		memcpy(row, input[index], l);

		char* inst = strtok(row, " ");
		char* svalue = strtok(NULL, " ");

		int multiplier = svalue[0] == '+' ? 1 : -1;
		int value = atoi(svalue + 1);

		if (strncmp(inst, "acc", 3) == 0) {
			goto acc;
		}
		else if (strncmp(inst, "jmp", 3) == 0) {
			if (changed++ == lastChanged) {
				goto nop;
			}

			goto jmp;
		}
		else if (strncmp(inst, "nop", 3) == 0) {
			if (changed++ == lastChanged) {
				goto jmp;
			}

			goto nop;
		}

acc:
		res += value * multiplier;
		index++;
		continue;

jmp:
		index += value * multiplier;
		continue;

nop:
		index++;
	}

	printf("Result: %d\n", res);
}
