void elevator()
{
	Initelevator();
	while (true)
	{
		moveelevator();
		createman();

		moveap();
		moveout();
		movein();
		movere();
		movedoor();

		moveap();
		moveout();
		//movein();
		//movere();
		movedoor();

		moveap();
		moveout();
		movein();
		movere();
		movedoor();

		moveap();
		moveout();
		//movein();
		//movere();
		movedoor();

		stop();
	}
}