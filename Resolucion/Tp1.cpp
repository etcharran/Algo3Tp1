#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>

using namespace std;

struct compareFirstPairMember {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

template<typename Iter>
void quickSort(std::vector<typename Iter::value_type>& vec, Iter left, 
    Iter right) {

    auto size = std::distance(left, right);
    if (size <= 1) {
        return;
    }
    auto pivot = std::next(right, -1);
    if (size == 2 && *pivot < *left) {
        std::iter_swap(left, pivot);
    }
    auto wall = left;
    auto curr = left;

    while (curr != right) {
        if (*curr < *pivot) {
            std::iter_swap(wall, curr);
            wall++;
        }
        curr++;
    }

    std::iter_swap(pivot, wall);
    quickSort(vec, left, wall);
    quickSort(vec, wall + 1, right);

}



void FuerzaBruta(int tamanio){
    vector<pair<int,int>> entrada; 
    std::vector<pair<int,int>>::iterator it;


    entrada.push_back(pair<int,int>(10,20));
    entrada.push_back(pair<int,int>(6,11));
    entrada.push_back(pair<int,int>(6,11));
    entrada.push_back(pair<int,int>(13,26));
    quickSort(entrada,entrada.begin(), entrada.end());

    pair<int,int> maxValor = pair<int,int>(0,0);

    int permutaciones = 0;
    do{
        int valor = 0;
        int tamanioSofar = 0;
        permutaciones++;
        cout << permutaciones << "\n";

        for(int it = 0; it < entrada.size(); it++ ){
            if(tamanioSofar + entrada[it].first <= tamanio){
                tamanioSofar += entrada[it].first;
                valor += entrada[it].second;
            }
        }
        if(valor > maxValor.second){
            maxValor = pair<int,int>(tamanioSofar,valor);
            cout << "tamaño: " << maxValor.first << ", valor: " << maxValor.second << "\n";
        }
    }
    while(next_permutation(entrada.begin(),entrada.end(),compareFirstPairMember()));

}

int main(){
     
    cout << "steady_clock" << endl;
    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;
    
    
    
    
    cout << endl << endl;
    auto startFuerzaBruta4 = chrono::steady_clock::now();
    FuerzaBruta(13);
    auto endFuerzaBruta4 = chrono::steady_clock::now();
    auto diffFuerzaBruta4 = endFuerzaBruta4 - startFuerzaBruta4;
    cout << "Tiempo utilizado por Fuerza bruta 4" << chrono::duration <double, milli> (diffFuerzaBruta4).count() << " ms" << endl;
    
    
    cout << endl << endl;
    auto startFuerzaBruta5 = chrono::steady_clock::now();
    //ochoReinasFuerzaBruta5();
    auto endFuerzaBruta5 = chrono::steady_clock::now();
    auto diffFuerzaBruta5 = endFuerzaBruta5 - startFuerzaBruta5;
    cout << "Tiempo utilizado por Fuerza bruta 5" << chrono::duration <double, milli> (diffFuerzaBruta5).count() << " ms" << endl;
    
    
    cout << endl << endl;
    auto startBacktracking = chrono::steady_clock::now();
    //ochoReinasBacktracking();
    auto endBacktracking = chrono::steady_clock::now();
    auto diffBacktracking = endBacktracking - startBacktracking;
    cout << "Tiempo utilizado por Backtracking " <<chrono::duration <double, milli> (diffBacktracking).count() << " ms" << endl;

    return 0;
}