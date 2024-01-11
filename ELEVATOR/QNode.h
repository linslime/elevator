typedef struct QNode
{
	QElemType data;
	struct QNode* next;
}QNode, * QueuePtr;