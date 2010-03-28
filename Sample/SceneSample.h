
#pragma once

#include "scene/SceneRendering.h"
#include "entity/EntityTextPrinter.h"
#include "entity/SceneEntitySprite.h"


class SceneSample
	: public SceneRendering
{
private:
	entity::EntityTextPrinter * m_pPrinter;
	entity::SceneEntitySprite * m_pSprite;

public:
	SceneSample(SceneID scene_id);

	void Initialize();
	void Finalize();
	void Update(unsigned int elapsed_time);

};
