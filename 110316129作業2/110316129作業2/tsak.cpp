#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

void choose_Task(team** start,project** start_P, task** start_T) {
	int choose = 0;
	char eat;
	while (choose != -1) {
		printf("1)�s�W���� 2)�R������ 3)�ק�������� 4)�ק���ȸ�T 5)�C�X�Ҧ����� -1)�W�@�B:");

		scanf("%d%c", &choose, &eat);
		if (choose == 1) {
			ADD_T(start, start_P, start_T);//�s�W����
		}
		else if (choose == 2) {
			Delect_T(start_T);//�R������
		}
		else if (choose == 3) {
			fix_T(start_T,start_P);//�ק����
		}
		else if (choose == 4) {//�ק���ȸ�T
			fix_T_T(start, start_T, start_P);
		}
		else if (choose == 5) {
			Show_T(*start_T);//�q�X����
		}
		else if (choose == -1) {
			printf("\n");
			break;
		}
		else {
			printf("�S�o�ﶵ\n");
		}
	}
}
void fix_T_T(team ** start,task** front, project** start_P) {
	if (*front == NULL) {
		printf("�S�����C\n");
		return;
	}
	char caption[50];//���Ȼ���
	char imp[50];//���n��
	char people[50];//�t�d�H
	char type[50];//��������
	char time[50];//�ɵ{
	char progress[50];//�ثe�i��
	char mark[200];//���O
	char n[50] = {}, eat;
	printf("�п�J�n�ק諸����:");
	int amount;
	gets_s(n);

	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, n) == 0) {
			int t;
			char newn[50] = {};
			printf("�����ȶ}�l�ק��T:\n");
			printf("�п�J���ȭ��n��:");
			gets_s(imp);
			Show_T_T(*start);//�q�H��
			printf("�п�J���ȭt�d�H:");
			gets_s(people);
			if (isNameExists(people, start)) {//���W�r
					printf("�п�J���Ȯɵ{:");
					gets_s(time);
					printf("�п�J���ȶi��:");
					gets_s(progress);
					printf("�п�J���ȵ��O:");
					gets_s(mark);
					strcpy(current->task_imp, imp);
					strcpy(current->task_time,time);
					strcpy(current->task_progress,progress);
					strcpy(current->task_mark,mark);
					return;
			}
			else {
				printf("�䤣��H��\n");
			}

		}
		previous = current;
		current = current->next;
	}
	printf("�䤣����w�����C\n");
}

void ADD_T(team** start, project** start_P, task** start_T) {
	char name[50];//���ȦW
	char caption[50];//���Ȼ���
	char imp[50];//���n��
	char people[50];//�t�d�H
	char type[50];//��������
	char time[50];//�ɵ{
	char progress[50];//�ثe�i��
	char mark[50];//���O
	printf("�п�J���ȦW��:");
	gets_s(name);

	if (isNameExists_T(name, start_T)) {//�����ƦW�r
		printf("%s�w�[�J����\n", name);
	}
	else {
		printf("�п�J���Ȼ���:");
		gets_s(caption);
		printf("�п�J���ȭ��n��:");
		gets_s(imp);
		Show_T_T(*start);//�q�H��
		printf("�п�J���ȭt�d�H:");
		gets_s(people);
		if (isNameExists(people, start)) {//���W�r
			Show_P_T(*start_P);//�q���O
			printf("�п�J��������:");
			gets_s(type);
			if (isNameExists_P(type, start_P)) {
				printf("�п�J���Ȯɵ{:");
				gets_s(time);
				printf("�п�J���ȶi��:");
				gets_s(progress);
				printf("�п�J���ȵ��O:");
				gets_s(mark);
				task* newMember = createMember_T(name, caption, imp, people, type, time, progress, mark);//�и`�I�s�J
				if (*start_T == NULL) {//�p�G�S��ƥ[�J�Y
					*start_T = newMember;
				}
				else {//�q���ڥ[
					task* current = *start_T;
					while (current->next != NULL) {
						current = current->next;
					}
					current->next = newMember;
				}
			}
			else {
				printf("�䤣���������\n");
			}
		}
		else {
			printf("�䤣��H��\n");
		}
	}

}

void Show_T_T(team* front) {//�q�խ����t
	team* temp = front;
	printf("�{���H��:\n");
	while (temp != NULL) {
		printf("�m�W: %s\t����: %s\n\n", temp->name,temp->role);
		temp = temp->next;
	}
}

void Show_P_T(project* front) {//�q���O
	if (front == NULL) {
		printf("�S�����C\n");
		return;
	}
	project* temp = front;
	printf("�{������:\n");
	while (temp != NULL) {
		printf("����: %s\n\n", temp->name);
		temp = temp->next;
	}
}



void Delect_T(task** front) {//�R������
	if (*front == NULL) {
		printf("�S���ȡC\n");
		return;
	}
	printf("�п�J�n�R������:");
	char name[50];
	gets_s(name);
	if (strlen(name) == 0) {
		printf("�����J�ť�\n");
		return;
	}
	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, name) == 0) {//�P�_���S�����n�R��������
			if (previous == NULL) {
				*front = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);//�R��
			printf("����:%s�w�R���C\n", name);
			return;
		}
		previous = current;
		current = current->next;
	}
	printf("�䤣����w�����ȡC\n");
}

void fix_T(task** front,project**start_P) {//�ק���������u��ק靈�����O
	if (*front == NULL) {
		printf("�S�����C\n");
		return;
	}
	char n[50] = {}, eat;
	printf("�п�J�n�ק諸����:");
	int amount;
	gets_s(n);

	task* current = *front;
	task* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->task_name, n) == 0) {
			int t;
			char newn[50] = {};
			Show_P_T(*start_P);
			printf("�п�J�n�ק令����������:");
			gets_s(newn);
			if (isNameExists_P(newn, start_P)) {
				
					printf("��������:%s\n�w�ק令%s\n", current->task_type, newn);
					strcpy(current->task_type, newn);
					return;
			}
			else {
				printf("�䤣����w�����C\n");
				return;
			}
		}
		previous = current;
		current = current->next;
	}
	printf("�䤣����w�����C\n");
}

void Show_T(task* front) {//�q�X����
	if (front == NULL) {
		printf("�S���ȡC\n");
		return;
	}
	task* temp = front;
	while (temp != NULL) {
		printf("���ȦW:%s\t���Ȼ���:%s\t���n��:%s\t�t�d�H��:%s\t��������:%s\t�ɵ{:%s\t�ثe�i��:%s\t���O:%s\n\n", 
			temp->task_name, temp->task_caption, temp->task_imp, temp->task_people,temp->task_type, temp->task_time, temp->task_progress, temp->task_mark);
		temp = temp->next;
	}
}

int isNameExists_T(char* name, task** front) {//�P�_���ȩ��O�_�ιL
	task* current = *front;
	while (current != NULL) {
		if (strcmp(current->task_name, name) == 0) {
			return 1; // �m�W�w�s�b
		}
		current = current->next;
	}
	return 0; // �m�W���s�b
}

task* createMember_T(char* name,char* caption, char* imp, char* people, char* type, char* time, char* progress, char* mark) {//�и`�I
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