/********************************************
*       TAD matriu d'enters En C++          *
*                                           *
*       Xavi Blanes curs 24/25              *
********************************************/

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

// ++++++++++ Classe Matriu d'enters ++++++++++
// Tindrem: files, columnes, una matriu bidimensinal 
// d'enters i els seus mètodes 

class Matriu {
private:
    int files, columnes;
    float m[10][10];
    
public:

// ++++++++++ consultar el nombre de files d'una matriu ++++++++++

    int filesMatriu(){return this -> files;}

// ++++++++++ consultar el nombre de columnes d'una matriu ++++++++++

    int columnesMatriu(){return this -> columnes;}

// ++++++++++ consultar un element concret d'una matriu ++++++++++

    int elementMatriu(int i, int j){return this -> m[i][j];}
    
// ++++++++++ retorna true si el rang de la matriu que crida ++++++++++
// al mètode és el mateix que el de la matriu passada com a paràmetre

    bool sumables(Matriu m){
        return (m.filesMatriu() == this -> filesMatriu())&&
        (m.columnesMatriu() == this -> columnesMatriu());
    }

// ++++++++++ retorna true si el nombre de files de una ++++++++++
// és igual al de columnes de l'altra i a l'inrevés
    
    bool multiplicable(Matriu m){
        return (this -> files == m.columnesMatriu()) &&
        (this -> columnes == m.filesMatriu()) ;
    }

// ++++++++++ retorna true si el nombre de files és iguals al de columnes ++++++++++
    
    bool esQuadrada(){
        return this -> files == this ->columnes;
    }

// ++++++++++ multiplica una matriu per un escalar ++++++++++

    Matriu perEscalar(float n){
       Matriu aux;
       int i, j, fil, col;
       fil = this -> files;
       col = this -> columnes;
        for(i=0;i<fil;i++)
            for(j=0;j<col;j++)
            aux.m[i][j] = this -> elementMatriu(i,j) * n;
        return aux;    
    }

// ++++++++++ elimina de una matriu la fila i la columna ++++++++++
// indicada el els paràmetres

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

// ++++++++++ retorna la transposada d'una matriu ++++++++++

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

// ++++++++++ retorna el valor del determinant d'una matriu ++++++++++

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
    
// ++++++++++ suma dues matrius, sumar m + (-1)·n és  ++++++++++
// el mateix que restar n de m. Aleshores resta no cal.

    Matriu sumarMatriu(Matriu m, Matriu n){
       Matriu suma;
       int i, j;
        for(i=0;i<m.filesMatriu();i++)
            for(j=0;j<m.columnesMatriu();j++)
            suma.m[i][j] = m.elementMatriu(i,j) + n.elementMatriu(i,j);
        return suma;
    }

// ++++++++++ retorna la matriu adjunta ++++++++++

    Matriu adjunta(){
        Matriu adj, aux;
        int i, j, fil, col;
        fil = this -> filesMatriu();
        col = this -> columnesMatriu();
        for(i=0;i<fil;i++)
            for(j=0;j<col;j++)
                {
                aux = this -> menorMatriu(i,j);
                adj.m[i][j] = pow(-1,(i+j)) * aux.determinant();
                }
        return adj;
    }

// ++++++++++ retorna la matriu inversa ++++++++++

    Matriu inversa(){
        Matriu aux;
        float x;
        aux = this -> adjunta();
        aux = aux.transposada();
        x = 1/(this -> determinant());
        aux = aux.perEscalar(x);
        return aux;
    }


// ++++++++++ escriu per pantalla una matriu ++++++++++

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

// ++++++++++ llig per teclat una matriu ++++++++++

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
    Matriu m, n, suma, resta, trans, menor, adj, inv;
    m = m.llegirMatriu();
    m.escriureMatriu();
    
    if(m.esQuadrada()) cout << "Sí, és quadrada" << endl;
    else cout << "No, no és quadrada" << endl;
    
    cout << "I la transposada és: " << endl;
    trans = m.transposada();
    trans.escriureMatriu();
    
    cout << "I la adjunta és: " << endl;
    adj = m.adjunta();
    adj.escriureMatriu();

    cout << "El determinant és: " << m.determinant() <<  endl;
    
    cout << "La inversa és: " <<  endl;
 
    inv = m.inversa();
    m.escriureMatriu();

 
    n = n.llegirMatriu();
    n.escriureMatriu();

    if(m.sumables(n))
        {    
        cout << "La suma és: " << endl;
        suma = suma.sumarMatriu(m,n);
        suma.escriureMatriu();
        }
    else cout << "No és poden sumar, no són sumables!!" << endl;
    
    if(m.sumables(n))
        {    
        cout << "La resta és: " << endl;
        n = n.perEscalar(-1);
        resta = resta.sumarMatriu(m,n);
        resta.escriureMatriu();
        }
    else cout << "No és poden restar, no són restables!!" << endl;
    return 0;
}
