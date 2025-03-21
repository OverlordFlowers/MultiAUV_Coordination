// This is going to be a very simplified AUV model in order to represent
// "exploring" the caves

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stdexcept>
#include <vector>
#include "../include/dag.h"

class AUV {
    private:
        bool is_leader;
        int hierarchy;
        int id;

        std::set<Node*> explored_nodes;
        std::set<Node*> next_nodes;
        // Nodes designated for communication purposes
        std::set<Node*> comm_nodes;

        std::set<AUV*> group;

    public:
        int test;

        // Define behaviors here
        void mergeGroups();
        void getNextNode();
        void chooseNode();
        
};