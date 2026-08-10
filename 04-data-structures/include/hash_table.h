#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 255
#define KEY_SIZE 25

typedef struct Entry
{
    char key[KEY_SIZE];
    int value;
    struct Entry *next;
} Entry;

typedef struct HashTable
{
    Entry *buckets[TABLE_SIZE];
}HashTable;

unsigned int hash(const char *key);
HashTable *create_table(void);
Entry *search(HashTable *table, const char *key);
int insert(HashTable *table, const char *key, int value);
int remove_entry(HashTable *table, const char *key);
void print_table(const HashTable *table);
void destroy_table(HashTable *table);

#endif
