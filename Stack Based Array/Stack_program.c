#include "Stack_interface.h"
#include "STD_TYPES.h"
#include <stdio.h>

void Stack_CreatStack(Stack *ps)
{
    ps->Stack_u8Top = 0;
}

u8 Stack_PushStack(StackEntry Copy_Element, Stack *ps)
{

    u8 Local_u8StackIsFull = 0;

    if (ps->Stack_u8Top == MAX_STACK)
    {
        Local_u8StackIsFull = 1;
    }
    else
    {
        ps->Local_StackElemnts[ps->Stack_u8Top++] = Copy_Element;
    }
    return Local_u8StackIsFull;
}

StackEntry PopStack(Stack *ps)
{
    u8 Local_u8StackIsFull = 0;
    if (ps->Stack_u8Top == -1)
    {
        Local_u8StackIsFull = 1;
        return Local_u8StackIsFull;
    }
    else
    {
        return ps->Local_StackElemnts[ps->Stack_u8Top];
    }
}

// another implementation of pop function
void Stack_PopStack(Stack *ps, StackEntry *pe)
{
    ps->Stack_u8Top--;
    *pe = ps->Local_StackElemnts[ps->Stack_u8Top];
}

u8 Stack_u8StackFull(Stack *ps)
{
    if (ps->Stack_u8Top == MAX_STACK)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

u8 Stack_u8StackEmpty(Stack *ps)
{
    return !ps->Stack_u8Top;

    /*we have two modes if the top = 0 OR any number else
    if the top =0 so => the return will be TRUE & then the stack is empty
    else the top has any vaule > 0 then it will retun 1 then the stack is not empty and the user will pop the element
    */
}

void Stack_voidGetStackTop(Stack *ps, StackEntry *pe)
{

    *pe = ps->Local_StackElemnts[ps->Stack_u8Top - 1];
}

u8 Stack_u8StackSize(Stack *ps)
{
    return ps->Stack_u8Top;
}

void Stack_voidClearStack(Stack *ps)
{
    ps->Stack_u8Top = 0;
}

void Stack_voidTraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    u32 Local_u32Iterator = ps->Stack_u8Top;
    for (Local_u32Iterator; Local_u32Iterator > 0; Local_u32Iterator--)
    {
        (*pf)(ps->Local_StackElemnts[Local_u32Iterator - 1]);
    }
}

void main(void)
{
    Stack s;
    StackEntry x = 16, y;
    Stack_CreatStack(&s);
    Stack_PushStack(x, &s);
    Stack_PopStack(&s, &y);
    printf("%d", y);
}

void DisplayElements(StackEntry Copy_Elements)
{
    printf("%d\n", Copy_Elements);
}