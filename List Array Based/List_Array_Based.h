/*********************************************************/
/*********************************************************/
/******************  List_Array_Based   ******************/
/******************  Autor : moHmd Ali  ******************/
/******************  Version : 1.00     ******************/
/*********************************************************/
/*********************************************************/

#ifndef LIST_ARRAY_BASED_H_
#define LIST_ARRAY_BASED_H_

#include "STD_TYPES.h"
/* choose the List size*/
#define MAX_LIST 100

/* choose the elemnts type that will be stored in the list*/
typedef u8 ListEntry;

typedef struct
{
    ListEntry Entry[MAX_LIST];
    u16 Size;

} List;

void List_Init(List *pl);

u8 List_Empty(List *pl);

u8 List_Full(List *pl);

u16 List_Size(List *pl);

void List_Destroy(List *pl);

void List_Insert(u16 Pos, ListEntry Elemnt, List *pl);

void list_Delete(u16 Pos, ListEntry *PtrElement, List *pl);

void List_Retrieve(u16 Pos, ListEntry *PtrElement, List *pl);

void List_Replace(u16 Pos, ListEntry Element, List *pl);

void List_Traverse(List *pl, void (*pf)(ListEntry));

#endif