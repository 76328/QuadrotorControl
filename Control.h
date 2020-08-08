#ifndef CONTROL_H
#define CONTROL_H

typedef struct _pid PID;

struct _pid{
	double target;
	double mes;
	double err;
	double err_1;
	double err_sum;
	double Kp;
	double Ki;
	double Kd;
	double T;
	double (*pid_cal)(PID *p);
};

void PIDModuleRegister(PID** alt, PID** roll, PID** pitch, PID** yaw,PID **altdz);


#endif // !CONTROL_H
