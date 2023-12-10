

const int countTESTS = 7; // кол-во тестов

int resTest( );
int Test( struct dataTest , int);


struct dataTest // Структура с тестами
{
    double a, b, c;
    double x1, x2;
    int countX;
};

int Test( const struct dataTest refTESTS[], int numT)  //Функция теста
{
    double Roots[2] = {};
    double ABC[3] = { refTESTS[numT].a, refTESTS[numT].b, refTESTS[numT].c};

    int countx = Solver( ABC, Roots);

    if ( ( isEqual( refTESTS[numT].x2, Roots[1]) || isEqual(refTESTS[numT].x2, Roots[0])) &&
        ( isEqual( refTESTS[numT].x1, Roots[1]) || isEqual( refTESTS[numT].x1, Roots[0])) &&
        countx == refTESTS[numT].countX)
    {

        return 1;
    }
    else
    {
        printf(" Ошибка с тестом номер %d\n", numT+1);
        printf( "Ожидалось x1 = %g, x2= %g, countx = %d, получено x1 = %g, x2 = %g,  countX = %d\n",
            refTESTS[numT].x1, refTESTS[numT].x2, countx, Roots[0], Roots[1],  refTESTS[numT].countX);
        return 0;
    }
}

int resTest( ) // Функция проверки теста
{
    struct dataTest refTESTS[countTESTS] = {
    { 0, 0, 0, 0, 0, INF}, // тест 1
    { 0, 0, 5, 0, 0, ZERO}, // тест 2
    { 0, 5, 0, 0, 0, ONE}, // тест 3
    { 1, 0, 0, 0, 0, ONE},  // тест 4
    { 1, 0, 4, 0, 0, ZERO}, // тест 5
    { 1, 0, -4, 2, -2, TWO}, // тест 6
    { 1, 5, 6, -2, -3, TWO}}; // тест 7

    int countOK = 0;

    for( int numT=0; numT<countTESTS; numT++)
    {
        assert( 0 <= numT && numT < countTESTS);
        countOK += Test( refTESTS, numT);
    }
    printf( "%d из %d тестов прошли успешно", countOK, countTESTS);
    return 0;
}

