#include<iostream>
#include<queue>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,e;
    cin>>n>>e;
    
    vector<vector<int> > graph(n+1,vector<int> (n+1,0));
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    cout<<"Adjacency Matrix"<<endl;

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}   
