#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person
{
    char Name[MAX_NAME];
    int age;
    struct person *Next;

} person;

unsigned int Hash(char *name)
{
    // Make The return of the hash the summation of all the word char ascii values
    int len = strnlen(name, MAX_NAME);
    int hash_res = 0;
    for (int i = 0; i < len; i++)
    {
        hash_res += name[i];
        hash_res = (hash_res * name[i]) % TABLE_SIZE;
    }
    return hash_res;
}

person *hash_table[TABLE_SIZE];

void init_HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void Print_Table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
            printf("\t%i\t----\n", i);

        else
        {
            printf("\t%i\t", i);
            person *temp = hash_table[i];
            while (temp != NULL)
            {
                printf("%s - ", temp->Name);
                temp = temp->Next;
            }
            printf("\n");
        }
    }
}
//--------------------------------------------------------
bool Insert_Table(person *p)
{
    int idx = Hash(p->Name);
    if (p == NULL)
        return NULL;
    else
        p->Next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

//--------------------------------------------------------

person *hash_table_lookup(char *p)
{

    int idx = Hash(p);
    person *temp = hash_table[idx];
    while (temp != NULL && (strncmp(p, hash_table[idx]->Name, MAX_NAME) != 0))
    {
        temp = temp->Next;
    }
    return temp;
}

//--------------------------------------------------------

person *hash_table_Delete(char *p)
{

    int idx = Hash(p);
    person *temp = hash_table[idx];
    person *prev = NULL;
    while (temp != NULL && (strncmp(p, hash_table[idx]->Name, MAX_NAME) != 0))
    {
        prev = temp;
        temp = temp->Next;
    }
    if (temp == NULL)
        return NULL;
    if (prev == NULL)
    {
        // we need to delete the first node
        hash_table[idx] = temp->Next;
    }
    else
    {
        // the node is somewhere either the head
        prev->Next = temp->Next;
    }
}

//--------------------------------------------------------

void main()
{
    init_HashTable();
    Print_Table();
    printf("\t*******************************************\n");
    person mohamed = {.Name = "mohamed", .age = 20};
    person Ahmed = {.Name = "Ahmed", .age = 44};
    person Sayed = {.Name = "Sayed", .age = 77};
    person Ali = {.Name = "Ali", .age = 40};
    person zaza = {.Name = "zaza", .age = 20};
    person lolo = {.Name = "lolo", .age = 44};
    person bebo = {.Name = "bebo1", .age = 77};
    person grendo = {.Name = "grendo", .age = 40};
    Insert_Table(&Sayed);
    Insert_Table(&mohamed);
    Insert_Table(&Ahmed);
    Insert_Table(&Ali);
    Insert_Table(&zaza);
    Insert_Table(&lolo);
    Insert_Table(&bebo);
    Insert_Table(&grendo);
    Print_Table();
}
