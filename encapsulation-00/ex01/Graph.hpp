#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <list>
#include <iostream>

class Graph{

    private:
        class Vector2
        {
            // private:
            //     float   X;
            //     float   Y;
            public:
                float   X;
                float   Y;
                Vector2(int X, int Y): X(X), Y(Y){};
        };
        std::list<Vector2 *> vector2list;
        Vector2 size;
        bool **graph;

    public:
        Graph(int X, int Y): size(X, Y){
            if (!X || !Y)
            {
                return;
                //throw
            }
            graph = new bool*[Y + 1];
            for (int i = 0; i <= Y; i++)
                graph[i] = new bool[X + 1];
            for(int j = 0; j <= Y; j++)
            {
                for(int i = 0; i <= X; i++)
                    graph[j][i] = false;
            }
        };

        void addVector(float X, float Y){
            if (X > size.X || Y > size.Y)
                return;
            vector2list.push_back(new Vector2(X, Y));
            graph[static_cast<int>(Y)][static_cast<int>(X)] = true; 
        };
        void drawGraph()
        {
            for (int j = 0; j <= size.Y; j++)
            {
                std::cout << " " << size.Y - j << " ";
                for(int i = 0; i <= size.X; i++)
                {
                    if (graph[static_cast<int>(size.Y - j)][i])
                        std::cout << " X ";
                    else
                        std::cout << " . ";
                }
                std::cout << "\n";
            }
            std::cout << "   ";
            for (int i = 0; i <= size.X; i++)
                std::cout << " " << i << " ";
            std::cout << std::endl;
        }

        ~Graph()
        {
            vector2list.clear();
        }

};
 
#endif