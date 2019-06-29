#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matrix.c"

typedef struct{
  matrix* X;
  matrix* y;
}data;
typedef struct{
  int n;
  data* set;
}raw_dataset;
typedef struct{
  int n_train;
  raw_dataset* train;

  int n_val;
  raw_dataset* val;
}dataset;
/**
dataset* random_data(matrix* x_dims, matrix *out_dims, int train, int val){

};
**/
