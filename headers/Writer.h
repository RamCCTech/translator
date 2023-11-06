#pragma once
#include <string> 
#include "Triangulation.h"
 
class Writer
{
    public :
        Writer();
        ~Writer();
 
        void writeObjToStl(std::string filePath ,Triangulation &triangulatio);
        
    private:
        void writeVertexToSTL(std::ofstream& dataFile, Point3D vertex );
 
};