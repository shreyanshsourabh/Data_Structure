#include<iostream>
#include<vector>
#include<stack>
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
    bool iscycle(int n, vector<bool> &vis,int parent){
        vis[n] = true;
        vector<int> :: iterator it;
        for(it=v[n].begin(); it!=v[n].end();it++){
            if(*it!=parent){
                if(vis[*it]) return true;
                if(!vis[*it] && iscycle(*it,vis,n)) return true;
            }
        }
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
        g.addedge(x,y);
    }
    bool cycle = false;
    vector<bool> vis(n,false);
    for(int i=0 ;i<n; i++){
        if(!vis[i] && g.iscycle(i,vis,-1)){
            cycle = true;
        }
    }

    if(cycle) cout<<"cycle is present"<<endl;
    else cout<<"cycle is not present"<<endl;

    
    
    return 0;
}   
