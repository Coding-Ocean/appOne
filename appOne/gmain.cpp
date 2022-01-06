#define _
#ifdef _
#include"libOne.h"
#include"SHADER/LAMBERT.h"
#include"CONTAINER/CONTAINER.h"
#include"CONTAINER/BATCH.h"
void gmain() 
{
    window(1000, 1000);
    
    SHADER* shader = new LAMBERT;
    MATRIX view;
    VECTOR camPos(0, 4, 1.5), lookat(0, 2, -1.5), up(0, 1, 0);
    view.camera(camPos, lookat, up);
    MATRIX proj;
    proj.pers(3.14f / 4, width / height, 1, 100);
    VECTOR lightPos(0, 0, 1);
    float ambient = 1;
    COLOR diffuse(1, 1, 1, 1);

    CONTAINER c("assets\\square.txt");
    BATCH* b = c.batch("square");
    MATRIX world;
    float angle = 0;

    while (notQuit)
    {
        angle += 0.017f;
        camPos.set(0, 3, -4 + sin(angle) * 5);
        lookat.set(0, 2, camPos.z - 1);
        view.camera(camPos, lookat, up);

        clear(60, 120, 240);

        shader->setProjView(proj * view);
        shader->setLightPosition(lightPos);
        shader->setLightAmbient(ambient);
        shader->setDiffuse(diffuse);
        setRasterizerCullBack();

        for (int i = 0; i < 10; i++)
        {
            world.identity();
            world.mulRotateZ(sin(angle + i * 0.017 * 30) * 0.25f);
            world.mulTranslate(0, 1, -10 + i);
            b->draw(shader, world);
        }
    }

    delete shader;
}
#endif
