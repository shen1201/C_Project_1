struct project//類型
{
	char name[50];//類別名
	project* next;
};

struct team//小組
{
	char name[50];//名字
	char cell[50];//電話
	char role[50];//角色
	team* next;
};

struct task//任務分配
{
	char task_name[50];//任務名
	char task_caption[50];//任務說明
	char task_imp[50];//重要性
	char task_people[50];//負責人
	char task_type[50];//類型
	char task_time[50];//時程
	char task_progress[50];//目前進度
	char task_mark[50];//註記
	task* next;
};

#ifndef FUNCTION_H
#define FUNCTION_H

void ADD(team** start);//新增人員
void Delect(team** front);//刪除人員
void fix(team** front);//修改人員資訊
void Show(team* front);//顯示全部人員
void choose_team(team **start);//選擇小組
int isNameExists(char* name, team **front);//判斷名字是否出現過
team* createMember(char name[], char phone[], char role[]);//創節點

#endif // !FUNCTION_H

#ifndef PROJECT_H//類別
#define PROJECT_H
int isNameExists_Ting(char* name, task** front);//判斷類別是否正在被使用

void ADD_P(project** start);//新增類別
void Delect_P(project** front,task**start_T);//刪除類別
void fix_P(project** front,task ** start_T);//修改類別
void Show_P(project* front);//顯示類別
void choose_Project(project** start, task** start_T);//選擇類別分類
int isNameExists_P(char* name, project** front);//判斷類別是否重複
project* createMember_P(char* name);

#endif // !FUNCTION_H

#ifndef TSAK_H//類別
#define TSAK_H
void choose_Free(team** start, project** start_P, task** start_T);
void choose_Task(team** start, project** start_P, task** start_T);//選擇任務分貝
void ADD_T(team** start, project** start_P, task** start_T);//新增任務
void Delect_T(task** front);//刪除任務
void fix_T(task** front, project**start_P);//修改任務類別
void fix_T_T(team** start,task** front, project** start_P);//修改任務資訊
void Show_T_T(team* front);//顯示小組成員
void Show_T(task* front);//顯示任務
void Show_P_T(project* front);//顯示類別種類
int isNameExists_T(char* name, task** front);//判斷任務名是否有重複
task* createMember_T(char* name, char* caption, char* imp, char* people, char* type, char* time, char* progress, char* mark);//創節點

#endif // !FUNCTION_H