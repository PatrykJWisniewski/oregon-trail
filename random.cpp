#include<iostream>
using namespace std;

int randomNumbers(int min, int max){
    // rand() % (max-min+1) + min
    return (rand() % (max-min+1)) + min;
}

int main(){
    int num = 0;
    // need to write before calling rand() to seed the random number generator
    srand(time(0));
    
    for(int i=0;i<10;++i){
        // random numbers between 3 and 10
        num = randomNumbers(3,10);
        cout<<num<<" ";
    }
}