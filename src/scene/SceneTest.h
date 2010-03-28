
#pragma once

#include "scene/SceneRendering.h"


class SceneTest
	: public SceneRendering
{
private:

public:
	SceneTest(SCENE_ID scene_id);

	void Initialize();
	void Finalize();
	void Update(unsigned int elapsed_time);

};
