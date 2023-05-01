#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Department.h"


void CreateList_L(LinkList &L, int n,const char depart[])
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (int i = n; i > 0; i--)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));
		p->staff_num = 0;
		p->sub_num = 0;
        //scanf("%s", &p->data);
        strcpy(p->data,depart);
		p->next = L->next;
		L->next = p;
	}
	return;
}

int ListInsert_L(LinkList L, int i, const char elem[])
{
	LinkList p, s;
	p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return 0;
	s = (LinkList)malloc(sizeof(LNode));
	s->staff_num = 0;
	s->sub_num = 0;
	//s->data = elem;
	strcpy(s->data, elem);
	s->next = p->next;
	p->next = s;
	return 1;
}


int ListInsert_Staff(departStaff L[], const char name[], const char depart[],const char job[])
{
	int i = 0;
	while (true)
	{
		if (!strcmp(L[i].staffName, "\0"))
			break;
		else if (!strcmp(L[i].staffName, name))
			break;
		i++;
	}
	strcpy(L[i].staffName, name);
	strcpy(L[i].department[L[i].department_num][0], depart);//将部门放入
	strcpy(L[i].department[L[i].department_num][1], job);//将职位放入
	L[i].department_num++;

	return 0;
}

int ListDelete_L(LinkList L, const char elem[])
{
	LinkList p, q;
	p = L;
	while (p->next && strcmp(elem,p->next->data))
	{
		p = p->next;
	}
	if (!(p->next))
		return 0;
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}

void LinkDisplay_L(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
	return;
}

int Link_Insert(LinkList L, const char elem[],const char name[],const char job[])
{
	int i;
	LinkList p = {0};
	p = L->next;
	
	i = 1;
	while (p != NULL && strcmp(p->data, elem))
	{

		p = p->next;
		i++;
	}
    if(p==NULL)
        return 0;
	if(!strcmp(job,"主管"))
		strcpy(p->supervisor,name);
	else if (!strcmp(job, "主管副职"))
	{
		strcpy(p->subSupervisor[p->sub_num], name);
		p->sub_num++;
	}
	else
	{
		strcpy(p->subSupervisor[p->staff_num], name);
		p->staff_num++;
	}
    return 1;
}

int StaffDisplay(departStaff S[], char name[])
{
	int i = 0;
	while (true)
	{
		if (!strcmp(S[i].staffName, "\0"))
			return 0;
		else if (!strcmp(S[i].staffName, name))
			break;
		i++;
	}
	printf("姓名:%s\n", S[i].staffName);
	for (int cnt = 0; cnt < S[i].department_num; cnt++)
	{
		printf("部门:%s,职业:%s\n", S[i].department[cnt][0],S[i].department[cnt][1]);
	}
	return 1;
}
