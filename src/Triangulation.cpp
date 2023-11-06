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

void Triangulation::addPoint(Point3D inPoint)
{
    mPoints.push_back(inPoint);
}
void Triangulation::addNormal(Point3D inNormal)
{
    mNormals.push_back(inNormal);
}
void Triangulation::addTriangle(Triangle inTriangle)
{
    mTriangles.push_back(inTriangle);
}