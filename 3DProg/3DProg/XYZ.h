#pragma once

#include "VisualObject.h"

class XYZ : public VisualObject
{
public:

	XYZ();
	~XYZ();
	void init(/*GLint matrixUniform*/) /*override*/;
	void draw() override;
};