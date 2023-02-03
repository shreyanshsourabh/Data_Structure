#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif


    int age;
    cin>>age;

    if(age>=18){
        cout<<"Eligible to vote\n";
    }else{
        cout<<"Not Eligible\n";
    }

    return 0;
}   