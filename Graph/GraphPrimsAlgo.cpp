#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[100];
int cost = 0;
void prims(int n){
    
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,e;
    cin>>n>>e;

    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,v});
    }

    prims(0);
    cout<<cost<<endl;

     
    return 0;
}   
