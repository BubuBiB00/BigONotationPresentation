#include <iostream> 
#include <chrono>

using namespace std::chrono;
using namespace std;

int bob_solution(int n){
    int solutions = 0;
    for (int a = 0; a <= n; a++){
        for (int b = 0; b <= n; b++){
            for (int c = 0; c <= n; c++){
                if (a + b + c == n){
                    solutions ++;
                    //cout << "["<< a <<","<< b << "," << c << "]" << endl;
                    // grosser einfluss auf die Laufzeit!
                }
                else {
                    continue;     
                }
            }
        }   
    }
    return solutions;
}

int alice_solution(int n){
    int solutions = 0;
    for (int a = 0; a <= n; a++){
        for (int b = 0; b <= n; b++){
            int c = n - (a+b);
            if (c >= 0){
                solutions ++;
                //cout << "["<< a <<","<< b << "," << c << "]" << endl;
                // grosser einfluss auf die Laufzeit!
            }
        }
    }
    return solutions;
}

int main(){
    int n = 10;

    auto start_alice = high_resolution_clock::now();
    auto alices_solution = alice_solution(n);
    auto stop_alice = high_resolution_clock::now();
    auto duration_alice = duration_cast<seconds>(stop_alice - start_alice);
    cout << "Alices Solution "<< alices_solution <<" took " << duration_alice.count() << " seconds to calculate!" << endl;

    auto start_bob = high_resolution_clock::now();
    auto bobs_solution = bob_solution(n);
    auto stop_bob = high_resolution_clock::now();
    auto duration_bob = duration_cast<seconds>(stop_bob - start_bob);
    cout << "Bobs Solution " << bobs_solution << " took " << duration_bob.count() << " seconds to caluculate!" << endl;
    

    return 0;
}

