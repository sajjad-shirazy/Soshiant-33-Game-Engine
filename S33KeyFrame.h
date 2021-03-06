#ifndef _S33KeyFrame_H
#define _S33KeyFrame_H

#include "ExternalLibs.h"
using namespace Pei::Utility;

namespace Soshiant33
{
	/// هر وضعیت اسپرایت شامل یک تام لاین است که در واقع آرایه ای از کی فریم هاست
	/// هر فریم مشخص می کند کدام ساب مش بایدنمایش داده شود و کدام تابع از اسکریپت باید اجرا شود
	struct S33KeyFrame : public SPSerializable
	{
		bool            hasAction;
		int				subsetIndex;
		std::string     actionFuncName;

		S33KeyFrame(int subsetIndex = -2);
	protected :
		virtual void serialize(SPArchive& archive);
	};
}
#endif