void stop()
{
	finish = clock();
	if ((double)(finish - start) / CLOCKS_PER_SEC >= 60)
	{
		FREQUENCY = 50;
	}
	if ((double)(finish - start) / CLOCKS_PER_SEC >= 590)
	{
		GotoXY(25, 98);
		printf("���������н���10���ӣ����򼴽�����");
	}
	if ((double)(finish - start) / CLOCKS_PER_SEC >= 600)
	{
		GotoXY(27, 98);
		printf("��ӭ�´����棬�ټ�o(*������*)��");
		Sleep(1000);
		exit(0);
	}
	
}