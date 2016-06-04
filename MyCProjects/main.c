#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

void printList(struct node *n)
{
    while (n != NULL)
    {
        printf("  %d ", n->data);
        n = n->next;
    }
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter( struct node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("\nThe given previous node can not be balnk");
        return;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}


void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last->next !=NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}


int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    push(&head,100);
    push(&head,20);
    push(&head,30);


    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    insertAfter(head,25);
    insertAfter(head->next->next,40);
    insertAfter(third, 10);

    append(&head,99);
    append(&third,200);

    push(&head,101);

    insertAfter(second,202);
    insertAfter(head->next,1000);

    //printf("Hello world!\n");
    printf("-----------------------------------\n");
    printf("Created Linked List Value is: \n");
    printf("-----------------------------------\n");
    printList(head);

    return 0;
}
