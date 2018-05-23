#ifndef HAVE_PROTO_H
#define HAVE_PROTO_H
#include "params.h"

void usage(char *argv[]);
void usage_long(char *argv[]);
void commandline(int argc, char *argv[], Params *params);
void initial_data(double q[3][3], double p[3][3], Params *params);
int evolve(double q[3][3], double p[3][3], Params *params);

void pdotpn0(double pdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;
void qdotpn0(double qdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;
void pdotpn1(double pdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;
void qdotpn1(double qdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;
void pdotpn2(double pdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;
void qdotpn2(double qdot[3][3], double q[3][3], double p[3][3], 
             Params *params) ;


int StoermerVerlet0(double qn[3][3],   double pn[3][3], 
                     double dt, int nsteps, Params *params);
int StoermerVerlet1(double qn[3][3],   double pn[3][3], 
                     double dt, int nsteps, Params *params);
int StoermerVerlet2(double qn[3][3],   double pn[3][3], 
                     double dt, int nsteps, Params *params);

double l2norm(double f[3][3]);
void cal_radii(double r[3], double f[3][3]);

#endif

