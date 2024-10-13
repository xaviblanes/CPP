/*****************************
* TAD matriu d'enters En C++ *
*                            *
* Xavi Blanes curs 24/25     *
*****************************/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Matriu {
private:
    int files, columnes;
    int m[10][10];
    
public:
    int filesMatriu(){return this -> files;}

    int columnesMatriu(){return this -> columnes;}

    int elementMatriu(int i, int j){return this -> m[i][j];}
    
    bool mateixRang(Matriu m){
        return (m.filesMatriu() == this -> filesMatriu())&&
        (m.columnesMatriu() == this -> columnesMatriu());
    }
    
    bool esQuadrada(){
        return this -> files == this ->columnes;
    }
    
    Matriu perEscalar(int n){
       Matriu aux;
       int i, j, fil, col;
       fil = this -> files;
       col = this -> columnes;
        for(i=0;i<fil;i++)
            for(j=0;j<col;j++)
            aux.m[i][j] = this -> elementMatriu(i,j) * n;
        return aux;    
    }

    Matriu menorMatriu(int x, int y){
        Matriu aux;
        int i, j, fil, col, suma_i, suma_j;
        fil = this -> files-1;
        col = this -> columnes-1;
        suma_i = 0;
        for(i=0;i<fil;i++)
            {
            suma_j = 0;
            if(i == x) suma_i++;
            for(j=0;j<col;j++)
                {
                if(j == y) suma_j++;
                aux.m[i][j] = this -> elementMatriu(i+suma_i,j+suma_j);
                }
            }
            aux.files = aux.columnes = fil;
        return aux;    
    }

    
    Matriu transposada(){
        Matriu trans;
        int i, j, fil, col;
        fil = this -> filesMatriu();
        col = this -> columnesMatriu();
        for(i=0;i<fil;i++)
            for(j=0;j<col;j++)
            trans.m[i][j] = this -> elementMatriu(j,i);
        trans.files = col;
        trans.columnes = fil;
        return trans;    
    }

        int determinant(){
        Matriu aux;
        int j, dim, det = 0;
        dim = this -> filesMatriu();
        if(dim == 1) det = this -> elementMatriu(0,0);
        else
            for(j=0;j<dim;j++)
                {
                aux = this -> menorMatriu(0,j);
                det = det + ( pow(-1,j) * this -> elementMatriu(0,j) 
                * aux.determinant());
                }
        return det;    
    }
    
    Matriu sumarMatriu(Matriu m, Matriu n){
       Matriu suma;
       int i, j;
        for(i=0;i<m.filesMatriu();i++)
            for(j=0;j<m.columnesMatriu();j++)
            suma.m[i][j] = m.elementMatriu(i,j) + n.elementMatriu(i,j);
        return suma;
    }

    void escriureMatriu(){
        int i, j, fil, col;
        fil = this -> filesMatriu();
        col = this -> columnesMatriu();
        for(i=0;i<fil;i++){
            for(j=0;j<columnes;j++)
            cout << elementMatriu(i,j) << ", ";
            cout << endl;
            }
        return ;
    }
    
    Matriu llegirMatriu(){
        Matriu matriu;
        int i, j;
        cout << "Número de files: ";
        cin >> matriu.files;
        cout << "Número de columnes: ";
        cin >> matriu.columnes;
        for(i=0;i<matriu.files;i++)
        for(j=0;j<matriu.columnes;j++)
            {
            cout << "Element " << i+1 << ", " << j+1 << ": ";
            cin >> matriu.m[i][j];        
            }
        return matriu;
    }
};

int main() {
    Matriu m, n, suma, resta, trans, menor;
    m = m.llegirMatriu();
    m.escriureMatriu();
    
    if(m.esQuadrada()) cout << "Sí, és quadrada" << endl;
    else cout << "No, no és quadrada" << endl;
    
    cout << "I la transposada és: " << endl;
    trans = m.transposada();
    trans.escriureMatriu();

    cout << "El determinant és: " << m.determinant() <<  endl;
    menor = m.menorMatriu(1,1);
    menor.escriureMatriu();


/*    
    n = n.llegirMatriu();
    n.escriureMatriu();

    if(m.mateixRang(n))
        {    
        cout << "La suma és: " << endl;
        suma = suma.sumarMatriu(m,n);
        suma.escriureMatriu();
        }
    else cout << "No és poden sumar perquè no tenen el mateix rang!!" << endl;
    
    if(m.mateixRang(n))
        {    
        cout << "La resta és: " << endl;
        n = n.perEscalar(-1);
        resta = resta.sumarMatriu(m,n);
        resta.escriureMatriu();
        }
    else cout << "No és poden restar perquè no tenen el mateix rang!!" << endl;
*/
    return 0;
}
