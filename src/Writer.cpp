#include <iostream>
#include <fstream>

#include "../headers/Writer.h"

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

void Writer::writeNormal(std::ofstream& dataFile, Point3D point)
{
    dataFile << "  facet Normal " << point.x() << " " << point.y() << " " << point.z() << std::endl;
}

void Writer :: writeObjToStl(std::string filePath ,Triangulation& triangulation)
{
    std::ofstream dataFile;
    dataFile.open(filePath);


    dataFile << "Solid " << triangulation.getName() << std::endl;

    for (Triangle t : triangulation.triangles())
    {
        std::cout<<t.getNormal()<<" "<<t.getIdxP1()<<" "<<t.getIdxP2()<<" "<<t.getIdxP3()<<std::endl;
        writeNormal(dataFile, triangulation.normals()[t.getNormal()]);
        dataFile << "outer loop " << std::endl;
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP1()]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP2()]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP3()]);
        dataFile << "endloop" << std::endl;
        dataFile << "endfacet" << std::endl;
    }

    dataFile << "Endsolid " << triangulation.getName() << std::endl;

    dataFile.close();
}
