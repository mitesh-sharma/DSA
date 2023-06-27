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
        
        bool checkCycleBFS(T src, unordered_map <T, bool>& visited){
            queue <T> q;
            unordered_map <T, T> parent;
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                T frontNode = q.front();
                q.pop();
                for(auto neighbour: adjList[frontNode]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = frontNode;
                    }
                    else{
                        if(neighbour != parent[frontNode]){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        bool checkCycleDFS(T src, unordered_map <T, bool>& visited, int parent){
            visited[src] = true;

            for(auto neighbour: adjList[src]){
                if(!visited[neighbour]){
                    bool ans = checkCycleDFS(neighbour, visited, src);
                    if(ans){
                        return true;
                    }
                }
                else{
                    if(neighbour != parent){
                        return true;
                    }
                }
            }
            return false;
        }
};
int main()
{
    Graph <int> g;

    g.addEdge(0,1,0);
    g.addEdge(0,2,0);
    g.addEdge(0,6,0);
    g.addEdge(1,3,0);
    g.addEdge(1,4,0);
    g.addEdge(1,5,0);
    g.addEdge(3,4,0);

    g.printAdjList();

    bool ans = false;
    unordered_map <int, bool> visited;
    int n;
    cout << "Enter number of Nodes: ";
    cin >> n;

    // ---------------------------------------------------
    //Using BFS
    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = g.checkCycleBFS(i, visited);
        }
        if(ans == true){
            break;
        }
    }
    // -----------------------------------------------------

    //Using DFS
    // for(int i=0; i<n; i++){
    //     if(!visited[i]){
    //         ans = g.checkCycleDFS(i, visited, -1);
    //     }
    //     if(ans == true){
    //         break;
    //     }
    // }
    //------------------------------------------------------

    if(ans){
        cout << "Cycle present" << endl;
    }
    else{
        cout << "Cycle Not Present"<< endl;
    }
    return 0;
}