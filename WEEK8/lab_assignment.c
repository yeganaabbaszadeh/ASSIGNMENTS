#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    char name[256];
    struct Node *next;
}node_t;

void addtoqueue(node_t **start, char *key){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    node_t *last = *start;
    strcpy(new_node->name, key);
    new_node->next = NULL;

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void print_queue(node_t *node){
    printf("Queue: ");
    while(node != NULL){
        printf("%s ", node->name);
        node = node->next;
    }
    printf("\n");
}

void lucky_customer(node_t **start, char *key){
    node_t *temp = *start;
    node_t *prev;

    if(temp != NULL && strcmp(temp->name, key) == 0)
        *start = temp->next;
    else{
        while (temp != NULL && strcmp(temp->name, key) != 0){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("There is no such a customer in the queue.\n");
            return;
        }
        prev->next = temp->next;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    node_t *last = *start;
    strcpy(new_node->name, temp->name);
    new_node->next = NULL;

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    free(temp);
    temp = NULL;
}

void admit_customer(node_t **start){
    if (*start == NULL){
        printf("There is no one left in the queue.\n");
        return;
    }

    node_t *next_node = (*start)->next;
    printf("%s was admitted.\n", (*start)->name);

    free(*start);
    *start = next_node;
}

void remove_name(node_t **start){
    node_t *current = *start, *next;

    while (current != NULL){
        next = current -> next;
        free(current);
        current = next;
    }

    *start = NULL;
}

int main(){

    char input[256];
    bool quit = 0;
    node_t *head = (node_t *)malloc(sizeof(node_t));

    strcpy(head->name, "Customer001");
    head->next = NULL;

    addtoqueue(&head, "Customer002");
    addtoqueue(&head, "Customer003");
    addtoqueue(&head, "Customer004");
    addtoqueue(&head, "Customer005");

    print_queue(head);

    while(!quit){
        printf("Enter a command: ");
        scanf("%s", input);

        if(strcmp(input, "quit") == 0)
            quit = 1;
        else if(strcmp(input, "admit") == 0)
            admit_customer(&head);
        else
            lucky_customer(&head, input);
        print_queue(head);
    }

    remove_name(&head);

    return 0;
}
