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

int main() {
	SPLoopManager loopman;
	loopman.AllowSleep(true);
	S33Engine engine;//(1366,768,true);
	S33ScenePattern* scenePattern = S33Library::GetScenePattern("01.sen");
	S33Scene* scene = (S33Scene*)engine.AddChild(scenePattern,0);
	float r = 0;
	while(!engine.GetWindow()->IsWindowClosed())
	{
		loopman.BeginLoop();
		SPWindow::ProcessMessages();
		engine.Update();
		engine.Render();
		engine.GetRenderer()->GetCamera()->Strafe(0.7f);
		engine.GetRenderer()->GetCamera()->Fly(sinf(r+=0.07f)*4);
		scene->ep.scale.x = scene->ep.scale.y = sinf(r)/4+1.2f;
		loopman.EndLoop();
	}
	S33Library::RemoveItems(0);
	return 0;
}