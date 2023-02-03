#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
    void dfs(int n){
        (*vis)[n] = 1;
        cout<<n<<" ";

        vector<int> :: iterator itv;
        for(itv=v[n].begin();itv!=v[n].end();itv++){
            if(!(*vis)[*itv]) {dfs(*itv);}
        }
    }
    void Connected(){
        for(int i=0;i<n; i++){
            if(!(*vis)[i]){
                dfs(i);
            }
            cout<<" <-> ";
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
    g.Connected();
     
    return 0;
}   
