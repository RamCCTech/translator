#pragma once
#include"Triangulation.h"

class Point3D
{
public:
    Point3D(double inX, double inY, double inZ);
    ~Point3D();

    double x();
    double y();
    double z();

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void operator==(Point3D p1);

    bool isUnique(std::vector<Triangulation> triangles);

private:
    double mX;
    double mY;
    double mZ;
};