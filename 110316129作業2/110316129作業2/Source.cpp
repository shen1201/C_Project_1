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
		printf("1)�p�� 2)�M�� 3)���� -1)����:");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			choose_team(&start);//��ܤp�ճ���
			break;
		case 2:
			choose_Project(&start_P,&start_T);//������O����
			break;
		case 3:
			choose_Task(&start, &start_P, &start_T);//��ܥ��ȳ���
			break;
		case -1://free�դ��n�O�����|
			choose_Free(&start, &start_P, &start_T);//��ܥ��ȳ���
			
			printf("����\n");
			break;
		default:
			printf("�S�o�ﶵ\n");
			break;
		}
	}
	return 0;
}