#ifdef STRUCT

#else
#define STRUCT

#include "index.h"
#include "login.h"

typedef struct Schedule {
	int year;
	int month;
	int day;
	int pw;
	char title[30];
	char memo[100];
	struct Schedule *pre;
	struct Schedule *next;
}sc;

typedef struct Timer
{
	int tm_sec; /* �� - [0��61]  */ 
	int tm_min; /* �� - [0��59] */ 
	int tm_hour; /* �� - [0��23] */ 
	int tm_mday; /* �� - [1��31] */
	int tm_mon; /* �� - [0��11] */
	int tm_year; /* 1900������ �� */
	int tm_wday; /* �Ͽ��Ϻ����� ���� - [0��6] */ 
	int tm_yday; /* ���ʺ����� ��� �ϼ� - [0��365] */ 
	int tm_isdst; /* ���� Ÿ���� ��ȿ�ϸ� ���, ��ȿ���� ������ 0, �Ҹ��̸� ����*/ 
}tm;

char tmp_id[20], tmp_pw[20];
int year, month, day;
sc *s_head = NULL, *s_tail = NULL;
tm *Time;

#endif