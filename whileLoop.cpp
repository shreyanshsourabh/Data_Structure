#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    while(n>0){
        cout<<n<<endl;
        cin>>n;
    }

    cout<<"Exit\n";


    return 0;
}   