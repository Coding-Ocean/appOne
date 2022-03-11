#define _FUNCTION

#ifdef _FUNCTION
#include<functional>
#include"framework.h"
#include"graphic.h"
#include"input.h"
#include"mathShape.h"

float func0(float x) { return x; }
float func1(float x) { return x * x; }
float func2(float x) { return x * x * x; }
float func3(float x) { return cosf(x); }

void graph(std::function<float(float)> f)
{
	strokeWeight(3);
	stroke(200, 0, 0);
	float next = 0.1f;
	for (float x = -maxScaleX(); x < maxScaleX(); x += next)
	{
		float x2 = x + next;
		mathLine(x, f(x), x2, f(x2));
	}
}

void gmain()
{
	window(1000, 1000);
	float x = -3.2f;
	float y = 0;
	std::function<float(float)> f = &func0;
	int sw = 0;
	while (notQuit)
	{
		//x座標
		x += 0.02f;
		if (x > 3.2f)x = -3.2f;
		//ｙ座標
		if (isTrigger(KEY_SPACE))
		{
			++sw %= 4;
			switch (sw)
			{
			case 0:f = &func0; break;
			case 1:f = &func1; break;
			case 2:f = &func2; break;
			case 3:f = &func3; break;
			}
		}
		y = f(x);

		clear();
		mathAxis(3.2f,255.0f);

		graph(f);

		fill(255);
		mathCircle(x, y, 0.1f);

	}
}
#endif

#ifdef _TEST
#include "libOne.h"

float func0(float x) { return x; }
float func1(float x) { return x * x; }
float func2(float x) { return x * x * x; }
float func3(float x) { return sin(x)*50; }

void gmain()
{
	window(1000, 1000);
	float x = -180;
	float y = 0;
	angleMode(DEGREES);
	while (notQuit)
	{
		//x座標
		x += 5;
		if (x > 180)x = -180;
		//ｙ座標
		y = func3(x);

		clear(255, 200, 200);
		mathAxis(180);

		fill(255, 0, 0);
		mathCircle(x, y, 10);
	}
}
#endif