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

		printf("【1.일반일정추가】【2.비밀일정추가】【3.돌아가기】\n");
		printf("【입력】: ");
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
			printf("잘못입력하셨습니다.\n");
			printf("다시입력해주세요.\n");
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
		printf("%d년 %d월 %d일\n", Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday);
		printf("오늘날짜로 일정을 추가하시겠습니까?『Y|N』\n");
		printf("【입력】: ");
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
				printf("%d년 %d월\n", data->year, data->month);
				data->day = day_in();

				while (1) {
					getchar();
					printf("%d년 %d월 %d일\n", data->year, data->month, data->day);
					printf("입력된 날짜가 맞습니까?『Y|N』\n");
					printf("【입력】: ");
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
						printf("잘못입력하셨습니다.\n");
						printf("다시입력해주세요.\n");
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
			printf("잘못입력하셨습니다.\n");
			printf("다시입력해주세요.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
	//
		printf("제목 : ");
		scanf("%s", data->title);
		//gets_s(data->title, sizeof(data->title));
		printf("일정 : ");
		scanf("%s", data->memo);
		//gets_s(data->memo, sizeof(data->memo));

		printf("추가 중");
		Sleep(500);
		for (i = 0; i < 3; i++) {
			printf(".");
			Sleep(500);
		}
		printf("\n");
		printf("추가완료!\n");
		system("pause");

	sort();
	save();//일정 추가될때마다 저장

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
		printf("%d년 %d월 %d일\n", Time->tm_year + 1900, Time->tm_mon + 1, Time->tm_mday);
		printf("오늘날짜로 일정을 추가하시겠습니까?『Y|N』\n");
		printf("【입력】: ");
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
					printf("%d년 %d월\n", data->year, data->month);
					data->day = day_in();

				while (1) {
					getchar();
					printf("%d년 %d월 %d일\n", data->year, data->month, data->day);
					printf("입력된 날짜가 맞습니까?『Y|N』\n");
					printf("【입력】: ");
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
						printf("잘못입력하셨습니다.\n");
						printf("다시입력해주세요.\n");
						system("pause");
						system("cls");
					}
				}
			}
			break;
		}
		else {
			printf("잘못입력하셨습니다.\n");
			printf("다시입력해주세요.\n");
			system("pause");
			system("cls");
		}
	}

		printf("비밀번호 : ");
		scanf("%d", &data->pw);
		printf("제목 : ");
		scanf("%s", data->title);
		//gets_s(data->title, sizeof(data->title));
		printf("일정 : ");
		scanf("%s", data->memo);
		//gets_s(data->memo, sizeof(data->memo));

		printf("추가 중");
		Sleep(500);
		for (i = 0; i < 3; i++) {
			printf(".");
			Sleep(500);
		}
		printf("\n");
		printf("추가완료!\n");
		system("pause");

	sort();
	save();//일정 추가될때마다 저장

	system("cls");
	calendar_disp(2);

}

#endif