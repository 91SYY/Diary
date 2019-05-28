#ifdef SCHEDULE_MODIFY

#else
#define SCHEDULE_MODIFY


#include "index.h"
#include "struct.h"
#include "disp.h"
#include "calendar.h"

int search(int y, int m, int d);
void del();
void continue_use();
void chage_secret();
int disp_ymd(int y, int m, int d);
int year_in();
int month_in();
int day_in();



void modify_main() {
	int num;

	while (1) {
	
		printf("��1.���� ��������2.�̾� ���⡽��3.��� �޸�� ���桽��4.���ư��⡽\n");
		printf("���Է¡�: ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			del();
			break;
		case 2:
			system("cls");
			calendar_disp(2);
			continue_use();
			break;
		case 3:
			system("cls");
			calendar_disp(2);
			chage_secret();
			break;
		case 4:
			system("cls");
			calendar_disp(2);
			return;
		default:
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("�ٽ��Է����ּ���.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			break;
		}
	}
}

void del() {
	int y, m, d, i = 0, j;
	int sel, number, pw;
	//sc * list;
	sc * del = s_head->next;

	while (1) {
		y = year;
		m = month;
		printf("%d�� %d��\n", y, m);
		d = day_in();

		if (search(y, m, d)) break;

		system("cls");
		calendar_disp(2);
		return;
	}

	while (1) {

		number = disp_ymd(y, m, d);

		printf("���°�� �����Ͻðڽ��ϱ�? : ");
		scanf("%d", &sel);

		if (sel < number) {
			while (del != NULL) {
				if ((del->year == y) && (del->month == m) && (del->day == d)) {
					i++;
					if (i == sel)
						break;
				}
				del = del->next;
			}

			if (del->pw != 0000) {
				printf("��и޸��Դϴ�.\n");
				printf("��й�ȣ�� �Է��� �ּ���.\n");
				printf("�Է� : ");
				scanf("%d", &pw);

				if (del->pw != pw) {
					printf("��ġ�����ʴ� ��й�ȣ �Դϴ�.\n");
					system("pause");
					system("cls");
					return;
				}
				else {
					printf("������ �����Ͽ����ϴ�.\n");
					Sleep(500);
				}
			}
			if (del->next != NULL)
				del->next->pre = del->pre;
			del->pre->next = del->next;
			free(del);
			printf("���� ��");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n�����Ϸ�!\n");
			system("pause");
			system("cls");
			break;

		}
		else {
			printf("%d��°���� ������ �����մϴ�.\n", number - 1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
	system("cls");
	calendar_disp(2);
}

int search(int y, int m, int d) {
	sc * move = s_head->next;

	while (move != NULL) {
		if ((move->year == y) && (move->month == m) && (move->day == d)) {
			return 1;
		}
		move = move->next;
	}
	printf("�ش糯¥�� ��ϵ� ������ �����ϴ�.\n");
	system("pause");
	system("cls");
	return 0;
}

void continue_use() {
	int y, m, d;
	int sel, number, i = 0, j, pw;
	char str[100];
	sc * modi = s_head->next;

	while (1) {
		y = year;
		m = month;
		printf("%d�� %d��\n", y, m);
		d = day_in();

		if (search(y, m, d)) break;

		system("cls");
		calendar_disp(2);
		return;
	}

	while (1) {

		number = disp_ymd(y, m, d);

		printf("���°�� �̾�� �Ͻðڽ��ϱ�? : ");
		scanf("%d", &sel);

		if (sel < number) {
			while (modi != NULL) {
				if ((modi->year == y) && (modi->month == m) && (modi->day == d)) {
					i++;
					if (i == sel)
						break;
				}
				modi = modi->next;
			}

			if (modi->pw != 0000) {
				printf("��и޸��Դϴ�.\n");
				printf("��й�ȣ�� �Է��� �ּ���.\n");
				printf("�Է� : ");
				scanf("%d", &pw);

				if (modi->pw != pw) {
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
			printf("���� ���� : %s\n", modi->title);
			printf("���� �� ���� �Է� : ");
			scanf("%s", modi->title);
			printf("���� ���� : %s\n", modi->memo);
			printf("�߰� �� ���� �Է� : ");
			scanf("%s", str);
			strcat(modi->memo, str);

			printf("���� ��");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n�����Ϸ�!\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			break;

		}
		else {
			printf("%d��°���� ������ �����մϴ�.\n", number - 1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
}

void chage_secret() {
	int y, m, d;
	int sel, number, i, j, pw;
	sc * list;
	sc * modi = s_head->next;

	while (1) {
		y = year;
		m = month;
		printf("%d�� %d��\n", y, m);
		d = day_in();

		if (search(y, m, d)) break;

		system("cls");
		calendar_disp(2);
		return;
	}

	while (1) {
		list = s_head->next;
		number = 1;
		i = 0;
		while (list != NULL) {
			if ((list->year == y) && (list->month == m) && (list->day == d)) {
				if (list->pw == 0000) {
					printf("-----------------------------------\n");
					printf("No.%d\n", number);
					printf("%d�� %d�� %d��\n", list->year, list->month, list->day);
					printf("���� : %s\n", list->title);
					printf("���� : %s\n", list->memo);
					printf("-----------------------------------\n");
					number++;
				}
			}
			list = list->next;
		}
		if (number == 1) {
			printf("�Ϲ� ������ �����ϴ�.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}

		printf("���° ������ ����������� �����Ͻðڽ��ϱ�? : ");
		scanf("%d", &sel);

		if (sel < number) {
			while (modi != NULL) {
				if ((modi->year == y) && (modi->month == m) && (modi->day == d)) {
					i++;
					if (i == sel)
						break;
				}
				modi = modi->next;
			}

			printf("��й�ȣ ���� : ");
			scanf("%d", &pw);
			modi->pw = pw;
			printf("���� ��");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n����Ϸ�!\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			break;
		}
		else {
			printf("%d��°���� ������ �����մϴ�.\n", number - 1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
}



#endif