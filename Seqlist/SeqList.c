#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//≥ı ºªØ
void SeqListInit(SL* ps)
{
	/*s.size = 0;
	s.a = NULL;
	s.capacity = 0;*/
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		printf("…Í«Îƒ⁄¥Ê ß∞‹\n");
		exit(-1);

	}
	ps->size = 0;
	ps->capacity = 4;

}

void SeqListPrint(SL* ps)
{
	int i = 0;
	assert(ps);
	for (i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);

	}
	printf("\n");
}

//Œ≤≤ÂŒ≤…æ
void SeqListPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;

}
void SeqListPopBack(SL* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0;
	ps->size--;


}
//Õ∑≤ÂÕ∑…æ
void SeqListPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;

}
void SeqListPopFront(SL* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;



}
//»Œ“‚Œª÷√≤Â»Î…æ≥˝
void SeqListInsert(SL* ps, int pos, SLDataType x) 
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end>=pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;

	}

	ps->a[pos] = x;
	ps->size++;


}
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos < ps->size && pos >= 0);
	int start = pos;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}

//≤È’“
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	while (i < ps->size)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		++i;
	}
	return -1;
}


//¿©»›
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("¿©»› ß∞‹\n");
			exit(-1);

		}
	}
}

//œ˙ªŸ
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;

}