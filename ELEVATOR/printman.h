void printman(ManType* passager)
{
	GotoXY(POS_X + (HEIGHT + 1) * (FLAMOUNT - passager->birthplace) + (passager->birthplace > passager->destination ? HEIGHT:2), POS_Y + passager->pos * 2);
	switch (passager->destination)
	{
	case 1:
		printf("��  ");
		break;
	case 2:
		printf("��  ");
		break;
	case 3:
		printf("��  ");
		break;
	case 4:
		printf("��  ");
		break;
	case 5:
		printf("��  ");
		break;
	case 6:
		printf("��  ");
		break;
	}
}