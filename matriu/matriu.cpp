/*****************************
* TAD matriu d'enters En C++ *
*                            *
* Xavi Blanes curs 24/25     *
*****************************/

#include <iostream>
#include <cstdlib>
using namespace std;

class Matriu {
private:
    int files, columnes;
    int m[10][10];
    
public:
    int filesMatriu(){return this -> files;}

    int columnesMatriu(){return this -> columnes;}

    int elementMatriu(int i, int j){return this -> m[i][j];}
    
    Matriu sumarMatriu(Matriu m, Matriu n){
       Matriu suma;
       int i, j;
        for(i=0;i<m.filesMatriu();i++)
            for(j=0;j<m.columnesMatriu();j++)
            suma.m[i][j] = m.elementMatriu(i,j) + n.elementMatriu(i,j);
        return suma;
    }

    void escriureMatriu(){
        int i, j;
        for(i=0;i<this -> filesMatriu();i++){
            for(j=0;j<this -> columnesMatriu();j++)
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
    Matriu m, n, suma;
    m = m.llegirMatriu();
    m.escriureMatriu();
    n = n.llegirMatriu();
    n.escriureMatriu();
    suma = suma.sumarMatriu(m,n);
    cout << "La suma és: "; 
    cout << endl;
    suma.escriureMatriu();
    return 0;
}
