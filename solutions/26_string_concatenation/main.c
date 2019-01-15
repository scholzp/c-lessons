#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* This tells the programm how much memory should by allocated.
* A higher value means more memory is allocated, which could be wasted, if
* it's not used. A low number means, that the system needs to reallocate more
* often ~~> lower performance
*/
#define INPUT_ALLOC_SIZE 14

//linked List object which holds start and end and stores the total size in bytes
struct stringList{
  struct stringNode *first;
  struct stringNode *last;
  size_t totalBytes;
};

//linked list elements
struct stringNode{
  char *string;
  struct stringNode *next;
  struct stringNode *prev;
};

//fuction to add a string to the list
void appEnd(struct stringList *list, char * string) {
  //allocate memory for a new object
  struct stringNode *newNode = calloc(1, sizeof(*list->last->next));
  //set the pointer to the string
  newNode->string = string;
  newNode->next = NULL;
  if(list->first == NULL){
    //if the first node is empty
    list->totalBytes = 1;
    newNode->prev = NULL;
    list->first = newNode;
  }else{
    //else just add
    newNode->prev = list->last;
    list->last->next = newNode;
  }
  list->last = newNode;
  list->totalBytes += strlen(string);
}

//function which iterates through the list and frees the allocated memory
void destroyList(struct stringList *list) {
  if(list->first != NULL){
    struct stringNode *current = list->first;
    struct stringNode *next = NULL;
    while(current->next != NULL){
      next = current->next;
      if(current->string != NULL)
        free(current->string);
      free(current);
      current = next;
    }
    free(current->string);
    free(current);
  }
}

int main(void){
  size_t currentInputSize = INPUT_ALLOC_SIZE;
  struct stringList list = {NULL, NULL};
  char *input = calloc(currentInputSize, sizeof(*input));
  size_t inputIndex = 0;


  while(1) {
    //read input
    input[inputIndex] = fgetc(stdin);
    // printf("Read char %d\n",input[inputIndex] );
    ++inputIndex;
    // check if the string fits in the buffer
    if(inputIndex >= currentInputSize){
      // .. if not resize the input buffer
      currentInputSize += INPUT_ALLOC_SIZE;
      char *reallocated = realloc(input, currentInputSize);
      if(reallocated != NULL) {
        input = reallocated;
      } else {
        printf("ERROR: Could not allocate enough memory for input!\n");
        break;
      }
    }
    //append input to list if linebreak is found
    if(input[inputIndex-1] == '\n'){
      //replace linebreak with '\0'
      input[inputIndex-1] = '\0';
      //check if more than one char was read
      if(inputIndex > 1){
        appEnd(&list, input);
        //create a new input 
        input = calloc(currentInputSize, sizeof(*input));
        inputIndex = 0;
      }else{
        break;
      }
    }
  }

  char *resultString = calloc(list.totalBytes, sizeof(*resultString));
  struct stringNode *current = list.last;
  while (current != NULL) {
    if(current->string != NULL)
      strcat(resultString, current->string);
    current = current->prev;
  }

  printf("Result String:\n%s\n", resultString);
  free(resultString);
  free(input);
  destroyList(&list);
  return EXIT_SUCCESS;
}
