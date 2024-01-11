void rules()
{
	if (monitor_pos() && door == 0 )
	{
		if (direction == STILL)
		{
			do
			{
				//内部有上方楼层请求
				if (monitor_in_up() == 1)
				{
					direction = UP;
					stilltime = 0;
					GotoXY(3, 96);
					printf("√");
					break;
				}

				//内部有下方楼层请求
				if (monitor_in_down() == 1)
				{
					direction = DOWN;
					stilltime = 0;
					GotoXY(4, 96);
					printf("√");
					break;
				}

				//外部有上方楼层请求
				if (monitor_out_up() == 1)
				{
					direction = UP;
					stilltime = 0;
					GotoXY(5, 96);
					printf("√");
					break;
				}

				//外部有下方楼层请求
				if (monitor_out_down() == 1)
				{
					direction = DOWN;
					stilltime = 0;
					GotoXY(6, 96);
					printf("√");
					break;
				}

				//电梯等待，外部当前楼层有向上请求
				if (monitor_out_cur_up() == 1)
				{
					direction = STILL;
					stilltime = 0;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(7, 96);
					printf("√");
					break;
				}

				//电梯等待，外部当前楼层有向下请求
				if (monitor_out_cur_down() == 1)
				{
					direction = STILL;
					stilltime = 0;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(7, 96);
					printf("√");
					break;
				}
				//电梯等待，内外部持续无请求
				if (monitor_pos() != 1 && monitor_out() == 0 && monitor_in() == 0)
				{
					stilltime++;
					if (stilltime == STILLTIME)
					{
						direction = DOWN;
						GotoXY(14, 96);
						printf("√");
						stilltime = 0;
					}
				}
			} while (0);
		}
		
		if (priorstill != monitor_pos())
		{
			do
			{
				//电梯向下运行，外部当前楼层有向下请求
				if (direction == DOWN && monitor_out_cur_down() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(8, 96);
					printf("√");
					break;
				}

				//电梯向下运行，外部当前楼层有向上请求，外部当前楼层无向下请求，内、外部无下方楼层请求
				if (direction == DOWN && monitor_out_cur_up() == 1 && monitor_out_cur_down() == 0 && monitor_in_down() == 0 && monitor_out_down() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(9, 96);
					printf("√");
					break;
				}

				//电梯向下运行，外部当前楼层有向上请求，内部当前楼层有请求
				if (direction == DOWN && monitor_in_cur() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					GotoXY(10, 96);
					printf("√");
					break;
				}

				//电梯向上运行，外部当前楼层有向上请求
				if (direction == UP && monitor_out_cur_up() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(11, 96);
					printf("√");
					break;
				}

				//电梯向上运行，外部当前楼层有向下请求，外部当前楼层无向上请求，内、外部上方楼层无请求
				if (direction == UP && monitor_out_cur_down() == 1 && monitor_out_cur_up() == 0 && monitor_in_up() == 0 && monitor_out_up() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(12, 96);
					printf("√");
					break;
				}

				//电梯向上运行，外部当前楼层无请求，内部当前楼层有请求
				if (direction == UP && monitor_in_cur() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					GotoXY(13, 96);
					printf("√");
					break;
				}

				//电梯向下运行，电梯内外部均无请求，到达最低层
				if (direction == DOWN && monitor_pos() == 1 && monitor_out() == 0 && monitor_in() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					GotoXY(15, 96);
					printf("√");
					break;
				}

				//电梯向下运行，内部无请求，外部下方无请求，外部当前楼层无请求，外部上方有请求
				if (direction == DOWN && monitor_in() == 0 && monitor_out_cur() == 0 && monitor_out_down() == 0 && monitor_out_up() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					GotoXY(16, 96);
					printf("√");
					break;

				}
			} while (0);
		}
	}
	
}

/*
			//向上，内部无请求，上方楼层无下方请求
			if (direction == UP && monitor_in() == 0 && monitor_out_up() == 0 && monitor_out_cur_up() == 1)
			{
				direction = STILL;
				door = 1;
				inelevator = 1;
				break;
			}

			if (direction == UP && monitor_in() == 0 && monitor_out_up() == 0 && monitor_out_cur_down() == 1)
			{
				direction = STILL;
				door = 1;
				inelevator = 0;
				break;
			}

			if (direction == DOWN && monitor_in() == 0 && monitor_out_down() == 0 && monitor_out_cur_up() == 1)
			{
				direction = STILL;
				door = 1;
				inelevator = 1;
				break;
			}

			if (direction == DOWN && monitor_in() == 0 && monitor_out_down() == 1 && monitor_out_cur_down() == 1)
			{
				direction = STILL;
				door = 1;
				inelevator = 2;
				break;
			}
			*/
			//向下，内部无当前楼层请求，内部有下方楼层请求，外部有当前楼层向下请求

//

//内部无请求，外部有当前楼层向下请求
/*
if (monitor_in() == 0 && monitor_out_cur_down() == 1)
{
	direction = STILL;
	door = 1;
	inelevator = 0;
	break;
}

//内部无请求，外部有当前楼层向上请求
if (monitor_in() == 0 && monitor_out_cur_up() == 1)
{
	direction = STILL;
	door = 1;
	inelevator = 1;
	break;
}

//内部有当前楼层请求,外部无当前楼层请求
if (monitor_in_cur() == 1 && monitor_out_cur() == 0)
{
	direction = STILL;
	door = 1;
	break;
}*/

//direction = temp;

/*if (pos == POS_X + (HEIGHT + 1) * (FLAMOUNT - 1))
	{
		direction = UP;
	}
	else if (pos == POS_X)
	{
		direction = DOWN;
	}*/

/*
		do
		{
			//等待，上方楼层有请求,上行
			if (direction == STILL && monitor_out_up() == 1)
			{
				temp = UP;
				break;
			}

			//等待，上方楼层无请求,等待
			if (direction == STILL && monitor_out_up() == 0)
			{
				temp = STILL;
				break;
			}

			//下行，下方楼层有请求,下行
			if (direction == DOWN && monitor_out_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//下行，下方楼层无请求，电梯内有下方请求,下行
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//下行，下方楼层无请求，电梯内有下方请求,下行
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//下行，下方楼层无请求，电梯内无下方请求，上方楼层无请求，电梯内无上方请求，位于第一层,等待
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up == 0 && monitor_in_down() == 0 && monitor_pos() == 1)
			{
				temp = STILL;
				break;
			}

			//下行，下方楼层无请求，电梯内无下方请求，上方楼层无请求，电梯内无上方请求，位于非一层,下行
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_pos() != 1)
			{
				temp = DOWN;
				break;
			}

			//下行，下方楼层无请求，电梯内无下方请求，上方楼层无请求，电梯内有上方请求,上行
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up() == 0 && monitor_in_up() == 1)
			{
				temp = UP;
				break;
			}

			//上行，上方楼层有请求,上行
			if (direction == UP && monitor_out_up() == 1)
			{
				temp = UP;
				break;
			}

			//上行，上方楼层无请求，电梯内有上方请求,上行
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 1)
			{
				temp = UP;
				break;
			}

			//上行，上方楼层无请求，电梯内无上方请求，下方楼层有请求,下行
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_out_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//上行，上方楼层无请求，电梯内无上方请求，下方楼层无请求，电梯内有下方请求,下行
			if (direction == UP && monitor_out_up() == 0 && monitor_in_down() == 0 && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//上行，上方楼层无请求，电梯内无上方请求，下方楼层无请求，电梯内无下方请求,下行
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_out_down() == 0 && monitor_in_down() == 0)
			{
				temp = DOWN;
				break;
			}

		} while (0);

		*/

		/*
				//电梯停止判断
				do
				{



					//向上，内部无当前楼层请求，内部有上方楼层请求，外部有当前楼层向上请求
					if (direction == UP && monitor_out_cur_up() == 1 )
					{
						direction = STILL;
						door = 1;
						inelevator = 1;
						break;
					}

					if (direction == UP && monitor_out_cur_down() == 1 && monitor_out_cur_up() == 0 && monitor_in_up() == 0 && monitor_out_up() == 0)
					{
						direction = STILL;
						door = 1;
						inelevator = 0;
						break;
					}

					if (direction == DOWN && monitor_out_cur_up() == 1 && monitor_out_cur_down() == 0 && monitor_in_down() == 0 && monitor_out_down() == 0)
					{
						direction = STILL;
						door = 1;
						inelevator = 1;
						break;
					}

					//向上，内部有当前楼层请求，外部无当前楼层向上请求
					if (direction == UP && monitor_out_cur() == 0 && monitor_in_cur() == 1)
					{
						direction = STILL;
						door = 1;
						break;
					}

					//向下，内部无当前楼层请求，内部有上方楼层请求，外部有当前楼层向上请求
					if (direction == DOWN && monitor_out_cur() == 0 && monitor_in_cur() == 1)
					{
						direction = STILL;
						door = 1;
						break;
					}



				} while (0);*/