#include <iostream>
#include <fstream>

#include "headers/Writer.h"

Writer::Writer(/* args */)
{
}

Writer::~Writer()
{
}

void Writer::writeVertexToSTL(std::ofstream &dataFile, Point3D vertex)
{
    dataFile <<"      vertex"<< vertex.x() << " " <<vertex.y()<< " "<< vertex.z() << std::endl;
}

void Writer ::writeObjToStl(std::string filePath, Triangulation &triangulatio)
{
}

void Writer::writeNormal(std::ofstream& dataFile, Point3D point)
{
    dataFile << "  facet Normal " << point.x() << " " << point.y() << " " << point.z() << std::endl;
}
