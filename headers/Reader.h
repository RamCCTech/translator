#pragma once
#include <vector>
#include <string>
#include "Triangle.h"
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
    void readSTL(std::string filePath, Triangulation &triangulation);

private:
};
