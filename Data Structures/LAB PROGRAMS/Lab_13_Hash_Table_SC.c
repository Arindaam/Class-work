#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int element;
	struct node* link;
}Node;

typedef struct
{
    /*int *table;*/
    Node** table;
    int size;
} HashTable;

// Create a hash table of the required size
HashTable *create_table(int size);

// Search for an element in the hash table
// Return 1 if the element is present in the table
// Return 0 otherwise
int search(HashTable *htable, int element);

// Insert the element into the hash table
void insert(HashTable *htable, int element);

// Delete the element from the hash table if present
void delete (HashTable *htable, int element);

// Display all the hash table elements
void display_table(HashTable *htable);

// Destroy the hash table
void destroy_table(HashTable *htable);

int main()
{
    int size, choice, loop = 1;
    int element, find;
    scanf("%d", &size);
    HashTable *htable = create_table(size);
    while (loop)
    {
	scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Insert element
            scanf("%d", &element);
            insert(htable, element);
            break;

       /* case 2:
            // Delete element
            scanf("%d", &element);
            delete (htable, element);
            break;
	*/
        case 3:
            // Search element
            scanf("%d", &element);
            find = search(htable, element);
            if (find)
                printf("YES\n");
            else
                printf("NO\n");
            break;
	/*
        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;
	*/
        default:
            // Destroy tree and exit the loop
            destroy_table(htable);
            loop = 0;
            break;
        }
    }
}

HashTable *create_table(int size)
{
    HashTable* hashtable = (HashTable*)malloc(sizeof(HashTable));
    hashtable->size = size;
    //hashtable->table = (int*)malloc(sizeof(int)*size);
    hashtable->table = (Node**)malloc(sizeof(Node*)*size);
    for(int i=0;i<size;i++){
        //hashtable->table[i]=-1;
	hashtable->table[i]=NULL;	
    }
    return hashtable;
}

void insert(HashTable *htable, int element)
{
    /*int count = 0;
    int index = element%htable->size;
    while(htable->table[index] > -1 && count < htable->size){
        index = (index+1)%htable->size;
        count++;
    }
    if(count == htable->size)
        return;
    htable->table[index] = element;
    */
    int index=element%htable->size;
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->element=element;
    temp->link=htable->table[index];
    htable->table[index]=temp;
}

int search(HashTable *htable, int element)
{
    /*
    int count = 0;
    int index = element%htable->size;
    for(int i=index;i<htable->size;i=(i+1)%htable->size){
        if(htable->table[i] == element){
            return 1;
        }
        if(count == htable->size)
            return 0;
        count++;
    }
    return 0;
    */
    int index=element%htable->size;
    Node* temp=htable->table[index];
    while(temp!=NULL && temp->element!=element){
	temp=temp->link;
    }
    if(temp==NULL){
	return 0;
    }
    return(1);
}
/*
void delete (HashTable *htable, int element)
{
    int count = 0;
    int index = element%htable->size;
    for(int i=index;i<htable->size;i=(i+1)%htable->size){
        if(htable->table[i]==element){
            htable->table[i]=-1;
            return;
        }
        if(count == htable->size)
            return;
        count++;
       
    }
}

void display_table(HashTable *htable)
{
    for(int i=0;i<htable->size;i++){
        printf("%d ",htable->table[i]);
    }
    printf("\n");
}
*/

void destroy_table(HashTable *htable)
{
}
