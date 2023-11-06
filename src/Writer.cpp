#include <iostream>
#include <fstream>
#include <filesystem>

#include "headers/Writer.h"

Writer::Writer(/* args */)
{
}

Writer::~Writer()
{
}

void Writer::writeVertexToSTL(std::ofstream& dataFile, Point3D vertex)
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

void Writer :: writeObjToStl(std::string filePath ,Triangulation& triangulation)
{
    std::ofstream dataFile;
    dataFile.open(filePath);

    std::filesystem::path p(filePath);

    dataFile << "Solid " << p.stem() << std::endl;

    for (Triangle t : triangulation.triangles())
    {
        writeNormal(dataFile, triangulation.normals()[t.getNormal() - 1]);
        dataFile << "outer loop " << std::endl;
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP1() - 1]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP2() - 1]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP3() - 1]);
        dataFile << "endloop" << std::endl;
        dataFile << "endfacet" << std::endl;
    }

    dataFile << "Endsolid " << p.stem() << std::endl;

    dataFile.close();
}
