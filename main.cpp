#include <iostream>

#include "./headers/Triangulation.h"
#include "./headers/Reader.h"
#include "./headers/Writer.h"

int main()
{
    Triangulation triangulation;

    std::cout << "           Welcome to Translator Application       " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "1. OBJ to STL file format" << std::endl;
    std::cout << "2. STL to OBJ file format" << std::endl;
    int option{};
    std::cin >> option;
    switch (option)
    {
        case 1:
        {
            Reader reader;
            reader.readOBJ("resources\\cube.obj", triangulation);

            Writer writer;
            writer.writeObjToStl("output\\outputSTL.stl", triangulation);
            break;
        }
        case 2:
        {
            Reader read;
            read.readSTL("resources/cubeModel.stl", triangulation);

            Writer writer(triangulation);
            writer.writeStlToObj("output\\outputObj.obj");
            break;
        }
    }
    return 0;
}