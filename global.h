#ifndef GLOBAL_H
#define GLOBAL_H
#include "Model.h"
#include "Control.h"
#include "LPF.h"

#define T_STEP 0.001
#define MAX_T 1000 
#define MAX_STEP (MAX_T/T_STEP)
#define PER_SEC (1/T_STEP)


typedef struct global GLOBAL;

typedef struct global
{
    MODEL* quadmodel;
    PID* altctr;
    PID* rollctr;
    PID* pitchctr;
    PID* yawctr;
    PID* altdzctr;
    LPF* siglpf;
};

extern GLOBAL Global_Sim;
void Init();
void SimRun(GLOBAL *p);
#endif // !GLOBAL_H

