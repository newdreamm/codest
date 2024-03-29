#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	STDataType _top;  //ջ���±�
	STDataType _capacity;
}ST;

//��ʼ��
void StackInit(ST* pst);
//����
void StackDestory(ST* pst);
//��ջ
void StackPush(ST* pst,STDataType x);
//��ջ
void StackPop(ST* pst);
//�����ݸ���
int StackSize(ST* pst);
//����1Ϊ�ա�����0�ǿ�
int StackEmpty(ST* pst);
//��ȡջ������
STDataType StackTop(ST* pst);