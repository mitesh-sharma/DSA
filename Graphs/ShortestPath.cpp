#include<iostream>
#include<unordered_map>
#include<list>
#include <queue>
#include <stack>
using namespace std;
template <typename T>

class Graph{

    unordered_map<T, list <pair<int, int>>> adjList;

    public:
        void addEdge(T u, T v, int wt,bool isdirected){
            adjList[u].push_back({v,wt});

            if(!isdirected){
                adjList[v].push_back({u,wt});
            }
        }

        void printAdjList(){
            for(auto node:adjList){
                cout << node.first << " -> ";
                for(auto nbr: node.second){
                    cout << "(" << nbr.first << ", " << nbr.second << ") ";
                }
                cout << endl;
            }
        }

        //FOR NON WEIGHTED GRAPH
        void shortestPathBFS(int src, int dest, unordered_map <int, int>& parent, unordered_map <int, bool>& visited){
            queue <T> q;

            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                T frontNode = q.front();
                q.pop();
                for(auto neighbour: adjList[frontNode]){
                    if(!visited[neighbour.first]){
                        q.push(neighbour.first);
                        visited[neighbour.first] = true;
                        parent[neighbour.first] = frontNode;
                    }
                }
            }
            int x = dest;
            stack <int> st;
            while(x != parent[src]){
                st.push(x);
                x = parent[x];
            }
            //using stack to reverse the output path
            cout << "Printing ans: ";
            while(!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
        }
        void topologicalSortDFS(T src, unordered_map <T, bool>& visited, stack <int>& st){
            visited[src] = true;

            for(auto neighbour: adjList[src]){
                if(!visited[neighbour.first]){
                    topologicalSortDFS(neighbour.first, visited, st);
                }
            }
            st.push(src);
        }
        
        void shortestPathUsingDFS(int dest, stack <int> topoOrder, int n){
            vector <int> dist(n, INT_MAX);
            int src = topoOrder.top();
            topoOrder.pop();
            dist[src] = 0;

            for(auto nbr:adjList[0]){
                if(dist[0] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[0] + nbr.second;
                } 
            }

            while(!topoOrder.empty()){
                int topElement = topoOrder.top();
                topoOrder.pop();
                if(dist[topElement] != INT_MAX){
                    for(auto nbr:adjList[topElement]){
                        if(dist[topElement] + nbr.second < dist[nbr.first]){
                            dist[nbr.first] = dist[topElement] + nbr.second;
                        } 
                    }
                }
                else{

                }
            }
            cout << "minimum distances for all nodes: " << endl;
            for(int i=0; i<n; i++){
                cout << i << "->" << dist[i] << ", ";
            }
            cout << endl;
            cout << "Minimum distance to reach destination node (" << dest << ") is --> " << dist[dest] << endl;
        }   
        
};
int main()
{
    Graph <int> g;

    //Non weighted graph
    // g.addEdge(0,1,1,1);
    // g.addEdge(1,2,1,1);
    // g.addEdge(2,3,1,1);
    // g.addEdge(3,4,1,1);
    // g.addEdge(0,5,1,1);
    // g.addEdge(5,4,1,1);
    // g.addEdge(0,6,1,1);
    // g.addEdge(6,7,1,1);
    // g.addEdge(7,8,1,1);
    // g.addEdge(8,4,1,1);

    // weighted graph
    int n;
    cout << "enter number of Nodes: ";
    cin >> n;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.printAdjList();
    cout << endl;

    int src = 0;
    int dest = 3;
    unordered_map <int, int> parent;
    parent[0] = -1;
    unordered_map <int, bool> visited;
    //FOR NON WEIGHTED GRAPH
    // g.shortestPathBFS(src, dest, parent, visited);

    //FOR WEIGHTED GRAPH
    stack <int> topoOrder;
    g.topologicalSortDFS(0,visited, topoOrder);
    g.shortestPathUsingDFS(dest, topoOrder, n);
    return 0;
}