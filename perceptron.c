#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
	int inputs;
	int outputs;
	struct matrix* weights;
	struct matrix* bias;
	char*activation;
//	layer*next;

} layer;
struct matrix{
	int n;
	int m;
	float **mat;
};
struct matrix* makemat(int n, int m){
	struct matrix * X = malloc(sizeof(struct matrix));
	X->n=n;
	X->m=m;
	X->mat=malloc(n*sizeof(float *));
	int i;
	for(i=0;i<n;i++){
		(X->mat)[i]=malloc(m*sizeof(float));
	}
	return X;

}
struct matrix* mult(struct matrix * A, struct matrix *B){
	if(A->m==B->n){
	printf("ok\n");
	
	
	struct matrix* C = makemat(A->n,B->m);
	int i,j,k;
	int n = A->m;
	for(i=0; i< n;i++){
		for(j=0;j<n;j++){
			float * c =& C->mat[i][j];
			for(k=0;k<n;k++){
				*c+=((A->mat)[i][k])*((B->mat)[k][j]);
			}
		}
	}
return C;
	
}
	//return C;
};
float sigmoid(float z){
	return 1.0/(1+exp(-z));
} 
struct matrix* sigmoid_activation(struct matrix *z){
	struct matrix *out = malloc(sizeof(struct matrix));
	int n = z->n;
	int m = z->m;
	out->n=n;
	out->m=m;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			out->mat[i][j]=sigmoid(out->mat[i][j]);
			}
		}
	return out;
}
struct matrix* add(struct matrix*A,struct matrix* B){
	if(A->n==B->n && A->m==B->m){
		printf("ok\n");
		struct matrix* C = makemat(A->n,B->m);
		int i,j;
		for(i=0;i<A->n;i++){
			for(j=0;j<A->n;j++){
				C->mat[i][j]=A->mat[i][j]+B->mat[i][j];
			}
		}
	return C;
	}
}
void printmat(struct matrix*m){
	int i,j;
	for(i=0;i<m->n;i++){
		for(j=0;j<m->m;j++){
			printf("%.6f\t",m->mat[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}
int main(){

	struct matrix * a = makemat(3,3);
	struct matrix* b = makemat(3,1);
	struct matrix* c = mult(a,b);
	struct matrix* d = sigmoid_activation(c);
	printf("printing a\n");
	printmat(a);
	printf("printing b\n");
	printmat(b);
	printf("printing ab\n");
	printmat(c);
	printmat(d);
	


}
