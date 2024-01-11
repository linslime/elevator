void moveout()
{
	if (doorstate == 1 && monitor_in_cur() == 1)
	{
		if (!StackEmpty(*stack[monitor_pos() - 1]) || passager->pos < WIDTH)
		{
			if (passager->pos == WIDTH || passager->pos == 0)
			{
				if (passager->pos == WIDTH)
				{
					GotoXY(pos + 5, POS_Y + 20 * 2);
					printf("  ");
				}
				Pop(stack[monitor_pos() - 1], passager);
				load -= passager->weight;
			}
			printout(passager);
			passager->pos++;
		}
		else
		{
			GotoXY(pos + 5, POS_Y + 20 * 2);
			printf("  ");
			inrequest[monitor_pos() - 1] = 0;
		}
	}
}