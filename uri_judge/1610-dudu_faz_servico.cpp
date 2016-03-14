// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;
 
class Graph
{
    int V;             // No. of vertices
    list<int> *adj;    // An array of adjacency lists
 
    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing 
    // time
    void fillOrder(int v, int visited[], stack<int> &Stack);
 
    // A recursive function to print DFS starting from v
    void DFSUtil(int v, int visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
 
    // The main function that finds and prints strongly connected
    // components
    void printSCCs();
 
    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, int visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::fillOrder(int v, int visited[], stack<int> &Stack)
{    
    // Mark the current node as visited and print it
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);
 
    // All vertices reachable from v are processed by now, push v 
    Stack.push(v);
}
 
// The main function that finds and prints all strongly connected 
// components
void Graph::printSCCs()
{
    stack<int> Stack;
    
    // Mark all the vertices as not visited (For first DFS)
    int visited[V];
    memset(visited,0, V*sizeof(int));
 
    // Fill vertices in stack according to their finishing times
    for(int i = 0; i < V; i++)
        if(!visited[i])
            fillOrder(i, visited, Stack);
 
    // Create a reversed graph
    Graph gr = getTranspose();
 
    // Mark all the vertices as not visited (For second DFS)
    memset(visited, 0, V*sizeof(int));
 
    // Now process all vertices in order defined by Stack
    int qt = 0;
    while (!Stack.empty())
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();
 
        // Print Strongly connected component of the popped vertex
        if (!visited[v])
        {
            qt++;
            gr.DFSUtil(v, visited);
        }
    }
    
    if(qt < V){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }
    
}
 
// Driver program to test above functions
int main()
{
    int T,a,b,V,E;
    scanf("%d", &T);
    for (unsigned int i = 0; i < T; i += 1)
    {
    
        // reading the edges of the graph
        scanf("%d %d", &V, &E);
        Graph g(V);
        for (unsigned int j = 0; j < E; j += 1)
        {
            scanf("%d %d", &a, &b);
            a--; b--;
            g.addEdge(a, b);
        }
        
        g.printSCCs();
    }
   
    return 0;
}
