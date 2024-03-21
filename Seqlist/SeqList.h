#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 10
typedef int SLDataType;



typedef struct SeqList
{
	SLDataType* a;
	int size;//��Ч���ݵĸ���
	int capacity;//����
}SL, SeqList;

//��ӡ
void SeqListPrint(SL* ps);
//��ʼ��
void SeqListInit(SL* ps);
//β��βɾ
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
//ͷ��ͷɾ
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//����λ�ò���ɾ��
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//����
int SeqListFind(SL* ps, SLDataType x);
//���ݺ���
void SeqListCheckCapacity(SL* ps);
//����
void SeqListDestory(SL* ps);