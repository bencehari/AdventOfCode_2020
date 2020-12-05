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

/*
	byr (Birth Year)		1
	iyr (Issue Year)		2
	eyr (Expiration Year)	4
	hgt (Height)			8
	hcl (Hair Color)		16
	ecl (Eye Color)			32
	pid (Passport ID)		64
	cid (Country ID)		128

	valid: 127, 255
*/

	int count = 0;
	unsigned char mask = 0;

	for (int i = 0; i < len; i++) {
		if (input[i][0] == '\0') {

			// printf("%d. %d\n", ++count, mask);
			count++;

			if (mask == 127 || mask == 255) valid++;
			mask = 0;
			continue;
		}

		int l = strlen(input[i]);
		char tmps[l + 1];
		memcpy(tmps, input[i], l + 1);

		char* token = strtok(tmps, " ");
		while (token != NULL) {
			if (token[0] == 'b') mask |= 1;
			else if (token[0] == 'i') mask |= 2;
			else if (token[0] == 'e') {
				if (token[1] == 'y') mask |= 4;
				else if (token[1] == 'c') mask |= 32;
			}
			else if (token[0] == 'h') {
				if (token[1] == 'g') mask |= 8;
				else if (token[1] == 'c') mask |= 16;
			}
			else if (token[0] == 'p') mask |= 64;
			else if (token[0] == 'c') mask |= 128;

			token = strtok(NULL, " ");
		}
	}

	printf("All passports: %d\nValid passports: %d\n-----------\n", count, valid);
}

char* getValue(const char* str) {
	int len = strlen(str);
	char* ret = NULL;
	for (int i = 0; i < len; i++) {
		if (str[i] == ':') {
			int l = len - i;
			ret = malloc(l);
			memcpy(ret, (str + i + 1), l);

			return ret;
		}
	}

	return NULL;
}

void b(int len) {
	int valid = 0;

/*
	[x] byr (Birth Year) - four digits; at least 1920 and at most 2002.
	[x] iyr (Issue Year) - four digits; at least 2010 and at most 2020.
	[x] eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
	[x] hgt (Height) - a number followed by either cm or in:
		[ ] If cm, the number must be at least 150 and at most 193.
		[ ] If in, the number must be at least 59 and at most 76.
	[x] hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
	[x] ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
	[x] pid (Passport ID) - a nine-digit number, including leading zeroes.
	[ ] cid (Country ID) - ignored, missing or not.
*/

	unsigned char mask = 0;

	for (int i = 0/*, count = 0*/; i < len; i++) {
		if (input[i][0] == '\0') {

			// printf("%d. %d\n", ++count, mask);

			if (mask == 127 || mask == 255) valid++;
			mask = 0;

			continue;
		}
		
		int l = strlen(input[i]);
		char tmps[l + 1];
		memcpy(tmps, input[i], l + 1);

		char* token = strtok(tmps, " ");

		while (token != NULL) {
			int len = strlen(token);
			char* value = NULL;
			int vLen = 0;
			for (int i = 0; i < len; i++) {
				if (token[i] == ':') {
					vLen = len - i;
					value = malloc(vLen);
					memcpy(value, (token + i + 1), vLen);
				}
			}
			vLen--;

			if (token[0] == 'b') {
				if (vLen != 4) goto next;
				int byr = atoi(value);
				if (byr >= 1920 && byr <= 2002) mask |= 1;
			}
			else if (token[0] == 'i') {
				if (vLen != 4) goto next;
				int iyr = atoi(value);
				if (iyr >= 2010 && iyr <= 2020) mask |= 2;
			}
			else if (token[0] == 'e') {
				if (token[1] == 'y') {
					if (vLen != 4) goto next;
					int eyr = atoi(value);
					if (eyr >= 2020 && eyr <= 2030) mask |= 4;
				}
				else if (token[1] == 'c') {
					if (vLen != 3) goto next;
					if (strcmp(value, "amb") == 0 ||
						strcmp(value, "blu") == 0 ||
						strcmp(value, "brn") == 0 ||
						strcmp(value, "gry") == 0 ||
						strcmp(value, "grn") == 0 ||
						strcmp(value, "hzl") == 0 ||
						strcmp(value, "oth") == 0) mask |= 32;
				}
			}
			else if (token[0] == 'h') {
				if (token[1] == 'g') {
					char end = value[vLen - 1];
					if (end == 'm') {
						int hgt = atoi(value);
						if (hgt >= 150 && hgt <= 193) mask |= 8;
					}
					else if (end == 'n') {
						int hgt = atoi(value);
						if (hgt >= 59 && hgt <= 76) mask |= 8;
					}
				}
				else if (token[1] == 'c') {
					if (vLen != 7 || value[0] != '#') goto next;
					for (int i = 1; i < 7; i++) {
						if (value[i] < 48 || (value[i] > 57 && value[i] < 97) || value[i] > 122) goto next;
					}

					mask |= 16;
				}
			}
			else if (token[0] == 'p') {
				if (vLen != 9) goto next;
				for (int i = 0; i < 9; i++) {
					if (value[i] < 48 || value[i] > 57) goto next;
				}

				mask |= 64;
			}
			else if (token[0] == 'c') {
				mask |= 128;
			}

next:

			free(value);
			token = strtok(NULL, " ");
		}
	}

	printf("Valid passports: %d\n-----------\n", valid);
}
