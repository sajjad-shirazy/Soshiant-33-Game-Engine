#include <Soshiant33.h>

#pragma comment(lib, "Pei_d.lib")
#pragma comment(lib, "Soshiant33_d.lib")
#pragma comment(lib, "lua5.1.lib")
#pragma comment(lib, "Box2d_d.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "winmm.lib")

using namespace Soshiant33;

int main()
{
// 1- Scene Initing
	S33Engine engine;//(1366,768,true);
	engine.GetRenderer()->GetCamera()->Walk(-500);
	S33ScenePattern* scenePattern = new S33ScenePattern();
	scenePattern->name = "01.sen";
	S33Scene* scene = (S33Scene*)engine.AddChild(scenePattern,0);

	{
	// 2- Moving Sprite Initing
		S33SpritePattern* spritePattern = new S33SpritePattern();
		spritePattern->bodyDef.type = b2_dynamicBody;//به صورت پیش فرض موجودات استاتیک اند.
		S33SpriteState* spriteState = spritePattern->AddNewState("State0");
		spriteState->SetGraphic("SpriteSheet_06.x");
		for(unsigned int i =0;i< spriteState->GetGraphic()->subsetsCount;i++)
			spriteState->AddKeyFrame(i);
		spriteState->frameTimeLenght = 1000/45;
		S33EntityParameters ep;
		ep.position.z = 0;
		S33Sprite* sprite = (S33Sprite*)scene->AddChild(spritePattern,&ep);

		//----------------------------------
		//تعریف شکل و سایر جزئیات تنه فیزیکی
		//----------------------------------
		sprite->isPhysical = true;//اگر فالس باشد مشخصات تنه با اسپرایت در صدا زدن متد آپدیت تنظیم نمی شود
		sprite->body->SetTransform(b2Vec2(0,15),(float)Math::PI /5.0f);
		b2PolygonShape box;
		box.SetAsBox(1.5f,3);
		//or
		//b2CircleShape circle;
		//circle.m_radius = 144.0f/S33Scene::meterPixelRatio/2;
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &box;
		fixtureDef.density = 100.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.restitution = 0.49f;
		sprite->body->CreateFixture(&fixtureDef);
		//-------------------------------------
	}
	{
	//3- Static Sprite Initing
		S33SpritePattern* spritePattern = new S33SpritePattern();
		S33SpriteState* spriteState = spritePattern->AddNewState("State0");
		spriteState->SetGraphic("Floor.sht");
		for(unsigned int i =0;i< spriteState->GetGraphic()->subsetsCount;i++)
			spriteState->AddKeyFrame(i);
		spriteState->frameTimeLenght = 1000/45;
		S33EntityParameters ep;
		ep.position.z = 0;
		S33Sprite* sprite = (S33Sprite*)scene->AddChild(spritePattern,&ep);
		//----------------------------------
		//تعریف شکل و سایر جزئیات تنه فیزیکی
		//----------------------------------
		sprite->isPhysical = true;//اگر فالس باشد مشخصات تنه با اسپرایت در صدا زدن متد آپدیت تنظیم نمی شود
		sprite->body->SetTransform(b2Vec2(0,-10),0);
		b2PolygonShape box;
		box.SetAsBox(10.0f, 1.0f);
		sprite->body->CreateFixture(&box,0);
		//-------------------------------------
	}
	while(!engine.GetWindow()->IsWindowClosed())
	{
		SPWindow::ProcessMessages();
		engine.Update();
		engine.Render();
	}
	S33Library::RemoveItems(0);
	return 0;
}
