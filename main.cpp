#include <stdio.h>
#include <stdlib.h>

struct Element
{
    Element* prev;
    int data;
    Element* next;
};
struct Queue
{
    Element* head = NULL, * tail = NULL;
};
void pusht(Queue& q, int d)
{
    Element* e = (Element*)malloc(sizeof(Element));
    e->data = d;
    e->next = NULL;
    e->prev = q.tail;

    if (q.head == NULL)
    {
        q.tail = e;
        q.head = e;
    }

    else
    {
        q.tail->next = e;
        q.tail = e;
    }
}
void pushh(Queue& q, int d)
{
    Element* e = (Element*)malloc(sizeof(Element));
    e->data = d;
    e->next = q.head;
    e->prev = NULL;

    if (q.tail == NULL)
    {
        q.tail = e;
        q.head = e;
    }

    else
    {
        q.head->prev = e;
        q.head = e;
    }
}
void pullh(Queue& q)
{
    if (q.head == q.tail)
    {
        q.tail = NULL;
    }

    Element* e = q.head;
    q.head = q.head->next;
    q.head->prev = NULL;
    free(e);
}
void pullt(Queue& q)
{
    if (q.head == q.tail)
    {
        q.tail = NULL;
    }

    Element* e = q.tail;
    q.head = q.head->next;
    q.head->prev = NULL;
    free(e);
}
void printh(Queue& q)
{
    for (Element* cur = q.head; cur != NULL; cur = cur->next)
    {
        printf("%4i", cur->data);
    }
    printf("\n");
}
void printt(Queue& q)
{
    for (Element* cur = q.tail; cur != NULL; cur = cur->prev)
    {
        printf("%4i", cur->data);
    }
    printf("\n");
}
int count(Queue& q)
{
    int a = 0;
    for (Element* cur = q.head; cur != NULL; cur = cur->next)
    {
        a++;
    }
    return a;
}
Element* find(Queue& q, int n)
{
    Element* cur = NULL;
    for (cur = q.head; cur != NULL; cur = cur->next)
    {
        if (cur->data == n)
        {
            return cur;
        }
    }
}
void kill(Queue& q, Element* dead)
{
    if (q.tail == q.head)
    {
        q.tail->data = NULL;
    }

    else if (q.head == dead)
    {
        Element* e = q.head;
        q.head = q.head->next;
        free(e);
    }

    for (Element* cur = q.head; cur != NULL; cur = cur->next)
    {
        if ((cur->next) == dead)
        {
            dead->data = 0;
            cur->next = dead->next;
            free(dead);
        }
    }
}
int hashCode(char* cityName, int hashSize) {
    int hash = 0;
    for (char* cur = cityName; *cur!='\0'; *cur++) {
        hash+=int(*cur);
    }
    hash = hash%hashSize;
    return hash;
}

int main() {
    int hashSize = 17;
    char cityName[30];
    for (int i = 0; i < 5; i++) {
        printf("Input city name: ");
        scanf("%s", cityName);
        int res = hashCode(cityName, hashSize);
        printf("%d\n", res);
    }
    Element* hashTable;
    hashTable = (Element*)malloc(hashSize * sizeof(Element*));
    
    free(hashTable);


}
