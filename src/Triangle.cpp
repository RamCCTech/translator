#include"../headers/Triangle.h"

Triangle::Triangle(int inIdxP1, int inIdxP2, int inIdxP3)
:mIdxP1(inIdxP1),
mIdxP2(inIdxP2),
mIdxP3(inIdxP3)
{

}


Triangle::~Triangle()
{

}
    
void Triangle::setNormal(int inNormal)
{
    mNormal = inNormal;
}
