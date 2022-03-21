#include <iostream>
#include <time.h>
using namespace std;


int main(){
    srand(time(NULL));
    const int N = 10;
    const int DIMENSION = 3;
    const int MAX_VALUE_RANGE = 20;
    cout<<DIMENSION<<endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < DIMENSION; j++)
            cout<<rand()%MAX_VALUE_RANGE*2-MAX_VALUE_RANGE<<" ";
        cout<<endl;
    }
    return 0;
}