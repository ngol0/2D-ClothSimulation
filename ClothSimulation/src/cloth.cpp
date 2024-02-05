#include "cloth.h"
#include "renderer.h"

cloth::cloth() {}

void cloth::init(vec2 start_pos, vec2 size, float spacing)
{
	float horizontal_rect = size.x / spacing;
	float vertical_rect = size.y / spacing;

	//create points and stick
	for (int x = 0; x <= horizontal_rect; x++)
	{
		for (int y = 0; y <= vertical_rect; y++)
		{
			//if not the first point, create the stick to the left
			if (x != 0)
			{

			}

			//if not the first point, create the stick up
			if (y != 0)
			{

			}
		}
	}
}

void cloth::update(float deltaTime, renderer& renderer)
{

}

void cloth::draw(renderer& renderer)
{

}