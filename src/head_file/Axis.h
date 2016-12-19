#ifndef AXIS_H
#define AXIS_H

// "Axis_h"   
struct Axis_state{        //状态
	bool Request;   //是否接受指指令
	bool Done;      //是否已完成运动指令
};


struct parameter{         //运动参数
	double Position;      //位置
	double Velocity;      //速度
	double Acceleration;  //加速度
	double Deceleration;  //减速度
};

struct new_cmd{           //接受命令
	double Position;
	double Velocity;
	double Acceleration;
	double Deceleration;
};
class Axis
{

public:
	Axis_state State;
	parameter Parameter;
	new_cmd New_Cmd;
	void init_Axis(Axis_state, parameter, new_cmd);  //轴初始化函数
	Axis_state Get_state();                          //返回Axis对象的状态
	parameter Get_parameter();                       //返回Axis对象的参数
	new_cmd Get_new_cmd();                           //返回Axis对象的接受命令参数
	void take_order(new_cmd init_new_cmd);                               //执行命令，并及时更新Axis对象
};

#endif
