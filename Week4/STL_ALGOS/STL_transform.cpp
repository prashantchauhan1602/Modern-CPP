/*
    IT IS A UNARY OPERATOR !!
*/


#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    std::vector<int> data{12,14,16,22,25,28};
    std::vector<int>result;

    std::transform(
        data.begin(),
        data.end(),
        std::inserter(result, result.begin()),
        [](int num){ return num* 100 ;}
    );

    for(int val: result){
        std::cout << val << "    " ;
    }
}
