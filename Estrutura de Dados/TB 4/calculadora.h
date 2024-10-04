#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <math.h>

#define M_PI 3.14
#define MAX 100

typedef struct {
    double data[MAX];
    int top;
} Stack;

void fazPilha(Stack *stack);
int PilhaCheia(Stack *stack);
int PilhaVazia(Stack *stack);
void push(Stack *stack, double value);
double pop(Stack *stack);
double Posfixa(char* expression);

#endif