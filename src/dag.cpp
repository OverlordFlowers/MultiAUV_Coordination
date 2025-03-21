#include "../include/dag.h"

Node::Node(int id) {
    this->id = id;
    printf("Node created with id: %d\n", id);
}

Node::Node(Node& src) {
    this->id = src.id;
}

Node::~Node() {
    delete this;
}

std::set<Node*>* Node::getEdges() {
    return &this->edges;
}

DAG::DAG(int num_nodes, int num_entrances) {
    if (num_nodes < 1) {
        throw std::runtime_error("Cannot have 0 nodes!");
    }

    if (num_entrances > num_nodes) {
        throw std::runtime_error("Cannot have more entrances than nodes!");
    }

    std::set<int> node_set;

    float edge_weights[] = {0.9, 0.05, 0.04, 0.01};
    int num_weights = 4;

    // Generate set of nodes
    for (int i = 0; i < num_nodes; i++) {
        nodes.push_back(new Node(i));
        node_set.insert(i);
    }

    std::set<int> entrance_candidates = node_set;
    for (int i = 0; i < num_entrances; i++) {
        int j = rand() % entrance_candidates.size();
        auto it = std::begin(entrance_candidates);
        std::advance(it, j);
        nodes[*it]->is_entrance = true;
        entrance_candidates.erase(*it);
        this->entrances.push_back(nodes[*it]);
        printf("Node %d designated as entrance.\n", *it);
    }

    int num_edges = 0;
    float gen_rand = 0.0;
    // Interate through nodes, generate edges and connect to random nodes based on some weights summing to one (1 edge being the most likely)
    for (int i = 0; i < nodes.size(); i++) {
        std::set<int> valid_nodes = node_set;
        // Don't consider current node
        valid_nodes.erase(i);
        
        // How many edges should this get?
        gen_rand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        for (int j = 0; j < num_weights; j++) {
            if (gen_rand < edge_weights[j]) {
                num_edges = j + 1;
            }
        }

        if (num_edges != nodes[i]->getEdges()->size()) {
            for (int j = 0; j < num_edges; j++) {
                int node_sel = rand() % valid_nodes.size();
                auto it = std::begin(valid_nodes);
                std::advance(it, node_sel);
                nodes[i]->getEdges()->insert(nodes[*it]);
                nodes[*it]->getEdges()->insert(nodes[i]);
                valid_nodes.erase(*it);
                printf("Node %d connected with Node %d\n", i, *it);
            }
        }

    }

    printf("DAG created with %d entrances.\n", num_entrances);
}

DAG::DAG(DAG& src) {
    // TODO:
    printf("Expecting something to happen?\n");
}

DAG::~DAG() {
    // TODO: Traverse & delete all nodes
}

void DAG::PrintDAG() {
    int side_length = this->nodes.size();

    // We can just generate a static array here.
    int** conn_mat = new int*[side_length];
    for (int i = 0; i < side_length; i++) {
        conn_mat[i] = new int[side_length];
        printf("\t%d ", i);
    }
    printf("\n");

    for (int i = 0; i < side_length; i++) {
        for (int j = 0; j < side_length; j++) {
            conn_mat[i][j] = 0;
        }
    }

    for (int i = 0; i < this->nodes.size(); i++) {
        std::set<Node*>* curr_edges = this->nodes[i]->getEdges();
        printf("%d\t", i);

        for (auto it = curr_edges->begin(); it != curr_edges->end(); it++) {
            conn_mat[i][(*it)->id] = 1;
        }

        for (int j = 0; j < side_length; j++) {
            if (i == j) {
                printf("x\t");
            } else {
                printf("%d\t", conn_mat[i][j]);
            }
        }
        printf("\n");
    }
}