
#pragma once

#include "scene/SceneRendering.h"
#include "entity/EntityTextPrinter.h"
#include "Ball.h"

class SceneSample
	: public BlueCarrot::SceneRendering
{
private:
	BlueCarrot::entity::EntityTextPrinter * m_pPrinter;
	Ball * m_pBall;

public:
	SceneSample(BlueCarrot::SceneID scene_id);

	void Initialize();
	void Finalize();
	void Update(unsigned int elapsed_time);

};
