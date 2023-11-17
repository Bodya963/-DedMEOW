#include <TXlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stacklib.h"



int main()
{
    struct stack stc = {};
    struct stack * stcP = &stc;

    if (( stackCtor( stcP, 10, "MyFirstStack")) == ERR)
    {
        printf(" Ошибка инцелизации стека\n");
        exit(1);
    }
    stackPrint( stc);


    stackPush( stcP, 13);
    stackPrint( stc);

    stackPush( stcP, 12);
    stackPrint( stc);

    stackPush( stcP, 11);
    stackPrint( stc);

    printf("meow stack = %d\n", stackPop( stcP));
    stackPrint( stc);

    stackDtor( stcP);
    return 0;
}
