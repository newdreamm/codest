#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushBack(&s, 10);
	SeqListPrint(&s);
	SeqListPopBack(&s, 9);
	SeqListPopBack(&s, 10);
	SeqListPrint(&s);
	SeqListPushFront(&s, 1);
	SeqListPushFront(&s, 2);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 9);
	SeqListPrint(&s);

	SeqListErase(&s, 2);
	SeqListPrint(&s);



	//Ïú»Ù
	//SeqListDestory(&s);



	



}

int main()
{
	TestSeqList1();
	return 0;
}