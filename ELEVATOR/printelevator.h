void printelevator()
{
	int i;
	GotoXY(pos - 1, 12);
	printf("                              ");
	GotoXY(pos + 0, 12);
	printf("������������������������������");
	for (i = 1; i < HEIGHT + 1; i++)
	{
		GotoXY(pos + i, 12);
		printf("��");
	}
	GotoXY(pos + HEIGHT + 1, 12);
	printf("������������������������������");
	GotoXY(pos + HEIGHT + 2, 12);
	printf("                              ");
	GotoXY(pos + 1, 13);
	printf("�� ��:%3d/%4d               ", load,CAPACITY);
	GotoXY(pos + 2, 13);
	printf("�� ��:%d                ", StackLength(*stack[0]) + StackLength(*stack[1]) + StackLength(*stack[2]) + StackLength(*stack[3]) + StackLength(*stack[4]) + StackLength(*stack[5]));
	GotoXY(pos + 3, 13);
	printf("                      ");
	for (i = 0; i < FLAMOUNT; i++)
	{
		GotoXY(pos + 4 + i, 13);
		printf("ȥ ��%d���������%d            ",  FLAMOUNT - i, StackLength(*stack[FLAMOUNT - i - 1]));
	}
}

