void Initelevator()
{
	//printf("¡ø¨‹¡÷¨Œ¢Ù¢Ú¢Û¢Ü¢Ý¢Þ¢ß");
	full_screen();
	Hide();
	printframe();
	int i, j;
	srand((unsigned)time(NULL));
	passagerwalk = (ManType*)malloc(sizeof(ManType));
	for (i = 0; i < FLAMOUNT; i++)
	{
		for (j = 0; j < 2; j++)
		{
			queue[i][j] = (LinkQueue*)malloc(sizeof(LinkQueue));
			InitQueue(queue[i][j]);
		}
	}
	for (i = 0; i < FLAMOUNT; i++)
	{
		stack[i] = (SqStack*)malloc(sizeof(SqStack));
		InitStack(stack[i]);
	}
	passager = (ManType*)malloc(sizeof(ManType));
	passager->pos = WIDTH;
	passager->weight = 0;
	tempqueue = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(tempqueue);
	passagerre = (ManType*)malloc(sizeof(ManType*));
	passagerre->pos = 0;
	start = clock();
	temptime = clock();
}