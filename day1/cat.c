#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // exit with 1 if argc is less than 2
  if (argc < 2) {
    fprintf(stderr, "Usage: %s FILE1 ... FILEN\n", argv[0]);
    return 1;
  }

  int allocMaxSize = 1024;
  int currentSize = 0;
  char *buffer = malloc(allocMaxSize);
  for (int i = 1; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "Cannot open file: %s\n", argv[i]);
      return 1;
    }

    // read the file, put the content into buffer
    char c;
    while ((c = fgetc(fp)) != EOF) {
      if (currentSize == allocMaxSize) {
        allocMaxSize *= 2;
        buffer = realloc(buffer, allocMaxSize);
      }
      buffer[currentSize++] = c;
    }
  }

  // print the content of buffer
  for (int i = 0; i < currentSize; i++) {
    printf("%c", buffer[i]);
  }

  return 0;
}
