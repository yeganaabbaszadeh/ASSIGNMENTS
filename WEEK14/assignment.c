#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 256 


typedef struct Node{
    int data;
    struct Node* next;
    bool swapped;
}node_t;


void append(node_t **head_ref, int new_data){ 
    
    node_t *new_node = (node_t *) malloc(sizeof(node_t)); 
    node_t *last = *head_ref;
    new_node->swapped = false;
    new_node->data = new_data; 
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL)
        last = last->next;
    
    last->next = new_node;
}


void printNumList(node_t *node){
    
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


void swapNodes(node_t **head, int swap_data){
    
    node_t *first = *head;
    node_t *former = NULL;
    while(first && first->data != swap_data){
        former = first;
        first = first->next;
    }

    node_t *second = first->next;
    node_t *latter = first;

    if(first == NULL || first->swapped == true || second == NULL || second->swapped == true){
        printf("No swap candidates found. Try again: \n");
        return;
    }

    if(former != NULL){
        former->next = second;
    }else{
        *head = second;
    }

    if(latter != NULL){
        latter->next = first;
    }else{
        *head = first;
    }

    node_t *temp = second->next;
    second->next = first->next;
    first->next = temp;

    first->swapped = true;
    second->swapped = true;

    printf("Result: ");
    printNumList(*head);
}


int main(){
    
    char input[MAXSIZE];
    int new_data, swap_data;
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head = NULL;
    bool quit = false;

    printf("Enter numbers to add to your list:\n");


    while(!quit){
        scanf("%s", input);
        if(strcmp(input, "DONE") == false){
            break;
        }else{
            append(&head, atoi(input));
        }
    }

    printf("Type two numbers to swap them around:\n");
    while(!quit){
        scanf("%s", input);
        if(strcmp(input, "DONE") == false){
            quit = true;
        }else{
            swapNodes(&head, atoi(input));
        }
    }

    return 0;
}