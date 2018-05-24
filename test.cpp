#include "NumberRenderer.h"

NumberRenderer* number_renderer = 0;

void init() {

    number_renderer = new NumberRenderer();
    number_renderer->Init();
}

void render() {

    char number[] = "123456";

    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);

    number_renderer->Render(100, 100, number);
}

