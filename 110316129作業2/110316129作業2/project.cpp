#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"

void choose_Project(project** start,task **start_T) {
	int choose = 0;
	char eat;
	while (choose != -1) {
		printf("1)�s�W�������� 2)�R���������� 3)�ק�������� 4)�C�X�Ҧ��������� -1)�W�@�B:");
		scanf("%d%c", &choose, &eat);
		if (choose == 1) {
			ADD_P(start);//�s�W����
			printf("\n");
		}
		else if (choose == 2) {
			Delect_P(start,start_T);//�R������
			printf("\n");
		}
		else if (choose == 3) {
			fix_P(start,start_T);//�ק�����
			printf("\n");
		}
		else if (choose == 4) {
			Show_P(*start);//��ܥ�������
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
void ADD_P(project** start) {
	char name[50];
	printf("�п�J��������:");
	gets_s(name);
	if (strlen(name) == 0) {
		printf("�����J�ť�\n");
		return;
	}
	if (isNameExists_P(name, start)) {//�����ƦW�r
		printf("%s�w�[�J����\n", name);
	}
	else {
		project* newMember = createMember_P(name);//�и`�I

		if (*start == NULL) {//�p�G�S��ƥ[�J�Y
			*start = newMember;
		}
		else {//�q���ڥ[
			project* current = *start;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newMember;
		}
	}
}
void Delect_P(project** front,task**start_T) {//�R�����O
	if (*front == NULL) {
		printf("�S�����C\n");
		return;
	}

	printf("�п�J�n�R������:");
	char name[50];
	gets_s(name);
	
	project* current = *front;
	project* previous = NULL;

	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {//�����S������

			if (!isNameExists_Ting(name, start_T)) {//�����O���S�����b�ϥ�
				if (previous == NULL) {//�P�_�O���O�Y
					*front = current->next;
				}
				else {//���O�Y���R��
					previous->next = current->next;
				}
				free(current);
				printf("����:%s�w�R���C\n", name);
				return;
			}
			else {
				printf("�������b���t�C\n");
				return;
			}

		}
		previous = current;
		current = current->next;
	}
	printf("�䤣����w�����C\n");
}
void fix_P(project** front,task**start_T) {//�ק����O�W
	if (*front == NULL) {
		printf("�S�����C\n");
		return;
	}
	char n[50] = {}, eat;
	printf("�п�J�n�ק諸����:");
	int amount;
	gets_s(n);
	if (strlen(n) == 0) {
		printf("�����J�ť�\n");
		return;
	}
	project* current = *front;

	if (!isNameExists_Ting(n, start_T)){//�����O���S�����b�ϥ�
		while (current != NULL) {
			if (strcmp(current->name, n) == 0) {//���S�����
				int t;
				char newn[50] = {};
				printf("�п�J�s���������W��:");
				gets_s(newn);
				project* current2 = *front;
				while (current2 != NULL) {
					if (strcmp(current2->name, newn) == 0) {//���s�W�����S������
						printf("�����w�s�b\n");
						return;
					}

					current2 = current2->next;
				}
				printf("��������:%s\n�w�ק令%s\n", current->name, newn);
				strcpy(current->name, newn);
				return;
			}
			current = current->next;
		}
		
	}
	else {
		printf("�������b���t�C\n");
		printf("�T�w�n�ק��?(Y/N)");
		char YN[50];
		gets_s(YN);
		if (YN[0] == 'Y' && strlen(YN) == 1) {
			while (current != NULL) {
				if (strcmp(current->name, n) == 0) {//���S�����
					int t;
					char newn[50] = {};
					printf("�п�J�s���������W��:");
					gets_s(newn);

					project* current2 = *front;
					while (current2 != NULL) {
						if (strcmp(current2->name, newn) == 0) {//���s�W�����S������
							printf("�����w�s�b\n");
							return;
						}
				//		previous = current2;
						current2 = current2->next;
					}
					task* current3 = *start_T;
					while (current3 != NULL) {
						if (strcmp(current3->task_type, n) == 0) {//���s�W�����S������
							break;
						}
						current3 = current3->next;
					}
					printf("��������:%s\n�w�ק令%s\n", current->name, newn);
					strcpy(current->name, newn);
					strcpy(current3->task_type, newn);
					return;
				}
				current = current->next;
			}
		//	previous = current;
			
		}
		else if (YN[0] == 'N' && strlen(YN) == 1) {
			printf("���ק�����\n");
		}
		return;
	}
	printf("�䤣����w�����C\n");
}

void Show_P(project* front) {//�q�������O
	if (front == NULL) {
		printf("�S�����C\n");
		return;
	}
	project* temp = front;
	while (temp != NULL) {
		printf("����: %s\n\n", temp->name);
		temp = temp->next;
	}
}

int isNameExists_P(char* name, project** front) {//�P�_���O�O�_�s�b

	project* current = *front;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			return 1; // �m�W�w�s�b
		}
		current = current->next;
	}
	return 0; // �m�W���s�b
}

int isNameExists_Ting(char* name, task** front) {//�P�_�b���ȬO�_�w�g�ϥιL
	task* current = *front;
	while (current != NULL) {
		if (strcmp(current->task_type, name) == 0) {
			return 1; // ���O���b���t�ϥ�
		}
		current = current->next;
	}
	return 0; // ���O�S�Q�Ψ�L
}

project* createMember_P(char* n) {//�зs�`�I
	project* newMember = (project*)malloc(sizeof(project));
	strcpy(newMember->name, n);
	newMember->next = NULL;
	return newMember;
}