#include"../headers/Triangulation.h"
#include"../headers/Reader.h"

int main()
{
    Triangulation triangulation;

    Reader read;
    read.readSTL("../resources/cubeModel.stl", triangulation);

    return 0;
}