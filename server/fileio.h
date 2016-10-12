#ifndef _fileio_h
#define _fileio_h

struct Stack {
  char *key;
  char *data;
  struct Dictionary *next;
};

struct Stack *read_config(char *file_path);

#endif
