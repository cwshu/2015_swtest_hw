#ifndef __NEXTDATE_H__
#define __NEXTDATE_H__

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

// Date(0, 0, 0) for error
const Date DATE_INVALID = {0, 0, 0};
Date nextdate(int year, int month, int day);

#endif /* end of include guard: __NEXTDATE_H__ */
