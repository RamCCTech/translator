#pragma once
#include<string>
#include"Triangulation.h"

class Reader
{
    public:
        Reader();
        ~Reader();

        void readSTL(std::string filePath, Triangulation& triangulation);
    
    private:
        
};