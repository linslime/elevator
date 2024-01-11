void moveap()
{
	Sleep(SPEED);
	if (human == 1)
	{
		printman(passagerwalk);
		if (passagerwalk->pos == mannumber[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1] + 1)
		{
			GotoXY(POS_X + (FLAMOUNT - passagerwalk->birthplace) * (HEIGHT + 1) + (passagerwalk->birthplace > passagerwalk->destination ? 6 : 3), POS_Y + 2);
			passagerwalk->birthplace > passagerwalk->destination ? printf("¨‹") : printf("¡ø");
			/*
			if (passagers[t]->pos == 1)
			{
				GotoXY(POS_X + (FLAMOUNT - passagers[t]->birthplace) * (HEIGHT + 1) +( passagers[t]->birthplace > passagers[t]->destination ? 6 : 3), POS_Y + 2);
				passagers[t]->birthplace > passagers[t]->destination ? printf("¨‹") : printf("¡ø");
			}
			*/
			EnQueue(queue[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1], *passagerwalk);
			outrequest[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1] = 1;
			mannumber[passagerwalk->birthplace - 1][passagerwalk->birthplace > passagerwalk->destination ? 0 : 1]++;
			human = 0;
			//passagerwalk->pos--;
			//t++;
		}
		else
		{
			passagerwalk->pos--;
		}

	}
}

/*
void moveman()
{
	if (human == 1)
	{
		Sleep(150);
		printman(passagers[t]);
		if (passagers[t]->pos == mannumber[passagers[t]->birthplace - 1][passagers[t]->birthplace > passagers[t]->destination ? 0 : 1] + 1)
		{
			if (passagers[t]->birthplace < passagers[t]->destination)
			{
				if (passagers[t]->pos == 1)
				{
					GotoXY(POS_X + (FLAMOUNT - passagers[t]->birthplace) * (HEIGHT + 1) + 3, POS_Y + 2);
					printf("¡ø");
				}
				EnQueue(queue[passagers[t]->birthplace - 1][1], *passagers[t]);
				outrequest[passagers[t]->birthplace - 1][1] = 1;
			}
			else if (passagers[t]->birthplace > passagers[t]->destination)
			{
				if (passagers[t]->pos == 1)
				{
					GotoXY(POS_X + (FLAMOUNT - passagers[t]->birthplace) * (HEIGHT + 1) + 6, POS_Y + 2);
					printf("¨‹");
				}
				EnQueue(queue[passagers[t]->birthplace - 1][0], *passagers[t]);
				outrequest[passagers[t]->birthplace - 1][0] = 1;
			}
			mannumber[passagers[t]->birthplace - 1][passagers[t]->birthplace > passagers[t]->destination ? 0 : 1]++;
			human = 0;
			passagers[t]->pos--;
			t++;
			//break;
		}
		else
		{
			passagers[t]->pos--;
		}

	}
}
*/