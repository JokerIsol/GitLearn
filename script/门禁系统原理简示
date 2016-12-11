#include<iostream>
using namespace std;


//void delay（）
//{
//	
//	for (int i=10000; i > 0; i--)
//	{
//		for (int j=10000; j > 0; j--);
//	}
//}

void main()
{
	char enter_or_out;   //1表示入闸ture，0表示出闸ture
	int up_or_downt = 0;    //1表示起落杆up，0表示起落杆down

	cout << "状态初始化..." << '\n';
	cout << "当前状态为红灯，起落杆落下状态，禁止通行" << '\n';

	while (1)
	{
		cout << "检测是否有车进入或离开门禁系统y or n" << '\n';
		cin >> enter_or_out;

		if (enter_or_out == 'y')
		{
			cout << "入闸ture，有车进入" << '\n';
			up_or_downt = 1;
			cout << "起落杆up ture" <<'\n';
			cout << "通行灯为红灯，汽车可通行" << '\n';
			//delay();
		}

		else
		{
			cout << "出闸ture，汽车出闸" << '\n';
			up_or_downt = 0;
			cout << "起落杆down ture" << '\n';
			cout << "通行灯为红灯，汽车禁止通行" << '\n';
			//delay();
		}

	}
}
