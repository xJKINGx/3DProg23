#ifndef TRIANGLESURFACE_CLASS_H
#define TRIANGLESURFACE_CLASS_H

#include "VisualObject.h"

class TriangleSurface : public VisualObject
{
public:
	TriangleSurface();
	TriangleSurface(std::string filename, bool ReadFileCheck);

	void init(/*GLint matrixUniform*/) override;
	void draw() override;
};

#endif

