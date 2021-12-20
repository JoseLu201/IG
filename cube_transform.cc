#include "cube_transform.h"

cube_transform::cube_transform(float size)
{   glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    cube.draw_line();
    glPopMatrix();
}
