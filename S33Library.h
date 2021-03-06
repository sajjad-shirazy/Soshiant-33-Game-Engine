#ifndef _S33Library_H
#define _S33Library_H

#include "ExternalLibs.h"

using namespace Pei;
using namespace Pei::Graphic;
using namespace Pei::Utility;

namespace Soshiant33
{
	struct S33ScenePattern;
	struct S33EntityPattern;
	struct S33SpritePattern;
	struct S33ComplexEntityPattern;
	/// کتابخانه معادل ریسورس منیجر برای الگو هاست
	class S33Library
	{
		friend struct S33EntityPattern;
	private:
		static unsigned char itemsGroupID;
	public:
		static std::string basePath;
		static S33ScenePattern* GetScenePattern(const char* name);
		static S33SpritePattern* GetSpritePattern(const char* name);
		static S33ComplexEntityPattern* GetComplexEntityPattern(const char* name);
		static void RemoveItems(unsigned char itemsGroupID);
		static void SetNewItemsGroupID(unsigned char value);
	};
}
#endif