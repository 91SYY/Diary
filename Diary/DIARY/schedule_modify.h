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
	
		printf("【1.일정 삭제】【2.이어 쓰기】【3.비밀 메모로 변경】【4.돌아가기】\n");
		printf("【입력】: ");
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
			printf("잘못입력하셨습니다.\n");
			printf("다시입력해주세요.\n");
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
		printf("%d년 %d월\n", y, m);
		d = day_in();

		if (search(y, m, d)) break;

		system("cls");
		calendar_disp(2);
		return;
	}

	while (1) {

		number = disp_ymd(y, m, d);

		printf("몇번째를 삭제하시겠습니까? : ");
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
				printf("비밀메모입니다.\n");
				printf("비밀번호를 입력해 주세요.\n");
				printf("입력 : ");
				scanf("%d", &pw);

				if (del->pw != pw) {
					printf("일치하지않는 비밀번호 입니다.\n");
					system("pause");
					system("cls");
					return;
				}
				else {
					printf("인증에 성공하였습니다.\n");
					Sleep(500);
				}
			}
			if (del->next != NULL)
				del->next->pre = del->pre;
			del->pre->next = del->next;
			free(del);
			printf("삭제 중");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n삭제완료!\n");
			system("pause");
			system("cls");
			break;

		}
		else {
			printf("%d번째까지 일정이 존재합니다.\n", number - 1);
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
	printf("해당날짜에 등록된 일정이 없습니다.\n");
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
		printf("%d년 %d월\n", y, m);
		d = day_in();

		if (search(y, m, d)) break;

		system("cls");
		calendar_disp(2);
		return;
	}

	while (1) {

		number = disp_ymd(y, m, d);

		printf("몇번째에 이어쓰기 하시겠습니까? : ");
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
				printf("비밀메모입니다.\n");
				printf("비밀번호를 입력해 주세요.\n");
				printf("입력 : ");
				scanf("%d", &pw);

				if (modi->pw != pw) {
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
			printf("현재 제목 : %s\n", modi->title);
			printf("변경 할 제목 입력 : ");
			scanf("%s", modi->title);
			printf("현재 일정 : %s\n", modi->memo);
			printf("추가 할 내용 입력 : ");
			scanf("%s", str);
			strcat(modi->memo, str);

			printf("수정 중");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n수정완료!\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			break;

		}
		else {
			printf("%d번째까지 일정이 존재합니다.\n", number - 1);
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
		printf("%d년 %d월\n", y, m);
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
					printf("%d년 %d월 %d일\n", list->year, list->month, list->day);
					printf("제목 : %s\n", list->title);
					printf("일정 : %s\n", list->memo);
					printf("-----------------------------------\n");
					number++;
				}
			}
			list = list->next;
		}
		if (number == 1) {
			printf("일반 일정이 없습니다.\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}

		printf("몇번째 일정을 비밀일정으로 변경하시겠습니까? : ");
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

			printf("비밀번호 설정 : ");
			scanf("%d", &pw);
			modi->pw = pw;
			printf("변경 중");
			Sleep(500);
			for (j = 0; j < 3; j++) {
				printf(".");
				Sleep(500);
			}
			printf("\n변경완료!\n");
			system("pause");
			system("cls");
			calendar_disp(2);
			break;
		}
		else {
			printf("%d번째까지 일정이 존재합니다.\n", number - 1);
			system("pause");
			system("cls");
			calendar_disp(2);
			return;
		}
	}
}



#endif