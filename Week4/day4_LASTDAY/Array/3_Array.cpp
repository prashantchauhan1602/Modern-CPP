#include<iostream>

void Magic(int arr[]){

}

void Magic2D(int arr2[][]){

}

void Magic3(int** arr, int row, int col){}

int main(){

    int arr[] = {1,2,3,4,5};             // STACK MEMORY 

    // WE ARE PASSING AN ARRAY OF UNDEFINED SIZE....
    Magic(arr);

    // BUT IN CASE OF 2D ARRAY, IT WILL GIVES AN ERROR  --- BECAUSE SHAPE IS NOT FIXED
    // FOR EG : YOU HAVE 2 COLS AND 3 ROWS ------------> TOTAL 6 VALUE'S SPACE
    // IT MAY BE 6*1 ARRAY, 2*3 ARRAY, 3*2 ARRAY  -----> CONFUSE AND GIVES ERROR

    // int arr2[][];
    // Magic2D(arr2);

    int** arr2D;
    int row = 2;
    int col = 3;
    // For rows ; 

    arr2D = new int*[2];  
    // arr2D Contains 2 pointers where each pointer points to base address of 1 integer array...

    for( int i=0;i < row; i++){
        // allocate space for columns...
        arr2D[i] = new int[col];
    }

    Magic3(arr2D,row,col);
}
