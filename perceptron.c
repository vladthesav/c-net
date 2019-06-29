#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matrix.c"
typedef struct{
	int inputs;
	int outputs;
	matrix* weights;
	matrix* bias;
	char *activation;
} perceptron;

perceptron* make_perceptron(int in, int out, char *activation){
	perceptron* l = malloc(sizeof(perceptron));
	l->inputs = in;
	l->outputs = out;
	l->activation = activation;
	l->weights = make_mat(out, in);
	l->bias = make_mat(out, 1);
	//make null if none

	//fuck it i'll deal with this later
	//l->prev = prev;
	//l->next = next;
	return l;
};
//this computes the forward for a perceptron
matrix* forward(perceptron* block, matrix* x){
	matrix* out = make_mat(block->outputs, 1);
	out = mult(block->weights,x);
	out = add(out, block->bias);
	//matrix *z;
	/**
	if(!strcmp(block->activation, "sigmoid")){
		z = sigmoid_activation(out);
	}else if(!strcmp(block->activation, "linear")){
		z = sigmoid_activation(out);
	}
	**/
	return out;
};
int main(){
	matrix*x = make_mat(3,3);
	kill_mat(x);
	/**
	perceptron* a = make_perceptron(5, 3, "linear");
	matrix* x = make_mat(5,1);
	matrix * z = forward(a, x);
	printmat(x);
	printmat(z);
	**/
}
