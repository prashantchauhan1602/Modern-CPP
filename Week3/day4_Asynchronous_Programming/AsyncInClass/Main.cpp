#include"DataOperation.h"

int main()
{
    // S1: I want to make a promise to provide an Integer;

    DataOperation* d1 = DataOperation::GetInstance();
    (*d1)();

}
