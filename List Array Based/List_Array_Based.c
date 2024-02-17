/*********************************************************/
/*********************************************************/
/******************  List_Array_Based   ******************/
/******************  Autor : moHmd Ali  ******************/
/******************  Version : 1.00     ******************/
/*********************************************************/
/*********************************************************/

#include "List_Array_Based.h"

void List_Init(List *pl)
{
    pl->Size = 0;
}

u8 List_Empty(List *pl)
{
    return !pl->Size;
}

u8 List_Full(List *pl)
{
    return pl->Size == MAX_LIST;
}

u16 List_Size(List *pl)
{
    return pl->Size;
}

void List_Destroy(List *pl)
{
    pl->Size = 0;
}

void List_Insert(u16 Pos, ListEntry Elemnt, List *pl)
{
    u16 List_Iterator;
    if (pl->Size > 0)
    {
        for (List_Iterator = pl->Size - 1; List_Iterator >= Pos; List_Iterator--)
        {
            pl->Entry[List_Iterator + 1] = pl->Entry[List_Iterator];
        }
        pl->Entry[Pos] = Elemnt;
        pl->Size++;
    }

    else if (pl->Size == 0)
    {
        pl->Entry[Pos] = Elemnt;
        pl->Size++;
    }
}

void list_Delete(u16 Pos, ListEntry *PtrElement, List *pl)
{
    u16 List_Iterator;
    *PtrElement = pl->Entry[Pos];
    for (List_Iterator = Pos + 1; List_Iterator <= pl->Size - 1; List_Iterator++)
    {
        pl->Entry[List_Iterator - 1] = pl->Entry[List_Iterator];
    }
    pl->Size--;
}

void List_Retrieve(u16 Pos, ListEntry *PtrElement, List *pl)
{
    *PtrElement = pl->Entry[Pos];
}

void List_Replace(u16 Pos, ListEntry Element, List *pl)
{
    pl->Entry[Pos] = Element;
}

void List_Traverse(List *pl, void (*pf)(ListEntry))
{
    u16 List_Iterator;
    for (List_Iterator = 0; List_Iterator <= pl->Size - 1; List_Iterator++)
    {
        (*pf)(pl->Entry[List_Iterator]);
    }
}
