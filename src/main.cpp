
#include <cstdio>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("%s /path/to/script.lua\n", argv[0]);
        return 1;
    }
    const char *fileName = argv[1];

    /*
    env = new Environment;
    runCPP();
    runSol(fileName);
    */

    return 0;
}
