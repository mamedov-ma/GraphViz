#ifndef _INCLUDE_PLACEMENT_HH_
#define _INCLUDE_PLACEMENT_HH_

#include <vector>
#include "geometry.hh"

namespace graph_viz
{

class FruchtermanReingold 
{
    public:
        FruchtermanReingold(const std::vector<std::vector<int>> &Graph, double Width,
                            double Height, int NumIter = 10000, double InitTemp = 5e3,
                            double MinTemp = 1.0, double Delta = 0.95)
            : Graph_(Graph), Width_(Width), Height_(Height), NumIter_(NumIter),
              InitTemp_(InitTemp), MinTemp_(MinTemp), Delta_(Delta) {}

        double getWidth() const;
        double getHeight() const;
        double getArea() const;
        int getNumNode() const;

        std::vector<Point> genPosition();

    private:
        const std::vector<std::vector<int>> Graph_;
        const double Width_;
        const double Height_;
        const int NumIter_;
        const double InitTemp_;
        const double MinTemp_;
        const double Delta_;

        double calAttractiveForce(const double x, const double k) const;
        double calRepulsiveForce(const double x, const double k) const;
        void genInitPos(std::vector<Point> &Positions) const;
        void scalePos(std::vector<Point> &Positions) const;
};

} // namespace graph_viz

#endif