void printout(ManType* passager)
{
	GotoXY(POS_X + (HEIGHT + 1) * (FLAMOUNT - passager->destination) + 5, POS_Y + passager->pos * 2);
	switch (passager->birthplace)
	{
	case 1:
		printf("  ��");
		break;
	case 2:
		printf("  ��");
		break;
	case 3:
		printf("  ��");
		break;
	case 4:
		printf("  ��");
		break;
	case 5:
		printf("  ��");
		break;
	case 6:
		printf("  ��");
		break;
	}
}