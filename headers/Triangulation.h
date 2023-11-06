#pragma once
#include"TypeDef.h"

class Triangulation
{
    public:
        Triangulation();
        ~Triangulation();

        TriangleList triangles();
        PointList points();
        PointList normals();

        void addPoint(Point3D inPoint);
        void addNormal(Point3D inNormal);
        void addTriangle(Triangle inPoint);
        

    private:
        TriangleList mTriangles;
        PointList mPoints;
        PointList mNormals;
};