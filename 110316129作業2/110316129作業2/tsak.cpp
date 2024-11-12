#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

void choose_Task(team** start,project** start_P, task** start_T) {
	int choose = 0;
	char eat;
	while (choose != -1) {
		printf("1)新增任務 2)刪除任務 3)修改任務類型 4)修改任務資訊 5)列出所有任務 -1)上一步:");

		scanf("%d%c", &choose, &eat);
		if (choose == 1) {
			ADD_T(start, start_P, start_T);//新增任務
		}
		else if (choose == 2) {
			Delect_T(start_T);//刪除任務
		}
		else if (choose == 3) {
			fix_T(start_T,start_P);//修改任務
		}
		else if (choose == 4) {//修改任務資訊
			fix_T_T(start, start_T, start_P);
		}
		else if (choose == 5) {
			Show_T(*start_T);//秀出任務
		}
		else if (choose == -1) {
			printf("\n");
			break;
		}
		else {
			printf("沒這選項\n");
		}
	}
}
void fix_T_T(team ** start,task** front, project** start_P) {
	if (*front == NULL) {
		printf("沒類型。\n");
		return;
	}
	char caption[50];//任務說明
	char imp[50];//重要性
	char people[50];//負責人
	char type[50];//任務類型
	char time[50];//時程
	char progress[50];//目前進度
	char mark[200];//註記
	char n[50] = {}, eat;
	printf("請輸入要修改的任務:");
	int amount;
	gets_s(n);

	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, n) == 0) {
			int t;
			char newn[50] = {};
			printf("找到任務開始修改資訊:\n");
			printf("請輸入任務重要性:");
			gets_s(imp);
			Show_T_T(*start);//秀人員
			printf("請輸入任務負責人:");
			gets_s(people);
			if (isNameExists(people, start)) {//防名字
					printf("請輸入任務時程:");
					gets_s(time);
					printf("請輸入任務進度:");
					gets_s(progress);
					printf("請輸入任務註記:");
					gets_s(mark);
					strcpy(current->task_imp, imp);
					strcpy(current->task_time,time);
					strcpy(current->task_progress,progress);
					strcpy(current->task_mark,mark);
					return;
			}
			else {
				printf("找不到人員\n");
			}

		}
		previous = current;
		current = current->next;
	}
	printf("找不到指定類型。\n");
}

void ADD_T(team** start, project** start_P, task** start_T) {
	char name[50];//任務名
	char caption[50];//任務說明
	char imp[50];//重要性
	char people[50];//負責人
	char type[50];//任務類型
	char time[50];//時程
	char progress[50];//目前進度
	char mark[50];//註記
	printf("請輸入任務名稱:");
	gets_s(name);

	if (isNameExists_T(name, start_T)) {//防重複名字
		printf("%s已加入類型\n", name);
	}
	else {
		printf("請輸入任務說明:");
		gets_s(caption);
		printf("請輸入任務重要性:");
		gets_s(imp);
		Show_T_T(*start);//秀人員
		printf("請輸入任務負責人:");
		gets_s(people);
		if (isNameExists(people, start)) {//防名字
			Show_P_T(*start_P);//秀類別
			printf("請輸入任務類型:");
			gets_s(type);
			if (isNameExists_P(type, start_P)) {
				printf("請輸入任務時程:");
				gets_s(time);
				printf("請輸入任務進度:");
				gets_s(progress);
				printf("請輸入任務註記:");
				gets_s(mark);
				task* newMember = createMember_T(name, caption, imp, people, type, time, progress, mark);//創節點存入
				if (*start_T == NULL) {//如果沒資料加入頭
					*start_T = newMember;
				}
				else {//從尾巴加
					task* current = *start_T;
					while (current->next != NULL) {
						current = current->next;
					}
					current->next = newMember;
				}
			}
			else {
				printf("找不到任務類型\n");
			}
		}
		else {
			printf("找不到人員\n");
		}
	}

}

void Show_T_T(team* front) {//秀組員分配
	team* temp = front;
	printf("現有人員:\n");
	while (temp != NULL) {
		printf("姓名: %s\t角色: %s\n\n", temp->name,temp->role);
		temp = temp->next;
	}
}

void Show_P_T(project* front) {//秀類別
	if (front == NULL) {
		printf("沒類型。\n");
		return;
	}
	project* temp = front;
	printf("現有類型:\n");
	while (temp != NULL) {
		printf("類型: %s\n\n", temp->name);
		temp = temp->next;
	}
}



void Delect_T(task** front) {//刪除任務
	if (*front == NULL) {
		printf("沒任務。\n");
		return;
	}
	printf("請輸入要刪除任務:");
	char name[50];
	gets_s(name);
	if (strlen(name) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, name) == 0) {//判斷有沒有找到要刪除的任務
			if (previous == NULL) {
				*front = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);//刪除
			printf("任務:%s已刪除。\n", name);
			return;
		}
		previous = current;
		current = current->next;
	}
	printf("找不到指定類任務。\n");
}

void fix_T(task** front,project**start_P) {//修改任務類型只能修改有的類別
	if (*front == NULL) {
		printf("沒類型。\n");
		return;
	}
	char n[50] = {}, eat;
	printf("請輸入要修改的任務:");
	int amount;
	gets_s(n);

	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, n) == 0) {
			int t;
			char newn[50] = {};
			Show_P_T(*start_P);
			printf("請輸入要修改成的任務類型:");
			gets_s(newn);
			if (isNameExists_P(newn, start_P)) {
				
					printf("任務類型:%s\n已修改成%s\n", current->task_type, newn);
					strcpy(current->task_type, newn);
					return;
			}
			else {
				printf("找不到指定類型。\n");
				return;
			}
		}
		previous = current;
		current = current->next;
	}
	printf("找不到指定類型。\n");
}

void Show_T(task* front) {//秀出任務
	if (front == NULL) {
		printf("沒任務。\n");
		return;
	}
	task* temp = front;
	while (temp != NULL) {
		printf("任務名:%s\t任務說明:%s\t重要性:%s\t負責人員:%s\t任務類型:%s\t時程:%s\t目前進度:%s\t註記:%s\n\n", 
			temp->task_name, temp->task_caption, temp->task_imp, temp->task_people,temp->task_type, temp->task_time, temp->task_progress, temp->task_mark);
		temp = temp->next;
	}
}

int isNameExists_T(char* name, task** front) {//判斷任務明是否用過
	task* current = *front;
	while (current != NULL) {
		if (strcmp(current->task_name, name) == 0) {
			return 1; // 姓名已存在
		}
		current = current->next;
	}
	return 0; // 姓名不存在
}

task* createMember_T(char* name,char* caption, char* imp, char* people, char* type, char* time, char* progress, char* mark) {//創節點
	task* newMember = (task*)malloc(sizeof(task));
	strcpy(newMember->task_name, name);
	strcpy(newMember->task_caption, people);
	strcpy(newMember->task_imp, imp);
	strcpy(newMember->task_people, people);
	strcpy(newMember->task_type, type);
	strcpy(newMember->task_time, time);
	strcpy(newMember->task_progress, progress);
	strcpy(newMember->task_mark, mark);
	newMember->next = NULL;
	return newMember;
}

void choose_Free(team** start, project** start_P, task** start_T) {
	while (*start != NULL) {
		team* by = *start;
		*start = (*start)->next;
		free(by);
	}

	while (*start_P != NULL) {
		project* by = *start_P;
		*start_P = (*start_P)->next;
		free(by);
	}
	while (*start_T != NULL) {
		task* by = (*start_T);
		*start_T = (*start_T)->next;
		free(by);
	}
}