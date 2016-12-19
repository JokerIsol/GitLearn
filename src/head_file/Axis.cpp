#include "Axis.h"
#include <stdio.h>

void Axis::init_Axis(Axis_state init_state, parameter init_parameter, new_cmd init_new_cmd)
{
	State = init_state;
	Parameter = init_parameter;
	New_Cmd = init_new_cmd;
}

Axis_state Axis::Get_state()
{
	return State;
}

parameter Axis::Get_parameter()
{
	return Parameter;
}

new_cmd Axis::Get_new_cmd()
{
	return New_Cmd;
}

void  Axis::take_order(new_cmd init_new_cmd)
{
	double Acceleration_time;
	double Deceleration_time;
	double Uniform_motion_time;
	if (State.Request)
	{
		Acceleration_time = Parameter.Velocity / New_Cmd.Acceleration;
		Deceleration_time = Parameter.Velocity / New_Cmd.Deceleration;
		Uniform_motion_time = (Parameter.Position - Acceleration_time*New_Cmd.Velocity) / New_Cmd.Velocity;
		printf("Acceleration_time : %f \n", Acceleration_time);
		printf("Deceleration_time : %f \n", Deceleration_time);
		printf("Uniform_motion_time : %f \n", Uniform_motion_time);
		while (State.Request)
		{

			int t1 = 0;
			double Speed_new;
			double S_new;

			while (t1 <= Acceleration_time)
			{
				Speed_new = t1*New_Cmd.Acceleration;
				S_new = 0.5*New_Cmd.Acceleration*t1*t1;
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}


			double s = S_new;
			while (t1 <= (Acceleration_time + Uniform_motion_time))
			{
				Speed_new = Speed_new;
				S_new = s + Speed_new*(t1 - Acceleration_time);
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}

			double sp = Speed_new;
			double ss = S_new;
			while (t1 <= (Acceleration_time + Uniform_motion_time + Deceleration_time))
			{
				Speed_new = sp - (t1 - Acceleration_time - Uniform_motion_time)*New_Cmd.Deceleration;
				S_new = ss + 0.5*New_Cmd.Deceleration*(t1 - Acceleration_time - Uniform_motion_time)*(t1 - Acceleration_time - Uniform_motion_time);
				printf("t= %d ms时，速度v= %f mm/s,位置s= %fmm\n", t1, Speed_new, S_new);
				t1++;
			}
			if (t1 > (Acceleration_time + Uniform_motion_time + Deceleration_time))
			{
				State.Request = false;
				State.Done = true;
			}

		}

	}
}