#include "../include/dag.h"

int main(int argc, const char* argv[]) {
    unsigned int seed = 5;
    srand(seed);

    DAG dag(10, 2);
    dag.PrintDAG();
}