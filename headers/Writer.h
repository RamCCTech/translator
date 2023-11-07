#pragma once

#include <string> 

#include "Triangulation.h"
 
class Writer
{
    public :
        Writer();
        Writer(Triangulation triangulation);
        ~Writer();
        void writeStlToObj(std::string filePath);
        void writeObjToStl(std::string filePath ,Triangulation &triangulatio);
        
    private:
        Triangulation mTriangulation;
        void writeVertexToSTL(std::ofstream& dataFile, Point3D vertex );
        void writeNormalToSTL(std::ofstream& dataFile, Point3D point);
        void writeNormalToOBJ(std::ofstream& dataFile);
        void writeVerticesToOBJ(std::ofstream& dataFile);
        void writeFacetToOBJ(std::ofstream& dataFile);
};