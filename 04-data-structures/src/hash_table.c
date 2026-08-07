#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_table.h"

unsigned int hash(const char *key){
    unsigned int key_value = 0;

    for(const char *p = key; *p != '\0'; p++){
        key_value += *p;
    }

    unsigned int bucket_index = key_value % TABLE_SIZE;

    return bucket_index;
}

HashTable *create_table(void){
    HashTable *new_hash = malloc(sizeof *new_hash); 

    if(!new_hash){
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }

    for(int i = 0; i < TABLE_SIZE; i++){
        new_hash->buckets[i] = NULL;
    }

    return new_hash;
}

// função insert - falta tratar duplicatas com search()

int insert(HashTable *table, const char *key, int value){

    if (strlen(key) >= KEY_SIZE)
    {
        fprintf(stderr, "key must contain at most 24 characters\n");
        return 0;
    }

    unsigned int bucket_index = hash(key);

    Entry *new_entry = malloc(sizeof *new_entry);

    if(!new_entry){
        fprintf(stderr, "Error allocating memory.\n");
        return 0;
    }

    strcpy(new_entry->key, key);
    new_entry->value = value;

    new_entry->next = table->buckets[bucket_index];
    table->buckets[bucket_index] = new_entry;

    return 1;

}

Entry *search(HashTable *table, const char *key){

}

int remove_entry(HashTable *table, const char *key){

}

void print_table(const HashTable *table){

}

void destroy_table(HashTable *table){

}