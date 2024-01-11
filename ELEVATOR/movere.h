void movere()
{
	if (Q == NULL)
	{
		Q = monitor_queue();
	}
	else if (!QueueEmpty(*Q) || passagerre->pos > tempnumber + 1)
	{
		if (!QueueEmpty(*Q) && (passagerre->pos == tempnumber + 1 || passagerre->pos == 0))
		{
			if (passagerre->pos == tempnumber + 1)
			{
				tempnumber++;
				EnQueue(tempqueue, *passagerre);
			}
			DeQueue(Q, passagerre);
		}
		passagerre->pos--;
		printman(passagerre);
		if (QueueEmpty(*Q) && passagerre->pos == tempnumber + 1)
		{
			tempnumber++;
			EnQueue(tempqueue, *passagerre);
			mannumber[passagerre->birthplace - 1][passagerre->birthplace > passagerre->destination ? 0 : 1] = tempnumber;
			tempnumber = 0;
			while (!QueueEmpty(*tempqueue))
			{
				DeQueue(tempqueue, passagerre);
				EnQueue(Q, *passagerre);
			}
			Q = NULL;
			passagerre->pos = 0;
		}
	} 
}

/*
void movere()
{	
	if (QueueEmpty(*tempqueue) && passagerre->pos == 0)
	{
		monitor_queue();
	}
	else if(!QueueEmpty(*tempqueue) || passagerre->pos > tempnumber)
	{
		if (passagerre->pos == tempnumber || passagerre->pos == 0)
		{
			if (passagerre->pos == tempnumber)
			{
				tempnumber++;
				EnQueue(queue[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1], *passagerre);
			}
			DeQueue(tempqueue, passagerre);
		}
		passagerre->pos--;
		printman(passagerre);
	}
	else if (QueueEmpty(*tempqueue) && passagerre->pos == tempnumber)
	{
		mannumber[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1] = tempnumber - 1;
		passagerre->pos = 0;
		tempnumber = 1;
	}
	
}
*/