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
	int tm_sec; /* 초 - [0～61]  */ 
	int tm_min; /* 분 - [0～59] */ 
	int tm_hour; /* 시 - [0～23] */ 
	int tm_mday; /* 일 - [1～31] */
	int tm_mon; /* 월 - [0～11] */
	int tm_year; /* 1900부터의 년 */
	int tm_wday; /* 일요일부터의 요일 - [0～6] */ 
	int tm_yday; /* 년초부터의 통산 일수 - [0～365] */ 
	int tm_isdst; /* 서머 타임이 유효하면 양수, 유효하지 않으면 0, 불명이면 음수*/ 
}tm;

char tmp_id[20], tmp_pw[20];
int year, month, day;
sc *s_head = NULL, *s_tail = NULL;
tm *Time;

#endif