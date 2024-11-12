#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

void choose_team(team  **start) {
	int choose = 0;
	char eat;
	while (choose != -1) {
		printf("1)新增成員 2)刪除成員 3)修改成員資料 4)列出所有成員 -1)上一步:");
		scanf("%d%c", &choose,&eat);
		if (choose == 1) {
			ADD(start);//新增組員
		}
		else if (choose == 2) {
			Delect(start);//刪除組員
		}
		else if (choose == 3) {//修改組員
			fix(start);
		}
		else if (choose == 4) {//顯示組員
			Show(*start);
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

void ADD(team** start) {//新增組員

	char name[50], phone[50], role[50];
	printf("請輸入姓名:");
	gets_s(name);
	if (strlen(name) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	printf("請輸入電話:");
	gets_s(phone);
	if (strlen(phone) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	printf("請輸入角色:");
	gets_s(role);
	if (strlen(role) == 0) {
		printf("不能輸入空白\n");
		return;
	}
	if (isNameExists(name, start)) {//防重複名字
		printf("%s已加入小組\n", name);
	}
	
	else {
		team* newMember = createMember(name, phone, role);//創節點

		if (*start == NULL) {//如果沒資料加入頭
			*start = newMember;
		}
		else {//從尾巴加
			team* current = *start;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newMember;
		}
	}
}
void fix(team** front) {//修改組員
	if (*front == NULL) {//判斷有沒有組員
		printf("成員列表為空。\n");
		return;
	}
	printf("請輸入要修改成員:");
	char name[50],phone[50],role[50];
	gets_s(name);
	
	team* current = *front;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {//修改資料
			char cell[50], role[50];
			printf("請輸入電話:");
			gets_s(cell);
			if (strlen(cell) == 0) {
				printf("不能輸入空白\n");
				return;
			}
			printf("請輸入角色:");
			gets_s(role);
			if (strlen(role) == 0) {
				printf("不能輸入空白\n");
				return;
			}
			strcpy(current->cell, cell);
			strcpy(current->role, role);
			printf("成員%s已修改\n電話:%s\n角色:%s\n", name,current->cell,current->role);
			return;
		}
		current = current->next;
	}
	printf("找不到指定成員。\n");
}

team* createMember(char name[], char phone[], char role[]) {//創節點
	team* newMember = (team*)malloc(sizeof(team));
	strcpy(newMember->name, name);
	strcpy(newMember->cell, phone);
	strcpy(newMember->role, role);
	newMember->next = NULL;
	return newMember;
}

int isNameExists(char* name, team **front) {//看看有沒有
	team* current = *front;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			return 1; // 姓名已存在
		}
		current = current->next;
	}
	return 0; // 姓名不存在
}

void Delect(team** front) {//刪除組員
	if (*front == NULL) {//判斷有沒有成員
		printf("成員列表為空。\n");
		return;
	}
	printf("請輸入要刪除成員:");
	char name[50];
	gets_s(name);
	

	team* current =* front;
	team* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {//找到成員
			if (previous == NULL) {//如果是頭刪除
				*front = current->next;
			}
			else {//頭以外刪除
				previous->next = current->next;
			}
			free(current);//刪除
			printf("成員%s已刪除。\n",name);
			return;
		}
		previous = current;
		current = current->next;
	}
	printf("找不到指定成員。\n");
}

void Show(team* front) {//顯示全部組員
	team* temp = front;
	if (front == NULL) {//判斷有沒有成員
		printf("成員列表為空。\n");
		return;
	}
	while (temp != NULL) {
		printf("姓名: %s\n電話: %s\n角色: %s\n\n", temp->name, temp->cell, temp->role);
		temp = temp->next;
	}
}