#ifndef LPF_H
#define LPF_H

typedef struct _lpf LPF;

struct _lpf {
	double a;
	double x;
	double in;
	double (*lpf_cal)(LPF* p);
};

void LPFModuleRegister(LPF **p);

#endif


