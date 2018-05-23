#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <getopt.h>

#include "tb.h"

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
int evolve(double q[3][3], double p[3][3], Params *params)
{
  
  FILE *fp;
  double tfinal = params->tfinal;
  double dt = params->dt;
  double time = 0.0;

  int error = 0;

  int itmax = tfinal/dt + 0.5;
  int it, rc;
  int nsteps = params->step;
  double dts = dt/nsteps;
  double r[3];

  fp = fopen("results.dat","w");
  
  while (it < itmax && error == 0) {
    if (params->order == 0) {
      rc = StoermerVerlet0(q, p, dts, nsteps, params);
    }
    if (params->order == 2) {
      rc = StoermerVerlet2(q, p, dts, nsteps, params);
    }
    it++;
    time += dt;

    cal_radii(r, q);
    printf("it = %d (%d), t = %g, radii = (%g, %g, %g)\n",it, itmax, time, 
           r[0], r[1], r[2]);

    fprintf(fp,"%20.13e  %20.13e  %20.13e  %20.13e  %20.13e  %20.13e  %20.13e  %20.13e  %20.13e  %20.13e\n",time,q[0][0],q[0][1],q[0][2],q[1][0],q[1][1],q[1][2],q[2][0],q[2][1],q[2][2]);
  }

  fclose(fp);

  return 0;
}
