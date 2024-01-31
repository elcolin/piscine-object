#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>

typedef struct Vector2
{
    float   X;
    float   Y;
};


class Graph{

    private:
        std::list<Vector2 *> vector2list; 

    public:
        Graph();
        addVector(Vector2 newVector){

        };
        // Graph(float X, float Y): X(X), Y(Y){
        // };

};

#endif