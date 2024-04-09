#include"1_Funtionality.h"

int main(){
    // DataContainer data{1,2,3,4,5,6,7,8,9,10,1,2,3,4,5};

    // Now we are taking an array of data of 5 size....and we have to apply all the methods on array...
    DataContainer data;
    TakeInput(data);

    ResultContainer result;
    ThreadContainer thArr;

    MapThreadToData(data,thArr,result);

    JoinThread(thArr);

    Display(result);
}


