#include"../headers/Triangulation.h"
 
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

void Triangulation::addTriangle(Point3D p1, Point3D p2, Point3D p3, Point3D normal)
{
    int idx1 = getIndex(p1);
    int idx2 = getIndex(p2);
    int idx3 = getIndex(p3);
    int idxn = getIndex(normal);
    Triangle t1 = Triangle(idx1, idx2, idx3);
    t1.setNormal(idxn);
    mTriangles.push_back(Triangle(idx1, idx2, idx3));
    
}

int Triangulation::getIndex(Point3D point)
{
    for(int i=0 ; i<mPoints.size(); i++)
    {
        if(mPoints[i] == point)
        {
            return i;
        }
    }

    mPoints.push_back(point);

    return mPoints.size()-1;
}
