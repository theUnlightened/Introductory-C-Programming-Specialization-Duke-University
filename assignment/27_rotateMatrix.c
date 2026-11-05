#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 12
  
void rotate(char matrix[10][10]);

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
  
  char matrix[10][10];
  char line[LINE_SIZE];
  int lineNumber = 0;
  while (fgets(line, LINE_SIZE, f) != NULL) {
    if (lineNumber >= 10) {
      fprintf(stderr, "Too many lines!\n");
      return EXIT_FAILURE;
    }
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "Line is too long!\n");
      return EXIT_FAILURE;
    }
    if ((strchr(line, '\n') - line) != 10) {
      fprintf(stderr, "Line is too short!\n");
      return EXIT_FAILURE;
    }
    for (int j = 0; j < 10; j++) {
      if (line[j] == '\n') {
        fprintf(stderr, "Line is too short!\n");
        return EXIT_FAILURE;
      }
      matrix[lineNumber][j] = line[j];
    }
    lineNumber++;
  }

  if (lineNumber != 10) {
    fprintf(stderr, "Not enough number of lines\n");
    return EXIT_FAILURE;
  }

  rotate(matrix);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", matrix[i][j]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}


void rotate(char matrix[10][10]) {
  int layer = 0;
  char temp1;
  char temp2;
  char temp3;

  while (layer <= 10 / 2) {
    for (int i = layer; i < 10 - 1 - layer; i++) {
      temp1 = matrix[i][10 - 1 - layer];
      temp2 = matrix[10 - 1 - layer][10 - 1 - i];
      temp3 = matrix[10 - 1 - i][layer];

      matrix[i][10 - 1 - layer] = matrix[layer][i];
      matrix[10 - 1 - layer][10 - 1 - i] = temp1;
      matrix[10 - 1 - i][layer] = temp2;
      matrix[layer][i] = temp3;
    }
    layer++;
  }
}
