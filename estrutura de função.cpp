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
struct Termo{//termo de uma função matematica
    public:
        double coeficiente;
        int operacao;
        double expoente;
}Termo;
class Funcao{
    public:
        vector <struct Termo> funcaoCompleta;
        //double valorDaFuncao;
        //double valorDeX;
        Funcao(){//construtor
            struct Termo auxiliar;

            auxiliar.coeficiente = 1;
            auxiliar.operacao = 1;
            auxiliar.expoente = 3;
            funcaoCompleta.push_back(auxiliar);


            auxiliar.coeficiente = -9;
            auxiliar.operacao = 1;
            auxiliar.expoente= 1;
            funcaoCompleta.push_back(auxiliar);

            auxiliar.coeficiente = 3;
            auxiliar.operacao = 1;
            auxiliar.expoente = 0;
            funcaoCompleta.push_back(auxiliar);

            /*auxiliar.coeficiente = 1;
            auxiliar.operacao = 4;
            //auxiliar.expoente = 1;
            funcaoCompleta.push_back(auxiliar);*/

            /*int i = 0;//loop
            int op = 0;//operação
            int n = 0;//n termos
            cout<<"Digite o numero de termos da funcao?"<<endl;
            cin>>n;
            for(i=0;i<n;i++){
                cout<<"Digite o coeficiente do termo numero: "<<i<<endl;
                cin>>auxiliar.coeficiente;
                cout<<"Digite a operacao:\n 1- Exponenciacao\n 2- Tangente \n 3- Cosseno \n 4- Elevar a e"<<endl;//ADICIONAR OUTRAS OPERAÇÕES
                cin>>op;
                switch(op){
                    case 1:{//exponenciação
                        auxiliar.operacao = 1;
                        cout<<"Digite o expoente"<<endl;
                        cin>>auxiliar.expoente;
                        break;
                        }//fim do case
                    case 2:{//tangente
                        auxiliar.operacao = 2;
                        break;
                        }//fim do case
                    case 3:{//cosseno
                        auxiliar.operacao = 3;
                        break;
                        }//fim do case
                    case 4:{//elevar a e
                        auxiliar.operacao = 4;
                        break;
                        }//fim do case
                        //ADICIONAR OUTRAS OPERAÇÕES
                    default:{
                        cout<<"Deu ruim 1"<<endl;
                        break;
                        }
                }//fim switch
                cout<<"Coeficiente recebido: "<<auxiliar.coeficiente<<endl;
                cout<<"Operacao recebida: "<<auxiliar.operacao<<endl;
                funcaoCompleta.push_back(auxiliar);
                cout<<endl;
                cout<<endl;
            }//fim do for*/

        }//fim do construtor
        void printFuncaoStruct(){//print da função na forma de struct
            int i = 0;
            for(i=0;i<funcaoCompleta.size();i++){
                cout<<"Coeficiente: "<<funcaoCompleta[i].coeficiente<<endl;
                cout<<"Operacao "<<funcaoCompleta[i].operacao<<endl;
                if(funcaoCompleta[i].operacao == 1){
                    cout<<"expoente: "<<funcaoCompleta[i].expoente<<endl;
                }
                cout<<endl;
            }//fim do for
        }//fim do print funcao
        void printFuncao(){//print em uma forma mais comum
            int i = 0;
            cout<<"________________________________________________________________________________"<<endl;
            for(i=0;i<funcaoCompleta.size();i++){
                cout<<funcaoCompleta[i].coeficiente;
                switch(funcaoCompleta[i].operacao){
                    case 1:{//exponenciação
                        cout<<"(x^"<<funcaoCompleta[i].expoente<<")";
                        break;
                        }//fim do case
                    case 2:{//tangente
                        cout<<"(tg(x))";
                        break;
                        }//fim do case
                    case 3:{//cosseno
                        cout<<"(cos(x))";
                        break;
                        }//fim do case
                    case 4:{//elevar a e
                        cout<<"(e^x)";
                        break;
                        }//fim do case
                        //ADICIONAR OUTRAS OPERAÇÕES
                    default:{
                        cout<<"Deu ruim 2"<<endl;
                        break;
                        }
                }//fim switch
                if(i != funcaoCompleta.size()-1){
                    cout<<" + ";
                }
                //cout<<endl;
            }//fim do for
            cout<<endl;
            cout<<"________________________________________________________________________________"<<endl;
            cout<<endl;
            cout<<endl;
        }//fim do print funcaoCompleta
        double calcularTermo(int k, double x){//numero de termo k
            double e = 2.718281828459;
            //double pi = 3,14159265358979323846;
            double retorno;
            switch(funcaoCompleta[k].operacao){
                case 1:{//exponenciação
                    retorno = funcaoCompleta[k].coeficiente * pow(x, funcaoCompleta[k].expoente);
                    break;
                }//fim do case
                case 2:{//tangente
                    retorno = funcaoCompleta[k].coeficiente * tan(x);
                    break;
                }//fim do case
                case 3:{//cosseno
                    retorno = funcaoCompleta[k].coeficiente * cos(x);
                    break;
                }//fim do case
                case 4:{//elevar a e
                    retorno = funcaoCompleta[k].coeficiente * pow(e, x);
                    break;
                }//fim do case
                //ADICIONAR OUTRAS OPERAÇÕES
                default:{
                    cout<<"Deu ruim 3"<<endl;
                    break;
                }
            }//fim switch
            return retorno;
        }//calcular termo
        double fDe(double x){
            int i = 0;
            double resultado = 0.0;
            for(i=0;i<funcaoCompleta.size();i++){
                resultado += calcularTermo(i, x);
            }
            return resultado;
        }
};
double bissecao(double precisao, double a, double b, Funcao func){//no maximo 10000 interações
    int i = 0;
    double c;
    while(fabs(b-a) > precisao && i < 10000){//fabs = modulo
        c = (a+b)/2.0;
        if(func.fDe(a)*func.fDe(c) < 0){
            b=c;
        }
        else{
            a=c;
        }
        i++;
        printf("na interacao %d    a = %.12f e b = %.12f    e  c = %.12f \n", i, a , b, c);
        Sleep(100);
    }//fim do while
    c = (a+b)/2.0;
    cout<<endl;
    return c;
}//fim da bissecao

double f(double x){
    double y;
    y = pow(x, 3) + (-9*x) + 3;
    return y;
}
double df(double x){
    double y;
    y = 3*pow(x, 2) - 9;
    return y;
}
double newtonRaphson (double precisao, double a, double b){ //FuncaoSimples func, FuncaoSimples  derivada){
    double xi = (a+b)/2;
    int i = 0;
    while(fabs(f(xi)) > precisao){
        if(df(xi) != 0){
            xi = xi-f(xi)/df(xi);
        }
        else{
            xi += precisao;
        }
        i++;
        printf("na interacao %d, xi = %.12f \n", i, xi);
    }
    return xi;
}
int main(){
    Funcao teste;
    teste.printFuncao();
    double precisao = 0.0000001 ;
    double raizAproximadaBissecsao = bissecao(precisao, 0, 1, teste);
    printf("Resultado (bissec), com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n",precisao, raizAproximadaBissecsao, raizAproximadaBissecsao, teste.fDe(raizAproximadaBissecsao));


    double raizAproximadaNewton = newtonRaphson(precisao, 0, 1);
    printf("Resultado (newton), com uma precisao de %.12f a raiz aproximada = %.12f :  f(%.12f) = %.12f \n",precisao, raizAproximadaNewton, raizAproximadaNewton, f(raizAproximadaNewton));

















}
