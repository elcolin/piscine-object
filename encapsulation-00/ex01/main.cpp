
#include "Graph.hpp"

int main()
{
    Graph test(4, 5);
    test.addVector(2, 1);
    test.addVector(0, 0);
    test.addVector(5, 4);
    test.addVector(4, 4);
    test.addVector(0, 5);
    test.drawGraph();

}