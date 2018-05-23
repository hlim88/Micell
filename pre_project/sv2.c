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

int StoermerVerlet2(double qn[3][3],   double pn[3][3], 
                    double dt, int nsteps, Params *params)
{

  int i, j, k, it;
  int done;
  double qnp1[3][3], pnp1[3][3];
  double pnph[3][3], pnph_new[3][3], pdot[3][3], dp[3][3];
  double qnp1_new[3][3], qdot[3][3], qdot2[3][3], dq[3][3];

  const int itmax = 2500;
  const double tol = 1.0e-11;
  
//printf("SV2: nsteps=%d\n",nsteps);
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
      pdotpn2(pdot, qn, pnph, params);
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          pnph_new[i][j] = pn[i][j] + 0.5*dt*pdot[i][j];
          dp[i][j] = pnph_new[i][j] - pnph[i][j];
          pnph[i][j] = pnph_new[i][j];
        }
      }
      if (l2norm(dp) < tol) {
        done = 1;
      }

      k++;
#if 0
      printf("PNPH Solver: k=%d, dt=%g, ||pnph|| = %g, ||pdot||=%g, ||dp|| = %g\n",k,dt,l2norm(pnph),l2norm(pdot),l2norm(dp));
      printf("    pa(n)     = (%g, %g, %g)  pb(n)     = (%g, %g, %g)\n",pn[0][0],pn[0][1],pn[0][2],pn[1][0],pn[1][1],pn[1][2]);
      printf("    pa(n+1/2) = (%g, %g, %g)  pb(n+1/2) = (%g, %g, %g)\n",pnph[0][0],pnph[0][1],pnph[0][2],pnph[1][0],pnph[1][1],pnph[1][2]);
      printf("    PA(n+1/2) = (%g, %g, %g)  PB(n+1/2) = (%g, %g, %g)\n",pnph_new[0][0],pnph_new[0][1],pnph_new[0][2],pnph_new[1][0],pnph_new[1][1],pnph_new[1][2]);
      printf("    dp(n+1/2) = (%g, %g, %g)  dp(n+1/2) = (%g, %g, %g)\n",dp[0][0],dp[0][1],dp[0][2],dp[1][0],dp[1][1],dp[1][2]);
      k++;
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          pnph[i][j] = pnph_new[i][j];
        }
      }
#endif
    }
    if (done != 1) {
      printf("SV2: failed to converge in pnph loop. ||dp|| = %g\n",l2norm(dp));
      exit(2);
    }

    /* Solve for q_{n+1} */
    qdotpn2(qdot, qn, pnph, params);
    k = 0;
    done = 0;
    while(k < itmax && done == 0) {
      qdotpn2(qdot2, qnp1, pnph, params);
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
      printf("SV2: failed to converge in qnp1 loop. ||dq|| = %g\n",l2norm(dq));
      exit(2);
    }

    /* Solve for p_{n+1} */
    pdotpn2(pdot, qnp1, pnph, params);
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


