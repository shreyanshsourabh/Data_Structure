#include<iostream>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    do{
        cout<<n<<endl;
        cin>>n;
    }while(n>0);

    cout<<"Exit\n";


    return 0;
}   