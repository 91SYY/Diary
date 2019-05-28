#ifdef CALENDAR

#else
#define CALENDAR

#include "disp.h"

void gotoxy(int x, int y);
void disp_diary();
void calendar_disp(int num); //달력 출력
int month_day(int year, int month);
int year_day(int year, int month);
void show_month(int year, int month);
int year_in();
int month_in();
int check(int y, int m, int d);


void calendar_disp(int num) {

	switch (num) {
	case 0:
		year = year_in();
		month = month_in();
		system("cls");
		break;
	case 1:
		year = Time->tm_year + 1900;
		month = Time->tm_mon + 1;
		break;
	case 2:
		disp_diary();
		show_month(year, month);
		return;
	}
	disp_diary();
	show_month(year, month);
}

int month_day(int year, int month) {
	const int mdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = mdays[month];

	if (month == 2)
	{
		if (year % 400 == 0 || ((year % 100) && (year / 4 == 0)))
			days++;
	}
	return days;
}

int year_day(int year, int month) {
	int days;
	int i;
	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

	for (i = 0; i < month; i++)
		days += month_day(year, i);
	return (++days % 7);
}

void show_month(int year, int month) {
	int x=17, y=5;
	int i, j, nline, c;
	int mday = 1;
	const char wdays[][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int mdays = month_day(year, month);
	int wday = year_day(year, month);
	nline = (mdays + wday) / 7;
	if ((mdays + wday) % 7) nline++;

	gotoxy(x, y -1);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	for (i = 0; i < 4; i++)
	{
		switch (i) {
		case 1:
			gotoxy(x, y + 1);
			printf("┃ ");
			break;
		case 2:
			gotoxy(x + 30, y + 1);
			printf("┃ ");
			gotoxy(x, y + 2);
			printf("┃ ");
	
			break;
		case 3:
			gotoxy(x + 30, y + 2);
			printf("┃ ");
			gotoxy(x, y + 3);
			printf("┃ ");
			break;
		case 4:
			gotoxy(x, y + 4);
			printf("┃ ");
			break;
		}
		for (j = 0; j < 7; j++)
		{
		
			if (i == 0)
			{
				gotoxy(x, y);
				printf("┃ ");
				printf("%2d %21d월",year, month);
				gotoxy(x+30, y);
				printf("┃ ");
				break;
			}
			else if (i == 2) {
				printf("%4s", wdays[j]);
			}
			else
				printf("%4s", "====");
		}
		gotoxy(x + 30, y + 3);
		printf("┃ ");
		printf("\n");
	}


	for (i = 0; i < nline; i++)
	{
		switch (i) {
		case 0:
			gotoxy(x, y + 4);
			printf("┃ ");
			break;
		case 1:
			gotoxy(x+30, y + 4);
			printf("┃ ");
			gotoxy(x, y + 5);
			printf("┃ ");
			break;
		case 2:
			gotoxy(x + 30, y + 5);
			printf("┃ ");
			gotoxy(x, y + 6);
			printf("┃ ");
			break;
		case 3:
			gotoxy(x + 30, y + 6);
			printf("┃ ");
			gotoxy(x, y + 7);
			printf("┃ ");
			break;
		case 4:
			gotoxy(x + 30, y + 7);
			printf("┃ ");
			gotoxy(x, y + 8);
			printf("┃ ");
			break;
		case 5:
			gotoxy(x + 30, y + 8);
			printf("┃ ");
			gotoxy(x, y + 9);
			printf("┃ ");
			break;
		}
	
		for (j = 0; j < 7; j++)
		{
			if (i == 0)
			{
				if (j < wday) 
					printf("%4c", ' ');
				else {
					c = check(year,month,mday);
					if (c == 1) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
						printf("%4d", mday++);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					}
					else
						printf("%4d", mday++);
				}
			}
			else
			{
				c = check(year, month, mday);
				if (c == 1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					printf("%4d", mday++);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else
					printf("%4d", mday++);

				if (mday > mdays)
					break;
			}
		}
		gotoxy(x + 30, y + 9);
		printf("┃ ");
		printf("\n");
	}
	gotoxy(x + 30, y + 8);
	printf("┃ ");
	gotoxy(x, y + 9);
	printf("┃ ");
	//for (j = 0; j < 7; j++)
		gotoxy(x, y+10);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n");
	printf("\n");
}

int check(int y, int m, int d) {
	sc * move = s_head->next;

	while (move != NULL) {
		if ((move->year == y) && (move->month == m) && (move->day == d)) {
			return 1;
		}
		move = move->next;
	}
	return 0;
}


#endif