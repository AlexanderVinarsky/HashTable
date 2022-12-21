#include <stdio.h>
#include <stdlib.h>
#include <cstring>

const int MAX_CITY_LENGTH = 30;

struct Element
{
    char data [MAX_CITY_LENGTH];
    Element* next;
};
struct Queue
{
    Element* head = nullptr, *tail = nullptr;
};
void push(Queue& q, char*s)
{
    Element* e = (Element*)malloc(sizeof(Element));
    strcpy(e->data,s);
    e->next = nullptr;

    if (q.head == nullptr)
    {
        q.tail = e;
        q.head = e;
    }
    else {
        q.tail->next = e;
        q.tail = e;
    }
}
int find(Queue &q, char* n)
{
    int counter = 0;
    Element* cur = nullptr;
    for (cur = q.head; cur != nullptr; cur = cur->next)
    {
        counter++;
        if (strcmp(cur->data, n) == 0)
        {
            printf("City was found!\n");
            return counter;
        }
    }
    printf("City wasn't found!\n");
    return counter;
}
int hashCode(char* cityName, int hashSize) {
    int hash = 0;
    for (char* cur = cityName; *cur!='\0'; *cur++) {
        hash+=int(*cur);
    }
    hash = hash%hashSize;
    return hash;
}
double HashTableCoef(Queue* hashTable, int hashSize) {
    double full = 0;
    for (int i = 0; i<hashSize; i++) {
        if (hashTable[i].head != nullptr) {
            full+=1.0;
        }
    }
    return full/hashSize;
}

int main() {
    int hashSize = 17;
    char cityName[30];
    struct Queue hashTable[hashSize];

    FILE * f = fopen(R"(C:\Users\vinar\CLionProjects\HashTable\cities.txt)","r");
    if(!f)
        printf("Error!\n");
    else {
        while (fscanf(f, " %30s", cityName) == 1) {
            push(hashTable[hashCode(cityName, hashSize)], cityName);
        }
    }
    fclose(f);

    printf("Input your city to find: ");
    scanf("%s", cityName);
    int d = find(hashTable[hashCode(cityName, hashSize)], cityName);
    printf("Number of elements: %d\n", d);
    printf("HashTable Coefficient: %.2f", HashTableCoef(hashTable, hashSize));
    return 0;
}

