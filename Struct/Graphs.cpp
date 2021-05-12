#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Graph{
    int amount_vert = 0;
    std::vector <std::vector<int>> neighbour;
};

void add_edge(Graph* G, int vert_1, int vert_2, bool orient = false){
    //add the edge between vert_1 and vert_2;
    //if orient = true, the edge will be oriented from vert_1 to vert_2;
    G->neighbour[vert_1].push_back(vert_2);
    if ((!orient) && (vert_1 != vert_2)){
        G->neighbour[vert_2].push_back(vert_1);
    }
}

void add_vert(Graph* G, std::vector <int> edges, int amount_edges){
    G->amount_vert++;
    G->neighbour.push_back(edges);
    for (int i : edges){
        add_edge(G, i, G->amount_vert - 1, true);
    }
}

void delete_vert(Graph* G, int vert2del){
    G->neighbour.erase(G->neighbour.begin() + vert2del);
    G->amount_vert--;
    for (int i = 0; i < G->amount_vert; i++){
        G->neighbour[i].erase(std::remove(G->neighbour[i].begin(), G->neighbour[i].end(), vert2del), G->neighbour[i].end());
    }
}

void print_vector(std::vector <int> vect2print){
    for (int i: vect2print){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void print_list_neighbours(Graph* G){
    for (int i = 0; i < G->amount_vert; i++){
        print_vector(G->neighbour[i]);
    }
}

void DFS(Graph* G, int vert, int* visited = nullptr, bool are_you_start = true, bool do_you_need_print = true, int* if_circle = nullptr){
    //the algorithm DFS;
    //you may not to use three last options;
    //if_circle is an array with one elem;
    if (!visited){
        visited = new int[G->amount_vert];
        for (int i = 0; i < G->amount_vert; i++){
            visited[i] = 0;
        }
    }
    if (visited[vert] == 0){
        //We haven't been there;
        visited[vert] = 1;
        if (do_you_need_print){
            std::cout << vert << " ";
        }
        for (int i = 0; i < G->neighbour[vert].size(); i++){
            DFS(G, G->neighbour[vert][i], visited, false, do_you_need_print, if_circle);
        }
    } else if (if_circle != nullptr){
        //we find a circle;
        if_circle[0] = 1;
    }
    if (are_you_start){
        delete [] visited;
        std::cout << std::endl;
    }
}

void BFS(Graph* G, int vert, int* visited = nullptr, bool do_you_need_visit = false){
    //if do_you_need_visit = true in the end visited won't be deleted;
    if (!visited){
        visited = new int[G->amount_vert];
        for (int i = 0; i < G->amount_vert; i++){
            visited[i] = 0;
        }
    }
    std::queue <int> que_vert;
    visited[vert] = 1;
    que_vert.push(vert);
    while (!que_vert.empty()){
        int vert = que_vert.front();
        que_vert.pop();
        std::cout << vert << " ";
        for (int i = 0; i < G->neighbour[vert].size(); i++){
            if (visited[G->neighbour[vert][i]] == 0){
                visited[G->neighbour[vert][i]] = 1;
                que_vert.push(G->neighbour[vert][i]);
            }
        }
    }
    std::cout << std::endl;
    if (!do_you_need_visit){
        delete [] visited;
    }
}

void find_connected(Graph* G, int vert){
    //print all connected verts with vert;
    int* visited = new int (G->amount_vert);
    for (int i = 0; i < G->amount_vert; i++){
        visited[i] = 0;
    }
    bool flag = true;
    while (flag){
        DFS(G, vert, visited, false, false);
        std::cout << std::endl;
        for (int i = 0; i < G->amount_vert; i++){
            flag = false;
            if (visited[i] = 0){
                vert = i;
                flag = true;
            }
        }
    }
    delete [] visited;
}

bool if_circle_exists(Graph* G, int vert){
    //true if the circle in the same connected component exists;
    int* res = new int(1);
    res[0] = false;
    DFS(G, vert, res, true, false);
    return res;
    delete [] res;
}
int main(){
    Graph* G = new Graph;
    G->amount_vert = 4;
    G->neighbour = std::vector <std::vector <int>> (4);
    for (int i = 0; i < 5; i++){
        int a, b;
        std::cin >> a >> b;
        add_edge(G, a, b);
    }
    print_list_neighbours(G);
    std::vector <int> edge {1, 2, 3};
    add_vert(G, edge, 4);
    std::cout << std::endl;
    BFS(G, 4);
    std::cout << std::endl;
    find_connected(G, 4);
    std::cout << std::endl;
    if (if_circle_exists(G, 4)){
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    delete_vert(G, 1);
    print_list_neighbours(G);
    G->neighbour.clear();
    delete G;
    return 0;
}
