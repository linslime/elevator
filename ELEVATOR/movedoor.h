void movedoor()
{
	if (door == 1 && doorstate == 0 )
	{
		GotoXY(pos + 8 - space , POS_Y);
		printf("  ");
		if (space == 7)
		{
			doorstate = 1;
		}
		else
		{
			space++;
		}
	}
	else if (inelevator == -1 && door == 1 && doorstate == 1 && monitor_in_cur() == 0)
	{
		GotoXY(pos + 8 - space, POS_Y);
		printf("¡ö");
		if (space == 0)
		{
			doorstate = 0;
			door = 0;
		}
		else
		{
			space--;
		}
	}
}