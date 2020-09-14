#include <GL/glut.h>
#include <GL/GL.H>
#include <GL/GLU.H>
/*20164043 �Ѽ���
�� ���α׷��� Ź�� �� �� ���� �ִ� ��ǰ���� ����� ���α׷��Դϴ�.*/
GLfloat vertices[][3] = {//å�� ��ǥ
    { -0.5, -0.15, -0.5 }, 
    { -0.5, -0.15, 0.5 }, 
    { 0.5, -0.15, 0.5 }, 
    { 0.5, -0.15, -0.5 }, 
    { -0.5, -0.3, -0.5 }, 
    { -0.5, -0.3, 0.5 }, 
    { 0.5, -0.3, 0.5 }, 
    { 0.5, -0.3, -0.5 }
};
 
GLfloat vertices2[][3] = {//���ϴ� å���� ��ǥ
    { -0.5, -0.5, 0.4 }, 
    { -0.5, -0.5, 0.5 }, 
    { -0.4, -0.5, 0.5 }, 
    { -0.4, -0.5, 0.4 }, 
    { -0.5, -0.3, 0.4 }, 
    { -0.5, -0.3, 0.5 }, 
    { -0.4, -0.3, 0.5 }, 
    { -0.4, -0.3, 0.4 }
};

GLfloat vertices3[][3] = {//�»�� å���� ��ǥ
    { -0.5, -0.5, -0.4 }, 
    { -0.5, -0.5, -0.5 }, 
    { -0.4, -0.5, -0.5 }, 
    { -0.4, -0.5, -0.4 }, 
    { -0.5, -0.3, -0.4 }, 
    { -0.5, -0.3, -0.5 }, 
    { -0.4, -0.3, -0.5 }, 
    { -0.4, -0.3, -0.4 }
};

GLfloat vertices4[][3] = {//���� å���� ��ǥ
    { 0.5, -0.5, -0.4 }, 
    { 0.5, -0.5, -0.5 }, 
    { 0.4, -0.5, -0.5 }, 
    { 0.4, -0.5, -0.4 }, 
    { 0.5, -0.3, -0.4 }, 
    { 0.5, -0.3, -0.5 }, 
    { 0.4, -0.3, -0.5 }, 
    { 0.4, -0.3, -0.4 }
};

GLfloat vertices5[][3] = {//���ϴ� å���� ��ǥ
    { 0.5, -0.5, 0.4 }, 
    { 0.5, -0.5, 0.5 }, 
    { 0.4, -0.5, 0.5 }, 
    { 0.4, -0.5, 0.4 }, 
    { 0.5, -0.3, 0.4 }, 
    { 0.5, -0.3, 0.5 }, 
    { 0.4, -0.3, 0.5 }, 
    { 0.4, -0.3, 0.4 }
};
int FlatShaded = 0;
//���� �Լ��� ���� ��ǥ ������ ���� ������ �����մϴ�.
void InitLight(){
	//�ش� �Լ��� ���� �ر⸦ ǥ���ϴ� �Լ��Դϴ�.
	GLfloat mat_diffuse[] = {0.5,0.4,0.3,1.0};
	GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
	GLfloat mat_ambient[] = {0.5,0.4,0.3,1.0};
	GLfloat mat_shininess[] = {15.0};
	GLfloat light_specular[] = {1.0,1.0,1.0,1.0};
	GLfloat light_diffuse[] = {0.8,0.8,0.8,1.0};
	GLfloat light_ambient[] = {0.3,0.3,0.3,1.0};
	GLfloat light_position[] = {-3,6,3.0,0.0};
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
}

void MyMouseMove(GLint X, GLint Y){
	//���콺�� �̵��� �߻��Ͽ��� ��� ����˴ϴ�.
	glutPostRedisplay();//��ǥ�� �ٽ� �����Ǿ����Ƿ� �������� �ٽ� �׸��� �Լ��� ȣ���մϴ�.
}

void MyKeyboard(unsigned char key, int x, int y){
	switch(key){
	case 'q': case 'Q': case '\033':exit(0); break;
		//q�� �ԷµǾ��� ��� ���α׷��� �����մϴ�.
	case 's': if(FlatShaded){
		//s�� �ԷµǾ��� ��� ���� ������ �ٲ�� ǥ�õ˴ϴ�.
				FlatShaded = 0;
				glShadeModel(GL_SMOOTH);
			  }
			  else{
				  FlatShaded = 1;
				  glShadeModel(GL_FLAT);
			  }
			  glutPostRedisplay();
			  break;
	}
}

void MakingHex(GLfloat vertices[][3]){
	//����ü�� ������ִ� �Լ��Դϴ�.
	//�ش� �Լ��� �̿��Ͽ� å���� ����ϴ�.
        glBegin(GL_QUADS);
 
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[1]);
 
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[2]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[5]);
 
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[6]);
    glVertex3fv(vertices[2]);
 
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[3]);
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[4]);
 
    glVertex3fv(vertices[7]);
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[5]);
    glVertex3fv(vertices[6]);
 
    glVertex3fv(vertices[4]);
    glVertex3fv(vertices[0]);
    glVertex3fv(vertices[1]);
    glVertex3fv(vertices[5]);
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//3���� �����̱⿡ �� �̿ܿ� ���� ���۸� �߰��Ͽ� �ʱ�ȭ�մϴ�.
    glRotatef(30, 1.0f, 1.0f, 0.0f);
	//3���� ��ü�� ȿ�������� �����ֱ� ���� ������ �ٲߴϴ�.
	glMatrixMode(GL_MODELVIEW);
	//����� ��带 �𵨺� ���·� ǥ���մϴ�.
	glLoadIdentity();
	glutSolidTeapot(0.2);
	MakingHex(vertices);
	MakingHex(vertices2);
	MakingHex(vertices3);
	MakingHex(vertices4);
	MakingHex(vertices5);
	//å��� å�� �ٸ��� ����ϴ�.
	glEnd();
	glFlush();
	
}

void MyReshape(int w, int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	//����Ʈ�� �ٽ� �����Ͽ��� �մϴ�.
	glMatrixMode(GL_PROJECTION);
	//����� ��带 �������� �մϴ�.
	glLoadIdentity();//������ķ� �ʱ�ȭ�մϴ�.
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv){ // main �Լ��� ����. glutInit �Լ� ���� �ش� �Ű������� �־�� �մϴ�.
	glutInit(&argc, argv);//glut �Լ��� ����ϱ� ���ؼ� �־�� �ϴ� �Լ��Դϴ�.
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);//RGB ���� ����� ���÷��̸� �����ϱ� ���� ȣ���ϴ� �Լ��Դϴ�.
	glutInitWindowSize(400, 400);//���� �������� �⺻ ����� �����մϴ�.
	glutInitWindowPosition(0, 0);//����� �ʱ� ������ â�� ��ġ�� �����մϴ�.
	glutCreateWindow("OpenGL Sample Drawing");//������ ������ �����մϴ�.
	glClearColor(0.4, 0.4, 0.4, 0.0);//����� â�� ���� �����մϴ�. �Ͼ���� ���� �����Դϴ�.
	InitLight();//���� ������Ű�� �Լ��Դϴ�.
	glutDisplayFunc(MyDisplay);//�ش� �Լ��� ��������ִ� �Լ�
	glutKeyboardFunc(MyKeyboard);//Ű���带 �Է��Ͽ��� ��� �̺�Ʈ�� �߻��մϴ�.
	glutMotionFunc(MyMouseMove);//���콺�� �̵��Ǿ��� �� ȣ��Ǵ� �Լ��Դϴ�.
	glutReshapeFunc(MyReshape);//������ â ����� ȣ��Ǵ� �Լ��Դϴ�.
	glutMainLoop();//�������� �����Ͽ��� ���α׷��� ����˴ϴ�.
	return 0;
}