#include "index.h"
#include "login.h"
#include "struct.h"
#include "disp.h"
#include "schedule_add.h"
#include "schedule_modify.h"
#include "save.h"
#include "calendar.h"


void init();
void load();
int menu_disp();

void main() {
	int num;
	
	init();

	num = Main_Menu();
	if (num == 0) {
	}
	load();

	const time_t t = time(NULL);
	Time = localtime(&t);

	calendar_disp(1);
	while (1) {
		switch (menu_disp())
		{
		case 1:
			disp_();
			break;
		case 2:
			system("cls");
			calendar_disp(2);
			add();
			break;
		case 3:
			system("cls");
			calendar_disp(2);
			modify_main();
			break;
		case 4:
			system("cls");
			calendar_disp(2);
			calendar_disp(0);
			break;
		case 5 :
			printf("『종료합니다.』");
			return;
		case 6 :
			disp_all(0);//임시
			sort();
			disp_all(0);
			break;
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

