#include "../headers/Reader.h"
#include "../headers/Triangle.h"
#include <sstream>
#include <fstream>
#include <iostream>

Reader::Reader()
{
}

Reader::~Reader()
{
}

void Reader::readOBJ(std::string filePath, Triangulation &triangulation)
{
	std::ifstream file;
	file.open(filePath);
	if (!file.is_open())
	{
		std::cout << "File not exist" << std::endl;
		return;
	}

	std::vector<Point3D> points;
	std::vector<Point3D> normals;

	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("v ") != std::string::npos)
		{
			readVertex(line, points);
		}

		else if (line.find("vn") != std::string::npos)
		{
			readNormal(line, normals);
		}

		else if (line.find("f") != std::string::npos)
		{
			readFacet(line, points, normals, triangulation);
		}
	}
}

void Reader::readFacet(std::string line, PointList &points, PointList &normals, Triangulation &triangulation)
{
	std::istringstream facetLine(line);
	std::string token;

	std::string stringP1;
	std::string stringP2;
	std::string stringP3;

	facetLine >> token >> stringP1 >> stringP2 >> stringP3;

	int indexP1 = stoi(stringP1.substr(0, stringP1.find("/")));
	int indexP2 = stoi(stringP2.substr(0, stringP2.find("/")));
	int indexP3 = stoi(stringP3.substr(0, stringP3.find("/")));

	std::string stringNormal = "";
	for (int i = stringP1.size() - 1; i >= 0; i--)
	{
		if (stringP1.at(i) == '/')
			break;

		stringNormal = stringP1.at(i) + stringNormal;
	}
	int indexNormal = stoi(stringNormal);

	triangulation.addTriangle(points[indexP1], points[indexP2], points[indexP3], normals[indexNormal]);
}
