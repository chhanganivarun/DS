#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

void list_insert(int x){
    struct Node *temp;
    temp = new struct Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print_list(){
    struct Node* current;
    current = head;
    while(current != NULL){
        printf("%d",current->data);
        printf(" ");
        current = current->next;
    }
    printf("\n");
}

void delete_value(int value){
    struct Node* current;
    struct Node* previous;
    current = head;
    previous = head;
    if (head->data == value){
        head = head->next;
    }
    else{
        while(current != NULL){
            if(current->data == value){
                previous->next = current->next;
                break;
            
            }
            previous = current;
            current = current->next;
        }
    }
    return;
}
int main() {
    head = NULL;
    int number_to_be_inserted,n;
    scanf("%d",&n);
    
    while(n--){
        scanf("%d",&number_to_be_inserted);
        list_insert(number_to_be_inserted);
    }
    print_list();
    int value;
    scanf("%d",&value);
    delete_value(value);
    print_list();
    return 0;
}