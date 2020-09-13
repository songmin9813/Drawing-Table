#include <GL/glut.h>
#include <GL/GL.H>
#include <GL/GLU.H>
/*20164043 한성민
본 프로그램은 탁자 및 그 위에 있는 물품들을 만드는 프로그램입니다.*/
GLfloat vertices[][3] = {//책상 좌표
    { -0.5, -0.15, -0.5 }, 
    { -0.5, -0.15, 0.5 }, 
    { 0.5, -0.15, 0.5 }, 
    { 0.5, -0.15, -0.5 }, 
    { -0.5, -0.3, -0.5 }, 
    { -0.5, -0.3, 0.5 }, 
    { 0.5, -0.3, 0.5 }, 
    { 0.5, -0.3, -0.5 }
};
 
GLfloat vertices2[][3] = {//좌하단 책상기둥 좌표
    { -0.5, -0.5, 0.4 }, 
    { -0.5, -0.5, 0.5 }, 
    { -0.4, -0.5, 0.5 }, 
    { -0.4, -0.5, 0.4 }, 
    { -0.5, -0.3, 0.4 }, 
    { -0.5, -0.3, 0.5 }, 
    { -0.4, -0.3, 0.5 }, 
    { -0.4, -0.3, 0.4 }
};

GLfloat vertices3[][3] = {//좌상단 책상기둥 좌표
    { -0.5, -0.5, -0.4 }, 
    { -0.5, -0.5, -0.5 }, 
    { -0.4, -0.5, -0.5 }, 
    { -0.4, -0.5, -0.4 }, 
    { -0.5, -0.3, -0.4 }, 
    { -0.5, -0.3, -0.5 }, 
    { -0.4, -0.3, -0.5 }, 
    { -0.4, -0.3, -0.4 }
};

GLfloat vertices4[][3] = {//우상단 책상기둥 좌표
    { 0.5, -0.5, -0.4 }, 
    { 0.5, -0.5, -0.5 }, 
    { 0.4, -0.5, -0.5 }, 
    { 0.4, -0.5, -0.4 }, 
    { 0.5, -0.3, -0.4 }, 
    { 0.5, -0.3, -0.5 }, 
    { 0.4, -0.3, -0.5 }, 
    { 0.4, -0.3, -0.4 }
};

GLfloat vertices5[][3] = {//우하단 책상기둥 좌표
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
//여러 함수에 사용될 좌표 변수를 전역 변수로 설정합니다.
void InitLight(){
	//해당 함수는 빛의 쬐기를 표현하는 함수입니다.
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
	//마우스의 이동이 발생하였을 경우 실행됩니다.
	glutPostRedisplay();//좌표가 다시 설정되었으므로 폴리곤을 다시 그리는 함수를 호출합니다.
}

void MyKeyboard(unsigned char key, int x, int y){
	switch(key){
	case 'q': case 'Q': case '\033':exit(0); break;
		//q가 입력되었을 경우 프로그램을 종료합니다.
	case 's': if(FlatShaded){
		//s가 입력되었을 경우 모델의 종류가 바뀌어 표시됩니다.
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
	//육면체를 만들어주는 함수입니다.
	//해당 함수를 이용하여 책상을 만듭니다.
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
	//3차원 도형이기에 색 이외에 깊이 버퍼를 추가하여 초기화합니다.
    glRotatef(30, 1.0f, 1.0f, 0.0f);
	//3차원 입체를 효과적으로 보여주기 위해 시점을 바꿉니다.
	glMatrixMode(GL_MODELVIEW);
	//행렬의 모드를 모델뷰 형태로 표현합니다.
	glLoadIdentity();
	glutSolidTeapot(0.2);
	MakingHex(vertices);
	MakingHex(vertices2);
	MakingHex(vertices3);
	MakingHex(vertices4);
	MakingHex(vertices5);
	//책상과 책상 다리를 만듭니다.
	glEnd();
	glFlush();
	
}

void MyReshape(int w, int h){
	glViewport(0,0,(GLsizei) w, (GLsizei) h);
	//뷰포트를 다시 설정하여야 합니다.
	glMatrixMode(GL_PROJECTION);
	//행렬의 모드를 투영모드로 합니다.
	glLoadIdentity();//단위행렬로 초기화합니다.
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}

int main(int argc, char** argv){ // main 함수의 시작. glutInit 함수 사용시 해당 매개변수를 넣어야 합니다.
	glutInit(&argc, argv);//glut 함수을 사용하기 위해서 넣어야 하는 함수입니다.
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);//RGB 색상 모드인 디스플레이를 선언하기 위해 호출하는 함수입니다.
	glutInitWindowSize(400, 400);//실행 윈도우의 기본 사이즈를 설정합니다.
	glutInitWindowPosition(0, 0);//실행시 초기 윈도우 창의 위치를 설정합니다.
	glutCreateWindow("OpenGL Sample Drawing");//윈도우 제목을 설정합니다.
	glClearColor(0.4, 0.4, 0.4, 0.0);//실행시 창의 색을 결정합니다. 하얀색을 위한 설정입니다.
	InitLight();//빛을 투영시키는 함수입니다.
	glutDisplayFunc(MyDisplay);//해당 함수를 실행시켜주는 함수
	glutKeyboardFunc(MyKeyboard);//키보드를 입력하였을 경우 이벤트가 발생합니다.
	glutMotionFunc(MyMouseMove);//마우스가 이동되었을 때 호출되는 함수입니다.
	glutReshapeFunc(MyReshape);//윈도우 창 변경시 호출되는 함수입니다.
	glutMainLoop();//루프문을 설정하여야 프로그램이 실행됩니다.
	return 0;
}