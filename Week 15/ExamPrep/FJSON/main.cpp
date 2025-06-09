#include "FJSON.hpp"
#include "StringPair.hpp"
#include "DatePair.hpp"
#include "TimePair.hpp"
#include "DateTimePair.hpp"

#include "MyString.h"
#include "Date.h"
#include "Time.h"
#include "DateTime.h"

#include <fstream>
#include <iostream>

int main() {
    MyString   strVal("Hello world");         
    Date       dateVal(15, 10, 2021);       
    Time       timeVal(10, 15);            
    DateTime   dtVal(dateVal, timeVal);

    StringPair<int>      sp(0, strVal);
    DatePair<int>        dp(1, dateVal);
    TimePair<int>        tp(2, timeVal);
    DateTimePair<int>    dtp(3, dtVal);

    FJSON<int, MyString>    fjStr;
    FJSON<int, Date>        fjDate;
    FJSON<int, Time>        fjTime;
    FJSON<int, DateTime>    fjDT;
    
    fjStr.addPair(sp);
    fjDate.addPair(dp);
    fjTime.addPair(tp);
    fjDT.addPair(dtp);
    
    std::ofstream ofs("test_output.txt");
    if (!ofs) {
        std::cerr << "Failed to open test_output.txt\n";
        return 1;
    }

    ofs << '[';
    fjStr.saveToFile(ofs);
    std::cout << "here2" << std::endl;

    ofs << ", ";
    std::cout << "her3e" << std::endl;

    fjDate.saveToFile(ofs);
    std::cout << "her3e" << std::endl;

    ofs << ", ";
    fjTime.saveToFile(ofs);
    std::cout << "here4" << std::endl;

    ofs << ", ";
    fjDT.saveToFile(ofs);
    ofs << "]\n";
    std::cout << "here" << std::endl;

    std::cout << "Wrote FJSON output to test_output.txt\n";
    return 0;
}
