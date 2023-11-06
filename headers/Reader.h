#pragma once
#include<string>
#include"Triangulation.h"

class Reader
{
    public:
        Reader();
        ~Reader();

        void read(std::string filePath, Triangulation& triangulation);
    
    private:
        
};