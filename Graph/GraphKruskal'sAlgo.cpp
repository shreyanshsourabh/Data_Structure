#include<iostream>
#include<vector>
using namespace std;

int l = 100;
vector<int> parent(l),sz(l);
void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" ,stdin);
        freopen("output.txt","w",stdout);
    #endif

    cout<<"int main is not running"<<endl;
    // for(int i=0; i<l; i++){
    //     make_set(i);
    // }

    // int n,e;
    // cin>>n>>e;
    // vector<vector<int> > edge;
    // for(int i=0; i<e; i++){
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     edge.push_back({w,u,v});
    // }

    // int cost =0;
    // //Sorting edges wrt weight
    // sort(edge.begin(),edge.end());

    // vector<vector<int> > ::iterator it;
    // for(int i=0; i<e; i++){
    //     int w = (*it)[0];
    //     int u = (*it)[1];
    //     int v = (*it)[2];

    //     int x = find_set(u);
    //     int y = find_set(v);

    //     if(x==y) continue;
    //     else {
    //         cout<<u<<" "<<v<<endl;
    //         cost+= w;
    //         union_set(u,v);
    //     }
    // }
    // cout<<cost;
     
    return 0;
}   
