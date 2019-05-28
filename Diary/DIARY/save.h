#ifdef SAVE

#else
#define SAVE

#include "index.h"
#include "struct.h"


void save();
void sort();
void sort_(sc *select, sc *cmp, int *arr);

void save() {
	FILE *f;
	sc *move = s_head->next;
	char str[100] = { "c:/diary/" };
	strcat(str, tmp_id);//임시로 aa설정 원래 tmp_id가 들어가야함
	strcat(str, "_schedule.txt");

	f = fopen(str, "w");
	while (move != NULL) {
		fprintf(f, "%d %d %d %d %s %s\n", move->year, move->month, move->day, move->pw, move->title, move->memo);
		move = move->next;
	}
	fclose(f);

}

void sort() {
	sc* select, *cmp;
	int *arr[2];

	select = s_head->next;
	while (select != s_tail) {
		cmp = select->next;
		while (cmp != NULL) {
			if (select->year == cmp->year) {
				if (select->month == cmp->month) {
					if (select->day > cmp->day) {
						sort_(select, cmp, arr);
						select = arr[0];
						cmp = arr[1];
					}
				}
				else if (select->month > cmp->month)
				{
					sort_(select, cmp,arr);
					select = arr[0];
					cmp = arr[1];
				}
			}
			else if (select->year > cmp->year)
			{
				sort_(select, cmp,arr);
				select = arr[0];
				cmp = arr[1];
			}
			cmp = cmp->next;
		}
		select = select->next;
	}
}

void sort_(sc *select, sc *cmp, int *arr) {
	sc *temp = NULL;
	temp = cmp->pre;

	cmp->pre->next = cmp->next;
	if (cmp->next != NULL)
		cmp->next->pre = cmp->pre;
	select->pre->next = cmp;
	cmp->pre = select->pre;
	select->pre = cmp;
	cmp->next = select;
	select = cmp;
	cmp = temp;
	if (cmp->next == NULL)
		s_tail = cmp;

	arr[0] = select;
	arr[1] = cmp;

}

#endif