#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	printf("%x", start[0]);
	printf("\n");
	if (start[0] && 1) {
		printf("little endian");
	}
	else {
		printf("big endian");
	}
	printf("\n");
}

int show_short(short x) {
	return show_bytes((byte_pointer) &x, sizeof(short));
}

int main (void) {
	return show_short(1);
}
