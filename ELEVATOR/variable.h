int pos = POS_X + (HEIGHT + 1) * (FLAMOUNT - 1);//��������λ��(�����Ļ)
int direction = 0;//�������з���
int temp = 0;//���ڴ�����ʱ�������з���
int name = 0;//���ֱ��
int human = 0;//�����˿ͳ���
ManType* passagerwalk;//���ֵĳ˿�
int t = 0;//�˿ͱ��
int mannumber[FLAMOUNT][2] = { 0 };//�ⲿ��������
LinkQueue* queue[FLAMOUNT][2];//�ⲿ����
SqStack* stack[FLAMOUNT];//�ڲ�����
LinkQueue* tempqueue;//��ʱ���������Ҫ����Ķ���
int x, y;
int tempnumber = 0;
int outrequest[FLAMOUNT][2] = { 0 }; //���������ⲿ����
int inrequest[FLAMOUNT] = { 0 };//���������ڲ�����
int door = 0;//���ݵ����ſ����ź�
int space = 0;//������
int doorstate = 0;//�ŵĿ���״̬
ManType* passager;//��������Ա
ManType* passagerre = NULL;//������Ա
//ManType nomean;
int inelevator = -1;
int load = 0;//�������ݵ�����
int priorstill = 0;
LinkQueue* Q = NULL;
int stilltime = 0;//��ʾ���ݵȴ�ʱ��


clock_t start, finish, temptime;
int FREQUENCY = 1;
int key = true;
