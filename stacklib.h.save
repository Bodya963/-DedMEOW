#define ERR -1
#define ERRPUSH -1
#define ERRPOP -1
#define MAXNIME 20

struct stack
{
    char name[ MAXNIME];
    int * arr;
    size_t size;
    size_t capacity;
};

int stackCtor( struct stack *, size_t, dconst char*); // интелезация стека. Возвращает ERR в случае ошибки

int stackPush( struct stack *, int); // кладет число в стек. Возвращает ERRPUSH
                                    // в случае не хватки обьема стека

int stackPop( struct stack *); // Убрать число из стека. Возвращает ERRPOP
                                // в случае если стек пуст

void stackDtor( struct stack *); // free( stack). Возвращает Err в случае ошибки

void stackPrint( struct stack);
