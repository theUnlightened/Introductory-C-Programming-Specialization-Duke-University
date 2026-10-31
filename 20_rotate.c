#include <stdio.h>
#include <stdlib.h>

void rotate(char matrix[10][10]) {
  int layer = 0;
  char temp1;
  char temp2;
  char temp3;
  while (layer <= 10/2) {
    for (int i = layer; i < 10 - 1 - layer; i++) {
      temp1 = matrix[i][10-1-layer];
      temp2 = matrix[10-1-layer][10-1-i];
      temp3 = matrix[10-1-i][layer];

      matrix[i][10-1-layer] = matrix[layer][i];
      matrix[10-1-layer][10-1-i] = temp1;
      matrix[10-1-i][layer] = temp2;
      matrix[layer][i] = temp3;
    }
    layer++;
  }  
}
