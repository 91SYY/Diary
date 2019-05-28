#ifdef SCHEDULE
#else
#define SCHEDULE

#include "index.h"
#include "struct.h"
#include "save.h"
#include "calendar.h"

void sc_add();
void sc_secretadd();


void add() {
	int num;

	while (1) {

		printf("��1.�Ϲ������߰�����2.��������߰�����3.���ư��⡽\n");
		printf("���Է¡�: ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			sc_add();
			break;
		case 2:
			sc_secretadd();
			break;
		case 3:
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
void sc_add() {
	char yn, yn2;
	int check=1, i;
	sc * data = (sc*)malloc(sizeof(sc));
	data->next = NULL;
	data->pw = 0000;
	s_tail->next = data;
	data->pre = s_tail;
	s_tail = data;

	while (1) {
		getchar();
		printf("%d�� %d�� %d��\n", Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday);
		printf("���ó�¥�� ������ �߰��Ͻðڽ��ϱ�?��Y|N��\n");
		printf("���Է¡�: ");
		scanf("%c", &yn);

		if (yn == 'y' || yn == 'Y') {
			data->year = Time->tm_year + 1900;
			data->month = Time->tm_mon + 1;
			data->day = Time->tm_mday;
			break;
		}
		else if (yn == 'n' || yn == 'N') {
			while (check) {
				data->year = year;
				data->month = month;
				printf("%d�� %d��\n", data->year, data->month);
				data->day = day_in();

				while (1) {
					getchar();
					printf("%d�� %d�� %d��\n", data->year, data->month, data->day);
					printf("�Էµ� ��¥�� �½��ϱ�?��Y|N��\n");
					printf("���Է¡�: ");
					scanf("%c", &yn2);
					if (yn2 == 'y' || yn2 == 'Y') {
						check = 0;
						break;
					}
					else if (yn2 == 'n' || yn2 == 'N') {
						system("cls");
						calendar_disp(2);
						return;
					}
					else {
						printf("�߸��Է��ϼ̽��ϴ�.\n");
						printf("�ٽ��Է����ּ���.\n");
						system("pause");
						system("cls");
						calendar_disp(2);
						return;
					}
				}
			}
			break;
		}
		else {
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("�ٽ��Է����ּ���.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
	//
		printf("���� : ");
		scanf("%s", data->title);
		//gets_s(data->title, sizeof(data->title));
		printf("���� : ");
		scanf("%s", data->memo);
		//gets_s(data->memo, sizeof(data->memo));

		printf("�߰� ��");
		Sleep(500);
		for (i = 0; i < 3; i++) {
			printf(".");
			Sleep(500);
		}
		printf("\n");
		printf("�߰��Ϸ�!\n");
		system("pause");

	sort();
	save();//���� �߰��ɶ����� ����

	system("cls");
	calendar_disp(2);
}
void sc_secretadd() {
	char yn, yn2;
	int check = 1, i;
	sc * data = (sc*)malloc(sizeof(sc));
	data->next = NULL;
	s_tail->next = data;
	data->pre = s_tail;
	s_tail = data;


	while (1) {
		getchar();
		printf("%d�� %d�� %d��\n", Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday);
		printf("���ó�¥�� ������ �߰��Ͻðڽ��ϱ�?��Y|N��\n");
		printf("���Է¡�: ");
		scanf("%c", &yn);

		if (yn == 'y' || yn == 'Y') {

			data->year = Time->tm_year + 1900;
			data->month = Time->tm_mon + 1;
			data->day = Time->tm_mday;
			break;
		}
		else if (yn == 'n' || yn == 'N') {
			while (check) {
					data->year = year;
					data->month = month;
					printf("%d�� %d��\n", data->year, data->month);
					data->day = day_in();

				while (1) {
					getchar();
					printf("%d�� %d�� %d��\n", data->year, data->month, data->day);
					printf("�Էµ� ��¥�� �½��ϱ�?��Y|N��\n");
					printf("���Է¡�: ");
					scanf("%c", &yn2);


					if (yn2 == 'y' || yn2 == 'Y') {
						check = 0;
						break;
					}
					else if (yn2 == 'n' || yn2 == 'N') {
						system("cls");
						calendar_disp(2);
						return;
					}
					else {
						printf("�߸��Է��ϼ̽��ϴ�.\n");
						printf("�ٽ��Է����ּ���.\n");
						system("pause");
						system("cls");
					}
				}
			}
			break;
		}
		else {
			printf("�߸��Է��ϼ̽��ϴ�.\n");
			printf("�ٽ��Է����ּ���.\n");
			system("pause");
			system("cls");
		}
	}

		printf("��й�ȣ : ");
		scanf("%d", &data->pw);
		printf("���� : ");
		scanf("%s", data->title);
		//gets_s(data->title, sizeof(data->title));
		printf("���� : ");
		scanf("%s", data->memo);
		//gets_s(data->memo, sizeof(data->memo));

		printf("�߰� ��");
		Sleep(500);
		for (i = 0; i < 3; i++) {
			printf(".");
			Sleep(500);
		}
		printf("\n");
		printf("�߰��Ϸ�!\n");
		system("pause");

	sort();
	save();//���� �߰��ɶ����� ����

	system("cls");
	calendar_disp(2);

}

#endif