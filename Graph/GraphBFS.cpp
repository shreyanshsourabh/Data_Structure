#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int n;
    bool vis[10];
    vector<int>* v;
    public:
    
    Graph(int l){
        n = l;
        v = new vector<int>[l*10];
        for(int i=0; i<10; i++) vis[i] = 0;
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
    void Bfs(int node){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        
        while(!q.empty()){
            int n = q.front();
            cout<<n<<" ";
            q.pop();
            vector<int> :: iterator it;
            for(it=v[n].begin(); it!=v[n].end(); it++){
                if(!vis[*it]) {
                    vis[*it] = true;
                    q.push(*it);
                }
            }
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

    cout<<"BFS"<<endl;

    g.Bfs(9);
     
    return 0;
}   
