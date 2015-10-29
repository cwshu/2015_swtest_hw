#include <iostream>
#include <cstdio>
#include <vector>

#include <gtest/gtest.h>

// Date(0, 0, 0) for error
struct Date {
    int year;
    int month;
    int day;

    Date(){
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }

    Date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }

    bool operator== (const Date& rhs) const {
        if( this->year != rhs.year )
            return false;
        if( this->month != rhs.month )
            return false;
        if( this->day != rhs.day )
            return false;

        return true;
    }
};
const Date DATE_INVALID = {0, 0, 0};

// 1812 <= year <= 2012
// 1 <= month <= 12
// 1 <= day <= 31
Date nextdate(int year, int month, int day){
    return DATE_INVALID;
}

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
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* Testing Code */
// equivalent class
// year: 400x year(2000), 100x year, 4x year, other | 1811, 2013
// month: {2}, {4, 6, 9, 11}, other | 0, 13
// days: {1 ~ 28}, 29, 30, 31 | 0, 32

// Multi-fault, Robust, Equivalent class
TEST(NextdateTest, robust){
    const int YEAR_LEN = 6;
    const int MONTH_LEN = 5;
    const int DAY_LEN = 6;

    const int year_test[YEAR_LEN] = {2000, 1900, 1948, 1911, 1811, 2013};
    const int month_test[MONTH_LEN] = {2, 6, 12, 0, 13};
    const int day_test[DAY_LEN] = {15, 29, 30, 31, 0, 32};

    const Date answer[YEAR_LEN][MONTH_LEN][DAY_LEN] = {
    { 
    {Date(2000, 2, 16), Date(2000, 3, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(2000, 6, 16), Date(2000, 6, 30), Date(2000, 7, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(2000, 12, 16), Date(2000, 12, 30), Date(2000, 12, 31), Date(2001, 1, 1), DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},

    {
    {Date(1900, 2, 16), DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1900, 6, 16), Date(1900, 6, 30), Date(1900, 7, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1900, 12, 16), Date(1900, 12, 30), Date(1900, 12, 31), Date(1901, 1, 1), DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},

    {
    {Date(1948, 2, 16), Date(1948, 3, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1948, 6, 16), Date(1948, 6, 30), Date(1948, 7, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1948, 12, 16), Date(1948, 12, 30), Date(1948, 12, 31), Date(1949, 1, 1), DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},

    {
    {Date(1911, 2, 16), DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1911, 6, 16), Date(1911, 6, 30), Date(1911, 7, 1), DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {Date(1911, 12, 16), Date(1911, 12, 30), Date(1911, 12, 31), Date(1912, 1, 1), DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},

    {
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},

    {
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID},
    {DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID, DATE_INVALID}},
    };

    for( int year_index = 0; year_index < YEAR_LEN; year_index++ ){
        for( int month_index = 0; month_index < MONTH_LEN; month_index++ ){
            for( int day_index = 0; day_index < DAY_LEN; day_index++ ){
                int year = year_test[year_index];
                int month = month_test[month_index];
                int day = day_test[day_index];

                EXPECT_EQ(answer[year_index][month_index][day_index], nextdate(year, month, day));
            }
        }
    }
}