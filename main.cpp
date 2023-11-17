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
                    cout << "["<< a <<","<< b << "," << c << "]" << endl;
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
                cout << "["<< a <<","<< b << "," << c << "]" << endl;
                // grosser einfluss auf die Laufzeit!
            }
        }
    }
    return solutions;
}


int f(int n, int &counter){
    ++counter;

    if (n==1){
        return 1;
    }
    else{
        return f(n-1,counter) + f(n-1,counter);
    }
}

int main(){
    int n = 5;

    auto start_alice = high_resolution_clock::now();
    auto alices_solution = alice_solution(n);
    auto stop_alice = high_resolution_clock::now();
    auto duration_alice = duration_cast<milliseconds>(stop_alice - start_alice);
    cout << "Alices Solution: " << alices_solution <<" number combinations, took " << duration_alice.count() << " milliseconds to calculate!" << endl;

    auto start_bob = high_resolution_clock::now();
    auto bobs_solution = bob_solution(n);
    auto stop_bob = high_resolution_clock::now();
    auto duration_bob = duration_cast<milliseconds>(stop_bob - start_bob);
    cout << "Bobs Solution: " << bobs_solution << " number combinations, took " << duration_bob.count() << " milliseconds to caluculate!" << endl;
    
    //int counter = 0;
    //auto a = f(n, counter);
    //cout << counter << endl;

    return 0;
}

