int pos = POS_X + (HEIGHT + 1) * (FLAMOUNT - 1);//监听电梯位置(相对屏幕)
int direction = 0;//电梯运行方向
int temp = 0;//用于储存临时电梯运行方向
int name = 0;//名字编号
int human = 0;//监听乘客出现
ManType* passagerwalk;//出现的乘客
int t = 0;//乘客编号
int mannumber[FLAMOUNT][2] = { 0 };//外部队列人数
LinkQueue* queue[FLAMOUNT][2];//外部队列
SqStack* stack[FLAMOUNT];//内部队列
LinkQueue* tempqueue;//临时检测有无需要重组的队列
int x, y;
int tempnumber = 0;
int outrequest[FLAMOUNT][2] = { 0 }; //监听电梯外部请求
int inrequest[FLAMOUNT] = { 0 };//监听电梯内部请求
int door = 0;//传递电梯门开关信号
int space = 0;//开关门
int doorstate = 0;//门的开关状态
ManType* passager;//出电梯人员
ManType* passagerre = NULL;//重组人员
//ManType nomean;
int inelevator = -1;
int load = 0;//监听电梯的载重
int priorstill = 0;
LinkQueue* Q = NULL;
int stilltime = 0;//表示电梯等待时间


clock_t start, finish, temptime;
int FREQUENCY = 1;
int key = true;
