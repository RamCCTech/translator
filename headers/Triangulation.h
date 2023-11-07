#pragma once

#include <string>

#include"TypeDef.h"
 
class Triangulation
{
    public:
        Triangulation();
        ~Triangulation();
 
        TriangleList triangles();
        PointList points();
        PointList normals();
       
        void addTriangle(Point3D p1, Point3D p2, Point3D p3, Point3D normal);

        std::string getName();
        void setName(std::string inName);
    
    private:
        int getVIndex(Point3D point);
        int getNIndex(Point3D point);

    private:
        TriangleList mTriangles;
        PointList mPoints;
        PointList mNormals;
        std::string mObjName;
};