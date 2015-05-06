#ifndef CCGAMMA_FILTER
#define CCGAMMA_FILTER

#include "CCFilter.h"

NS_CC_EXT_BEGIN

//================== GammaFilter

class GammaFilter : public SingleFloatParamFilter
{

public:
	static GammaFilter* create();
	static GammaFilter* create(float param);

	GammaFilter();

	virtual void setParameter(float param);
protected:
	virtual GLProgram* loadShader();
	virtual void setAttributes(GLProgram* glp);
	virtual void setUniforms(GLProgram* glp);

};

NS_CC_EXT_END

#endif //CCGAMMA_FILTER
