#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stdexcept>
#include <vector>

class Node {
    private:
        std::set<Node*> edges;

    public:
        int id;
        bool is_entrance;

        Node(int id);
        Node(Node& src);
        ~Node();

        // Getters
        std::set<Node*>* getEdges();
};

class DAG {
    private:
        std::vector<Node*> nodes;
        std::vector<Node*> entrances;

    public:
        DAG(int levels, int num_entrances);
        DAG(DAG& src);
        ~DAG();

        // Prints the DAG as a matrix
        void PrintDAG();
};