/*
  fileio.c
  This file is used for basic input and output to files including the
  server.conf (configuration) file.
  Author:        Brian Garrison
  Date-Started:  10/12/2016
  Date-Finished:
  Modifications:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"


/*
  read_config
  A function for reading a GNU-styled configuration file and saving it to a
  stack indexed by a string key for later use.
  Parameters:
    char *file_path (the file path of the configuration file)
  Returns:
    An array of "Stack" structures that have a char* key.
*/

struct Stack *read_config(char *file_path) {
  // Function variables
  FILE *file;
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t line_size;
  struct Stack *return_stack = NULL;

  // Open the file and print and error and return NULL if not valid
  file = fopen(file_path, "r");
  if(file == NULL) {
    printf("The file_path specified was an incorrect file.\n");
    return(NULL);
  } else {
    // The file was found so now we get each individual line of the file so long
    // as the line exists (isn't -1)
    while((line_size = getline(&line, &buffer_size, file)) != -1) {
      // Checks if there is a comment delimiter in the line
      char *comment = strchr(line, '#');
      if(comment != NULL) {
        // Get the index of the comment character
        int index = comment - line;
        line[index] = 0;
      }
      if (line_size != 0) {
        printf("%s", line);
      }
    }
  }
  // Attempts to close the file if it still exists, if it doesn't return null and
  // print an error.
  if(fclose(file) != 0) {
    printf("The file configuration file is no longer available. Was it moved?\n");
    return(NULL);
  }
  return(return_stack);
}
