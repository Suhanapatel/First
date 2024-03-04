#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); // Set color to yellow

    // Draw face
    drawCircle(250.0, 250.0, 200.0, 100);

    glColor3f(0.0, 0.0, 0.0); // Set color to black

    // Draw eyes
    drawCircle(175.0, 325.0, 25.0, 100);
    drawCircle(325.0, 325.0, 25.0, 100);

    // Draw mouth
    glBegin(GL_LINES);
    glVertex2f(200.0, 175.0);
    glVertex2f(300.0, 175.0);
    glEnd();

    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Smiley Face");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}

