void rules()
{
	if (monitor_pos() && door == 0 )
	{
		if (direction == STILL)
		{
			do
			{
				//�ڲ����Ϸ�¥������
				if (monitor_in_up() == 1)
				{
					direction = UP;
					stilltime = 0;
					GotoXY(3, 96);
					printf("��");
					break;
				}

				//�ڲ����·�¥������
				if (monitor_in_down() == 1)
				{
					direction = DOWN;
					stilltime = 0;
					GotoXY(4, 96);
					printf("��");
					break;
				}

				//�ⲿ���Ϸ�¥������
				if (monitor_out_up() == 1)
				{
					direction = UP;
					stilltime = 0;
					GotoXY(5, 96);
					printf("��");
					break;
				}

				//�ⲿ���·�¥������
				if (monitor_out_down() == 1)
				{
					direction = DOWN;
					stilltime = 0;
					GotoXY(6, 96);
					printf("��");
					break;
				}

				//���ݵȴ����ⲿ��ǰ¥������������
				if (monitor_out_cur_up() == 1)
				{
					direction = STILL;
					stilltime = 0;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(7, 96);
					printf("��");
					break;
				}

				//���ݵȴ����ⲿ��ǰ¥������������
				if (monitor_out_cur_down() == 1)
				{
					direction = STILL;
					stilltime = 0;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(7, 96);
					printf("��");
					break;
				}
				//���ݵȴ������ⲿ����������
				if (monitor_pos() != 1 && monitor_out() == 0 && monitor_in() == 0)
				{
					stilltime++;
					if (stilltime == STILLTIME)
					{
						direction = DOWN;
						GotoXY(14, 96);
						printf("��");
						stilltime = 0;
					}
				}
			} while (0);
		}
		
		if (priorstill != monitor_pos())
		{
			do
			{
				//�����������У��ⲿ��ǰ¥������������
				if (direction == DOWN && monitor_out_cur_down() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(8, 96);
					printf("��");
					break;
				}

				//�����������У��ⲿ��ǰ¥�������������ⲿ��ǰ¥�������������ڡ��ⲿ���·�¥������
				if (direction == DOWN && monitor_out_cur_up() == 1 && monitor_out_cur_down() == 0 && monitor_in_down() == 0 && monitor_out_down() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(9, 96);
					printf("��");
					break;
				}

				//�����������У��ⲿ��ǰ¥�������������ڲ���ǰ¥��������
				if (direction == DOWN && monitor_in_cur() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					GotoXY(10, 96);
					printf("��");
					break;
				}

				//�����������У��ⲿ��ǰ¥������������
				if (direction == UP && monitor_out_cur_up() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 1;
					GotoXY(11, 96);
					printf("��");
					break;
				}

				//�����������У��ⲿ��ǰ¥�������������ⲿ��ǰ¥�������������ڡ��ⲿ�Ϸ�¥��������
				if (direction == UP && monitor_out_cur_down() == 1 && monitor_out_cur_up() == 0 && monitor_in_up() == 0 && monitor_out_up() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					inelevator = 0;
					GotoXY(12, 96);
					printf("��");
					break;
				}

				//�����������У��ⲿ��ǰ¥���������ڲ���ǰ¥��������
				if (direction == UP && monitor_in_cur() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					door = 1;
					GotoXY(13, 96);
					printf("��");
					break;
				}

				//�����������У��������ⲿ�������󣬵�����Ͳ�
				if (direction == DOWN && monitor_pos() == 1 && monitor_out() == 0 && monitor_in() == 0)
				{
					direction = STILL;
					priorstill = monitor_pos();
					GotoXY(15, 96);
					printf("��");
					break;
				}

				//�����������У��ڲ��������ⲿ�·��������ⲿ��ǰ¥���������ⲿ�Ϸ�������
				if (direction == DOWN && monitor_in() == 0 && monitor_out_cur() == 0 && monitor_out_down() == 0 && monitor_out_up() == 1)
				{
					direction = STILL;
					priorstill = monitor_pos();
					GotoXY(16, 96);
					printf("��");
					break;

				}
			} while (0);
		}
	}
	
}

/*
			//���ϣ��ڲ��������Ϸ�¥�����·�����
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
			//���£��ڲ��޵�ǰ¥�������ڲ����·�¥�������ⲿ�е�ǰ¥����������

//

//�ڲ��������ⲿ�е�ǰ¥����������
/*
if (monitor_in() == 0 && monitor_out_cur_down() == 1)
{
	direction = STILL;
	door = 1;
	inelevator = 0;
	break;
}

//�ڲ��������ⲿ�е�ǰ¥����������
if (monitor_in() == 0 && monitor_out_cur_up() == 1)
{
	direction = STILL;
	door = 1;
	inelevator = 1;
	break;
}

//�ڲ��е�ǰ¥������,�ⲿ�޵�ǰ¥������
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
			//�ȴ����Ϸ�¥��������,����
			if (direction == STILL && monitor_out_up() == 1)
			{
				temp = UP;
				break;
			}

			//�ȴ����Ϸ�¥��������,�ȴ�
			if (direction == STILL && monitor_out_up() == 0)
			{
				temp = STILL;
				break;
			}

			//���У��·�¥��������,����
			if (direction == DOWN && monitor_out_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//���У��·�¥�������󣬵��������·�����,����
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//���У��·�¥�������󣬵��������·�����,����
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//���У��·�¥�������󣬵��������·������Ϸ�¥�������󣬵��������Ϸ�����λ�ڵ�һ��,�ȴ�
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up == 0 && monitor_in_down() == 0 && monitor_pos() == 1)
			{
				temp = STILL;
				break;
			}

			//���У��·�¥�������󣬵��������·������Ϸ�¥�������󣬵��������Ϸ�����λ�ڷ�һ��,����
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_pos() != 1)
			{
				temp = DOWN;
				break;
			}

			//���У��·�¥�������󣬵��������·������Ϸ�¥�������󣬵��������Ϸ�����,����
			if (direction == DOWN && monitor_out_down() == 0 && monitor_in_down() == 0 && monitor_out_up() == 0 && monitor_in_up() == 1)
			{
				temp = UP;
				break;
			}

			//���У��Ϸ�¥��������,����
			if (direction == UP && monitor_out_up() == 1)
			{
				temp = UP;
				break;
			}

			//���У��Ϸ�¥�������󣬵��������Ϸ�����,����
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 1)
			{
				temp = UP;
				break;
			}

			//���У��Ϸ�¥�������󣬵��������Ϸ������·�¥��������,����
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_out_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//���У��Ϸ�¥�������󣬵��������Ϸ������·�¥�������󣬵��������·�����,����
			if (direction == UP && monitor_out_up() == 0 && monitor_in_down() == 0 && monitor_out_down() == 0 && monitor_in_down() == 1)
			{
				temp = DOWN;
				break;
			}

			//���У��Ϸ�¥�������󣬵��������Ϸ������·�¥�������󣬵��������·�����,����
			if (direction == UP && monitor_out_up() == 0 && monitor_in_up() == 0 && monitor_out_down() == 0 && monitor_in_down() == 0)
			{
				temp = DOWN;
				break;
			}

		} while (0);

		*/

		/*
				//����ֹͣ�ж�
				do
				{



					//���ϣ��ڲ��޵�ǰ¥�������ڲ����Ϸ�¥�������ⲿ�е�ǰ¥����������
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

					//���ϣ��ڲ��е�ǰ¥�������ⲿ�޵�ǰ¥����������
					if (direction == UP && monitor_out_cur() == 0 && monitor_in_cur() == 1)
					{
						direction = STILL;
						door = 1;
						break;
					}

					//���£��ڲ��޵�ǰ¥�������ڲ����Ϸ�¥�������ⲿ�е�ǰ¥����������
					if (direction == DOWN && monitor_out_cur() == 0 && monitor_in_cur() == 1)
					{
						direction = STILL;
						door = 1;
						break;
					}



				} while (0);*/