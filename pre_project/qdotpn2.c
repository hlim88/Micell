#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tb.h"

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void qdotpn2(double qdot[3][3], double q[3][3], double p[3][3], Params *params) 
{

  double qdot2[3][3][18];
  int ibody, idim, iterm;
  

#include "qdotpn2_vars.h"

  double qax = q[0][0];
  double qay = q[0][1];
  double qaz = q[0][2];
  double qbx = q[1][0];
  double qby = q[1][1];
  double qbz = q[1][2];
  double qcx = q[2][0];
  double qcy = q[2][1];
  double qcz = q[2][2];

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

  double G = params->G;
  double CC = params->CC;
  

  for (ibody = 0; ibody < 3; ibody++) {
    for (idim = 0; idim < 3; idim++) {
      for (iterm = 0; iterm < 18; iterm++) {
#include "qdotpn2_rhs.h"
      }
    }
  }

  /* everything needs to be synchronized at this point. */

  for (ibody = 0; ibody < 3; ibody++) {
    for (idim = 0; idim < 3; idim++) {
      qdot[ibody][idim] = 0.0;
      for (iterm = 0; iterm < 18; iterm++) {
        qdot[ibody][idim] += qdot2[ibody][idim][iterm];
      }
    }
  }

}

