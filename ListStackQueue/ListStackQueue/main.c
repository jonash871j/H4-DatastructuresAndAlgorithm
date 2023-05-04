#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;


node_t* InsertNext(node_t* node, int value)
{
    node_t* currentNodeValue = node->next;
    node->next = (node_t*)malloc(sizeof(node_t));
    node->next->val = value;
    node->next->next = currentNodeValue;
    return node->next;
}

void RemoveNext(node_t* node)
{
    if (node->next == NULL)
    {
        return;
    }
    node_t* nextNextValue = node->next->next;
    free(node->next);
    node->next = nextNextValue;
}

node_t* SearchNode(node_t* head, int index)
{
    node_t* currentNode = head;
    for (int i = 0; currentNode != NULL; i++)
    {
        if (i == index)
        {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

void PrintList(node_t* node)
{
    while (node != NULL) {
        printf("%i, ", node->val);
        node = node->next;
    }
    printf("\n");
}

void main()
{
    node_t head = { 1, NULL };

    node_t* nextItem = &head;
    for (int i = 0; i < 10; i++)
    {
        nextItem = InsertNext(nextItem, rand() % 255);
    }

    PrintList(&head);
    RemoveNext(&head);
    PrintList(&head);
    RemoveNext(head.next);
    PrintList(&head);

    node_t* searchedNode = SearchNode(&head, 5);
    printf("The value of index 5 is %i", searchedNode->val);
}