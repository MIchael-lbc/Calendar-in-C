
// #include <stdio.h>

// int main() {
//     char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
//     for (int i = 0; i < 7; i++) {
//         printf("Day code %d = %s\n", i, days[i]);
//     }

//     return 0;
// }


#include <stdio.h>
// #define true 1 //true → replaces with 1
// //false → replaces with 0
// #define false 0
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};  // This is an array holding the number of days in each month.
// Index 0 is unused (that’s why it’s 0 first).
// So:
// days_in_month[1] = 31 → January
// days_in_month[2] = 28 → February
// days_in_month[3] = 31 → March
// and so on.
// That’s useful if you want to loop through months to print a calendar.
// ⚠️ days_in_month[0] = 0 — used only so month numbering starts from 1.

// If it’s a leap year, you’ll later change days_in_month[2] to 29.
char *months[]=  //Stores names of months (array of strings)
{
"\n\n\nJanuary", 
"\n\n\nFebruary",
"\n\n\nMarch",
"\n\n\nApril",
"\n\n\nMay",
"\n\n\nJune",
"\n\n\nJuly", 
"\n\n\nAugust", 
"\n\n\nSeptember",
"\n\n\nOctober",
"\n\n\nNovember",
"\n\n\nDecember"
};
int input_year()
{
    int year;
    printf("please enter a year ");
    scanf("%d",&year);
    return year;
    
}
int determineLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
     {days_in_month[2] = 29;
        return 1; // leap year
     }
    else
     { days_in_month[2] = 28;
        return 0; // not leap year  
     }
}
//The determineDayCode() function only tells you the day of the week for January 1st of the year, not for every month.

int determineDayCode(int year)
{
    int daycode;
    int d1, d2, d3;

    d1 = (year - 1) / 4;
    d2 = (year - 1) / 100;
    d3 = (year - 1) / 400;

    daycode = (year + d1 - d2 + d3) % 7;

    return daycode;
}

void calendar(int year, int daycode) {
    int month, day;

    for (month = 1; month <= 12; month++) {
        // Print month name
        printf("%s\n", months[month - 1]);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        // Print spaces for the first day of the month
        for (day = 0; day < daycode; day++) {
            printf("    "); // 4 spaces for alignment
        }

        // Print all days of the month
        for (day = 1; day <= days_in_month[month]; day++) {
            printf("%3d ", day);

            // Move to next line after Saturday
            if ((day + daycode) % 7 == 0)
                printf("\n");
        }

        printf("\n----------------------------\n");

        // Update daycode for next month
        daycode = (daycode + days_in_month[month]) % 7;
    }
}

int main() {
    int year, daycode;

    year = input_year();            // ask user for year
    determineLeapYear(year);        // adjust February if leap year
    daycode = determineDayCode(year); // get day code for Jan 1

    calendar(year, daycode);        // print full calendar

    return 0;
}
