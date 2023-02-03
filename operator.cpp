#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int a=10;
    int b;

    //b=a++  + ++a;

    int c;
    c= ++a + a++;
    cout<<a<<c<<endl;;

    
    return 0;
}   