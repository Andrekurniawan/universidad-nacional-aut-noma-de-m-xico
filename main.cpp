#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void mouseMove(int x, int y);
void mouseButton(int button, int state, int x, int y);
using namespace std;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown = false;
int is_depth;
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("City University of Hong Kong");
    init();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.4, 0.7, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(6.0f);

}

void display(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);

    glBegin(GL_POLYGON);//alas
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-600, 0, -450);
    glColor3f(0.6, 1.4, 0.4);
    glVertex3f(-600, 0, 400);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(600, 0, 400);
    glColor3f(0.6, 1.4, 0.4);
    glVertex3f(600, 0, -450);
    glEnd();
    glBegin(GL_LINE_LOOP);//garis alas
    glColor3f(0, 0, 0);
    glVertex3f(-600, 0, -450);
    glVertex3f(-600, 0, 400);
    glVertex3f(600, 0, 400);
    glVertex3f(600, 0, -450);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_POLYGON);//gedung bawah bagian depan
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-400, 0, 130);
    glVertex3f(400, 0, 130);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(400, 200, 130);
    glVertex3f(-400, 200, 130);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_POLYGON);//gedung bawah bagian belakang
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-400, 0, -380);
    glVertex3f(400, 0, -380);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(400, 200, -380);
    glVertex3f(-400, 200, -380);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah bagian kiri
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-400, 0, -380);
    glVertex3f(-400, 0, 130);
    glVertex3f(-400, 200, 130);
    glVertex3f(-400, 200, -380);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah bagian kanan
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(400, 0, -380);
    glVertex3f(400, 0, 130);
    glVertex3f(400, 200, 130);
    glVertex3f(400, 200, -380);
    glEnd();

    //Gedung bawah pondasi

    glLineWidth(6.0f);
    glBegin(GL_POLYGON);//gedung bawah pondasi bagian depan
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-450, 200, 170);
    glVertex3f(450, 200, 170);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(450, 250, 170);
    glVertex3f(-450, 250, 170);
    glEnd();

    glLineWidth(6.0f);
    glBegin(GL_POLYGON);//gedung bawah pondasi bagian belakang
    glColor3f(0.612, 0.612, 0.612);
    glVertex3f(-450, 200, -420);
    glVertex3f(450, 200, -420);
    glColor3f(0.812, 0.812, 0.812);
    glVertex3f(450, 250, -420);
    glVertex3f(-450, 250, -420);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah pondasi bagian kiri
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(-450, 200, -420);
    glVertex3f(-450, 200, 170);
    glVertex3f(-450, 250, 170);
    glVertex3f(-450, 250, -420);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah pondasi bagian kanan
    glColor3f(0.45, 0.45, 0.9);
    glVertex3f(450, 200, -420);
    glVertex3f(450, 200, 170);
    glVertex3f(450, 250, 170);
    glVertex3f(450, 250, -420);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah bagian atap
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(450, 200, 170);
    glVertex3f(450, 200, -420);
    glVertex3f(-450, 200, -420);
    glVertex3f(-450, 200, 170);
    glEnd();

    glBegin(GL_POLYGON);//gedung bawah bagian atap
    glColor3f(0.4, 0.4, 0.4);
    glVertex3f(450, 250, 170);
    glVertex3f(450, 250, -420);
    glVertex3f(-450, 250, -420);
    glVertex3f(-450, 250, 170);
    glEnd();

    //Gedung Atas

    glBegin(GL_LINES);//gedung atas atap garis depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-250, 850, -60);
    glVertex3f(250, 850, -60);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap garis belakang
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-250, 850, -240);
    glVertex3f(250, 850, -240);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap garis kiri
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-250, 850, -60);
    glVertex3f(-250, 850, -240);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap garis kanan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(250, 850, -60);
    glVertex3f(250, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas atap
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(250, 850, -240);
    glVertex3f(250, 850, -60);
    glVertex3f(-250, 850, -60);
    glVertex3f(-250, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas depan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-250, 850, -60);
    glVertex3f(250, 850, -60);
    glVertex3f(250, 200, -60);
    glVertex3f(-250, 200, -60);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas belakang
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-250, 850, -240);
    glVertex3f(250, 850, -240);
    glVertex3f(250, 200, -240);
    glVertex3f(-250, 200, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kiri
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-250, 850, -240);
    glVertex3f(-250, 850, -60);
    glVertex3f(-250, 200, -60);
    glVertex3f(-250, 200, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kanan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(250, 850, -240);
    glVertex3f(250, 850, -60);
    glVertex3f(250, 200, -60);
    glVertex3f(250, 200, -240);
    glEnd();

    //Gedung atas kecil

    glBegin(GL_LINES);//gedung atas atap kecil garis depan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100, 950, -60);
    glVertex3f(100, 950, -60);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap kecil garis belakang
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100, 950, -240);
    glVertex3f(100, 950, -240);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap kecil garis kiri
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100, 950, -60);
    glVertex3f(-100, 950, -240);
    glEnd();
    glBegin(GL_LINES);//gedung atas atap kecil garis kanan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(100, 950, -60);
    glVertex3f(100, 950, -240);
    glEnd();

    glBegin(GL_POLYGON);//gedung atas kecil atap
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(100, 950, -240);
    glVertex3f(100, 950, -60);
    glVertex3f(-100, 950, -60);
    glVertex3f(-100, 950, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kecil depan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 950, -60);
    glVertex3f(100, 950, -60);
    glVertex3f(100, 850, -60);
    glVertex3f(-100, 850, -60);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kecil belakang
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 950, -240);
    glVertex3f(100, 950, -240);
    glVertex3f(100, 850, -240);
    glVertex3f(-100, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kecil kiri
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 950, -240);
    glVertex3f(-100, 950, -60);
    glVertex3f(-100, 850, -60);
    glVertex3f(-100, 850, -240);
    glEnd();
    glBegin(GL_POLYGON);//gedung atas kecil kanan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(100, 950, -240);
    glVertex3f(100, 950, -60);
    glVertex3f(100, 850, -60);
    glVertex3f(100, 850, -240);
    glEnd();

    //Pintu Depan

    glBegin(GL_POLYGON);//pintu kecil atap
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(100, 100, 100);
    glVertex3f(100, 100, 250);
    glVertex3f(-100, 100, 250);
    glVertex3f(-100, 100, 100);
    glEnd();
    glBegin(GL_POLYGON);//pintu kecil bawah
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(100, 80, 100);
    glVertex3f(100, 80, 250);
    glVertex3f(-100, 80, 250);
    glVertex3f(-100, 80, 100);
    glEnd();

    glBegin(GL_POLYGON);//pintu kecil depan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 100, 250);
    glVertex3f(100, 100, 250);
    glVertex3f(100, 80, 250);
    glVertex3f(-100, 80, 250);
    glEnd();

    glBegin(GL_POLYGON);//pintu kecil kiri
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 100, 100);
    glVertex3f(-100, 100, 250);
    glVertex3f(-100, 80, 250);
    glVertex3f(-100, 80, 100);
    glEnd();
    glBegin(GL_POLYGON);//pintu kecil kanan
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(100, 100, 100);
    glVertex3f(100, 100, 250);
    glVertex3f(100, 80, 250);
    glVertex3f(100, 80, 100);
    glEnd();

    glBegin(GL_LINES);//garis pintu kiri
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100, 80, 130);
    glVertex3f(-100, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis pintu kanan
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(100, 80, 130);
    glVertex3f(100, 0, 130);
    glEnd();

    //Pillar Pintu

    glBegin(GL_POLYGON);
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(-100, 100, 250);
    glVertex3f(-80, 100, 230);
    glVertex3f(-80, 0, 230);
    glVertex3f(-100, 0, 250);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.93, 0.93, 0.93);
    glVertex3f(100, 100, 250);
    glVertex3f(80, 100, 230);
    glVertex3f(80, 0, 230);
    glVertex3f(100, 0, 250);
    glEnd();

    //Jendela Depan

    glBegin(GL_LINES);//garis1
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(100, 200, 130);
    glVertex3f(100, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis2
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-100, 200, 130);
    glVertex3f(-100, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis3
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-200, 200, 130);
    glVertex3f(-200, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis4
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(-300, 200, 130);
    glVertex3f(-300, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis5
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(200, 200, 130);
    glVertex3f(200, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis6
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(300, 200, 130);
    glVertex3f(300, 0, 130);
    glEnd();

    glBegin(GL_LINES);//garis7
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(400, 80, 130);
    glVertex3f(-400, 80, 130);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void mouseMove(int x, int y) {
    if (mousedown) {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mousedown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mousedown = false;
    }
    glutPostRedisplay();
}
/*
Cara penggunaan :
+++++++++++++++++++++----------------------------------------------------+++++++++++++
untuk penggunaan mouse langsung klik rumah dan arahkan
+++++++++++++++++++++----------------------------------------------------+++++++++++++
tombol pada keyboard:
"a": ke kiri
"d": ke kanan
"w": ke depan
"s": ke belakang
"z" : ke atas
"x" : ke bawah
"i" : rotasi ke bawah terhadap sumbu X
"k" : rotasi ke atas terhadap sumbu X
"j" : rotasi ke kiri terhadap sumbu Y
"l" : rotasi ke kanan terhadap sumbu Y
"m" : rotasi ke kiri terhadap sumbu Z
"n" : rotasi ke kanan terhadap sumbu Z
"5" : transparankan rumah
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
    case 'A':
        glTranslatef(15.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-15.0, 0.0, 0.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 15.0, 0.0);
        break;
    case 'x':
    case 'X':
        glTranslatef(0.0, -15.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 15.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -15.0);
        break;
    case 'i':
    case 'I':
        glRotatef(3.0, 1.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glRotatef(-3.0, 1.0, 0.0, 0.0);
        break;
    case 'j':
    case 'J':
        glRotatef(3.0, 0.0, 1.0, 0.0);
        break;
    case 'l':
    case 'L':
        glRotatef(-3.0, 0.0, 1.0, 0.0);
        break;
    case 'm':
    case 'M':
        glRotatef(3.0, 0.0, 0.0, 1.0);
        break;
    case 'n':
    case 'N':
        glRotatef(-3.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    display();
}
void resize(int width, int height)
{
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, width / height, 30.0, 2000.0);
    glTranslatef(0.0, -500.0, -1500.0);
    glMatrixMode(GL_MODELVIEW);
}
