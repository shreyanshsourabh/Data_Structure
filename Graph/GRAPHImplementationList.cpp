#include<iostream>
#include<vector>
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

};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<"Adjacency List"<<endl;

    int n,e;
    cin>>n>>e;
    Graph g(n);

    for(int i=0; i<e;i++){
        int x,y;
        cin>>x>>y;
        g.addedge(x,y);
    }
    g.display();

    
    return 0;
}   
