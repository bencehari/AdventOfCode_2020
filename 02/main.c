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
	int valid = 0;
	const char delim[] = " ";

	for (int i = 0; i < len; i++) {
		int l = strlen(input[i]);
		char str[l + 1];
		memcpy(str, input[i], l);

		char* token = strtok(str, "-");
		int min = atoi(token);

		token = strtok(NULL, delim);
		int max = atoi(token);

		token = strtok(NULL, delim);
		char letter = token[0];

		token = strtok(NULL, delim);
		char* password = token;

		int lCounter = 0;
		for (int i = 0; i < strlen(password); i++) {
			if (password[i] == letter) {
				lCounter++;
			}
		}

		if (lCounter >= min && lCounter <= max) {
			valid++;
		}
	}

	printf("0. Valid count: %d\n", valid);
}

void b(int len) {
	int valid = 0;
	const char delim[] = " ";

	for (int i = 0; i < len; i++) {
		int l = strlen(input[i]);
		char str[l + 1];
		memcpy(str, input[i], l);

		char* token = strtok(str, "-");
		int min = atoi(token) - 1;

		token = strtok(NULL, delim);
		int max = atoi(token) - 1;

		token = strtok(NULL, delim);
		char letter = token[0];

		token = strtok(NULL, delim);
		char* password = token;

		if ((password[min] == letter && password[max] != letter) ||
			(password[max] == letter && password[min] != letter)) valid++;
	}

	printf("1. Valid count: %d\n", valid);
}
