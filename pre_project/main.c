#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <getopt.h>

#include "tb.h"
/*  to use GNU floating point exception traps
#define _GNU_SOURCE
#include <fenv.h>
*/




/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
int main(int argc, char *argv[])
{

/*
    feenableexcept(FE_INVALID   | 
                   FE_DIVBYZERO | 
                   FE_OVERFLOW);
//                 FE_UNDERFLOW);
*/

  double q[3][3], p[3][3];
  Params params;

  commandline(argc, argv, &params);

  if (params.verbose > 2) {
    printf("calling initial data...\n");
  }
  initial_data(q, p, &params);

  if (params.verbose > 2) {
    printf("calling evolve...\n");
  }
  evolve(q, p, &params);

  printf("Finis.\n");
  return (0);

}


/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void commandline(int argc, char *argv[], Params *params)
{

 /* default values */
  double dt = 0.01;
  double CC = 1.0;
  double G  = 1.0;
  double phi = 0.0;
  double rho = 0.0;
  double tol = 1.0e-10;
  int    order = 0;
  int    run_number = 0;
  int    step = 1;
  int    verbose = 0;
  char   filename[256];
  sprintf(filename,"IDfile");

  double tfinal;


  static struct option long_options[] = 
    {
      {"time_step",       required_argument, 0, 'd'},
      {"order",           required_argument, 0, 'o'},
      {"tolerance",       required_argument, 0, 'e'},
      {"id_file",         required_argument, 0, 'f'},
      {"help",            no_argument,       0, 'h'},
      {"speed_of_light",  required_argument, 0, 'C'},
      {"newton_G",        required_argument, 0, 'G'},
      {"run_number",      required_argument, 0, 'n'},
      {"phi",             required_argument, 0, 'p'},
      {"rho",             required_argument, 0, 'r'},
      {"step",            required_argument, 0, 's'},
      {"verbose",         required_argument, 0, 'v'},
      {0, 0, 0, 0}
    };
  int option_index = 0;
  int c;

  if (argc < 1) {
    usage(argv);
    exit(2);
  }

  while (1) {
    c = getopt_long(argc, argv, "d:o:e:f:hn:p:r:s:v:C:G:",
                    long_options, &option_index);
    if (c == -1)
      break;

    switch (c)
      {
      case 'd':
        dt = atof(optarg);
        printf("   dt = %g\n",dt);
        break;

      case 'o':
        order = atoi(optarg);
        printf("   dt = %d\n",order);
        break;

      case 'e':
        tol = atof(optarg);
        printf("   tol = %g\n",tol);
        break;

      case 'f':
        sprintf(filename,"%s",optarg);
        printf("   idfile = %s\n",filename);
        break;

      case 'G':
        G = atof(optarg);
        printf("   Newton's constant G = %g\n",G);
        break;

      case 'h':
        usage_long(argv);
        exit(2);
        break;

      case 'C':
        CC = atof(optarg);
        printf("   speed of light (c) = %g\n",CC);
        break;

      case 'n':
        run_number = atoi(optarg);
        printf("   dt = %d\n",run_number);
        break;

      case 'p':
        phi = atof(optarg);
        printf("   phi = %g\n",phi);
        break;

      case 'r':
        rho = atof(optarg);
        printf("   rho = %g\n",rho);
        break;

      case 's':
        step = atoi(optarg);
        printf("   step = %d\n",step);
        break;

      case 'v':
        verbose = atoi(optarg);
        printf("   verbose level = %d\n",verbose);
        break;

      default:
        abort();

      }
  }

  if (optind == argc-1) {
    tfinal = atof(argv[optind]);
    printf("   tfinal = %g\n",tfinal);
  }
  else {
    usage(argv);
    exit(2);
  }

  params->order = order;
  params->run_number = run_number;

  params->dt     = dt;
  params->G      = G;
  params->CC     = CC;
  params->phi    = phi;
  params->rho    = rho;
  params->tfinal = tfinal;
  params->tol    = tol;
  params->step   = step;
  params->verbose = verbose;
  sprintf(params->id_file,"%s",filename);
  
    
}

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void usage(char *argv[])
{
  printf("Usage: %s [-defhnoprsvCG] <time>\n\n",argv[0]);
  printf("  For additional information use -h or --help\n");
}

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void usage_long(char *argv[])
{
  printf("Usage: %s [-defhnoprsvCG] <time>\n\n",argv[0]);
  printf("  -d REAL | --time_step REAL  Time step for output\n");
  printf("  -e REAL | --tolerance REAL  Tolerance for iterative solver.\n");
  printf("  -f FILE | --id_file FILE    Name of initial data file\n");
  printf("  -h      | --help            Print this help message\n");
  printf("  -n INT  | --run_number INT  Run number\n");
  printf("  -o INT  | --order INT       Post-Newtonian order.\n");
  printf("  -p REAL | --phi REAL        phi\n");
  printf("  -r REAL | --rho REAL        rho\n");
  printf("  -s INT  | --step INT        Integrator takes s steps per dt.\n");
  printf("  -v INT  | --verbose INT     Verbose level (0,1,2,...)\n");
}

/*----------------------------------------------------------------------
 *
 *
 *
 *----------------------------------------------------------------------*/
void initial_data(double q[3][3], double p[3][3], Params *params)
{

  double ma, qax, qay, qaz, pax, pay, paz;
  double mb, qbx, qby, qbz, pbx, pby, pbz;
  double mc, qcx, qcy, qcz, pcx, pcy, pcz;

  FILE *idfile = fopen(params->id_file, "r");

  if (idfile != NULL) {
    fscanf(idfile,"%lg %lg %lg %lg %lg %lg %lg",&ma,&qax,&qay,&qaz,
           &pax,&pay,&paz);
    fscanf(idfile,"%lg %lg %lg %lg %lg %lg %lg",&mb,&qbx,&qby,&qbz,
           &pbx,&pby,&pbz);
    fscanf(idfile,"%lg %lg %lg %lg %lg %lg %lg",&mc,&qcx,&qcy,&qcz,
           &pcx,&pcy,&pcz);
  }
  else {
    printf("INITIAL_DATA: Unable to open the initial data file:  %s\n",
            params->id_file);
    abort();
  }
  fclose(idfile);

  params->ma = ma;
  q[0][0] = qax;
  q[0][1] = qay;
  q[0][2] = qaz;
  p[0][0] = pax;
  p[0][1] = pay;
  q[0][2] = paz;
  params->mb = mb;
  q[1][0] = qbx;
  q[1][1] = qby;
  q[1][2] = qbz;
  p[1][0] = pbx;
  p[1][1] = pby;
  q[1][2] = pbz;
  params->mc = mc;
  q[2][0] = qcx;
  q[2][1] = qcy;
  q[2][2] = qcz;
  p[2][0] = pcx;
  p[2][1] = pcy;
  q[2][2] = pcz;

  if (params->verbose > 0) {
    printf("----------------------------------------------------------------\n");
    printf("\n");
    printf(" Initial Data\n");
    printf("-------------\n");
    printf("   Body 1:   m1 = %g\n",params->ma);
    printf("             q  = (%g, %g, %g)\n",q[0][0],q[0][1],q[0][2]);
    printf("             p  = (%g, %g, %g)\n",p[0][0],p[0][1],p[0][2]);
    printf("\n");
    printf("   Body 2:   m2 = %g\n",params->mb);
    printf("             q  = (%g, %g, %g)\n",q[1][0],q[1][1],q[1][2]);
    printf("             p  = (%g, %g, %g)\n",p[1][0],p[1][1],p[1][2]);
    printf("\n");
    printf("   Body 3:   m3 = %g\n",params->mc);
    printf("             q  = (%g, %g, %g)\n",q[2][0],q[2][1],q[2][2]);
    printf("             p  = (%g, %g, %g)\n",p[2][0],p[2][1],p[2][2]);
    printf("\n");
    printf("----------------------------------------------------------------\n");
    printf("\n");
  }
}
