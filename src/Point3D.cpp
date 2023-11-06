#include "../headers/Point3D.h"

Point3D::Point3D(double inX, double inY, double inZ)
    : mX(0),
      mY(0),
      mZ(0)
{
    mX = inX;
    mY = inY;
    mZ = inZ;
}

Point3D::~Point3D()
{
}

double Point3D::x()
{
    return mX;
}

double Point3D::y() 
{
    return mY;
}

double Point3D::z()
{
    return mZ;
}

void Point3D::setX(double x)
{
    mX = x;
}

void Point3D::setY(double y)
{
    mY = y;
}

void Point3D::setZ(double z)
{
    mZ = z;
}

bool Point3D::operator==(const Point3D& p1)
{
    return mX == p1.mX && mY == p1.mY && mZ == p1.mZ;
}