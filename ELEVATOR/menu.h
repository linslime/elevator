void quit()
{
    GotoXY(40, 80);
    printf("��ӭ�´����棬�ټ�o(*������*)��");
    Sleep(1500);
    exit(0);
}

void menu() {
    Initelevator();
    while (1)
    {
        GotoXY(20, 84);
        printf("*******(���Թ�)*******");
        GotoXY(22, 84);
        printf("======================");
        GotoXY(24, 84);
        printf("||   1. ���� ģʽ   ||");
        GotoXY(26, 84);
        printf("||   2. ���� ģʽ   ||");
        GotoXY(28, 84);
        printf("||   3. �ر� ����   ||");
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
            break;  //��������
        default:
            break;
        }
        system("cls");
        elevator();
    }
    

}