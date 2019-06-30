#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct{
	int n;
	int m;
	float *mat;
}matrix;

matrix* make_mat(int n, int m){
	assert(n>0 && m>0);
	matrix * X = (matrix*)malloc(sizeof(matrix));
	X->n=n;
	X->m=m;
	X->mat=(float*)malloc(n*m*sizeof(float));
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
      (X->mat)[m*i + j]=(float)rand()/(float)(RAND_MAX);
    }
	}
	return X;
}
void kill_mat(matrix*M){
  free(M->mat);
  free(M);
}
matrix* mult(matrix * A,matrix *B){
	assert(A->m==B->n);
	int n = A->n;
	int m = B->m;
	matrix* C = make_mat(n,m);
	int i,j,k;
	for(i=0; i< n;i++){
		for(j=0;j<m;j++){
			float * c =& C->mat[i*m+j];
			for(k=0;k<A->m;k++){
				*c+=((A->mat)[i*m +k])*((B->mat)[k*m +j]);
				}
			}
		}
	return C;
};

float sigmoid(float z){
	return (float)1.0/(1+exp(-z));
}
float sigmoid_derivative(float z){
	float x = sigmoid(z);
	return x*(1-x);
}
float relu(float z){
  if(z>=0.0) return z;
  return 0.0;
}
matrix* sigmoid_activation(matrix *z){
	int n = z->n;
	int m = z->m;
	assert(n > 0 && m > 0);
  matrix *out = make_mat(n,m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			(z->mat)[i*m + j]=sigmoid((z->mat)[i*m + j]);
			}
		}
	return out;
}
matrix* add(matrix*A,matrix* B){
	assert(A->n==B->n && A->m==B->m);
	int n = A->n;
  int m = A->m;
	matrix* C = make_mat(n,m);
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			C->mat[i*m + j]=A->mat[i*m +j]+B->mat[i*m + j];
			}
		}
return C;
}
matrix* transpose(matrix*M){
	int n = M->n;
  int m = M->m;
	matrix * t = make_mat(m,n);
	int i,j;
	for(i = 0; i<n;i++){
		for(j=0;j<m;j++){
			t->mat[i + j*m] = M->mat[i*m+j];
		}
	}
	return t;
}
void printmat(matrix*M){
  int n = M->n;
  int m = M->m;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%.6f\t",(M->mat)[m*i + j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
