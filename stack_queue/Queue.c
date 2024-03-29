#include "Queue.h"


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;

}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;

}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("ÄÚ´æ²»×ã\n");
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;

	}
	else
	{
		pq->tail -> next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	QNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}

}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{

	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL ? 1 : 0;

}
int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;

}