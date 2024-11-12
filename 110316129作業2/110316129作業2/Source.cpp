#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

int main() {
	int choose = 0;
	team* start = NULL;
	project* start_P = NULL;
	task* start_T = NULL;

	while (choose != -1) {
		printf("1)小組 2)專案 3)任務 -1)結束:");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			choose_team(&start);//選擇小組部分
			break;
		case 2:
			choose_Project(&start_P,&start_T);//選擇類別部分
			break;
		case 3:
			choose_Task(&start, &start_P, &start_T);//選擇任務部分
			break;
		case -1://free調不要記憶體遺漏
			choose_Free(&start, &start_P, &start_T);//選擇任務部分
			
			printf("結束\n");
			break;
		default:
			printf("沒這選項\n");
			break;
		}
	}
	return 0;
}