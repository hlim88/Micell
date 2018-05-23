#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "tb.h"

/*-----------------------------------------------------------------------
 *
 * Take one step with the 2nd order Stoermer-Verlet algorithm:
 *
 *    p_{n+1/2} = p_n - h/2 H_q(p_{n+1/2},q_n)
 *
 *    q_{n+1} = q_n + h/2 [ H_p(p_{n+1/2},q_n) +  H_p(p_{n+1/2},q_{n+1}) ]
 *
 *    p_{n+1} = p_{n+1/2} - h/2 H_q(p_{n+1/2},q_{n+1})
 *
 *-----------------------------------------------------------------------*/

int StoermerVerlet0(double qn[3][3],   double pn[3][3], 
                    double dt, int nsteps, Params *params)
{

  int i, j, k, it;
  int done;
  double qnp1[3][3], pnp1[3][3];
  double pnph[3][3], pnph_new[3][3], pdot[3][3], dp[3][3];
  double qnp1_new[3][3], qdot[3][3], qdot2[3][3], dq[3][3];

  const int itmax = 15;
  const double tol = 1.0e-11;
  
  printf("SV0: nsteps=%d\n",nsteps);
  for (it = 0; it < nsteps; it++) {

    /*------------- BEGIN one step of S-V -------------------*/
    /* initial guess for p at n+1/2 and q at n+1 */
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        pnph[i][j] = pn[i][j];
        qnp1[i][j] = qn[i][j];
      }
    }

    /* Solve for p_{n+1/2} */
    k = 0;
    done = 0;
    while(k < itmax && done == 0) {
      printf("sv0: calling pdotpn0...\n");
      pdotpn0(pdot, qn, pnph, params);
      printf("sv0: return pdotpn0...\n");
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          printf("i=%d, j=%d\n",i,j);
          pnph_new[i][j] = pn[i][j] + 0.5*dt*pdot[i][j];
          dp[i][j] = pnph_new[i][j] - pnph[i][j];
          pnph[i][j] = pnph_new[i][j];
        }
      }
      if (l2norm(dp) < tol) {
        done = 1;
      }
      printf("PNPH Solver: k=%d, ||pnph|| = %g, ||dp|| = %g\n",k,l2norm(pnph),l2norm(dp));
      k++;
    }
    if (done != 1) {
      printf("SV0: failed to converge in pnph loop. ||dp|| = %g\n",l2norm(dp));
      exit(2);
    }

    /* Solve for q_{n+1} */
    qdotpn0(qdot, qn, pnph, params);
    k = 0;
    done = 0;
    while(k < itmax && done == 0) {
      qdotpn0(qdot2, qnp1, pnph, params);
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          qnp1_new[i][j] = qn[i][j] + 0.5*dt*(qdot[i][j] + qdot2[i][j]);
          dq[i][j] = qnp1_new[i][j] - qnp1[i][j];
          qnp1[i][j] = qnp1_new[i][j];
        }
      }
      if (l2norm(dq) < tol) {
        done = 1;
      }
      k++;
    }
    if (done != 1) {
      printf("SV0: failed to converge in qnp1 loop. ||dq|| = %g\n",l2norm(dq));
      exit(2);
    }

    /* Solve for p_{n+1} */
    pdotpn0(pdot, qnp1, pnph, params);
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        pnp1[i][j] = pnph[i][j] + 0.5*dt*pdot[i][j];
      }
    }

    /*------------- END one step of S-V -------------------*/

    /* Now copy t^{n+1} solution to t^n */
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        pn[i][j] = pnp1[i][j];
        qn[i][j] = qnp1[i][j];
      }
    }
    
  }

  return 1;
 
}


