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
		printf("程序已运行将近10分钟，程序即将结束");
	}
	if ((double)(finish - start) / CLOCKS_PER_SEC >= 600)
	{
		GotoXY(27, 98);
		printf("欢迎下次再玩，再见o(*￣▽￣*)ブ");
		Sleep(1000);
		exit(0);
	}
	
}