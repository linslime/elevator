void printframe()
{	int i, j;
	for (i = 0; i < 54; i++)
	{
		GotoXY(i, 94);
		printf("■");
	}
	for (i = 0; i < (HEIGHT + 1)* FLAMOUNT + 1; i++)
	{
		GotoXY(POS_X + i, POS_Y);
		printf("■");
	}
	for (i = 0; i < FLAMOUNT + 1; i++)
	{
		GotoXY(POS_X + i * (HEIGHT + 1), POS_Y + 2);
		for (j = 0; j < WIDTH; j++)
		{
			printf("■");
		}
	}
	for (i = 0; i < FLAMOUNT; i++)
	{
		GotoXY(POS_X + i * (HEIGHT + 1) + 3, POS_Y + 2);
		printf("△  floor%d",5 - i);
		GotoXY(POS_X + i * (HEIGHT + 1) + 6, POS_Y + 2);
		printf("▽");
	}

	GotoXY(3, 98);
	printf("电梯已停靠于该楼层,内部有上方楼层请求,上行");
	GotoXY(4, 98);
	printf("电梯已停靠于该楼层,内部有下方楼层请求,下行");
	GotoXY(5, 98);
	printf("电梯已停靠于该楼层,外部有上方楼层请求,上行");
	GotoXY(6, 98);
	printf("电梯已停靠于该楼层,内部有下方楼层请求,下行");
	GotoXY(7, 98);
	printf("电梯已停靠于该楼层,外部当前楼层有请求,停止,开门");
	GotoXY(8, 98);
	printf("电梯向下运行,外部当前楼层有向下请求,停止,开门");
	GotoXY(9, 98);
	printf("电梯向下运行,外部当前楼层有向上请求,外部当前楼层无向下请求,内,外部无下方楼层请求,停止,开门");
	GotoXY(10, 98);
	printf("电梯向下运行,外部当前楼层有向上请求,内部当前楼层有请求,停止，开门");
	GotoXY(11, 98);
	printf("电梯向上运行,外部当前楼层有向上请求,停止，开门");
	GotoXY(12, 98);
	printf("电梯向上运行,外部当前楼层有向下请求,外部当前楼层无向上请求,内,外部上方楼层无请求,停止,开门");
	GotoXY(13, 98);
	printf("电梯向上运行,外部当前楼层无请求,内部当前楼层有请求,停止，开门");
	GotoXY(14, 98);
	printf("电梯等待，内外部持续%d秒无请求,向下运行到最底层", STILLTIME * 4 * SPEED / 1000);
	GotoXY(15, 98);
	printf("电梯向下运行，内外部均无请求，运行到最底层停止");
	GotoXY(16, 98);
	printf("电梯向下运行，内部无请求，外部当前楼层无请求，外部下方楼层无请求，外部上方有请求，停止");
}