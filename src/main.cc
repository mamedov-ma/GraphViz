#include <iostream>
#include <vector>
#include <string>
#include <ctime>

#include "geometry.hh"
#include "placement.hh"
#include "matplotlibcpp.hh"

namespace plt = matplotlibcpp;
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

    std::vector<int> x, y;

    for (int i = 0; i < n; ++i)
    {
        x.push_back(coordinate[i][0]);
        y.push_back(coordinate[i][1]);
    }

    std::vector<std::vector<std::vector<int>>> segments;

    for (int i = 0; i < m; ++i)
    {
        segments.push_back({{x[graph[i][0]], x[graph[i][1]]}, {y[graph[i][0]], y[graph[i][1]]}});  
    }
    
    for (std::vector<std::vector<int>> segment: segments)
    {
        plt::plot(segment[0], segment[1], "k-o");
    }
    
    for (int i = 0; i < n; ++i)
    {
        plt::annotate("ITEM " + std::to_string(i), x[i], y[i]);
    }

    plt::savefig("../images/" + std::to_string(time(0)) + ".png");
    
    return 0;
}
