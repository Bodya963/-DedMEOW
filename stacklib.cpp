#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "stacklib.h"

int stackCtor(struct stack * st, size_t Capacity,const char * Name = NULL)
{
    st ->arr = (int*)calloc( Capacity, sizeof(int));
    st ->size = 0;
    st ->capacity = Capacity;

    if ( Name == NULL)
        strcpy( st ->name, "");
    else
        strcpy( st ->name, Name);

    if ( st == NULL)
        return ERR;

    return 0;
}

int stackPush(struct stack * st, int num)
{
    assert( st != NULL);

    if( st ->size >= st ->capacity)
        return ERRPUSH;

    st ->arr[st->size] = num;
    st ->size++ ;
    return 0;
}

int stackPop( struct stack * st)
{
    assert( st != NULL);

    if( st ->size <= 0)
        return ERRPOP;

    st ->size--;
    return st ->arr[st->size];
}

void stackDtor( struct stack * st)
{
    free( st ->arr);
    st ->size = -1;
    st ->capacity = -1;
    free( st);

}

void stackPrint( struct stack st)
{
    printf(">>>\" %s \" \n", st.name);
    printf("size = %d\n", st.size);
    printf("capacity = %d\n", st.capacity);

    for (size_t i = 0; i < st.size; i++)
    {
        printf("    arr[%d] = %d\n", i, st.arr[i]);
    }
    printf("\n");
}
