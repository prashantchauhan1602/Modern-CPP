

/*  

    For reusability :

        Save the function into (auto type) function, for reusabale puprose..

        Whenever we are using a function, we are actually making an object of some class created by compiler in the background. This means ^ function call object on it...

*/

#include<iostream>
#include<functional>


class Magic{

    private:

    public:


 
    // Functor...
    int operator()(int number){
        return number * number;
    }
};

int main(){
    Magic m1;
    std::cout << m1(10) << std::endl;   
                              // 100
    std::cout << Magic{}(10);                             // 100

    auto f1 = [] (int number) { return number* number ;};   // We don't know the type of lambda
                                                            //  class...that's why we use auto here..

    // Kept it in inside the function...(wrapper function) 
    std::function<int(int number)> fn = [] (int number) { return number* number ;};

    f1(10);

}
