void printout(ManType* passager)
{
	GotoXY(POS_X + (HEIGHT + 1) * (FLAMOUNT - passager->destination) + 5, POS_Y + passager->pos * 2);
	switch (passager->birthplace)
	{
	case 1:
		printf("  ¢Ù");
		break;
	case 2:
		printf("  ¢Ú");
		break;
	case 3:
		printf("  ¢Û");
		break;
	case 4:
		printf("  ¢Ü");
		break;
	case 5:
		printf("  ¢Ý");
		break;
	case 6:
		printf("  ¢Þ");
		break;
	}
}