void quit()
{
    GotoXY(40, 80);
    printf("欢迎下次再玩，再见o(*￣▽￣*)ブ");
    Sleep(1500);
    exit(0);
}

void menu() {
    Initelevator();
    while (1)
    {
        GotoXY(20, 84);
        printf("*******(走迷宫)*******");
        GotoXY(22, 84);
        printf("======================");
        GotoXY(24, 84);
        printf("||   1. 快速 模式   ||");
        GotoXY(26, 84);
        printf("||   2. 慢速 模式   ||");
        GotoXY(28, 84);
        printf("||   3. 关闭 程序   ||");
        GotoXY(30, 84);
        printf("======================");
        char t;
        t = getch();
        switch (t) {
        case '1':
        
            break;
        case '2':
        {
            FREQUENCY = 50;
        }
            break;
        case '3':
            quit();
            break;  //结束程序
        default:
            break;
        }
        system("cls");
        elevator();
    }
    

}