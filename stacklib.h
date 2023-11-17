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

int stackCtor( struct stack *, size_t, dconst char*); // ����������� �����. ���������� ERR � ������ ������

int stackPush( struct stack *, int); // ������ ����� � ����. ���������� ERRPUSH
                                    // � ������ �� ������ ������ �����

int stackPop( struct stack *); // ������ ����� �� �����. ���������� ERRPOP
                                // � ������ ���� ���� ����

void stackDtor( struct stack *); // free( stack). ���������� Err � ������ ������

void stackPrint( struct stack);
