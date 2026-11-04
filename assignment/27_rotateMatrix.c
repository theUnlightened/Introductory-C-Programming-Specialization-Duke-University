#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: rotateMatrix inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
      fprintf(stderr, "Could not open file\n");
      return EXIT_FAILURE;
    }
  
  char* matrix[10][10];

}
