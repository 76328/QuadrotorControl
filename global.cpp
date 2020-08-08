#include "global.h"
#include <iostream>
#include <Windows.h>


using namespace std;

GLOBAL Global_Sim;

double x = 10;
double y = 10;
double z = 10;

void ConstrainD(double *p,double c)
{
    if ((*p) > c)
    {
        *p = c;
     }
    if ((*p) < -c)
    {
        *p = -c;
    }

}

void SimRun(GLOBAL *p)
{
    double aux;
    for (int i=0;i<MAX_STEP;i++)
    {
        //p->altctr->target = sin(i*0.00001);
       // p->siglpf->in = 10;
        p->altctr->target = z;//p->siglpf->lpf_cal(p->siglpf);
        p->altctr->mes = p->quadmodel->z;
       // p->quadmodel->u1 = p->altctr->pid_cal(p->altctr)+p->quadmodel->m*G;
        p->altdzctr->target=p->altctr->pid_cal(p->altctr);
        p->altdzctr->mes = p->quadmodel->dz;
        p->quadmodel->u1 = p->altdzctr->pid_cal(p->altdzctr) + p->quadmodel->m * G-1.0*p->quadmodel->dz;

        aux = 0.8*(y - p->quadmodel->y)-1.4*p->quadmodel->dy;
        ConstrainD(&aux, 0.4);
        p->rollctr->target = aux;
        p->rollctr->mes = p->quadmodel->fai;
        p->quadmodel->u2=p->rollctr->pid_cal(p->rollctr)-0.5*p->quadmodel->dfai;


        aux = -0.9*(x - p->quadmodel->x)+1.4*p->quadmodel->dx;
        ConstrainD(&aux, 0.4);
        p->pitchctr->target = aux;
        p->pitchctr->mes = p->quadmodel->theta;
        p->quadmodel->u3 = p->pitchctr->pid_cal(p->pitchctr) - 0.5 * p->quadmodel->dtheta;
      


        p->quadmodel->model_cal(p->quadmodel);
        if (i % 1000 == 0)
        {
            cout<<"x: "<<p->quadmodel->x<<"y: "<<p->quadmodel->y<<"z: "<< p->quadmodel->z<<"roll: "<<p->quadmodel->fai<<"pitch: "<<p->quadmodel->theta<<"ref: "<<p->altctr->target<<"TIME: "<<i/1000<<endl;
            Sleep(1000);
        }
    }
}

void Init()
{
    ModelModuleRegister(&Global_Sim.quadmodel,T_STEP);
    PIDModuleRegister(&Global_Sim.altctr, &Global_Sim.rollctr, &Global_Sim.pitchctr, &Global_Sim.yawctr,&Global_Sim.altdzctr);
    LPFModuleRegister(&Global_Sim.siglpf);
}