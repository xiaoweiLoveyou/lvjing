
#ifndef CCSEPIA_FILTER
#define CCSEPIA_FILTER

#include "CCFilter.h"

NS_CC_EXT_BEGIN

//================== SepiaFilter

class SepiaFilter : public Filter
{

public:
	static SepiaFilter* create();
	static SepiaFilter* create(float resolation);

	SepiaFilter();

	void setParameter();
protected:
	virtual GLProgram* loadShader();
	virtual void setAttributes(GLProgram* glp);
	virtual void setUniforms(GLProgram* glp);
};

NS_CC_EXT_END

#endif //CCSEPIA_FILTER
