#ifndef _S33Entity_H
#define _S33Entity_H

#include "S33Library.h"
#include "S33Script.h"

using namespace Pei::Graphic;

namespace Soshiant33
{
	//----------------------------------------------------
	//Entity Pattern :
	/// با استفاده از الگوها می توانیم بر اساس آنها موجودیت در صحنه کپی کنیم
	/// برای درک مفهوم الگوی موجودیت و موجودیت به رابطه نقشه ساختمان و ساختمان توجه کنید
	struct S33EntityPattern abstract: public SPSerializable
	{
		friend class S33Library;
		enum Types : unsigned char
		{
			Type_EntityPattern = 0,
			Type_SpritePattern = 1,
			Type_ComplexEntityPattern = 2,
			Type_ScenePattern = 3
		};
		Types				  type;
		std::string			  name;
		std::string			  script;
		S33EntityPattern(const char* name,Types type);
		virtual void Save(const char* name) = 0;
		virtual void Load(const char* name) = 0;
	protected:
		void serializeBase_S33EntityPattern(SPArchive& archive);
	private:
		unsigned char	itemGroupID;
		S33EntityPattern* next;
		S33EntityPattern* prev;


	};
	//----------------------------------------------------
	//Entity Parameters
	struct S33EntityParameters : public SPRenderingParameters
	{
		//unsigned short id;
		std::string     name;
		S33EntityParameters();
	protected:
		virtual void serialize(SPArchive& archive);
	};
	//----------------------------------------------------
	//Entity
	class S33Scene;
	class S33ComplexEntity;
	class S33Entity abstract
	{
		friend class S33ComplexEntity;
	public:
		enum Types : unsigned char
		{
			Type_Entity,
			Type_Sprite,
			Type_ComplexEntity,
			Type_Scene,			
			Type_Engine
		};
	public:		
		S33Script            script;
		S33EntityPattern*    pattern;
		S33EntityParameters  ep;
		S33ComplexEntity*    parent;
		S33Scene*            scene;
		Types                type;
		bool                 isAlive;

		S33Entity(S33EntityPattern* entityDef,S33EntityParameters* ep,S33ComplexEntity* parent);
		~S33Entity();

		virtual void Update() = 0;
		virtual void Render() = 0;
		virtual float GetDepth(){return this->ep.position.z;}
		/// تست برخورد موس با موجودیت
		virtual S33Entity* Pick(POINT* point) = 0;
	};
}
#endif