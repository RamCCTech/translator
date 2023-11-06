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
        void writeNormal(std::ofstream& dataFile, Point3D point);
        void writeNormals(std::ofstream& dataFile);
        void writeVertices(std::ofstream& dataFile);
        void writeFacets(std::ofstream& dataFile);
};