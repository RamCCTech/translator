for(int i = 0; i < triangles.size(); i++)
{
    x1 = triangles.at(i).x();
    y1 = triangles.at(i).y();
    z1 = triangles.at(i).z();
    if((x1 != triangles.at(i).x()) && ((y1 != triangles.at(i).y())) && ((z1 != triangles.at(i).z())))
    {
        triangles2.push_back(triangles);
    }

    if(triangles.at(i) != triangles.at(i+1))
    {
        Triangles triangle = triangles.at(i);
        triangles2.push_back(triangles);
    }
}

  #include"../headers/UniquePoints.h"
#include<vector>
using namespace std;



vector<Point3D> UniquePoints :: Find_Unique_Points(vector<Triangle> triangles)
{
    double x, y, z;
    doublt x1, y1, z1;

    Point3D p;
    p.setx() = x = triangles.at(0).x();
    p.sety() = y = triangles.at(0).y();
    p.setz() = z = triangles.at(0).z();

    vector<Point3D> point;
    point.push_back(p);
    
    bool bFlag = false;

    for(int i = 0; i < triangles.size(); i++)
    {
      x1 = triangles.at(i).x();
      y1 = triangles.at(i).y();
      z1 = triangles.at(i).z(); 

      for(int j = 0; j < points.size(); j++)
      {
        if((point.at(i).x() == triangles.at(i).x()) && (point.at(i).y() == triangles.at(i).y()) && (point.at(i).z() == triangles.at(i).z()))
        {
          return true;
        }
      }
    }   
}    

      