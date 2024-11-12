struct project//����
{
	char name[50];//���O�W
	project* next;
};

struct team//�p��
{
	char name[50];//�W�r
	char cell[50];//�q��
	char role[50];//����
	team* next;
};

struct task//���Ȥ��t
{
	char task_name[50];//���ȦW
	char task_caption[50];//���Ȼ���
	char task_imp[50];//���n��
	char task_people[50];//�t�d�H
	char task_type[50];//����
	char task_time[50];//�ɵ{
	char task_progress[50];//�ثe�i��
	char task_mark[50];//���O
	task* next;
};

#ifndef FUNCTION_H
#define FUNCTION_H

void ADD(team** start);//�s�W�H��
void Delect(team** front);//�R���H��
void fix(team** front);//�ק�H����T
void Show(team* front);//��ܥ����H��
void choose_team(team **start);//��ܤp��
int isNameExists(char* name, team **front);//�P�_�W�r�O�_�X�{�L
team* createMember(char name[], char phone[], char role[]);//�и`�I

#endif // !FUNCTION_H

#ifndef PROJECT_H//���O
#define PROJECT_H
int isNameExists_Ting(char* name, task** front);//�P�_���O�O�_���b�Q�ϥ�

void ADD_P(project** start);//�s�W���O
void Delect_P(project** front,task**start_T);//�R�����O
void fix_P(project** front,task ** start_T);//�ק����O
void Show_P(project* front);//������O
void choose_Project(project** start, task** start_T);//������O����
int isNameExists_P(char* name, project** front);//�P�_���O�O�_����
project* createMember_P(char* name);

#endif // !FUNCTION_H

#ifndef TSAK_H//���O
#define TSAK_H
void choose_Free(team** start, project** start_P, task** start_T);
void choose_Task(team** start, project** start_P, task** start_T);//��ܥ��Ȥ���
void ADD_T(team** start, project** start_P, task** start_T);//�s�W����
void Delect_T(task** front);//�R������
void fix_T(task** front, project**start_P);//�ק�������O
void fix_T_T(team** start,task** front, project** start_P);//�ק���ȸ�T
void Show_T_T(team* front);//��ܤp�զ���
void Show_T(task* front);//��ܥ���
void Show_P_T(project* front);//������O����
int isNameExists_T(char* name, task** front);//�P�_���ȦW�O�_������
task* createMember_T(char* name, char* caption, char* imp, char* people, char* type, char* time, char* progress, char* mark);//�и`�I

#endif // !FUNCTION_H