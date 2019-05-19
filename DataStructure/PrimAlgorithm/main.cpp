#include "Predefine.h"

extern void initNetwork(Network &network);
extern void prim(Network G, int k);
int main()
{
    Network network;
    initNetwork(network);
    prim(network, 0);
    return 0;
}
