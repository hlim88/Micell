#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tb.h"

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void qdotpn0(double qdot[3][3], double q[3][3], double p[3][3], Params *params) 
{

  int ibody, idim;
  
  double pax = p[0][0];
  double pay = p[0][1];
  double paz = p[0][2];
  double pbx = p[1][0];
  double pby = p[1][1];
  double pbz = p[1][2];
  double pcx = p[2][0];
  double pcy = p[2][1];
  double pcz = p[2][2];

  double ma = params->ma;
  double mb = params->mb;
  double mc = params->mc;


  for (ibody = 0; ibody < 3; ibody++) {
    for (idim = 0; idim < 3; idim++) {
      qdot[ibody][idim]=pax/ma;
      qdot[ibody][idim]=pay/ma;
      qdot[ibody][idim]=paz/ma;
      qdot[ibody][idim]=pbx/mb;
      qdot[ibody][idim]=pby/mb;
      qdot[ibody][idim]=pbz/mb;
      qdot[ibody][idim]=pcx/mc;
      qdot[ibody][idim]=pcy/mc;
      qdot[ibody][idim]=pcz/mc;
    }
  }

}

