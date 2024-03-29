#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//初始化
void StackInit(ST* pst)
{
	assert(pst);
	pst->_a = malloc(sizeof(STDataType)*4);
	pst->_top = 0;
	pst->_capacity = 4;


}
//销毁
void StackDestory(ST* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;



}
//入栈
void StackPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("内存不足\n");
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
//出栈
void StackPop(ST* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	--pst->_top;


}
//求数据个数
int StackSize(ST* pst)
{
	assert(pst);
	return pst->_top;


}
//返回1为空。返回0非空
int StackEmpty(ST* pst)
{
	assert(pst);
	return pst->_top == 0 ? 1 : 0;
	/*return !pst->_top;*/

}
//获取栈顶数据

STDataType StackTop(ST* pst)
{
	assert(pst);
	assert(pst->_top > 0);

	return pst->_a[pst->_top - 1];



}