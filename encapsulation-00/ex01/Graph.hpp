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
        void addVector(Vector2 &newVector){
            vector2list.push_back

        };
        // Graph(float X, float Y): X(X), Y(Y){
        // };

};

#endif