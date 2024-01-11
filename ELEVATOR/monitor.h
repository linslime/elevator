//��������λ��
int monitor_pos()
{
	int i;
	for (i = 1; i <= FLAMOUNT; i++)
	{
		if (pos == POS_X + (HEIGHT + 1) * (FLAMOUNT - i))
		{
			return i;
		}
	}
	return 0;
}

//���������ⲿ�Ϸ�����
int monitor_out_up()
{
	int i, j;
	for (i = FLAMOUNT - 1; POS_X + (HEIGHT + 1) * (FLAMOUNT - i - 1) < pos; i--)
	{
		for (j = 0; j < 2; j++)
		{  
			if (outrequest[i][j] == 1)
			{
				return 1;
			}
		}
	}
	return 0;
		
}

//���������ⲿ�·�����
int monitor_out_down()
{
	int i, j;
	for (i = 0; POS_X + (HEIGHT + 1) * (FLAMOUNT - i - 1) > pos; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (outrequest[i][j] == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

//���������ⲿ��ǰ¥������
int monitor_out_cur()
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (outrequest[monitor_pos() - 1][i] == 1)
		{
			return 1;
		}
	}
	return 0;
}

//���������ⲿ����
int monitor_out()
{
	int i, j;
	for (i = 0;i < FLAMOUNT ; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (outrequest[i][j] == 1)
			{
				return 1;
			}
		}
	}
	return 0;
}

//���������ⲿ��ǰ¥����������
int monitor_out_cur_up()
{
	if (outrequest[monitor_pos() - 1][1] == 1)
	{
		return 1;
	}
	return 0;
}

//���������ⲿ��ǰ¥����������
int monitor_out_cur_down()
{
	if (outrequest[monitor_pos() - 1][0] == 1)
	{
		return 1;
	}
	return 0;
}

//���������ڲ��Ϸ�����
int monitor_in_up()
{
	int i;
	for (i = FLAMOUNT - 1; POS_X + (HEIGHT + 1) * (FLAMOUNT - i - 1) < pos; i--)
	{
		if (inrequest[i] == 1)
		{
			return 1;
		}
	}
	return 0;
}

//���������ڲ��·�����
int monitor_in_down()
{
	int i;
	for (i = 0; POS_X + (HEIGHT + 1) * (FLAMOUNT - i - 1) > pos; i++)
	{
		if (inrequest[i] == 1)
		{
			return 1;
		}
	}
	return 0;
}

//���������ڲ���ǰ¥������
int monitor_in_cur()
{
	if (inrequest[monitor_pos() - 1] == 1)
	{
		return 1;
	}
	return 0;
}

//���������ڲ�����
int monitor_in()
{

	int i;
	for (i = 0;i < FLAMOUNT; i++)
	{
		if (inrequest[i] == 1)
		{
			return 1;
		}
	}
	return 0;
}

//�������޶�����Ҫ������
LinkQueue* monitor_queue()
{
	int i, j;
	for (i = 0; i < FLAMOUNT; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (QueueLength(*queue[i][j]) != mannumber[i][j] && monitor_pos() != i + 1)
			{
				return queue[i][j];
			}
		}
	}
	return NULL;
}

