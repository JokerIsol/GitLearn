
#include<iostream>
using namespace std;

class new_cmd
{
private:
	double S ;                  //��ʼ��λ��Ϊ��
	double Acceleration;        // ���ٶ�
	double Deceleration;        //���ٶ�
	double Speed;               //�ٶ�
	int  T1;                 //�Ӽ��ٵ�ʱ��
	int  T2;				    //������ʻʱ��
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
	double Input_S = 0;                  //��ʼ��λ��Ϊ��
	double Input_Acceleration;        // ���ٶ�
	double Input_Deceleration;        //���ٶ�
	double Input_Speed = 0;               //�ٶ�
	int Input_T1;                 //�Ӽ��ٵ�ʱ��
	int Input_T2;				    //������ʻʱ��
	int Input_T3;

	cout << "���ڳ�ʼ��"<< '\n';
	while (1)
	{
		cout << "���ڽ���new_cmd" << '\n';
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
				cout << "t=" << t1 << "ʱ��" << "�ٶ�Ϊ��" << Speed_new << "   λ��Ϊ��" << S_new << '\n';
				t1++;
			}

		/*
		t1 = new_order.GetT1();
		Speed_new = new_order.GetSpeed() + t1*new_order.GetAcceleration();
		S_new = new_order.GetS() + 0.5*new_order.GetAcceleration()*t1*t1;
		cout << "t=" << t1 << "ʱ��" << "�ٶ�Ϊ��" << Speed_new << "   λ��Ϊ��" << S_new << '\n';
		*/

		while (t1 <= new_order.GetT1() + new_order.GetT2())
		{
			Speed_new = Speed_new;
			S_new = S_new;
			cout << "t=" << t1 << "ʱ��" << "�ٶ�Ϊ��" << Speed_new << "   λ��Ϊ��" << S_new << '\n';
			t1++;
		}		

		double sp = Speed_new;
		double ss = S_new;
		while ( t1 <= ( new_order.GetT1() + new_order.GetT2() + new_order.GetT3() ) )
		{
			Speed_new = sp - (t1 - new_order.GetT1() - new_order.GetT2())*new_order.GetDeceleration();
			S_new = ss - 0.5*new_order.GetDeceleration()*(t1 - new_order.GetT1()
				- new_order.GetT2())*(t1 - new_order.GetT1() - new_order.GetT2());
			cout << "t=" << t1 << "ʱ��" << "�ٶ�Ϊ��" << Speed_new << "   λ��Ϊ��" << S_new << '\n';
			t1++;
		}

	};





}
