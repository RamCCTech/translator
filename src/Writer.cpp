#include <iostream>
#include <fstream>

#include "../headers/Writer.h"
#include "../headers/Writer.h"

Writer::Writer(/* args */)
{
}

Writer::Writer(Triangulation triangulation)
{   
 mTriangulation = triangulation;   
}


Writer::~Writer()
{
}

void Writer::writeVertexToSTL(std::ofstream& dataFile, Point3D vertex)
{
    dataFile <<"      vertex "<< vertex.x() << " " <<vertex.y()<< " "<< vertex.z() << std::endl;
}

void Writer::writeNormal(std::ofstream& dataFile, Point3D point)
{
    dataFile << "  facet normal " << point.x() << " " << point.y() << " " << point.z() << std::endl;
}

void Writer :: writeObjToStl(std::string filePath ,Triangulation& triangulation)
{
    std::ofstream dataFile;
    dataFile.open(filePath);
    std::cout<<filePath<<std::endl;

    dataFile << "solid " << triangulation.getName() << std::endl;

    for (Triangle t : triangulation.triangles())
    {
        std::cout<<t.getNormal()<<" "<<t.getIdxP1()<<" "<<t.getIdxP2()<<" "<<t.getIdxP3()<<std::endl;
        writeNormal(dataFile, triangulation.normals()[t.getNormal()]);
        dataFile << "    outer loop " << std::endl;
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP1()]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP2()]);
        writeVertexToSTL(dataFile, triangulation.points()[t.getIdxP3()]);
        dataFile << "    endloop" << std::endl;
        dataFile << "  endfacet" << std::endl;
    }

    dataFile << "endsolid " << triangulation.getName() << std::endl;

    dataFile.close();
}
void Writer::writeStlToObj(std::string filePath)
{
    std::ofstream dataFile;
    dataFile.open(filePath);

    writeVertices(dataFile);
    writeNormals(dataFile);
    writeFacets(dataFile);

    dataFile.close();
}

void Writer::writeNormals(std::ofstream& dataFile)
{
    for(Point3D normal: mTriangulation.normals())
    {
        dataFile << "vn" << " " << normal.x() << " " << normal.y() << " " << normal.z() << std::endl;
    }
}

void Writer::writeFacets(std::ofstream& dataFile)
{
    TriangleList triangles = mTriangulation.triangles();
 
    for(int i=0;i<triangles.size();i++)
    {
        Triangle triangle = triangles[i];
        dataFile <<"f "<<triangle.getIdxP1()+1<<"//"<<triangle.getNormal()+1<<" "
        <<triangle.getIdxP2()+1<<"//"<<triangle.getNormal()+1<<" "
        <<triangle.getIdxP3()+1<<"//"<<triangle.getNormal()+1<<std::endl;
    }
}

void Writer::writeVertices(std::ofstream& dataFile)
{
    for(Point3D vertex : mTriangulation.points())
    {
        dataFile << "v " << vertex.x() << " " << vertex.y() << " " << vertex.z() <<std::endl;
    }   
}

