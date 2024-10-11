#include <iostream>
#include <cstdlib>
using namespace std;

class Matriu {
private:
    int files, columnes;
    int m[10][10];
public:
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

    void escriureMatriu(Matriu matriu){
        int i, j;
        for(i=0;i<matriu.files;i++){
            for(j=0;j<matriu.columnes;j++)
            cout << matriu.m[i][j] << ", ";
            cout << endl;
            }
        return ;
    }
};

int main() {
    Matriu m;
    m = m.llegirMatriu();
    m.escriureMatriu(m);
    return 0;
}

