
#include "Ball.h"

using namespace BlueCarrot;

Ball::Ball()
	: SceneEntitySprite("resource/master/reversi/board.tga")
{
	EnableAlphablending();
	SetRect(utility::Rect<float>(0, 0, 100, 100));
}

Ball::~Ball()
{
}
