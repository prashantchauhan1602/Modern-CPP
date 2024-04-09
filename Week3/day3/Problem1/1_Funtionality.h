#ifndef INC_1_FUNTIONALITY_H
#define INC_1_FUNTIONALITY_H

#include<thread>
#include<array>
#include<iostream>

using DataContainer = std::array<int, 15>;
using ThreadContainer = std::array<std::thread, 3>;
using ResultContainer = std::array<int, 15>;


void Square(DataContainer&, ResultContainer& , int start, int end);

void Cube(DataContainer&, ResultContainer& , int start, int end);

void factorial(DataContainer&, ResultContainer& , int start, int end);


void MapThreadToData(DataContainer& , ThreadContainer&, ResultContainer&);

void JoinThread(ThreadContainer&);

void Display(ResultContainer&);

void TakeInput(DataContainer&);

#endif // INC_1_FUNTIONALITY_H
