#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

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
    stack<int> topo;
    void dfs(int n){
        (*vis)[n] = 1;
        // cout<<n<<" ";

        vector<int> :: iterator itv;
        for(itv=v[n].begin();itv!=v[n].end();itv++){
            if(!(*vis)[*itv]) {dfs(*itv);}
        }
        topo.push(n);
    }
    
    stack<int> topological(){
        
        for(int i=0 ;i<n; i++){
            if(!((*vis)[i])) dfs(i);
        }
        return topo;
    };

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    //Method 2 using dfs
    int n,e;
    cin>>n>>e;
    Graph g(n);
    for(int i=0 ;i<e; i++){
        int x,y;
        cin>>x>>y;
        g.addedge(x,y);
    }

    stack<int> s = g.topological();
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;






    // // Method- 1 without dfs and graph class
    // int n,e;
    // cin>>n>>e;
    // vector<vector<int> > adj(n);
    // vector<int> id(n,0);

    // for(int i=0 ;i<e; i++){
    //     int x,y;
    //     cin>>x>>y;
    //     adj[x].push_back(y);
    //     id[y]++;
    // }

    // queue<int> q;
    // for(int i=0 ;i<n; i++){
    //     if(id[i]==0) q.push(i);
    // }
    // int count = 0;
    // while(!q.empty()){
    //     count++;
    //     int x = q.front();
    //     q.pop();
    //     cout<<x<<" ";
    //     vector<int> :: iterator it;
    //     for(it=adj[x].begin(); it!=adj[x].end();it++){
    //         id[*it]--;
    //         if(id[*it]==0) q.push(*it);
    //     }
    // }
    return 0;
}   
