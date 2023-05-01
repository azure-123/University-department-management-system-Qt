#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "Department.h"
#include <iostream>
#include <QDebug>
#include<QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


LinkList _list=NULL;
departStaff S[100];
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_insertDepartment_clicked()
{
    QString output;
    QString Qdepartment=ui->lineEdit_inputDepartment->text();
    string Sdepartment=Qdepartment.toStdString();
    const char* department=Sdepartment.c_str();
    if(_list==NULL)
    {
        CreateList_L(_list,1,department);
    }
    else
    {
        ListInsert_L(_list,1,department);
    }
    //输出
    LinkList p;
    p = _list->next;
    output.append("当前部门：\n");
    //qDebug()<<"当前部门：\n";
    while (p)
    {
        //printf("%s\n", p->data);
        //qDebug()<<p->data;
        output.append(p->data);
        output.append("\n");
        p = p->next;
    }
    ui->lineEdit_inputDepartment->clear();
    ui->textEdit_output->setText(output);
}



void MainWindow::on_pushButton_deleteDepartment_clicked()
{
    QString output;
    QString Qdepartment=ui->lineEdit_inputDepartment->text();
    string Sdepartment=Qdepartment.toStdString();
    const char* department=Sdepartment.c_str();
    int judge=ListDelete_L(_list,department);
    if(judge==0)
    {
        QMessageBox::critical(this,"错误","找不到该部门！");
        return;
    }
    //输出
    LinkList p;
    p = _list->next;
    //qDebug()<<"当前部门：";
    output.append("当前部门：\n");
    while (p)
    {
        //printf("%s\n", p->data);
        //qDebug()<<p->data;
        output.append(p->data);
        p = p->next;
    }
    ui->lineEdit_inputDepartment->clear();
    ui->textEdit_output->setText(output);
}



void MainWindow::on_pushButton_insertStaff_clicked()
{
    //字符串转换
    QString output;
    QString Qdepartment=ui->lineEdit_inputDepartment_staff->text();
    string Sdepartment=Qdepartment.toStdString();
    const char* department=Sdepartment.c_str();

    QString QstaffName=ui->lineEdit_inputStaff_insert->text();
    string SstaffName=QstaffName.toStdString();
    const char* staffName=SstaffName.c_str();

    QString Qjob=ui->lineEdit_inputJob->text();
    string Sjob=Qjob.toStdString();
    const char* job=Sjob.c_str();

    //函数调用
    int judge=Link_Insert(_list, department, staffName,job);
    if(judge==0)
    {
        QMessageBox::critical(this,"错误","找不到该部门！");
        return;
    }
    ListInsert_Staff(S,staffName, department,job);
    //qDebug()<<S[0].staffName;

    //输出
    LinkList p;
    p = _list->next;
    //qDebug()<<"当前部门：";
    output.append("当前部门：\n");
    while (p)
    {
        //printf("%s\n", p->data);
        //qDebug()<<p->data;
        output.append(p->data);
        output.append("\n");
        p = p->next;
    }
    output.append(QstaffName+"信息插入成功！");
    ui->lineEdit_inputDepartment_staff->clear();
    ui->lineEdit_inputStaff_insert->clear();
    ui->lineEdit_inputJob->clear();
    ui->textEdit_output->setText(output);
}

void MainWindow::on_pushButton_query_clicked()
{
    //qDebug()<<"1";
    QString output;
    QString QstaffName=ui->lineEdit_inputStaff_query->text();
    string SstaffName=QstaffName.toStdString();
    const char* Name=SstaffName.c_str();

    //输出结果
    int i = 0;
    bool flag=false;
    while (true)
    {
        if (!strcmp(S[i].staffName, "\0"))
        {
            break;
        }
        else if (!strcmp(S[i].staffName, Name))
        {
            flag=true;
            break;
        }
        i++;
    }
    if(flag==false)
    {
        QMessageBox::critical(this,"错误","找不到该员工！");
        return;
    }
    //printf("姓名:%s\n", S[i].staffName);
    output.append("姓名：");
    output.append(S[i].staffName);
    output.append("\n");
    //qDebug()<<"姓名："<<S[i].staffName;
    for (int cnt = 0; cnt < S[i].department_num; cnt++)
    {
        //printf("部门:%s,职业:%s\n", S[i].department[cnt][0],S[i].department[cnt][1]);
        //qDebug()<<"部门："<<S[i].department[cnt][0];
        //qDebug()<<"职业："<<S[i].department[cnt][1];
        output.append("部门：");
        output.append(S[i].department[cnt][0]);
        output.append("\n");
        output.append("职业：");
        output.append(S[i].department[cnt][1]);
        output.append("\n");
    }
    ui->textEdit_output->setText(output);
}
