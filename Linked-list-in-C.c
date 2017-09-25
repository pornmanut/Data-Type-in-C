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

void InsertFrist(TYPE_NODEPTR *List,TYPE_NODEPTR New){
  New -> next = *List;
  *List = New;
}
void InsertAfter(TYPE_NODEPTR Point,TYPE_NODEPTR New){
  New -> next = Point -> next;
  Point -> next = New;
}
void InsertLast(TYPE_NODEPTR Point,TYPE_NODEPTR New){
  if(Point != NULL){
    while(Point -> next != NULL){
      Point = Point -> next;
    }
    Point -> next = New;
  }else{
    Point = New;
  }
  New -> next = NULL;
}
void FreeNode(TYPE_NODEPTR node){
  free(node);
}

void Print(TYPE_NODEPTR List){
  if(List != NULL){
    //printf("%p:%c\n",List,List -> info);
    while(List -> next){
        printf("%p:%c\n",List,List -> info);
        List = List->next;
    }
    printf("%p:%c\n",List,List -> info);
  }
}

TYPE_NODEPTR DeleteFirst(TYPE_NODEPTR *List){
  
}
int main(){
  TYPE_NODEPTR list = NewNode('A');
  TYPE_NODEPTR add = NewNode('B');
  TYPE_NODEPTR after = NewNode('D');
  TYPE_NODEPTR last = NewNode('Z');
  TYPE_NODEPTR last2 = NewNode('Y');
  TYPE_NODEPTR after2 = NewNode('C');
  InsertFrist(&list,add);
  InsertAfter(add,after);
  InsertLast(list,last);
  InsertLast(list,last2);
  InsertAfter(last,after2);
  Print(list);
  return 0;
}
