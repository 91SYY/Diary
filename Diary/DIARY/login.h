#ifdef LOGIN
#else
#define LOGIN

#include "index.h"
#include "struct.h"

int Main_Menu();
int Login();
int Id_Load();
int Entry();
void gotoxy(int x, int y);
void disp_diary_login();


//����������������������������������
//��碹��������������

int Main_Menu() {
	int num;
	int x = 15, y = 5;
	while (1) {
		system("cls");
		disp_diary_login();
		gotoxy(x, y);
		printf("��1.�α��Ρ���2.ȸ�����ԡ���3.���᡽");
		gotoxy(x, y + 2);
		printf("�����á�: ");
		scanf("%d", &num);
		getchar();
		switch (num) {
		case 1:
			if (Login()) {
				gotoxy(x + 5, y + 8);
				printf("%s�� ȯ���մϴ�!\n\n", tmp_id);
				gotoxy(x + 5, y + 9);
				system("pause");
				system("cls");
				return 1;
			}
			break;
		case 2:
			if (Entry()) {
				return 1;
			}
			//Entry();
			break;
		case 3:return 0;
		default:break;
		}
	}
}
int Login() {
	int x = 25, y = 5;
	int re = 0;

	while (re == 0) {
		system("cls");
		disp_diary_login();
		gotoxy(x, y);
		printf("<  L O G I N  >");
		gotoxy(x - 5, y + 2);
		printf("���̵� : ");
		gets(tmp_id);
		gotoxy(x - 5, y + 3);
		printf("��й�ȣ : ");
		gets(tmp_pw);

		re = Id_Load();
		if (re == 1) {
			return 1;
		}
		else if (re == 2) {
			return 0;
		}
	}
}
int Id_Load() {
	FILE *p;
	int num = 0, i;
	int x = 20, y = 10;
	char id_check[20], pw_check[20], yn;

	p = fopen("c:/diary/member.txt", "r");

	while (!feof(p)) {
		fscanf(p, "%s %s\n", id_check, pw_check);
		if (!strcmp(tmp_id, id_check) && !strcmp(tmp_pw, pw_check)) {
			gotoxy(x, y);
			printf("�α���");
			Sleep(500);
			for (i = 0; i < 3; i++) {
				printf(".");
				Sleep(500);
			}
			printf("����!\n");
			fclose(p);
			return 1;
		}
	}
	fclose(p);
	gotoxy(x, y);
	printf("��ġ�����ʴ� id, pw �Դϴ�.\n");
	gotoxy(x, y + 1);
	printf("���Է��Ͻðڽ��ϱ�?(y/n)\n");
	gotoxy(x, y + 2);
	printf("�Է� :");
	while (1) {
		scanf("%c", &yn);
		getchar();
		if (yn == 'Y' || yn == 'y') {
			return 0;
		}
		else if (yn == 'N' || yn == 'n') {
			return 2;
		}
	}
}
int Entry() {
	int x = 23, y = 5;
	FILE *p;
	char id_find[20], pw_find[20];
	char yn;
	system("cls");
	disp_diary_login();
	gotoxy(x, y);
	printf("\t  <  ȸ������  >\n");
	gotoxy(x, y + 2);
	printf("���̵� : ");
	gets(tmp_id);
	gotoxy(x, y + 3);
	printf("��й�ȣ : ");
	gets(tmp_pw);
	gotoxy(x - 2, y + 5);
	printf("========================\n");
	gotoxy(x - 2, y + 6);
	printf("���̵� : %s\n", tmp_id);
	gotoxy(x - 2, y + 7);
	printf("��й�ȣ : %s\n", tmp_pw);
	gotoxy(x - 2, y + 8);
	printf("�Է��Ͻ� ���� �½��ϱ�?\n");
	gotoxy(x - 2, y + 9);
	printf("(y/n) : ");
	while (1) {
		scanf("%c", &yn);
		getchar();
		if (yn == 'N' || yn == 'n') {
			return 0;
		}
		else if (yn == 'Y' || yn == 'y') {
			p = fopen("c:/diary/member.txt", "r");

			if (p != NULL) {
				while (!feof(p)) {
					fscanf(p, "%s %s\n", id_find, pw_find);
					if (!strcmp(id_find, tmp_id)) {
						gotoxy(x, y + 11);
						printf("������ ID�� �ֽ��ϴ�. \n");
						fclose(p);
						gotoxy(x, y + 12);
						system("pause");
						return 0;
					}
				}
			}
			p = fopen("c:/diary/member.txt", "a+");
			gotoxy(x - 2, y + 11);
			fprintf(p, "%s %s\n", tmp_id, tmp_pw);//�갡 �� �� ����...??
			gotoxy(x - 2, y + 12);
			printf("ȸ�������� �Ϸ�Ǿ����ϴ�.\n");
			gotoxy(x - 2, y + 13);
			printf("���Ե� ���̵�� �α��� ���ּ���.\n");
			gotoxy(x - 2, y + 14);
			system("pause");
			fclose(p);
			return 0;
		}
	}
}
void init() {
	s_head = (sc*)malloc(sizeof(sc));
	s_head->pre = NULL;
	s_head->next = NULL;
	s_tail = s_head;
}
void load() {
	FILE *f;
	sc *move;
	char str[100] = { "c:/diary/" };
	strcat(str, tmp_id);
	strcat(str, "_schedule.txt");


	f = fopen(str, "r");

	if (f == NULL) {
		f = fopen(str, "w");
		fclose(f);
		return;
	}
	fscanf(f, "\n");
	if (feof(f)) {
		fclose(f);
		return;
	}
	f = fopen(str, "r");

	while (!feof(f)) {
		move = (sc*)malloc(sizeof(sc));
		move->next = NULL;
		fscanf(f, "%d %d %d %d %s %s\n", &move->year, &move->month, &move->day, &move->pw, move->title, move->memo);
		s_tail->next = move;
		move->pre = s_tail;
		s_tail = move;
	}
	fclose(f);
}

#endif