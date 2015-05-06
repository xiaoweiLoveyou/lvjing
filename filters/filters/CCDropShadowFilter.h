
#ifndef CCDROP_SHADOW_FILTER
#define CCDROP_SHADOW_FILTER

#include "CCFilter.h"

NS_CC_EXT_BEGIN

//================== DropShadowFilter

class DropShadowFilter : public Filter
{

public:
	static DropShadowFilter* create();
	static DropShadowFilter* create(float resolation);

	DropShadowFilter();

	void setParameter(float resolation);
	virtual void initSprite(FilteredSprite* sprite);
protected:
	virtual GLProgram* loadShader();
	virtual void setAttributes(GLProgram* glp);
	virtual void setUniforms(GLProgram* glp);
	float _textureWidth;
	float _textureHeight;
};


NS_CC_EXT_END

#endif //CCDROP_SHADOW_FILTER
