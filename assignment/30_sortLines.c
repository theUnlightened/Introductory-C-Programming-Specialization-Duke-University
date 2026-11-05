#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int stringOrder(const void *vp1, const void *vp2) {
  const char *const *p1 = vp1;
  const char *const *p2 = vp2;
  return strcmp(*p1, *p2);
}

void sortData(char **data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void processFile(FILE *f) {
  char **lines = NULL;
  char *curr = NULL;
  size_t sz = 0;
  size_t i = 0;

  while (getline(&curr, &sz, f) >= 0) {
    char **tmp = realloc(lines, (i + 1) * sizeof(*lines));
    if (!tmp) {
      perror("realloc");
      free(curr);
      for (size_t k = 0; k < i; k++) free(lines[k]);
      free(lines);
      return;
    }
    lines = tmp;
    lines[i] = curr;
    curr = NULL;
    i++;
  }

  free(curr);
  sortData(lines, i)

  for (size_t j = 0; j < i; j++) {
    printf("%s", lines[j]);
    free(lines[j]);
  }
  free(lines);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    processFile(stdin);
  } else {
    for (int i = 1; i < argc; i++) {
      FILE *f = fopen(argv[i], "r");
      if (f == NULL) {
        perror(argv[i]);
        return EXIT_FAILURE;
      }
      processFile(f);
      if (fclose(f) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
      }
    }
  }
  return EXIT_SUCCESS;
}
