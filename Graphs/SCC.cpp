#include<iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Graph{

    unordered_map<T, list <int>> adjList;

    public:
        void addEdge(T u, T v, bool isdirected){
            adjList[u].push_back(v);

            if(!isdirected){
                adjList[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto node:adjList){
                cout << node.first << " -> ";
                for(auto neighbor: node.second){
                    cout << neighbor <<" ";
                }
                cout << endl;
            }
        }

//============================================= SCC ====================================================

        void dfs1(int src, stack <int>& s, unordered_map <int, bool>& visited){
            visited[src] = true;

            for(auto nbr: adjList[src]){
                if(!visited[nbr]){
                    dfs1(nbr, s, visited);
                }
            }
            s.push(src);
        }
        void dfs2(int src, unordered_map <int, bool>& vis,unordered_map <int, list <int>> newAdjList){
            vis[src] = true;
            cout << src << " ";
            for(auto nbr: newAdjList[src]){
                if(!vis[nbr]){
                    dfs2(nbr, vis, newAdjList);
                }
            }
        }
        //main SCC function
        int SCC(int n){

            //DFS Traversal
            stack <int> s;
            unordered_map <int, bool> visited;
            // dfs1(0, s, visited);
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    dfs1(i, s, visited);
                }
            }
            
            //reversing the flow
            unordered_map <int, list <int>> newAdjList;
            for(auto t: adjList){
                for(auto nbr: t.second){
                    int u = t.first;
                    int v = nbr;
                    newAdjList[v].push_back(u);
                }
            }

            //traversing and counting 
            int cnt = 0;
            unordered_map <int, bool> visited2;
            while(!s.empty()){
                int node = s.top();
                s.pop();
                if(!visited2[node]){
                    cout << "SCC "<< cnt+1 << " -> ";
                    dfs2(node, visited2, newAdjList);
                    cout << endl;
                    cnt++;
                }
            }
            return cnt;
        }
};
int main()
{
    Graph <int> g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,4,1);
    g.addEdge(6,7,1);

    g.printAdjList();
    cout << endl;

    int ans = g.SCC(8);
    cout << "Total SCC: "<< ans << endl << endl;
    return 0;
}