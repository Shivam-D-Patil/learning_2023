/*
Count no. of days
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;  // Leap year
    }
    return 0;  // Not a leap year
}

int getDaysInMonth(int month, int year) {
    int daysInMonth;

    switch (month) {
        case 2:  // February
            if (LeapYear(year)) {
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11:  // November
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
    }

    return daysInMonth;
}

int countDays(char* date) {
    int day, month, year;
    sscanf(date, "%d-%d-%d", &day, &month, &year);

    int referenceDay = 1;
    int referenceMonth = 1;
    int referenceYear = 2000;

    int count = 0;
 
    for (int i = referenceYear; i < year; i++) {
        count += LeapYear(i) ? 366 : 365;
    }
 
    for (int i = referenceMonth; i < month; i++) {
        count += getDaysInMonth(i, year);
    }
 
    count += day - referenceDay;

    return count;
}

int main() {
    char date[11];
    printf("Enter a date  ");
    scanf("%10s", date);

    int days = countDays(date);
    printf("Number of days: %d\n", days);

    return 0;
}
