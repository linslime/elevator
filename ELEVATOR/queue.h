Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		exit(OVERFLOW);
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue* Q)
{
	QueuePtr p;
	while (Q->front->next)
	{
		p = Q->front->next;

		Q->front->next = p->next;
		free(p);
	}
	Q->rear = Q->front;
	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear && Q.front != NULL)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(LinkQueue Q)
{
	QueuePtr p;//ÁÙÊ±Ö¸Õë
	int count = 0;//¼ÆËãÆ÷
	p = Q.front->next;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count;
}

Status GetHead(LinkQueue Q, QElemType* e)
{
	if (QueueEmpty(Q) == TRUE)
		return ERROR;
	*e = Q.front->next->data;
	return OK;
}

Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue* Q, QElemType* e)
{
	if (Q->front == Q->rear)
		return ERROR;
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
