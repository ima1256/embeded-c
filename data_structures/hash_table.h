#ifdef HASH_TABLE_H
#define HASH_TABLE_H

#define HASH_SIZE 1024

typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    int size;
    HashNode **buckets;
} HashTable;

// funciones públicas
HashTable* createHashTable(int size);
void insertHash(HashTable *table, int key, int value);
int searchHash(HashTable *table, int key);
void freeHashTable(HashTable *table);

#endif