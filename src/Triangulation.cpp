#include "../headers/Triangulation.h"

Triangulation::Triangulation()
{
}

Triangulation::~Triangulation()
{
}

TriangleList Triangulation::triangles()
{
    return mTriangles;
}

PointList Triangulation::points()
{
    return mPoints;
}

PointList Triangulation::normals()
{
    return mNormals;
}

