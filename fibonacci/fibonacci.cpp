/*****************************************************************
*       Averigua el número de la Successió de Fibonacci          *
*       inmediatament superior al número introduït per           *
*       l'usuari i també quin terme de la successió és           *
*                                                                *
*       Xavi Blanes curs 24/25                                   *
*****************************************************************/

#include <iostream>
using namespace std;

int fibonacci(int n){
    int aux;
    if(n == 0) aux=0;
    else{
        if((n == 1)||(n == 2)) aux=1;
        else{
            aux=fibonacci(n-1)+fibonacci(n-2);
        }
    }
    return aux;
}

int main() {
    int n, i;
    cout << "Introduix un número i calcularé el número de la Successió de Fibonacci inmediatament superior i també quin terme de la successió és: ";
    cin >> n;
    i=0;
    while(fibonacci(i++) < n);    
    cout << fibonacci(i-1) << " que és el terme " << i-1 << endl;
    return 0;
}
