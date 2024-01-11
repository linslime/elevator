void movein()
{
	if (doorstate == 1 && monitor_in_cur() == 0 && inelevator >= 0)
	{	
		if (QueueEmpty(*queue[monitor_pos() - 1][inelevator]))
		{
			GotoXY(pos + 6 - 3 * inelevator, POS_Y + 2);
			inelevator == 0? printf("¨Œ"): printf("¡÷");
			GotoXY(pos + 8 - inelevator * 6, POS_Y);
			printf("  ");
			mannumber[monitor_pos() - 1][inelevator] = 0;
			outrequest[monitor_pos() - 1][inelevator] = 0;
			inelevator = -1;
		}
		else if (!QueueEmpty(*queue[monitor_pos() - 1][inelevator]))
		{
			if (passager->pos == WIDTH || passager->pos == 0)
			{
				GetHead(*queue[monitor_pos() - 1][inelevator], passager);
				GotoXY(pos + 8 - inelevator * 6, POS_Y);
				printf("  ");
			}
			if (passager->weight + load <= CAPACITY)
			{
				passager->pos--;
				printman(passager);
				if (passager->pos == 0)
				{
					Push(stack[passager->destination - 1], *passager);
					load += passager->weight;
					inrequest[passager->destination - 1] = 1;
					DeQueue(queue[monitor_pos() - 1][inelevator], passager);
					passager->pos = 0;
				}
			}
			else if (passager->weight + load > CAPACITY)
			{
				inelevator = -1;
				passager->pos = 0;
			}
		}
	}
	//else if()
}