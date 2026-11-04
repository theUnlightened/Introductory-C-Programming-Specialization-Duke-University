#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

size_t max(int * letters, size_t n);
int decrypt(FILE * f);

int main(int argc, char ** argv) {
  
  if (argc != 2) {
    fprintf(stderr,"Usage: breaker inputFileName\n");
    return EXIT_FAILURE;
  }
  
  FILE *f =fopen(argv[1],"r");
  if (f == NULL) {
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  size_t key = decrypt(f);

  if (fclose(f) != 0) {
    perror("Could not close file");
    return EXIT_FAILURE;
  }
  
  printf("%zu\n", key);
  return EXIT_SUCCESS;
}

size_t max(int * letters, size_t n) {
  int maxCount = letters[0];
  int maxElementIndex = 0;

  for (size_t i = 1; i < n; i++) {
    if (letters[i] > maxCount) {
      maxCount = letters[i];
      maxElementIndex = i;
    }
  }
  return maxElementIndex;
}

int decrypt(FILE * f) {
  int c;
  int letters[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      letters[c] = letters[c] + 1;
    }
  }

  size_t maxElement = max(letters, 26);
  int ans = (maxElement - 4 + 26) % 26;
  return ans;
}
