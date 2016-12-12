
#include<iostream>
using namespace std;

class new_cmd
{
private:
	double S ;                  //初始化位移为零
	double Acceleration;        // 加速度
	double Deceleration;        //减速度
	double Speed;               //速度
	int  T1;                 //加减速的时间
	int  T2;				    //匀速行驶时间
	int T3;                 //

public:
	void Assignment(double, double, double, double, int, int, int);
	double GetS();
	double GetAcceleration();
	double GetDeceleration();
	double GetSpeed();
	int GetT1();
	int GetT2();
	int GetT3();
};

void new_cmd::Assignment(double s, double acceleration, double deceleration,
	double speed, int t1, int t2, int t3)
{
	S = s; Acceleration = acceleration; Deceleration = deceleration; 
	Speed = speed; T1 = t1; T2 = t2; T3 = t3;
}

double new_cmd::GetS()
{
	return(S);
}
double new_cmd::GetAcceleration()
{
	return(Acceleration);
}
double new_cmd::GetDeceleration()
{
	return(Deceleration);
}
double new_cmd::GetSpeed()
{
	return(Speed);
}
int new_cmd::GetT1()
{
	return(T1);
}
int new_cmd::GetT2()
{
	return(T2);
}
int new_cmd::GetT3()
{
	return(T3);
}

void main()
{
	double Input_S = 0;                  //初始化位移为零
	double Input_Acceleration;        // 加速度
	double Input_Deceleration;        //减速度
	double Input_Speed = 0;               //速度
	int Input_T1;                 //加减速的时间
	int Input_T2;				    //匀速行驶时间
	int Input_T3;

	cout << "正在初始化"<< '\n';
	while (1)
	{
		cout << "正在接收new_cmd" << '\n';
		cin >> Input_Acceleration >> Input_Deceleration >> Input_T1 >> Input_T2 >> Input_T3;
		new_cmd new_order;
		new_order.Assignment(Input_S, Input_Acceleration, Input_Deceleration, Input_Speed, Input_T1, Input_T2, Input_T3);
		int t1 = 0 ;
		double Speed_new;
		double S_new;

		while(t1 <= new_order.GetT1())
			{
				Speed_new = new_order.GetSpeed() + t1*new_order.GetAcceleration();
				S_new = new_order.GetS() + 0.5*new_order.GetAcceleration()*t1*t1;
				cout << "t=" << t1 << "时，" << "速度为：" << Speed_new << "   位移为：" << S_new << '\n';
				t1++;
			}

		/*
		t1 = new_order.GetT1();
		Speed_new = new_order.GetSpeed() + t1*new_order.GetAcceleration();
		S_new = new_order.GetS() + 0.5*new_order.GetAcceleration()*t1*t1;
		cout << "t=" << t1 << "时，" << "速度为：" << Speed_new << "   位移为：" << S_new << '\n';
		*/

		while (t1 <= new_order.GetT1() + new_order.GetT2())
		{
			Speed_new = Speed_new;
			S_new = S_new;
			cout << "t=" << t1 << "时，" << "速度为：" << Speed_new << "   位移为：" << S_new << '\n';
			t1++;
		}		

		double sp = Speed_new;
		double ss = S_new;
		while ( t1 <= ( new_order.GetT1() + new_order.GetT2() + new_order.GetT3() ) )
		{
			Speed_new = sp - (t1 - new_order.GetT1() - new_order.GetT2())*new_order.GetDeceleration();
			S_new = ss - 0.5*new_order.GetDeceleration()*(t1 - new_order.GetT1()
				- new_order.GetT2())*(t1 - new_order.GetT1() - new_order.GetT2());
			cout << "t=" << t1 << "时，" << "速度为：" << Speed_new << "   位移为：" << S_new << '\n';
			t1++;
		}

	};





}
