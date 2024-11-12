#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

void choose_Project(project** start,task **start_T) {
	int choose = 0;
	char eat;
	while (choose != -1) {
		printf("1)新增任務類型 2)刪除任務類型 3)修改任務類型 4)列出所有任務類型 -1)上一步:");
		scanf("%d%c", &choose, &eat);
		if (choose == 1) {
			ADD_P(start);//新增類型
			printf("\n");
		}
		else if (choose == 2) {
			Delect_P(start,start_T);//刪除類型
			printf("\n");
		}
		else if (choose == 3) {
			fix_P(start,start_T);//修改類型
			printf("\n");
		}
		else if (choose == 4) {
			Show_P(*start);//顯示全部類型
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
void ADD_P(project** start) {
	char name[50];
	printf("請輸入任務類型:");
	gets_s(name);
	if (strlen(name) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	if (isNameExists_P(name, start)) {//防重複名字
		printf("%s已加入類型\n", name);
	}
	else {
		project* newMember = createMember_P(name);//創節點

		if (*start == NULL) {//如果沒資料加入頭
			*start = newMember;
		}
		else {//從尾巴加
			project* current = *start;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newMember;
		}
	}
}
void Delect_P(project** front,task**start_T) {//刪除類別
	if (*front == NULL) {
		printf("沒類型。\n");
		return;
	}

	printf("請輸入要刪除類型:");
	char name[50];
	gets_s(name);
	
	project* current = *front;
	project* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {//防有沒有重複

			if (!isNameExists_Ting(name, start_T)) {//防類別有沒有正在使用
				if (previous == NULL) {//判斷是不是頭
					*front = current->next;
				}
				else {//不是頭的刪除
					previous->next = current->next;
				}
				free(current);
				printf("類型:%s已刪除。\n", name);
				return;
			}
			else {
				printf("類型正在分配。\n");
				return;
			}

		}
		previous = current;
		current = current->next;
	}
	printf("找不到指定類型。\n");
}
void fix_P(project** front,task**start_T) {//修改類別名
	if (*front == NULL) {
		printf("沒類型。\n");
		return;
	}
	char n[50] = {}, eat;
	printf("請輸入要修改的類型:");
	int amount;
	gets_s(n);
	if (strlen(n) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	project* current = *front;

	if (!isNameExists_Ting(n, start_T)){//防類別有沒有正在使用
		while (current != NULL) {
			if (strcmp(current->name, n) == 0) {//有沒有找到
				int t;
				char newn[50] = {};
				printf("請輸入新任務類型名稱:");
				gets_s(newn);
				project* current2 = *front;
				while (current2 != NULL) {
					if (strcmp(current2->name, newn) == 0) {//防新增的有沒有重複
						printf("類型已存在\n");
						return;
					}

					current2 = current2->next;
				}
				printf("任務類型:%s\n已修改成%s\n", current->name, newn);
				strcpy(current->name, newn);
				return;
			}
			current = current->next;
		}
		
	}
	else {
		printf("類型正在分配。\n");
		printf("確定要修改嗎?(Y/N)");
		char YN[50];
		gets_s(YN);
		if (YN[0] == 'Y' && strlen(YN) == 1) {
			while (current != NULL) {
				if (strcmp(current->name, n) == 0) {//有沒有找到
					int t;
					char newn[50] = {};
					printf("請輸入新任務類型名稱:");
					gets_s(newn);

					project* current2 = *front;
					while (current2 != NULL) {
						if (strcmp(current2->name, newn) == 0) {//防新增的有沒有重複
							printf("類型已存在\n");
							return;
						}
				//		previous = current2;
						current2 = current2->next;
					}
					task* current3 = *start_T;
					while (current3 != NULL) {
						if (strcmp(current3->task_type, n) == 0) {//防新增的有沒有重複
							break;
						}
						current3 = current3->next;
					}
					printf("任務類型:%s\n已修改成%s\n", current->name, newn);
					strcpy(current->name, newn);
					strcpy(current3->task_type, newn);
					return;
				}
				current = current->next;
			}
		//	previous = current;
			
		}
		else if (YN[0] == 'N' && strlen(YN) == 1) {
			printf("不修改類型\n");
		}
		return;
	}
	printf("找不到指定類型。\n");
}

void Show_P(project* front) {//秀全部類別
	if (front == NULL) {
		printf("沒類型。\n");
		return;
	}
	project* temp = front;
	while (temp != NULL) {
		printf("類型: %s\n\n", temp->name);
		temp = temp->next;
	}
}

int isNameExists_P(char* name, project** front) {//判斷類別是否存在

	project* current = *front;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			return 1; // 姓名已存在
		}
		current = current->next;
	}
	return 0; // 姓名不存在
}

int isNameExists_Ting(char* name, task** front) {//判斷在任務是否已經使用過
	task* current = *front;
	while (current != NULL) {
		if (strcmp(current->task_type, name) == 0) {
			return 1; // 類別正在分配使用
		}
		current = current->next;
	}
	return 0; // 類別沒被用到過
}

project* createMember_P(char* n) {//創新節點
	project* newMember = (project*)malloc(sizeof(project));
	strcpy(newMember->name, n);
	newMember->next = NULL;
	return newMember;
}