#include "Control.h"


PID altctr, rollctr, pitchctr, yawctr, altdzctr;

double pid_cal(PID *p)
{
	double u;
	p->err = p->target - p->mes;
	p->err_sum = p->err_sum + p->err;
	u = p->Kp * p->err + p->Ki * p->err_sum + p->Kd * (p->err - p->err_1);
	p->err_1 = p->err;
	return u;
}



void PIDModuleRegister(PID **alt,PID **roll,PID **pitch,PID **yaw,PID **altdz)
{
	altctr.Kp = 2.0;
	altctr.Kd = 1.5;
	altctr.Ki = 0.0;
	altctr.pid_cal = pid_cal;
	*alt = &altctr;

	rollctr.Kp = 1;
	rollctr.Kd = 0.1;
	rollctr.Ki = 0;
	rollctr.pid_cal = pid_cal;
	*roll = &rollctr;

	pitchctr.Kp = 1;
	pitchctr.Kd = 0.1;
	pitchctr.Ki = 0;
	pitchctr.pid_cal = pid_cal;
	*pitch = &pitchctr;

	yawctr.Kp = 1;
	yawctr.Kd = 0.1;
	yawctr.Ki = 0;
	yawctr.pid_cal = pid_cal;
	*yaw = &yawctr;

	altdzctr.Kp = 1;
	altdzctr.Kd = 0.0;
	altdzctr.Ki = 0;
	altdzctr.pid_cal = pid_cal;
	*altdz =&altdzctr;
	


}
