/// BFS DFS PRIMS KRUSKAL

#include <iostream>
using namespace std;

const int MAX = 7;
const int INF = 99999; //way to represent unreachable or unbounded values

struct Edge {
    int src, dest, weight;
};

void bfs(int start, int graph[7][7], int MAX) {
    int node;
    int visited[MAX] = {0,0,0,0,0,0,0};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;
 
    cout << "TRAVERSAL ACC. TO BFS: "<<endl;

    while (front < rear) {
         node = queue[front++];
        cout << char(node + 'a') << " ";//node index to characters (assuming that they are from a to g)

        for (int i = 0; i < MAX; i++) {
            if (graph[node][i] != 0 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

void dfs(int node, int graph[7][7], int visited[7], int MAX) {
    visited[node] = true;
    cout << char(node + 'a') << " ";

    for (int i = 0; i < MAX; i++) {
        if (graph[node][i] != 0 && !visited[i]) {
            dfs(i, graph, visited, MAX);
        }
    }
}


void prim(int graph[MAX][MAX]) {
    int parent[MAX]; // store constructed MST
    int key[MAX];    // Key values used to pick minimum weight edge
    bool inMST[MAX];// vertices included in MST
        int totalWeight = 0;  

    // Initialize all keys as infinite and MST as false
    for (int i = 0; i < MAX; i++) {
        key[i] = INF;
        inMST[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    for (int count = 0; count < MAX - 1; count++) {
        // Find the minimum key vertex
        int minKey = INF, minIndex;
        for (int v = 0; v < MAX; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST
        inMST[minIndex] = true;

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < MAX; v++) {
            if (graph[minIndex][v] && !inMST[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    cout << "Edge  \tWeight\n";
    for (int i = 1; i < MAX; i++) {
        cout << char(parent[i] + 'a') << " - " << char(i + 'a') << "\t" << graph[i][parent[i]] << endl;
    totalWeight += graph[i][parent[i]]; 
    }
    cout<<"total weight: "<<totalWeight<<endl;

}





// Find function with path compression
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}


void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

void sortEdges(Edge edges[], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }
}

void kruskal(Edge edges[], int edgeCount) {
    int parent[MAX];
    int totalWeight = 0;
    for (int i = 0; i < MAX; i++) {
        parent[i] = -1;
    }

    // Sort edges based on weight
    sortEdges(edges, edgeCount);

    cout <<"\nKRUSKAL'S ALGORITHM : \nEdge \tWeight\n";
    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // If including this edge does not cause a cycle
        if (x != y) {
            cout << char(edges[i].src + 'a') << " - " << char(edges[i].dest + 'a') << "\t" << edges[i].weight << endl;
            totalWeight += edges[i].weight;
            unionSets(parent, x, y);
        }
    }
    cout<<"total weight: "<<totalWeight;
    }



int main() {
    int graph[MAX][MAX] = { 
    {0, 1, 4, 0, 0, 0, 0},  // a
    {1, 0, 2, 3, 10, 0, 0}, // b
    {4, 2, 0, 6, 0, 0, 3},  // c
    {0, 3, 6, 0, 5, 0, 1},  // d
    {0, 10, 0, 5, 0, 7, 2}, // e
    {0, 0, 0, 0, 7, 0, 5},  // f
    {0, 0, 3, 1, 2, 5, 0} 
    };

    bfs(0, graph, MAX);

    int visited[7] = {0,0,0,0,0,0,0};

    cout<<"TRAVERSAL ACC. TO DFS:"<<endl;
    dfs(0, graph, visited, MAX);
    cout << endl;


    cout<<"PRIM'S ALGORITHM:"<<endl;
     prim(graph);


//  edges for Kruskal's algorithm
    Edge edges[] = {
    {0, 1, 1},  // a-b
    {0, 2, 4},  // a-c
    {1, 2, 2},  // b-c
    {1, 4, 10}, // b-e
    {1, 3, 3},  // b-d
    {2, 6, 3},  // c-g
    {2, 3, 6},  // c-d
    {3, 6, 1},  // d-g
    {3, 4, 5},  // d-e
    {4, 5, 7},  // e-f
     {4, 6, 2}, // e-g
     {5, 6, 5} // f-g
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, edgeCount);
    
    return 0;
}