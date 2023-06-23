#include<iostream>
#include<unordered_map>
#include<list>
#include <queue>
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

        void bfs(T src, unordered_map <T, bool>& visited){
            queue <T> q;

            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                T frontNode = q.front();
                q.pop();
                cout << frontNode << " ";
                for(auto neighbour: adjList[frontNode]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;

                    }
                }
            }
        }

        void dfs(T src, unordered_map <T, bool>& visited){
            cout << src << " ";
            visited[src] = true;

            for(auto neighbour: adjList[src]){
                if(!visited[neighbour]){
                    dfs(neighbour, visited);
                }
            }
        }
};
int main()
{
    Graph <int> g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,7,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    g.printAdjList();
    cout << endl;

    //If the graph is disconnected
    unordered_map <int, bool> visited;
    //printing bfs
    cout << "Printing BFS: ";
    for(int i = 0; i<=7; i++){
        if(!visited[i]){
            g.bfs(i, visited);
        }
    }
    cout << endl;

    //printing dfs
    cout << "Printing DFS: ";
    unordered_map <int, bool> visited2;
    for(int i = 0; i<=7; i++){
        if(!visited2[i]){
            g.dfs(i, visited2);
        }
    }


    return 0;
}