#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//��ʼ��
void StackInit(ST* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDataType)*4);
	pst->_top = 0;
	pst->_capacity = 4;


}
//����
void StackDestory(ST* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;



}
//��ջ
void StackPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("�ڴ治��\n");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;


}
//��ջ
void StackPop(ST* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	--pst->_top;


}
//�����ݸ���
int StackSize(ST* pst)
{
	assert(pst);
	return pst->_top;


}
//����1Ϊ�ա�����0�ǿ�
int StackEmpty(ST* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
	/*return !pst->_top;*/

}
//��ȡջ������

STDataType StackTop(ST* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	return pst->_a[pst->_top - 1];



}