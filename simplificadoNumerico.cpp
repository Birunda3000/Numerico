#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>// Função Sleep
//#include <thread> bibliotecas de  um compilador não padrão
//#include <chrono>
#include <cstdlib>// rand e srand
#include <time.h>
#include <vector>
#include <string>
using namespace std;
//------TODOS OS NUMEROS DEVEM TER SUA PARTE FRACIONARIA EXEMPLO: 1 VIRA 1.0  ,  2 VIRA 2.0------
double e = 2.718281828459;
double f(double x){
    double y;
    y = pow(x,5.0) - 6.0;
    return y;
}
double df(double x){
    double y;
    y = 5.0*pow(x,4.0);
    return y;
}
double bissecao(double precisao, double a, double b, FILE* arquivo){//no maximo 10000 interações
    int i = 0;
    double c = (a+b)/2.0;

    printf("            |         a           |         b           |       c      \n", i);
    printf("interacao %d | a = %.12f | b = %.12f | c = %.12f \n", i, a , b, c);

    //fprintf(arquivo, "            |         a           |         b           |       c      \n", i);
    fprintf(arquivo, "interacao %d | a = %.12f | b = %.12f | c = %.12f \n", i, a , b, c);

    while(fabs(f(c)) > precisao && i < 1000){//fabs = modulo
        c = (a+b)/2.0;
        if(f(a)*f(c) < 0.0){
            b=c;
        }
        else{
            a=c;
        }
        i++;
        printf("interacao %d | a = %.12f | b = %.12f | c = %.12f \n", i, a , b, c);
        fprintf(arquivo, "interacao %d | a = %.12f | b = %.12f | c = %.12f \n", i, a , b, c);
        //Sleep(100);
    }//fim do while
    c = (a+b)/2.0;
    printf("Resultado (bissec), com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n",precisao, c, c, f(c));
    fprintf(arquivo,"Resultado (bissec), com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n",precisao, c, c, f(c));
    cout<<endl;
    return c;
}//fim da bissecao
double newtonRaphson (double precisao, double x0, FILE* arquivo){ //FuncaoSimples func, FuncaoSimples  derivada){
    double xi = x0;
    int i = 0;
    while(fabs(f(xi)) > precisao && i < 1000){
        if(df(xi) != 0){
            xi = xi-f(xi)/df(xi);
        }
        else{
            xi += precisao;
        }
        i++;
        printf("na interacao %d, xi = %.12f | f(xi) = %.12f \n", i, xi, f(xi));
        fprintf(arquivo, "interacao %d | xi = %.12f  | f(xi) = %.12f \n", i, xi, f(xi));
    }
    cout<<endl;
    printf("Resultado (newton-raphson) com x0 = %.12f, com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n", x0, precisao, xi, xi, f(xi));
    fprintf(arquivo,"Resultado (newton-raphson) com x0 = %.12f, com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n", x0, precisao, xi, xi, f(xi));
    return xi;
}
int main(){
    FILE * arquivo;
    arquivo = fopen("tabela", "wt");
    double precisao = 0.0001;
    double a = 0.0;
    double b = 5.0;
    double x0 = (a+b)/2.0;
    double raizAproximadaBissecsao = bissecao(precisao, a, b, arquivo);
    double raizAproximadaNewton = newtonRaphson(precisao, x0, arquivo);
    fclose(arquivo);
}
