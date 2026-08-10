#include <stdio.h>
#include "hash_table.h"

int main(void)
{

    printf("=== HASH TABLE TESTS ===\n\n");

    HashTable *table = create_table();

    if (table == NULL)
    {
        return 1;
    }

    printf("1. Inserting entries:\n");

    insert(table, "isa", 20);
    insert(table, "alice", 8);
    insert(table, "carlos", 32);
    insert(table, "diana", 25);

    print_table(table);

    printf("2. Testing collision:\n");

    /*
        "abc" and "cba" have the same character sum,
        so our simple hash function sends them
        to the same bucket.
    */

    insert(table, "abc", 100);
    insert(table, "cba", 200);

    printf("Hash of abc: %u\n", hash("abc"));
    printf("Hash of cba: %u\n\n", hash("cba"));

    print_table(table);

    printf("3. Searching for existing key:\n");

    Entry *found = search(table, "alice");

    if (found != NULL)
    {
        printf("Found: %s -> %d\n\n", found->key, found->value);
    }
    else
    {
        printf("Key not found.\n\n");
    }

    printf("4. Searching for nonexistent key:\n");

    found = search(table, "bruno");

    if (found != NULL)
    {
        printf("Found: %s -> %d\n\n", found->key, found->value);
    }
    else
    {
        printf("Bruno was not found.\n\n");
    }

    printf("5. Testing duplicate key:\n");

    printf("Before update:\n");

    found = search(table, "isa");

    if (found != NULL)
    {
        printf("isa -> %d\n", found->value);
    }

    insert(table, "isa", 99);

    printf("After update:\n");

    found = search(table, "isa");

    if (found != NULL)
    {
        printf("isa -> %d\n\n", found->value);
    }

    printf("6. Removing collision entry (head):\n");

    remove_entry(table, "cba");

    print_table(table);

    printf("7. Removing remaining collision entry:\n");

    remove_entry(table, "abc");

    print_table(table);

    printf("8. Removing nonexistent key:\n");

    if (remove_entry(table, "bruno"))
    {
        printf("Bruno removed.\n\n");
    }
    else
    {
        printf("Bruno was not found.\n\n");
    }

    printf("9. Removing normal entry:\n");

    remove_entry(table, "alice");

    print_table(table);

    printf("10. Destroying hash table:\n");

    destroy_table(table);

    printf("Hash table successfully destroyed.\n");

    return 0;
}