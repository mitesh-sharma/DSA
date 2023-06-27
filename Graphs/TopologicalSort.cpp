#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include <queue>
#include <stack>
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

        void topologicalSortDFS(T src, unordered_map <T, bool>& visited, stack <int>& st){
            visited[src] = true;

            for(auto neighbour: adjList[src]){
                if(!visited[neighbour]){
                    topologicalSortDFS(neighbour, visited, st);
                }
            }
            st.push(src);
        }

        void topologicalSortBFS(int n, vector <int>& ans){
            queue <int> q;
            unordered_map <int, int> indegree;

            //incrementing indegree of neighbours
            for(auto i: adjList){
                for(auto nbr: i.second){
                    indegree[nbr]++;
                }
            }
            //put all nodes in queue with indegree 0
            for(int i=0; i<n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

            while(!q.empty()){
                int fNode = q.front();
                q.pop();
                ans.push_back(fNode);
                for(auto nbr: adjList[fNode]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }

};
int main()
{
    Graph <int> g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,2,1);

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    g.printAdjList();
    cout << endl;

    unordered_map <int, bool> visited;
    stack <int> st;

    // for(int i = 0; i<=7; i++){
    //     if(!visited[i]){
    //         g.topologicalSortDFS(i, visited, st);
    //     }
    // }
    // //Printing topologically sorted nodes
    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    //BFS
    vector <int> ans;
    g.topologicalSortBFS(n, ans);

    //*******************************************
    
    //Cycle Detection using topological sort (BFS)
    //If cycle is present in the graph all nodes will not be inserted in array after Topological sort

    if(ans.size() == n){
        //printing topologically sorted graph
        cout << "Valid Topological sort" << endl;
        for(auto i: ans){
            cout << i << " ";
        }
    }
    else{
        cout << "CYCLE PRESENT" << endl;
        cout << "not a valid topological sort" << endl;
    }
    
    return 0;
}