#include <iostream>
#include"../headers/Triangulation.h"
#include"../headers/Reader.h"
#include"../headers/Writer.h"
using namespace std;
 
int main()
{
    Triangulation triangulation;
 
    // Reader read();
   // read.("../resources/cubeModel.stl", triangulation);
 
    cout << "           welcome to translator application       " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "1. OBJ to STL file format" << endl;
    cout << "2. STL to OBJ file format" << endl;
    int option{};
    cin>> option;
    switch (option)
    {
        case 1:
        {
            Reader reader;
            reader.readOBJ("translator\\resources\\cube.obj",triangulation);
 
            Writer writer;
            writer.writeObjToStl("output/outputSTL.stl",triangulation);
                   
        }
        case 2:
        {
 
        }
    }
    return 0;
}