#pragma once
#ifndef MODEL_H
#define MODEL_H

#define G 9.81

typedef struct Quadrotor MODEL;

struct Quadrotor {

	double m;
	double Ixx;
	double Iyy;
	double Izz;

	double ddx;
	double dx;
	double x;

	double ddy;
	double dy;
	double y;

	double ddz;
	double dz;
	double z;

	double ddfai;
	double dfai;
	double fai;

	double ddtheta;
	double dtheta;
	double theta;

	double ddeta;
	double deta;
	double eta;

	double u1;
	double u2;
	double u3;
	double u4;

	double t;

	void (*model_cal)(MODEL *p);
};

void ModelModuleRegister(MODEL **p,double t);

#endif // !MODEL_H

