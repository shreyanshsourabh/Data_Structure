#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool bipart = true;
class Graph{
    int n;
    vector<int>* v;
    public:
    vector<bool>* vis;

    Graph(int l){
        n = l;
        v = new vector<int>[l*10];
        vis = new vector<bool>(l*10,0);
    }
    void addedge(int x,int y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    void display(){
        for(int i=1; i<n+1; i++){
            cout<<i<<" -> ";
            vector<int> :: iterator it;
            for(it=v[i].begin(); it!=v[i].end();it++){
                cout<<*it<<" ";
            }cout<<endl;
        }
    }
    void color(int u,int curr,vector<int> &col,vector<bool> &vis){
        if(col[u]!=-1 && col[u]!=curr){
            bipart =  false;
            return;
        }
        col[u] = curr;
        if(vis[u]) return;
        vis[u] = true;
        vector<int> :: iterator it;
        for(it=v[u].begin(); it!=v[u].end();it++){
            color(*it,(curr) xor 1,col,vis);
        }
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n,e;
    cin>>n>>e;
    Graph g(n);

    for(int i=0 ;i<e ; i++){
        int x,y;
        cin>>x>>y;
        g.addedge(x,y);
    }

    vector<bool> vis(n,0);
    vector<int> col(n,-1);

    for(int i=0;i<n; i++){
        if(!vis[i]){
            g.color(i,0,col,vis);
        }
    }
    if(bipart) cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;
     
    return 0;
}   
