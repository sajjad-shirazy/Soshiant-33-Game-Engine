#ifndef _S33SpriteState_H
#define _S33SpriteState_H

#include "S33KeyFrame.h"
using namespace Pei::Graphic;

namespace Soshiant33
{
	class S33Sprite;
	/// هر اسپراست از چند وضعیت تشکیل شده
	/// هر وضعیت اسپرایت از یک گرافیک - که فعلا فقط مش- و یک تایم لاین دارد
	struct S33SpriteState : public SPSerializable
	{
	private:
		int                                 extraFrameTime;//ms
		SPMesh*								mesh;
		void serialize(SPArchive& archive);
	public:
		std::string                         graphic;
		unsigned short                      frameTimeLenght; // 1000 / fps ms		
		unsigned short                      currentFrame;	
		unsigned short                      totalFrames;
		std::string                         name;
		std::vector<S33KeyFrame*>			timeline;
		
		S33SpriteState(const char* name);
		~S33SpriteState();	
		void Render(S33Sprite* instance);
		void SetGraphic(const char* name);
		SPMesh* GetGraphic(){return this->mesh;}
		
		S33KeyFrame* AddKeyFrame(int subsetNum);
		void RemoveKeyFrame(unsigned short index);
	};
}

#endif