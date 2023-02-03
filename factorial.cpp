#include<iostream>
using namespace std;

int fact(int n){
    int x = n;
    for(int i=n-1; i>=1; i--){
        x *= (n-i);
    }
    return x;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    cout<<fact(n)<<endl;

    
    return 0;
}   