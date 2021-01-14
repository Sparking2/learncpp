// 04_SummaryQuiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "io.h"

int main()
{
    int x{ readNumber() };
    int y{ readNumber() };

    writeAnswer(x + y);

    return 0;
}


