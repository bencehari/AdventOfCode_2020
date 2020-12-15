#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "input.h"

enum Direction {
	NORTH = 270,
	EAST = 0,
	SOUTH = 90,
	WEST = 180,
	G0 = -90,
	G1 = -180,
	G2 = -270
};

void a(int len);
void b(int len);

int main(int argc, char** argv) {
	int len = (sizeof input) / (sizeof input[0]);

	a(len);
	b(len);
}

void a(int len) {
	enum Direction facing = EAST;
	int x = 0, y = 0;

	for (int i = 0; i < len; i++) {
		int value = atoi(&input[i][1]);
		switch (input[i][0])
		{
			case 'N': { y += value; break; }
			case 'E': { x += value; break; }
			case 'S': { y -= value; break; }
			case 'W': { x -= value; break; }
			case 'L': { facing -= value; break; }
			case 'R': { facing += value; break; }
			case 'F': {
				switch (facing)
				{
					case NORTH: { y += value; break; }
					case EAST: { x += value; break; }
					case SOUTH: { y -= value; break; }
					case WEST: { x -= value; break; }
					default: break;
				}
				break;
			}
		}

		if (facing >= 360) facing -= 360;
		else if (facing < 0) facing += 360;
	}

	printf("Manhattan distance: %d\n-----------\n", (abs(x) + abs(y)));
}

void b(int len) {
	int shipX = 0; int shipY = 0;
	int wpX = 10; int wpY = 1;

	for (int i = 0; i < len; i++) {
		int value = atoi(&input[i][1]);
		switch (input[i][0])
		{
			case 'N': wpY += value; break;
			case 'E': wpX += value; break;
			case 'S': wpY -= value; break;
			case 'W': wpX -= value; break;
			case 'L': {
				float rad = (float)value * (3.14159f / 180.0f);
				float sin = sinf(rad);
				float cos = cosf(rad);
				int x = roundf(wpX * cos - wpY * sin);
				int y = roundf(wpX * sin + wpY * cos);
				wpX = x;
				wpY = y;
				break;
			}
			case 'R': {
				float rad = (float)value * (3.14159f / 180.0f);
				float sin = sinf(-rad);
				float cos = cosf(-rad);
				int x = roundf(wpX * cos - wpY * sin);
				int y = roundf(wpX * sin + wpY * cos);
				wpX = x;
				wpY = y;
				break;
			}
			case 'F': {
				shipX += wpX * value;
				shipY += wpY * value;
				break;
			}
		}
	}

	printf("Manhattan distance: %d\n", (abs(shipX) + abs(shipY)));
}
