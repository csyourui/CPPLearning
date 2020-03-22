//
//  DayBetweenYear.cpp
//  test
//
//  Created by yourui on 2020/2/25.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#define NY 365
using namespace std;

class Date{
public:
    Date(int Y, int M, int D):Year(Y), Month(M), Day(D){ };
    Date(string str){
        vector<int> v;
        int pos2 = (int) str.find('-');
        int pos1 = 0;
        while(pos2 != str.npos){
            v.push_back(stoi(str.substr(pos1, pos2-pos1)));
            pos1 = pos2 + 1;
            pos2 = (int)str.find('-', pos1);
        }
        if(pos1 != str.length())
            v.push_back(stoi(str.substr(pos1)));
        Year = v[0];
        Month = v[1];
        Day = v[2];
    }
    Date& operator=(const Date& t){
        if(this == &t){
            return *this;
        }
        Year = t.Year;
        Month = t.Month;
        Day = t.Day;
        return *this;
    }
    bool operator==(const Date& t){
        return (this->Year == t.Year) && (this->Month == !t.Month) && (this->Day == t.Day);
    }
    bool operator!=(const Date& t){
        return (this->Year != t.Year) || (this->Month != !t.Month) || (this->Day != t.Day);
    }
    
    int dayInthisYear() const{
        return this->Day + accusum[this->Month - 1] + (isLeapYear(this->Year) && this->Month > 2);
    }
    int dayInthatYear() const{
        return NY - this->Day - accusum[this->Month - 1] + (isLeapYear(this->Year) && this->Month <= 2);
    }
    void printDate(){
        printf("%d-%d-%d\n",this->Year, this->Month, this->Day);
    }
    static bool isLeapYear(int Year);
    static int disDate1(const Date &BirthDay, const Date &Today);
    static int disDate2(Date BirthDay, Date Today);
private:
    static int accusum[];
    int Year;
    int Month;
    int Day;
};
bool Date::isLeapYear(int Year){
    return ((Year % 4 == 0) && (Year % 100 !=0))||((Year % 400 ==0));
}
int Date::accusum[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int Date::disDate1(const Date &BirthDay, const Date &Today){
    int A = BirthDay.dayInthatYear();
    int B = 0;
    int C = Today.dayInthisYear();
    if (Today.Year == BirthDay.Year) {
        return C + A - (NY + isLeapYear(Today.Year));
    }
    else{
        for (int i = BirthDay.Year + 1; i < Today.Year; i++) {
            B += NY;
            if (isLeapYear(i)) {
                B += 1;
            }
        }
        return A + B + C;
    }
}
int Date::disDate2(Date BirthDay, Date Today){
    int count = 0;
    int dayOfMon[13] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dayOfMon[2] = isLeapYear(BirthDay.Year) + 28;
    while (true) {
        if(BirthDay.Year == Today.Year && BirthDay.Month == Today.Month && BirthDay.Day == Today.Day)
            break;
        count++;
        BirthDay.Day += 1;
        if(BirthDay.Day > dayOfMon[BirthDay.Month]){
            BirthDay.Month += 1;
            BirthDay.Day = 1;
        }
        if(BirthDay.Month > 12){
            BirthDay.Year += 1;
            dayOfMon[2] = isLeapYear(BirthDay.Year) + 28;
            BirthDay.Month = 1;
        }

    }
    return count;
}
int main(){

    char birthdateStr[20],TodayStr[20];
    printf("请输入出生日期：(YYYY-MM-DD)\n");
    scanf("%s", birthdateStr);
    Date BirthDay(birthdateStr);
    //int a = 10;
    printf("请输入今天日期：(YYYY-MM-DD)\n");
    scanf("%s", TodayStr);
    Date Today(TodayStr);
    
    printf("出生日期：");
    BirthDay.printDate();
    printf("今天日期：");
    Today.printDate();

    printf("%d\n", Date::disDate1(BirthDay, Today));
    printf("%d\n", Date::disDate2(BirthDay, Today));

}
