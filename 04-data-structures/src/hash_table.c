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

int insert(HashTable *table, const char *key, int value){

    if(!table|| !key){
        fprintf(stderr, "Invalid table or key.\n");
        return 0;
    }

    if (strlen(key) >= KEY_SIZE)
    {
        fprintf(stderr, "key must contain at most 24 characters\n");
        return 0;
    }

    unsigned int bucket_index = hash(key);

    Entry *existing_entry = search(table, key);

    if( existing_entry != NULL){

        existing_entry->value = value;
        
        return 1;
    }

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
    unsigned int bucket_index = hash(key);

    Entry *temp = table->buckets[bucket_index];

    while(temp != NULL && (strcmp(key, temp->key)) != 0){
        temp = temp->next;
    }

    return temp;

}

int remove_entry(HashTable *table, const char *key){

    unsigned int bucket_index = hash(key);

    Entry *head = table->buckets[bucket_index];

    if(head == NULL){
        printf("Bucket is empty.\n");
        return 0;
    }

    if((strcmp(head->key, key)) == 0){
        table->buckets[bucket_index] = head->next;
        
        free(head);

        return 1;
    }

    Entry *previous = head;
    Entry *temp = head->next;
    
    while(temp != NULL && (strcmp(temp->key, key)) != 0 ){
        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        return 0;
    }

    previous->next = temp->next;
    
    free(temp);

    return 1;
}

void print_table(const HashTable *table){

    for(int i = 0; i < TABLE_SIZE; i++){
        const Entry *bucket = table->buckets[i];

        while(bucket != NULL){
            printf("Bucket: %d\nKey: %s\nValue: %d\n\n", i, bucket->key, bucket->value);

            bucket = bucket->next;
        }
    }
}

void destroy_table(HashTable *table){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Entry *bucket = table->buckets[i];

        while (bucket != NULL)
        {
            Entry *temp = bucket->next;

            free(bucket);

            bucket = temp;
        }
    }

    free(table);
}