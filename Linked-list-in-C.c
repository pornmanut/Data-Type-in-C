#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  char info;
  struct Node *next;
}TYPE_NODE;

typedef struct Node *TYPE_NODEPTR;

TYPE_NODEPTR NewNode(char Item){
  TYPE_NODEPTR node;
  node = (TYPE_NODEPTR) malloc(sizeof(TYPE_NODE));
  node -> info = Item;
  node -> next = NULL;
  return(node);
}

void FreeNode(TYPE_NODEPTR node){
  free(node);
}

int main(){
  printf("%lu\n",sizeof(TYPE_NODE));
  return 0;
}
