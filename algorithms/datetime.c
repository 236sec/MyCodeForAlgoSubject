#include <stdio.h>

typedef struct datetime {
  int date;      // 1-31
  int month;     // 1-12
  int year;      // 1970++
  int dayOfWeek; // 0-6
  int hour;      // 0-23
  int minute;    // 0-59
  int second;    // 0-59
} datetime_t;

int year_check(int year_now) {
  if (year_now % 4 == 0) {
    if (year_now % 100 != 0) {
      return 1;
    } else if (year_now % 100 == 0 && year_now % 400 == 0) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int getYearDay(int year_now) {
  if (year_check(year_now)) {
    return 366;
  } else {
    return 365;
  }
}

int getMonthDay(int month_number, int year_now) {
  if (month_number == 4 || month_number == 6 || month_number == 9 ||
      month_number == 11) {
    return 30;
  } else if (month_number == 2) {
    if (year_check(year_now)) {
      return 29;
    } else {
      return 28;
    }
  } else {
    return 31;
  }
}

void printMonth(int month_number) {
  switch (month_number) {
  case 1:
    printf("JAN");
    break;
  case 2:
    printf("FEB");
    break;
  case 3:
    printf("MAR");
    break;
  case 4:
    printf("APR");
    break;
  case 5:
    printf("MAY");
    break;
  case 6:
    printf("JUN");
    break;
  case 7:
    printf("JUL");
    break;
  case 8:
    printf("AUG");
    break;
  case 9:
    printf("SEP");
    break;
  case 10:
    printf("OCT");
    break;
  case 11:
    printf("NOV");
    break;
  case 12:
    printf("DEC");
    break;
  }
}

void dayString(int dayofweek) {
  switch (dayofweek) {
  case 0:
    printf("Thu "); // Thursday
    break;
  case 1:
    printf("Fri "); // Friday
    break;
  case 2:
    printf("Sat "); // Saturday
    break;
  case 3:
    printf("Sun ");// Sunday
    break;
  case 4:
    printf("Mon ");// Monday
    break;
  case 5:
    printf("Tue ");// Tuesday
    break;
  case 6:
    printf("Wed ");// Wedneseday
    break;
  }
}

datetime_t createDate(int timestamp) {
  datetime_t dateat;
  int date_far = timestamp / 86400;
  dateat.dayOfWeek = date_far % 7;
  timestamp -= 86400 * date_far;
  int i = 0;
  dateat.year = 1970;
  while (date_far > getYearDay(1970 + i)) {
    date_far -= getYearDay(1970 + i);
    dateat.year++;
    i++;
  }
  i=1;
  dateat.month = 1;
  while (date_far > getMonthDay( i, dateat.year)){
    date_far-=getMonthDay( i, dateat.year);
    dateat.month++;
    i++;
  }
  if(date_far>0){
    if(date_far+1 > getMonthDay(i, dateat.year)){
      dateat.month++;
      dateat.date = 1;
    }else{
      dateat.date = date_far+1;
    }
  }else{
    dateat.date = 1;
  }
  dateat.hour = timestamp / 3600;
  timestamp -= 3600 * dateat.hour;
  dateat.minute = timestamp / 60;
  timestamp -= 60 * dateat.minute;
  dateat.second = timestamp;
  return dateat;
}

void printDate(datetime_t dateat){
  dayString(dateat.dayOfWeek);
  printf("%d ",dateat.date);
  printMonth(dateat.month);
  printf(" %d ",dateat.year);
  printf("%02d:%02d:%02d",dateat.hour,dateat.minute,dateat.second);
}

int main(void) {
  datetime_t inputDate;
  int timestamp;
  scanf("%d", &timestamp);
  inputDate = createDate(timestamp);
  printDate(inputDate);
  return 0;
}