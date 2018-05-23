#ifndef HAVE_PARAMS_H
#define HAVE_PARAMS_H

typedef struct {

  int order;
  int run_number;
  int step;
  int verbose;
  double tfinal;
  double dt;
  double ma;
  double mb;
  double mc;
  double CC;
  double G;
  double phi;
  double rho;
  double tol;
  char   id_file[256];

} Params;

#endif

