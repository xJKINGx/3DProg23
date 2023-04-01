#ifndef FILEMANAGER_CLASS_H
#define FILEMANAGER_CLASS_H

#include <fstream>
#include <glad/glad.h>
#include "Vertex.h"
#include <vector>

class FileManager {
public:

	FileManager();

	friend std::ostream& operator<< (std::ostream&, const Vertex&);

	friend std::istream& operator>> (std::istream&, Vertex&);

	void ReadFile(std::string filename, std::vector<Vertex>& mVertices);
	void WriteFile(std::string filename, std::vector<Vertex>& mVertices);
};


#endif