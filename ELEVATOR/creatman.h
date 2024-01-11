void createman()
{
	if (human == 0)
	{
		if (rand() % FREQUENCY == 0)
		{
			passagerwalk->birthplace = rand() % FLAMOUNT + 1;
			passagerwalk->destination = rand() % FLAMOUNT + 1;
			passagerwalk->weight = rand() % 41 + 40;
			passagerwalk->pos = WIDTH;
			if (passagerwalk->destination == passagerwalk->birthplace || mannumber[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1] == WIDTH)
			{
				human = 0;
			}
			else
			{
				human = 1;
			}
		}
	}
}