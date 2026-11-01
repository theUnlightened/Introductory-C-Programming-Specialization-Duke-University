#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n == 0){
    return 0;
  }
  size_t longest_streak_length = 1;
  size_t running_streak_length = 1;
  int temp = array[0];

  for (size_t i = 1; i < n; i++) {
    if (array[i] > temp) {
      running_streak_length++;
      if (running_streak_length > longest_streak_length) {
	longest_streak_length = running_streak_length;
      }
    } else {
      running_streak_length = 1;
    }
    temp = array[i];
  }
  return longest_streak_length;

int main(void) {
  if (maxSeq(NULL, 0)) {
    return EXIT_FAILURE;
  }

  int array1[] = {1, 2, 3, 2};
  int array2[] = {2, -3, 5, 6, 8};
  int array3[] = {5};
  int array4[] = {2, 4, 3, 6, 10, 15, -1, 7, 8, 2};
  int array5[] = {-2};
  int array6[] = {2,2,2,3};

  if (maxSeq(array1, 0)) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array1, 4) != 3) {    
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array2, 5) != 4) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array3, 1) != 1) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array4, 10) != 4) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array5, 1) != 1) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }
  if (maxSeq(array6, 4) != 2) {
    printf("not good!\n");
    return EXIT_FAILURE;
  }

  printf("good!\n");
  return EXIT_SUCCESS;
}
