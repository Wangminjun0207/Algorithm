#include "CLex.h"

int main()
{
    CLex lex;
    lex.SetFileName("test.txt");
    lex.GenToken();
    return 0;
}
