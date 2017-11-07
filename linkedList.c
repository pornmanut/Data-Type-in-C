#include <stdio.h>
#include <malloc.h>

typedef struct _node{
    int data;
    struct _node* next;
}node;

typedef void (*callback)(node* data);


node* create(int data,node* next){
    node* n = (node*)malloc(sizeof(node));
    if(n == NULL){
        printf("Error createing a new node.\n");
    }
    n->data = data;
    n->next = next;

    return n;
}
int count(node *head){
    node* cursor = head;
    int c = 0;
    while(cursor != NULL){
        c++;
        cursor = cursor->next;
    }
    return c;
}
node* prepend(node* head,int data){
    node* n = create(data,head);
    head = n;
    return head;
}
node* append(node* head,int data){
    node* cursor = head;
    while(cursor-> next != NULL){
        cursor = cursor->next;
    }

    node* new_node = create(data,NULL);
    cursor->next = new_node;
    return head;
}
void traverse(node* head,callback f){
    node* cursor = head;
    while(cursor != NULL){
        f(cursor);
        cursor = cursor-> next;
    }
}

void display (node* n){
    if(n != NULL) printf("%d ",n->data);
}

int main(){
    node* head = NULL;
    callback disp = display;

    int num = 0;
    num = count(head);
    head = prepend(head,5);
    head = prepend(head,6);
    head = append(head,3);
    head = prepend(head,1);
    printf("Count: %d\n",num);
    traverse(head,disp);
    return 0;
}
