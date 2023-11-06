#pragma once
#include <string>
#include "Triangulation.h"
#include "TypeDef.h"

class Reader
{
public:
    Reader();
    ~Reader();

    void readOBJ(std::string filePath, Triangulation &triangulation);
    void readVertex(std::string line, PointList &points);
    void readNormal(std::string line, PointList &normals);
    void readFacet(std::string line, PointList &points, PointList &normals, Triangulation &triangulation);

private:
};
