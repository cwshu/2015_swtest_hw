#include <iostream>
#include <cstdio>
#include <vector>

#include <gtest/gtest.h>

#include "nextdate.h"

// 1812 <= year <= 2012
// 1 <= month <= 12
// 1 <= day <= 31
Date nextdate(int year, int month, int day){
    if( year < 1812 || year > 2012 )
        return DATE_INVALID;
    if( month < 1 || month > 12 )
        return DATE_INVALID;
    if( day < 1 || day > 31 )
        return DATE_INVALID;

    int days_per_month = 0;
    switch( month ){
        case 1: case 3: case 5: case 7: 
        case 8: case 10: case 12:
            days_per_month = 31;
            break;
        case 4: case 6: case 9: case 11: 
            days_per_month = 30;
            break;
        // 28 or 29 days
        case 2:
            if( year%4 != 0 )
                days_per_month = 28;
            else if( year%100 != 0 )
                days_per_month = 29;
            else if( year%400 != 0 )
                days_per_month = 28;
            else
                // year%400 == 0
                days_per_month = 29;
            break;
    }

    if( day <= days_per_month-1 ){
        return Date(year, month, day+1);
    }
    else if( day == days_per_month ){
        if( month != 12 )
            return Date(year, month+1, 1);
        return Date(year+1, 1, 1);
    }
    else{
        return DATE_INVALID;
    }
}

#ifdef __USAGE_TEST__

void example_usage(){
    int year, month, day;
    std::cout << "Please input 3 integer for (year, month, day), year should be between 1812 to 2012:" << std::endl;
    std::cin >> year >> month >> day;
   
    Date Tomorrow = nextdate(year, month, day);
    if( Tomorrow == DATE_INVALID ){
        printf("%04d/%02d/%02d is invalid date.", year, month, day);
    }
    else{
        printf("Tomorrow's date is %04d/%02d/%02d", Tomorrow.year, Tomorrow.month, Tomorrow.day);
    }
}

int main(int argc, char *argv[]){
    example_usage();
}

#endif
