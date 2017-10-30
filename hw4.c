#include <stdio.h>

void bubble_a(long *data, long count) {
  long i, last;
  for (last = count-1; last > 0; last--) {
    for (i = 0; i < last; i++) {
      if (data[i+1] < data[i]) {
	long t = data[i+1];
	data[i+1] = data[i];
	data[i] = t;
      }
    }
  }
}

void printData(long* data, long count) {
  long i;
  for (i = 0; i < count; i++) {
    printf("%ld ", data[i]);
  }
  printf("\n");
  return;
}

void bubble_p(long* data, long count) {
  long i, last;
  long* pos;
  
  for (last = count-1; last > 0; last--) {
    pos = data;
    for (i = 0; i < last; i++) {
      long* nextPos = pos;
      nextPos++;
      if (*nextPos < *pos) {
	long t = *nextPos;
	*nextPos = *pos;
	*pos = t;
      }
      pos++;
    }
  }

  return;
}

// elements are accessed with pointers
/*struct Element {
  long val;
  ele* next;
};*/

/*struct Element* firstEle;
  struct Element* currentEle;
  struct Element* previousEle;
  struct Element* nextEle;

  firstEle = data;
  
  for (last = count-1; last > 0; last--) {
    currentEle = firstEle;
    previousEle = NULL;
    for (i = 0; i < last, i++) {
      nextEle = currentEle->next;
      if (nextEle->val < currentEle->val) {
	struct Element* t = nextEle->next;
	if (previousEle == NULL) {
	  firstEle = nextEle;
	} else {
	  previousEle->next = nextEle;
	}
	nextEle->next = currentEle;
	currentEle->next = t;
      }
      previousEle = previousEle->next;
      currentEle = previousEle->next;
    }
  }*/

int main () {
  long count = 5;
  long data[] = {4, 3, 5, 2, 1};
  bubble_p(data, count);
  printData(data, count);

  return 0;
}
      

