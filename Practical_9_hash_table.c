#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

struct Node {
    int key;
    struct Node* next;
};

struct HashTableChaining {
    struct Node* table[TABLE_SIZE];
};

void initChaining(struct HashTableChaining* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

void insertChaining(struct HashTableChaining* ht, int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int searchChaining(struct HashTableChaining* ht, int key) {
    int index = hashFunction(key);
    struct Node* current = ht->table[index];
    while (current) {
        if (current->key == key) return 1;
        current = current->next;
    }
    return 0;
}

void displayChaining(struct HashTableChaining* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* current = ht->table[i];
        while (current) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

struct HashTableOpenAddressing {
    int table[TABLE_SIZE];
    int occupied[TABLE_SIZE];
};

void initOpenAddressing(struct HashTableOpenAddressing* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->occupied[i] = 0;
    }
}

void insertOpenAddressing(struct HashTableOpenAddressing* ht, int key) {
    int index = hashFunction(key);
    while (ht->occupied[index]) {
        index = (index + 1) % TABLE_SIZE;
    }
    ht->table[index] = key;
    ht->occupied[index] = 1;
}

int searchOpenAddressing(struct HashTableOpenAddressing* ht, int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (ht->occupied[index]) {
        if (ht->table[index] == key) return 1;
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;
    }
    return 0;
}

void displayOpenAddressing(struct HashTableOpenAddressing* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->occupied[i]) {
            printf("[%d]: %d\n", i, ht->table[i]);
        } else {
            printf("[%d]: EMPTY\n", i);
        }
    }
}


int main() {
    
    struct HashTableChaining hashTableChaining;
    initChaining(&hashTableChaining);
    insertChaining(&hashTableChaining, 15);
    insertChaining(&hashTableChaining, 25);
    insertChaining(&hashTableChaining, 35);
    insertChaining(&hashTableChaining, 5);

    printf("Chaining Method Hash Table:\n");
    displayChaining(&hashTableChaining);

   
    printf("Searching for key 25: %s\n", searchChaining(&hashTableChaining, 25) ? "Found" : "Not Found");

    struct HashTableOpenAddressing hashTableOpenAddressing;
    initOpenAddressing(&hashTableOpenAddressing);
    insertOpenAddressing(&hashTableOpenAddressing, 15);
    insertOpenAddressing(&hashTableOpenAddressing, 25);
    insertOpenAddressing(&hashTableOpenAddressing, 35);
    insertOpenAddressing(&hashTableOpenAddressing, 5);

    printf("\nOpen Addressing Hash Table:\n");
    displayOpenAddressing(&hashTableOpenAddressing);

    printf("Searching for key 25: %s\n", searchOpenAddressing(&hashTableOpenAddressing, 25) ? "Found" : "Not Found");

    return 0;
}
