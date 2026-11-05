#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char *computeOutputFileName(const char *inputName) {
  const char *suffix = ".count";

  if (inputName == NULL) {
    return NULL;
  }

  size_t len = strlen(inputName) + strlen(suffix) + 1;

  char *outname = malloc(len);
  if (outname == NULL) {
    return NULL;
  }

  strcpy(outname, inputName);
  strcat(outname, suffix);

  return outname;
}
