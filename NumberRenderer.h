#ifndef NUMBER_RENDERER_H_
#define NUMBER_RENDERER_H_

#include <GL/glut.h>

class NumberRenderer {
private:
    struct NumberVertices {
        int n;
        double v[32];
    };
private:
    double position_;
    NumberVertices numbers_[10];
public:
    NumberRenderer()
    : numbers_{
        { 5, { // 0
            0.0, 0.0,
            1.0, 0.0,
            1.0, 1.0,
            0.0, 1.0,
            0.0, 0.0 }},

        { 3, { // 1
            0.25, 0.0,
            0.75, 0.0,
            0.75, 1.0 }},

        { 6, { // 2
            0.0, 0.0,
            1.0, 0.0,
            1.0, 0.2,
            0.0, 0.8,
            0.0, 1.0,
            1.0, 1.0 }},

        { 6, { // 3
            0.0, 0.0,
            1.0, 0.0,
            0.5, 0.5,
            1.0, 0.5,
            0.5, 1.0,
            0.0, 1.0 }},

        { 6, { // 4
            0.75, 1.0,
            0.75, 0.0,
            0.5, 0.0,
            0.0, 0.5,
            0.0, 0.75,
            1.0, 0.75 }},

        { 7, { // 5
            1.0, 0.0,
            0.0, 0.0,
            0.0, 0.3,
            0.75, 0.3,
            1.0, 0.65,
            0.75, 1.0,
            0.0, 1.0 }},

        { 8, { // 6
            0.75, 0.0,
            0.25, 0.0,
            0.0, 0.5,
            0.0, 1.0,
            0.75, 1.0,
            1.0, 0.75,
            0.75, 0.5,
            0.0, 0.5 }},

        { 5, { // 7
            0.0, 0.0,
            1.0, 0.0,
            1.0, 0.25,
            0.5, 0.5,
            0.5, 1.0 }},

        { 9, { // 8
            0.25, 0.0,
            0.75, 0.0,
            0.75, 0.3,
            0.15, 0.5,
            0.15, 1.0,
            0.85, 1.0,
            0.85, 0.5,
            0.25, 0.3,
            0.25, 0.0 }},

        { 7, { // 9
            1.0, 0.5,
            0.0, 0.5,
            0.0, 0.0,
            1.0, 0.0,
            1.0, 0.5,
            0.5, 1.0,
            0.0, 1.0 }}
    }
    {}
    ~NumberRenderer() {}
    void Init() {}
    void RenderDigit(int digit) {

        glBegin(GL_LINE_STRIP);
        for (int i=0; i<numbers_[digit].n; ++i) {
            glVertex2d(position_ + numbers_[digit].v[2*i+0], numbers_[digit].v[2*i+1]);
        }
        glEnd();

        position_ += 1.2;
    }
    void Render(int x, int y, const char *number) {

        glLoadIdentity();
        glTranslatef(x, y, 0.0);
        glScalef(60.0, 100.0, 1.0);

        position_ = 0.0;
        for (int i=0; i<strlen(number); ++i) {
            RenderDigit(number[i] - '0');
        }
    }
};

#endif // NUMBER_RENDERER_H_

