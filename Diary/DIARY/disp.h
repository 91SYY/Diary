#ifdef DISP

#else
#define DISP

#include "index.h"
#include "struct.h"
#include "schedule_modify.h"
#include "calendar.h"

void gotoxy(int x, int y);
void disp_all();
void disp_();
int disp_ymd(int y, int m, int d);
void disp_y(int y);
void disp_m(int y, int m);
void disp_d(int y, int m, int d);
void search_word();
void disp_secret();
void disp_diary_login();


//─│┌┐┘└├┬┤┴┼━┃┏┓┛┗
//→←▷▶【】『』《》

void disp_diary() {
	int x = 18, y = 1;
	gotoxy(x,y);
	printf("==============================\n");
	gotoxy(x, y+1);
	printf("    C  A  L  E  N  D  A  R  \n");
	gotoxy(x, y+2);
	printf("==============================\n");
}

void disp_diary_login() {
	int x = 18, y = 1;
	gotoxy(x, y);
	printf("==============================\n");
	gotoxy(x, y + 1);
	printf("         D  I  A  R  Y  \n");
	gotoxy(x, y + 2);
	printf("==============================\n");
}

void disp_() {
	int num, y,m,d;

	while (1) {
		system("cls");
		calendar_disp(2);
		printf("【1.년별】【2.월별】【3.일별】【4.단어검색】【5.비밀일정】【6.돌아가기】\n");
		printf("【입력】: ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			y = year;
			disp_y(y);
			break;
		case 2:
			y = year;
			m = month;
			disp_m(y,m);
			break;
		case 3:
			y = year;
			m = month;
			printf("%d년 %d월\n", y, m);
			d = day_in();
			disp_d(y,m,d);
			break;
		case 4:
			search_word();
			break;
		case 5:
			disp_secret();
			break;
		case 6:
			system("cls");
			calendar_disp(2);
			return;
		default:
			printf("잘못입력하셨습니다.\n");
			printf("다시입력해주세요.\n");
			system("pause");
			break;
		}
	}
}

int year_in() {
	int year;
	while (1)
	{
		printf("년도(年) : ");
		scanf("%d", &year);
		if (year >= 1 && year <= 10000)
			break;
		printf("다시 입력하세요.(1年~10000年)\n");
	}
	return year;
}

int month_in() {
	int month;
	while (1)
	{
		printf("월(月) : ");
		scanf("%d", &month);
		if (month >= 1 && month <= 12)
			break;
		printf("다시 입력하세요.(1月~12月)\n");
	}
	return month;
}

int day_in() {
	int day;
	while (1)
	{
		printf("일(日) : ");
		scanf("%d", &day);
		if (day >= 1 && day <= 31)
			break;
		printf("다시 입력하세요.(1日~30/31日)\n");
	}
	return day;
}

int menu_disp() {
	int num;

	printf("【1.일정보기】【2.일정추가】【3.일정수정】【4.달력날짜변경】【5.종료】\n");
	printf("【입력】: ");
	scanf("%d", &num);

	return num;
}

void disp_y(int y) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n          《%d년 일정》\n", y);

	while (list != NULL) {
		if (list->year == y) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("제목 : %s\n", list->title);
				printf("일정 : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("비밀메모입니다.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("등록된 일정이 없습니다.\n");
	system("pause");
}

void disp_m(int y, int m) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n        《%d년 %d월 일정》\n", y,m);

	while (list != NULL) {
		if ((list->year == y) && (list->month == m)) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("제목 : %s\n", list->title);
				printf("일정 : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("비밀메모입니다.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("등록된 일정이 없습니다.\n");
	system("pause");
}

void disp_d(int y, int m, int d) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n      《%d년 %d월 %d일 일정》\n", y, m,d);

	while (list != NULL) {
		if ((list->year == y) && (list->month == m) && (list->day == d)) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("제목 : %s\n", list->title);
				printf("일정 : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("비밀메모입니다.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("등록된 일정이 없습니다.\n");
	system("pause");
}

int disp_ymd(int y, int m, int d) {
	sc * list;
	int number = 1;
	list = s_head->next;

	while (list != NULL) {
		if ((list->year == y) && (list->month == m) && (list->day == d)) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("제목 : %s\n", list->title);
				printf("일정 : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("비밀메모입니다.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	return number;
}

void disp_all() {
	sc *disp;
	disp = s_head->next;
		while (disp != NULL) {
			printf("------------------------------------\n");
			printf("%d년 %d월 %d일\n", disp->year, disp->month, disp->day);
			printf("비밀번호 : %d \n", disp->pw);
			printf("제목 : %s\n", disp->title);
			printf("일정 : %s\n", disp->memo);
			printf("------------------------------------\n");
			disp = disp->next;
		}
	system("pause");
	system("cls");
}

void search_word() {
	sc * list = s_head->next;
	int number = 1;
	char str[20];
	getchar();
	printf("검색할 단어 : ");
	gets(str);
	system("cls");
	printf("《“%s”가 포함된 일정》\n", str);

	while (list != NULL) {
		if (strstr(list->memo,str) != NULL) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("제목 : %s\n", list->title);
				printf("일정 : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
				printf("비밀메모입니다.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("등록된 일정이 없습니다.\n");
	system("pause");
}

void disp_secret() {
	sc * list = s_head->next;
	sc * secret = s_head->next;
	int number = 1, i = 0, pw, sel;
	system("cls");
	printf("《비밀일정 목록》\n");

	while (list != NULL) {
		if (list->pw != 0000) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("-----------------------------------\n");
			printf("No.%d\n", number);
			printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
			printf("비밀메모입니다.\n");
			printf("-----------------------------------\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			number++;
		}
		list = list->next;
	}
		if (number == 1) {
			printf("등록된 비밀일정이 없습니다.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
		
		printf("몇번 비밀메모를 보시겠습니까? : ");
		scanf("%d", &sel);

		if (sel < number) {
			while (secret != NULL) {
				if (secret->pw != 0000) {
					i++;
					if (i == sel)
						break;
				}
				secret = secret->next;
			}

			printf("비밀번호를 입력해 주세요.\n");
			printf("입력 : ");
			scanf("%d", &pw);

			if (secret->pw != pw) {
				printf("일치하지않는 비밀번호 입니다.\n");
				system("pause");
				system("cls");
				calendar_disp(2);
				return;
			}
			else {
				printf("인증에 성공하였습니다.\n");
				Sleep(500);
			}
		}
		else {
			printf("현재 비밀메모는 %d번 까지있습니다.\n", number-1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
		printf("-----------------------------------\n");
		printf("%d년 %d월 %d일\n", secret->year, secret->month, secret->day);
		printf("제목 : %s\n", secret->title);
		printf("일정 : %s\n", secret->memo);
		printf("-----------------------------------\n");
		system("pause");
		system("cls");
		calendar_disp(2);
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

#endif