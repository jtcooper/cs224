#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_short(short x) {
	show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x) {
	show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
	show_bytes((byte_pointer) &x, sizeof(double));
}

int main (void) {
	show_short(44);
	show_short(-2);
	show_short(2346);
	printf("\n");
	show_long(44);
	show_long(-2443);
	show_long(4555950493402);
	printf("\n");
	show_double(4.3);
	show_double(0.0);
	show_double(-422.50234);
	printf("\n");
	return 0;
}
