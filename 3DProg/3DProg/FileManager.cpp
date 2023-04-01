#include "FileManager.h"

FileManager::FileManager()
{

}

// This wri|tes information into files
std::ostream& operator<< (std::ostream& os, const Vertex& v) {
    os << std::fixed;
    os << "(" << v.xyz[0] << ", " << v.xyz[1] << ", " << v.xyz[2] << ") ";
    os << "(" << v.rgb[0] << ", " << v.rgb[1] << ", " << v.rgb[2] << ") ";
    os << "(" << v.uv[0] << ", " << v.uv[1] << ") ";
    return os;
}

// This takes information from files
std::istream& operator>> (std::istream& is, Vertex& v) {
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> v.xyz[0] >> dum2 >> v.xyz[1] >> dum3 >> v.xyz[2] >> dum4;
    is >> dum >> v.rgb[0] >> dum2 >> v.rgb[1] >> dum3 >> v.rgb[2] >> dum4;
    is >> dum >> v.uv[0] >> dum2 >> v.uv[1] >> dum3;
    return is;
}

void FileManager::ReadFile(std::string filnavn, std::vector<Vertex>& mVertices)
{
    std::ifstream inn;
    inn.open(filnavn.c_str());

    if (inn.is_open())
    {
        int n;
        Vertex vertex;
        inn >> n;
        mVertices.reserve(n);
        for (int i = 0; i < n; i++)
        {
            inn >> vertex;
            mVertices.push_back(vertex);
        }
        inn.close();
    }
}

void FileManager::WriteFile(std::string filnavn, std::vector<Vertex>& mVertices)
{
    std::ofstream ut;
    ut.open(filnavn.c_str());

    if (ut.is_open())
    {
        auto n = mVertices.size();

        Vertex vertex;
        ut << n << std::endl;
        for (auto it = mVertices.begin(); it != mVertices.end(); it++)
        {
            ut << *it << std::endl;
        }

        ut.close();
    }
}