
#pragma once

#include "scene/SceneRendering.h"


class SceneSample
	: public SceneRendering
{
private:

public:
	SceneSample(SceneID scene_id);

	void Initialize();
	void Finalize();
	void Update(unsigned int elapsed_time);

};
