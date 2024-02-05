#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE (2 * 1024 * 1024) // 2MB

struct Node
{
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
    int size;
};

struct LinkedList *createLinkedList()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (list == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void enqueue(struct LinkedList *list, int data)
{
    int nodeSize = sizeof(struct Node) + sizeof(int); // Size of Node + int data
    if (nodeSize > MAX_MEMORY_SIZE)
    {
        printf("Data size exceeds maximum node size\n");
        return;
    }

    if (list->size == 0)
    {
        list->head = (struct Node *)malloc(nodeSize);
        if (list->head == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        list->head->data = data;
        list->head->next = NULL;
        list->tail = list->head;
        list->size++;
    }
    else if (list->size < MAX_MEMORY_SIZE)
    {
        struct Node *newNode = (struct Node *)malloc(nodeSize);
        if (newNode == NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        newNode->data = data;
        newNode->next = NULL;
        list->tail->next = newNode;
        list->tail = newNode;
        list->size++;
    }
    else
    {
        list->head->data = data;
        list->tail = list->head;
        list->head = list->head->next;
        // if (list->head->next)
        // {
        //     list->head = list->head->next;
        //     list->tail = list->tail->next ? list->tail->next : list->tail;
        // }
        // list->head->data = data;
    }
}

void read(struct LinkedList *list)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int main()
{
    struct LinkedList *list = createLinkedList();

    for (int i = 1; i <= MAX_MEMORY_SIZE; ++i)
    {
        enqueue(list, i);
    }
    printf("\n");

    read(list);
    free(list);
    return 0;
}