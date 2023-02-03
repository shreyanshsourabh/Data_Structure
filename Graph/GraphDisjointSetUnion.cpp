#include<iostream>
#include<vector>
using namespace std;

int n = 100;
vector<int> parent(n),sz(n);
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

    for(int i=0; i<n; i++){
        make_set(i);
    }
     
    return 0;
}   
