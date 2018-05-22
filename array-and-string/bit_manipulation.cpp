#include <iostream>
#include <bitset>
using namespace std;

// int bit_count(int num){
    
//     while (num != 0)
// }

// long flip_bits(long num){

// }

// void flip_kth_bit(int& num){

// }

// void append_bit(int num){

// }

void print_by_bits(int num){ 
    bitset<8> x(num);
    cout << x << endl;
}   

int main(){ 
    int x = 15;
    //cout << x<<1 << endl;
    x >>= 3;
    print_by_bits(x);
    return 0;
    
}