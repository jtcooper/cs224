#include <stdio.h>
#include <limits.h>
 
int has_one_bit(int input)
{
  return input && 1;
}
 
int has_zero_bit(int input)
{
  return has_one_bit(~input);
}
 
int has_zero_bit_B(int input)
{
  return (input + 1) && 1;
}
 
int has_one_bit_last_byte(int input)
{
  return has_one_bit(input & 0x000000FF);
}
 
// NEED WORD SIZE
int has_zero_bit_first_two_bytes(int input)
{
  return has_one_bit(~input & 0xFF000000);
}
 
int main()
{
 
  printf("has_one_bit:");
 
  int output = has_one_bit(55);
  printf("55 && 1 is %d\n", output);
 
  output = has_one_bit(-1);
  printf("-1 && 1 is %d\n", output);
 
  output = has_one_bit(0);
  printf("0 && 1 is %d\n", output);
 
  printf("has_zero_bit:\n");
 
  int test = 0;
  output = has_zero_bit(test);
  printf("%d && 1 is %d\n", test, output);
 
  test = 8;
  output = has_zero_bit(test);
  printf("%d && 1 is %d\n", test, output);
 
  test = -1;
  output = has_zero_bit(test);
  printf("%d is %d\n", test, output);
 
  printf("has_zero_bit_B:\n");
  test = -1;
  output = has_zero_bit_B(test);
  printf("%d is %d\n", test, output);
 
  test = 0;
  output = has_zero_bit_B(test);
  printf("%d is %d\n", test, output);
 
  test = 555;
  output = has_zero_bit_B(test);
  printf("%d is %d\n", test, output);
 
  test = -412;
  output = has_zero_bit_B(test);
  printf("%d is %d\n", test, output);
 
  // x & 0x000000FF
  // 0000 0000 0000 0000 1111 0101 0011 0010
  // 0000 0000 0000 0000 0000 0000 1111 1111
  // ---
  // 0000 0000 0000 0000 0000 0000 0011 0010
  // has_one_bit()
  //
  //
  printf("has_one_bit_last_byte:\n");
  test = 1;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = 15;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = 256;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = 512;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = 512 + 256;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = -256;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  test = -255;
  output = has_one_bit_last_byte(test);
  printf("%d is %d\n", test, output);
 
  // x & 0xFF000000
  // 0000 0000 0000 0000 1111 0101 0011 0010 (negate)
  // 1111 1111 1111 1111 0000 1010 1100 1101
  // ---
  // 1111 1111 0000 0000 0000 0000 0000 0000 (& FF)
  // ---
  //
 
  printf("has_zero_bit_first_two_bytes:\n");
  test = -1;
  output = has_zero_bit_first_two_bytes(test);
  printf("%d is %d\n", test, output);
 
  test = 0;
  output = has_zero_bit_first_two_bytes(test);
  printf("%d is %d\n", test, output);
 
  test = 0x03000000;
  output = has_zero_bit_first_two_bytes(test);
  printf("%d is %d\n", test, output);
 
  test = 0x00100000;
  output = has_zero_bit_first_two_bytes(test);
  printf("%d is %d\n", test, output);
 
  test = 0xFF000000;
  output = has_zero_bit_first_two_bytes(test);
  printf("%d is %d\n", test, output);
 
  return 0;
}
