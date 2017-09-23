#include <stdio.h>

typedef unsigned char *byte_pointer;

int get_endian(byte_pointer x) {
	return (x[0] && 1);
}

int is_little_endian(void) {
	int x = 1;
	return get_endian((byte_pointer) &x);
}

int main (void) {
	printf("%d\n", is_little_endian());
	return 0;
}
