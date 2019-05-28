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


//����������������������������������
//��碹��������������

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
		printf("��1.�⺰����2.��������3.�Ϻ�����4.�ܾ�˻�����5.�����������6.���ư��⡽\n");
		printf("���Է¡�: ");
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
			printf("%d�� %d��\n", y, m);
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
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("�ٽ��Է����ּ���.\n");
			system("pause");
			break;
		}
	}
}

int year_in() {
	int year;
	while (1)
	{
		printf("�⵵(Ҵ) : ");
		scanf("%d", &year);
		if (year >= 1 && year <= 10000)
			break;
		printf("�ٽ� �Է��ϼ���.(1Ҵ~10000Ҵ)\n");
	}
	return year;
}

int month_in() {
	int month;
	while (1)
	{
		printf("��(��) : ");
		scanf("%d", &month);
		if (month >= 1 && month <= 12)
			break;
		printf("�ٽ� �Է��ϼ���.(1��~12��)\n");
	}
	return month;
}

int day_in() {
	int day;
	while (1)
	{
		printf("��(��) : ");
		scanf("%d", &day);
		if (day >= 1 && day <= 31)
			break;
		printf("�ٽ� �Է��ϼ���.(1��~30/31��)\n");
	}
	return day;
}

int menu_disp() {
	int num;

	printf("��1.�������⡽��2.�����߰�����3.������������4.�޷³�¥���桽��5.���᡽\n");
	printf("���Է¡�: ");
	scanf("%d", &num);

	return num;
}

void disp_y(int y) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n          ��%d�� ������\n", y);

	while (list != NULL) {
		if (list->year == y) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("���� : %s\n", list->title);
				printf("���� : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("��и޸��Դϴ�.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("��ϵ� ������ �����ϴ�.\n");
	system("pause");
}

void disp_m(int y, int m) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n        ��%d�� %d�� ������\n", y,m);

	while (list != NULL) {
		if ((list->year == y) && (list->month == m)) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("���� : %s\n", list->title);
				printf("���� : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("��и޸��Դϴ�.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("��ϵ� ������ �����ϴ�.\n");
	system("pause");
}

void disp_d(int y, int m, int d) {
	sc * list;
	list = s_head->next;
	int number = 1;
	system("cls");
	printf("\n      ��%d�� %d�� %d�� ������\n", y, m,d);

	while (list != NULL) {
		if ((list->year == y) && (list->month == m) && (list->day == d)) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("���� : %s\n", list->title);
				printf("���� : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("��и޸��Դϴ�.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("��ϵ� ������ �����ϴ�.\n");
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
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("���� : %s\n", list->title);
				printf("���� : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("��и޸��Դϴ�.\n");
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
			printf("%d�� %d�� %d��\n", disp->year, disp->month, disp->day);
			printf("��й�ȣ : %d \n", disp->pw);
			printf("���� : %s\n", disp->title);
			printf("���� : %s\n", disp->memo);
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
	printf("�˻��� �ܾ� : ");
	gets(str);
	system("cls");
	printf("����%s���� ���Ե� ������\n", str);

	while (list != NULL) {
		if (strstr(list->memo,str) != NULL) {
			if (list->pw == 0000) {
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("���� : %s\n", list->title);
				printf("���� : %s\n", list->memo);
				printf("-----------------------------------\n");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("-----------------------------------\n");
				printf("No.%d\n", number);
				printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
				printf("��и޸��Դϴ�.\n");
				printf("-----------------------------------\n");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			number++;
		}
		list = list->next;
	}
	if (number == 1)
		printf("��ϵ� ������ �����ϴ�.\n");
	system("pause");
}

void disp_secret() {
	sc * list = s_head->next;
	sc * secret = s_head->next;
	int number = 1, i = 0, pw, sel;
	system("cls");
	printf("��������� ��ϡ�\n");

	while (list != NULL) {
		if (list->pw != 0000) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("-----------------------------------\n");
			printf("No.%d\n", number);
			printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
			printf("��и޸��Դϴ�.\n");
			printf("-----------------------------------\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			number++;
		}
		list = list->next;
	}
		if (number == 1) {
			printf("��ϵ� ��������� �����ϴ�.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
		
		printf("��� ��и޸� ���ðڽ��ϱ�? : ");
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

			printf("��й�ȣ�� �Է��� �ּ���.\n");
			printf("�Է� : ");
			scanf("%d", &pw);

			if (secret->pw != pw) {
				printf("��ġ�����ʴ� ��й�ȣ �Դϴ�.\n");
				system("pause");
				system("cls");
				calendar_disp(2);
				return;
			}
			else {
				printf("������ �����Ͽ����ϴ�.\n");
				Sleep(500);
			}
		}
		else {
			printf("���� ��и޸�� %d�� �����ֽ��ϴ�.\n", number-1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
		printf("-----------------------------------\n");
		printf("%d�� %d�� %d��\n", secret->year, secret->month, secret->day);
		printf("���� : %s\n", secret->title);
		printf("���� : %s\n", secret->memo);
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