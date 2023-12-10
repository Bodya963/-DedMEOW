#include <TXlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>




enum ROOTS_AMNT {
    INF = -1,
    ZERO,
    ONE,
    TWO
};

//----Константы-----------------

const int countCOEFFS = 3; //кол-во коэффицентов
const int countROOTS = 2; // максимальное кол-во корней ур-ия
const double Ee = 0.000001;


//-----Функции-------------------

enum ROOTS_AMNT Solver( double*, double*);
enum ROOTS_AMNT SolverLINE( double*, double*);
enum ROOTS_AMNT IFc0( double*, double*);
int inputABC( double*);
int clearINPUT();
int outputXX( double*, int);
int assertIN( double*);
int isZero( double);
int isEqual(double, double);

#include "unixTest.h"


//-------Main--------------------

int main( int argc, char* argv[])
{
    //Только юнит тесты------------

    if ( argc != 2)
    {
        printf("Не правильные аргументы коммандной строки\n");
        return 1;
    }
    if ( strcmp("++test", argv[1]) == 0)
    {
        resTest( );
        return 0;
    }

    if ( strcmp("--test", argv[1]) == 0)
        printf("Программа запустилось\n");

    // Квадратка-------------------

    printf("Введите коэффициенты:\n");

    double ABC[countCOEFFS] = {};  //массив с коэффицентами
    double Roots[countROOTS] = {}; // массив с корнями ур-ия

    //Ввод

    inputABC( ABC );

    //проверки

    assertIN( ABC );

    //решение ур-ия

    enum ROOTS_AMNT countx = Solver( ABC, Roots); // кол-во корней уравнения

    //вывод

    outputXX( Roots, countx);

    return 0;
}

//---Функции Ввода-------------------

/*
int arr[] = {};
int res = 0;

for (int i = 0; i < n; ++i)
    res ^= arr[i];

return res;
 */

int inputABC( double ABC[] )
{
    for (int i=0; i < countCOEFFS; i++)
    {
        assert( 0 <= i && i < countCOEFFS);

        while ((scanf( "%lg", &ABC[i])) != 1)
        {
            printf("Ошибка ввода\n");
            clearINPUT();
            i = 0; // Reset

        }

    }
    return 0;
}

//----Проверки-----------------------

int assertIN( double ABC[])
{
    for (int i=0; i<countCOEFFS; i++)
    {
        assert( 0 <= i && i < countCOEFFS);
        assert( ABC[i] != NAN);
        assert( isfinite(ABC[i]));
    }
    return 0;
}

//----Функция вычисления ур-ия--------

enum ROOTS_AMNT Solver( double ABC[], double Roots[])
{
    assert(ABC != NULL);

//---если один из аргументов равен 0---

    if ( isZero( ABC[0] ))
    {
        return SolverLINE( ABC, Roots );
    }

    if ( isZero( ABC[2] ))
    {
        return IFc0( ABC, Roots );
    }

//---Решение квадратного ур-ия--------



    double D = ABC[1]*ABC[1] - (4*ABC[0]*ABC[2]); // Дискриминант

    if (D >= 0)
    {
        Roots[0] = (-ABC[1]+sqrt(D)) / (2*ABC[0]);
        Roots[1] = (-ABC[1]-sqrt(D)) / (2*ABC[0]);
        return TWO;
    }

    return ZERO;

}

//-----Решение линейного ур-ия-------------

enum ROOTS_AMNT SolverLINE( double ABC[], double Roots[] )
{
    assert( ABC != NULL);
    assert( Roots != NULL);

    if ( isZero( ABC[1] ))
    {
        if ( isZero( ABC[2] ))
            return INF;
        else
            return ZERO;
    }

    if ( isZero( ABC[2] ))
    {
        Roots[0] = 0;
        return ONE;
    }

    Roots[0] = (-ABC[2]) / ABC[1];
    return ONE;


}

//----Если с = 0-----------------------

enum ROOTS_AMNT IFc0( double ABC[], double Roots[] )
{
    assert(ABC != NULL);
    assert(Roots != NULL);

    if ( isZero( ABC[1]))
    {
        Roots[0] = 0;
        return ONE;
    }

    Roots[0] = 0;
    Roots[1] = -ABC[1];
    return TWO;
}

//---------Вывод-----------------------

int outputXX( double Roots[], int countx)
{
    assert(Roots != NULL);

    if ( countx == ZERO)
        printf( "Нет действительных решений\n");
    if ( countx == INF)
        printf( "x любое число\n");
    else
    {
        for ( int i=0; i < countx; i++)
        {
            assert( 0 <= i && i < countROOTS);
            printf( "x%d = %g\n", i+1, Roots[i]);
        }
    }
    return 0;
}

//--------------------------------------


int isEqual( double a, double b)
{
    return fabs(a-b) < Ee;
}

int isZero( double num)
{
    return isEqual(num, 0);
}

int clearINPUT()
{
    while ( getchar() != '\n');
    return 0;
}
