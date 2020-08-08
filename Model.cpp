#include "Model.h"
#include "math.h"

MODEL quadrotor;

void _model_cal(MODEL *p)
{
	p->x = p->x + p->t * p->dx;
	p->y = p->y + p->t * p->dy;
	p->z = p->z + p->t * p->dz;

	p->dx = p->dx + p->t * p->ddx;
	p->dy = p->dy + p->t * p->ddy;
	p->dz = p->dz + p->t * p->ddz;

	p->fai = p->fai + p->t * p->dfai;
	p->eta = p->eta + p->t * p->deta;
	p->theta = p->theta + p->t * p->dtheta;

	p->dfai = p->dfai + p->t * p->ddfai;
	p->deta = p->deta + p->t * p->ddeta;
	p->dtheta = p->dtheta + p->t * p->ddtheta;

	p->ddx = -(p->u1 / p->m) * sin(p->theta);
	p->ddy = (p->u1 / p->m) * sin(p->fai) * cos(p->theta);
	p->ddz = (p->u1 / p->m) * cos(p->fai) * cos(p->theta) - G;

	p->ddfai = (1 / p->Ixx) * p->u2;
	p->ddtheta = (1 / p->Iyy) * p->u3;
	p->ddeta = (1 / p->Izz) * p->u4;
}

void ModelModuleRegister(MODEL **p,double t)
{
	quadrotor.Ixx = 0.0075;
	quadrotor.Iyy = 0.0075;
	quadrotor.Izz = 0.0013;
	
	quadrotor.u2 = 0;
	quadrotor.u3 = 0;
	quadrotor.u4 = 0;

	quadrotor.m = 0.65;
	quadrotor.t = t;
	quadrotor.model_cal = _model_cal;

	*p = &quadrotor;
}