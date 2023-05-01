#pragma once
#define NAME_MAX_LENGTH 15
#define SUB_SUPV_NUM 100
#define STAFF_MAX_NUM 1000
#define DEPART_MAX_NUM 20
typedef struct LNode
{
	int sub_num = 0;
	int staff_num = 0;
	char data[NAME_MAX_LENGTH];//��������
	struct LNode* next;
	char supervisor[NAME_MAX_LENGTH];//����
	char subSupervisor[SUB_SUPV_NUM][NAME_MAX_LENGTH];//���ܸ�ְ
	char staff[STAFF_MAX_NUM][NAME_MAX_LENGTH];//��Ա
	
}LNode, *LinkList;

typedef struct departStaff
{
	char staffName[10];
	int department_num=0;//��Ա���Ĳ�������
	char department[DEPART_MAX_NUM][2][NAME_MAX_LENGTH];
}departStaff,Staff[STAFF_MAX_NUM];


void CreateList_L(LinkList &L, int n, const char depart[]);
int ListInsert_L(LinkList L, int i, const char elem[]);
int ListDelete_L(LinkList L, const char elem[]);
void LinkDisplay_L(LinkList L);
int Link_Insert(LinkList L, const char elem[], const char name[],const char job[]);
int ListInsert_Staff(departStaff L[], const char name[], const char depart[], const char job[]);
int StaffDisplay(departStaff S[], char name[]);
