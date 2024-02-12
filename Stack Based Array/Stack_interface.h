#ifndef STACK_INTERFACE_H_
#define STACK_INTERFACE_H_

#include "STD_TYPES.h"
/*chose the number of elements u will push in the stack*/
#define MAX_STACK 10

/*chose the data type of elements u will push in the stack*/
typedef int StackEntry;

/*the stack feild*/
typedef struct Stack
{
    StackEntry Local_StackElemnts[MAX_STACK];
    u8 Stack_u8Top;
} Stack;

/*use this function in the begaining to initialize a stack*/
void Stack_CreatStack(Stack *ps);
/*use this function to push an element in ur stack*/
u8 Stack_PushStack(StackEntry Copy_Element, Stack *ps);
/*use this function to pop an element from ur stack */
StackEntry PopStack(Stack *ps);
/*use this function to pop an element from ur stack */
void Stack_PopStack(Stack *ps, StackEntry *pe);
/*use this function to check if ur stack is full or not */
u8 Stack_u8StackFull(Stack *ps);
/*use this function to check if ur stack is empty or not */
u8 Stack_u8StackEmpty(Stack *ps);
/*use this function to get the element which is at the top of ur stack */
void Stack_voidGetStackTop(Stack *ps, StackEntry *pe);
/*use this function to know ur stack size */
u8 Stack_u8StackSize(Stack *ps);
/*use this function to Clear ur stack */
void Stack_voidClearStack(Stack *ps);
/*use this function to display all the elements in the stack with help of a function u have to implemnt it in the main file that just accept a parameter of ur elements data type the do what u want like print the elemnts */
void Stack_voidTraverseStack(Stack *ps, void (*pf)(StackEntry));
// this prototype will be removed because the user who will implement it
void DisplayElements(StackEntry Copy_Elements);

#endif
