#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* _a;
	STDataType _top;  //栈顶下标
	STDataType _capacity;
}ST;

//初始化
void StackInit(ST* pst);
//销毁
void StackDestory(ST* pst);
//入栈
void StackPush(ST* pst,STDataType x);
//出栈
void StackPop(ST* pst);
//求数据个数
int StackSize(ST* pst);
//返回1为空。返回0非空
int StackEmpty(ST* pst);
//获取栈顶数据
STDataType StackTop(ST* pst);