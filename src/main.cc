#include <iostream>
#include <vector>
#include "geometry.hh"
#include "placement.hh"

using namespace graph_viz;

int main(int argc, char **argv)
{
    
    int n;
    int m = 0;
    std::vector<std::vector<int>> graph;
    std::cin >> n;

    int connectivity_matrix[n][n];
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            std::cin >> connectivity_matrix[i][j];
            
            if(connectivity_matrix[i][j] == 1 && j >= i)
            {
                ++m;
                graph.push_back({i,j});
            }
        }
    }

    auto coordinate = Visualization(n, m, graph);

    for (std::vector<int> i: coordinate)
    {
        for (int j: i)
        {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
