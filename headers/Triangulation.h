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
        

    private:
        TriangleList mTriangles;
        PointList mPoints;
        PointList mNormals;
};