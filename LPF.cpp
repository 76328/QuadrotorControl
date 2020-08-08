#include "LPF.h"
LPF sig_lpf;

double lpf_cal(LPF* p)
{	
	p->x = p->x + p->a * (p->in - p->x);
	return p->x;
}

void LPFModuleRegister(LPF **p)
{
	sig_lpf.a = 0.001;
	sig_lpf.in = 0;
	sig_lpf.x = 0;
	sig_lpf.lpf_cal = lpf_cal;
	*p = &sig_lpf;

}