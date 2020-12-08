#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input.h"

struct Bag {
	char* name;
	int parentLen;
	struct Bag** parent;
	int good;
};

struct Bag2 {
	char* name;
	int childLen;
	struct Bag2** children;
	int** bagCount;
};

void a(int len);
void b(int len);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	a(len);
	b(len);
}

void setParentGood(struct Bag* bag) {
	bag->good = 1;
	for (int i = 0; i < bag->parentLen; i++) {
		setParentGood(bag->parent[i]);
	}
}

void a(int len) {
	char ownBag[] = "shiny gold";

	struct Bag** bags = malloc(sizeof (struct Bag*));
	int bagsLen = 0;

	for (int i = 0; i < len; i++) {
		int index = 0;
		int level = 0;
		struct Bag* parentBag = NULL;
		struct Bag* actBag = NULL;

		for (int j = 2; j < strlen(input[i]); j++) {
			if ((input[i][j] == 'g') && (input[i][j - 1] == 'a') && (input[i][j - 2] == 'b')) {
				int l = j - 2 - index;
				char tmp[l];
				memcpy(tmp, &input[i][index], l);
				tmp[l - 1] = '\0';

				if (strcmp(tmp, "gs contain no other") == 0) continue;

				actBag = NULL;

				for (int k = 0; k < bagsLen; k++) {
					if (strcmp(bags[k]->name, tmp) == 0) {
						actBag = bags[k];
						break;
					}
				}

				if (actBag == NULL) {
					actBag = malloc(sizeof (struct Bag));
					int tl = strlen(tmp) + 1;
					actBag->name = malloc(tl);
					memcpy(actBag->name, tmp, tl);
					actBag->parentLen = 0;
					actBag->parent = NULL;
					actBag->good = 0;

					bags = realloc(bags, sizeof (struct Bag*) * (bagsLen + 1));
					bags[bagsLen++] = actBag;
				}

				index = j;

				if (level++ == 0) {
					parentBag = actBag;
					continue;
				}

				if (actBag->parentLen == 0) {
					actBag->parent = malloc(sizeof (struct Bag*));
					actBag->parent[0] = parentBag;
					actBag->parentLen = 1;
				}
				else {
					actBag->parent = realloc(actBag->parent, sizeof (struct Bag*) * (actBag->parentLen + 1));
					actBag->parent[actBag->parentLen++] = parentBag;
				}

				if (strncmp(tmp, ownBag, 10) == 0) {
					parentBag->good = 1;
				}

				index = j;
			}

			if (input[i][j] >= '0' && input[i][j] <= '9') {
				index = j + 2;
			}
		}

		level = 0;
	}
	
	for (int i = 0; i < bagsLen; i++) {
		if (bags[i]->good) {
			setParentGood(bags[i]);
		}
	}

	int res = 0;
	for (int i = 0; i < bagsLen; i++) {
		if (bags[i]->good == 1) res++;
	}

	printf("Result: %d\n-----------\n", res);

	for (int i = 0; i < bagsLen; i++) {
		free(bags[i]->name);
		free(bags[i]);
	}
	free(bags);
}

void addBagCounts(const struct Bag2* bag, int* sum) {
	for (int i = 0; i < bag->childLen; i++) {
		*sum += *bag->bagCount[i];
		for (int j = 0; j < *bag->bagCount[i]; j++) addBagCounts(bag->children[i], sum);
	}
}

void b(int len) {
	char ownBag[] = "shiny gold";

	struct Bag2** bags = malloc(sizeof (struct Bag2*));
	int bagsLen = 0;

	for (int i = 0; i < len; i++) {
		int index = 0;
		int level = 0;
		struct Bag2* parentBag = NULL;
		struct Bag2* actBag = NULL;

		for (int j = 2; j < strlen(input[i]); j++) {
			if ((input[i][j] == 'g') && (input[i][j - 1] == 'a') && (input[i][j - 2] == 'b')) {
				int l = j - 2 - index;
				char tmp[l];
				memcpy(tmp, &input[i][index], l);
				tmp[l - 1] = '\0';

				if (strcmp(tmp, "gs contain no other") == 0) continue;

				actBag = NULL;

				for (int k = 0; k < bagsLen; k++) {
					if (strcmp(bags[k]->name, tmp) == 0) {
						actBag = bags[k];
						break;
					}
				}

				if (actBag == NULL) {
					actBag = malloc(sizeof (struct Bag2));
					int tl = strlen(tmp) + 1;
					actBag->name = malloc(tl);
					memcpy(actBag->name, tmp, tl);
					actBag->childLen = 0;
					actBag->children = NULL;
					actBag->bagCount = NULL;

					bags = realloc(bags, sizeof (struct Bag2*) * (bagsLen + 1));
					bags[bagsLen++] = actBag;
				}

				index = j;

				if (level++ == 0) {
					parentBag = actBag;
					continue;
				}

				if (parentBag->childLen == 0) {
					parentBag->children = malloc(sizeof (struct Bag2*));
					parentBag->children[0] = actBag;
					parentBag->childLen = 1;
				}
				else {
					parentBag->children = realloc(parentBag->children, sizeof (struct Bag2*) * (parentBag->childLen + 1));
					parentBag->children[parentBag->childLen++] = actBag;
				}

				index = j;
			}

			if (input[i][j] >= '0' && input[i][j] <= '9') {
				index = j + 2;

				if (parentBag->childLen == 0) {
					parentBag->bagCount = malloc(sizeof (int*));
					int* c = malloc(sizeof (int));
					*c = (int)(input[i][j] - '0');
					parentBag->bagCount[0] = c;
				}
				else {
					parentBag->bagCount = realloc(parentBag->bagCount, sizeof (int*) * (parentBag->childLen + 1));
					int* c = malloc(sizeof (int));
					*c = (int)(input[i][j] - '0');
					parentBag->bagCount[parentBag->childLen] = c;
				}
			}
		}

		level = 0;
	}

	int res = 0;
	for (int i = 0; i < bagsLen; i++) {
		if (strncmp(bags[i]->name, ownBag, 10) == 0) {
			addBagCounts(bags[i], &res);
			break;
		}
	}

	printf("Result: %d\n", res);

	for (int i = 0; i < bagsLen; i++) {
		free(bags[i]->name);
		for (int j = 0; j < bags[i]->childLen; j++) {
			free(bags[i]->bagCount[j]);
		}
		free(bags[i]->bagCount);
		free(bags[i]);
	}
	free(bags);
}
