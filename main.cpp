#include <iostream>
#include <math.h>

using namespace std;

//Soma de pesos das moedas
int sumMoedas(int *lista,  int ini, int fim){
    int sum = 0,ii;
    for(ii=ini;ii<fim;ii++){
        sum += lista[ii];
    }
    return sum;
}

//fake coin problem
// assumes that the fake coin is known to be, say, lighter than the genuine one
int FakeCoinProblem(int *A, int ini, int fim){
    //Input: An array A[0..n−1] with weight from coins, a zero number and length of array
    //Output: An index of the array’s element that is fake coin

    int ii,jj,kk,peso1,peso2,peso3,n=fim-ini;

    if (n <= 1)
        return ini;
    else if (n == 2){
        if(A[ini] > A[ini+1])
            return ini+1;
        else
            return ini;
    }
    else{
        ii = floor(n/3);
        jj = 2*floor(n/3);
        kk = 3*floor(n/3);
        peso1 = sumMoedas(A,ini,ini+ii);
        peso2 = sumMoedas(A,ini+ii,ini+jj);
        peso3 = sumMoedas(A,ini+jj,ini+kk);

        if((peso1==peso2)&&(peso1==peso3)){
            FakeCoinProblem(A, ini+kk, fim);
        }
        else if(peso1==peso2){
            FakeCoinProblem(A, ini+jj,ini+kk);
        }
        else if(peso1>peso2){
            FakeCoinProblem(A, ini+ii,ini+jj);
        }
        else{
            FakeCoinProblem(A, ini,ini+ii);
        }
    }
}


int main()
{
    int lista[100] = {1,1,1,1,1,1,1,1,1,0,1};
    int tamanho_lista = 11;
    int retorno;
    retorno = FakeCoinProblem(lista,0,tamanho_lista);
    cout << retorno << endl;
    return 0;
}
