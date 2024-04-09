#include <memory>

/*
    UNIQUE POINTER --------------> NOT COPY CONSTRUCTOR AND NOT COPY ASSIGNABLE
*/

// void Magic(std::unique_ptr<int[]> ptr1)           // Gives error !!
// {
// }

void Magic(std::unique_ptr<int[]> &ptr1)           // Solve error !!
{
}

int main()
{

    /*
        When you send the values -----> you need to use make_unique here..

        a) For space allocation :
            unique_ptr be used

        b) I want to make sure that the raw pointer returned from this allocation is not accessible from
            next statement onwards

        c) Since, this allocation is for integer array, unique pointer needs to aware about it... Hence <int[]>

        d) Since, we don't have to forward any parameters to any constructor

        e) PASS BY VALUE IS NOT ACCEPTABLE !!

    */

    std::unique_ptr<int[]> ptr1(new int[2]); // 8 bytes...
    Magic(ptr1);
}
