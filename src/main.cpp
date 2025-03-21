#include "../include/dag.h"

int main(int argc, const char* argv[]) {
    unsigned int seed = 5;
    srand(seed);
    /*    
    printf("Hello, world!\n");
    Node n1(2);
    int random_id = (rand() % 1000 + 1);
    Node n2(random_id);
    */

    DAG dag(10, 2);
    dag.PrintDAG();
}