#include <iostream>
#include "KDTree.hpp"

using namespace std;

int main(){
    //Inicjalizacja danych
    KDTree kdt;
    int dimension;
    cin>>dimension;
    int arr[dimension];
    while(cin>>arr[0]){
        for(int i=1;i<dimension;i++){
            cin>>arr[i];
        }
        kdt.insert(arr);
    }
    int point[] = {10, 6, 2};
    double min_distance = 1000;


    cout<<"Tree size = "<<kdt.getTreeSize()<<endl;
    cout<<"Tree depth = "<<kdt.getTreeDepth()<<endl;
    cout<<"\n\nBase contains:\n";
    kdt.preorder(kdt.root);
    Node *closest = nullptr;
    cout<<"\nFind the nearest point to\n";
    for(int i=0;i < sizeof(point)/sizeof(int);i++)
        cout<<point[i]<<" ";
    cout<<endl;
    kdt.getClosestPoint(kdt.root, point, 0, &closest, min_distance);
    // string('-',20);
    cout<<"\nNearest point is:"<<endl;
    closest->print();
    cout<<"Distance from point = "<<min_distance<<endl;
    return 0;
}