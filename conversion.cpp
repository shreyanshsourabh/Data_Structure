#include<iostream>
using namespace std;

int binaryToDecimal(int n){
    int ans = 0;
    int x = 1;
    while(n>0){
        ans += x*(n%10);
        x *= 2;
        n/= 10;
    }

    return ans;
}

int octalToDecimal(int n){
    int ans = 0;
    int x = 1;
    while(n>0){
        ans += x*(n%10);
        x *= 8;
        n/= 10;
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    // cout<<binaryToDecimal(n)<<endl;

    cout<<octalToDecimal(n)<<endl;

    return 0;
}   