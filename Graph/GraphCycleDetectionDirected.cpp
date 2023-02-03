#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int n;
    vector<int>* v;
    public:
    
    Graph(int l){
        n = l;
        v = new vector<int>[l*10];
    }
    void addUndirectedEdge(int x,int y){
        v[x].push_back(y);
        v[y].push_back(x);
    }
    void addDirectedEdge(int x,int y){
        v[x].push_back(y);
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
    bool iscycle(int n, vector<bool> &vis,vector<int> &stack){
        stack[n] = true;
        if(!vis[n]){
            vis[n] = true;
            vector<int> :: iterator it;
            for(it=v[n].begin(); it!=v[n].end();it++){
                if(!vis[*it] && iscycle(*it,vis,stack)) return true;
                if(stack[*it]) return true;
            }
        }
        stack[n] = false;
        return false;
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
    for(int i=0; i<e; i++){
        int x,y;
        cin>>x>>y;
        g.addDirectedEdge(x,y);
    }
    bool cycle = false;
    vector<bool> vis(n,false);
    vector<int> stack(n,0);
    for(int i=0 ;i<n; i++){
        if(!vis[i] && g.iscycle(i,vis,stack)){
            cycle = true;
        }
    }

    if(cycle) cout<<"cycle is present"<<endl;
    else cout<<"cycle is not present"<<endl;
    return 0;
}   
