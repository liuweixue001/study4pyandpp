#include <iostream>

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int getDayofYear(int year, int month, int day) {
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1) {
        // 输入参数异常
        return 0;
    }

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // 处理闰年2月份的天数
    if (isLeapYear(year) && month == 2) {
        daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month]) {
        // 输入参数异常，天数超出该月最大天数
        return 0;
    }

    int dayOfYear = day;
    for (int i = 1; i < month; ++i) {
        dayOfYear += daysInMonth[i];
    }

    return dayOfYear;
}

int main() {
    // 例子：计算2024年2月1日的年积日
    int year = 2024;
    int month = 12;
    int day = 14;

    int result = getDayofYear(year, month, day);

    if (result == 0) {
        std::cout << "输入参数异常" << std::endl;
    } else {
        std::cout << year << " " << month << " " << day << " " << result << std::endl;
    }

    return 0;
}
