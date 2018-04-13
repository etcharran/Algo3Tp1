#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include "FuerzaBruta.cpp"

using namespace std;

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