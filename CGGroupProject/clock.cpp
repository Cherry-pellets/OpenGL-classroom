//#include <gl\glut.h>    
//#include <gl\GLU.h>
//#include <gl\GL.h>
//#include <math.h>
//#include <windows.h>
//#include <stdio.h>
//
//const int Width = 800;
//const int Height = 600;
//
//const GLfloat PI = 3.141592653f;
//
//// ��ǰʱ�䣬ʱ �� ��
//float h = 0.0f;
//float m = 0.0f;
//float s = 0.0f;
//
///*
//��ʱ�ӵĺ���
//*/
//void myDisplay(void)
//{
//	// �õ�ǰ���ɫ�����ɫ�����������趨���ڵı���ɫ
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(0.1f, 0.2f, 0.1f); // ��ɫ
//
//
//	// 1 ������Χͬ��Բ
//	int cx = 600; Width / 2; //���ĵ�
//	int cy = 400;// Height / 2;
//	int R = 50; // �뾶��
//	int n = 50;
//	int i;
//
//	glBegin(GL_LINE_LOOP); // ���ƶ���Σ�n�㹻��ͻ���Բ��
//	for (i = 0; i < n; i++)
//	{
//		glVertex2f(cx + (R + 2) * cos(2 * PI / n * i), cy + (R + 2) * sin(2 * PI / n * i));
//	}
//	glEnd();
//
//	glBegin(GL_LINE_LOOP);
//	for (i = 0; i < n; i++)
//	{
//		//glVertex2f(cx + R*cos(2 * PI / n * i), cy + R*sin(2 * PI / n * i));
//		glVertex2f(cx + (R + 5) * cos(2 * PI / n * i), cy + (R + 5) * sin(2 * PI / n * i));
//	}
//	glEnd();
//
//
//	// 2 ����ʱ�� Բ�ϵĿ̶ȣ��̶ȴ�ϸ�����Ȳ�һ��
//	int lines = 60;
//	float ship1 = 10;
//	float ship2 = 5;
//	for (i = 0; i < lines; i++)
//	{
//		if (i % 5 == 0)    //  0��12��-11�Ķ���
//		{
//			glLineWidth(5);
//			//glColor3f(0.0, 1.0, 0.0);
//			glBegin(GL_LINES);
//			glVertex2f(cx + (R - ship1) * sin(2 * PI / lines * i), cy + (R - ship1) * cos(2 * PI / lines * i));
//			glVertex2f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i));
//			glEnd();
//		}
//		else
//		{
//			glLineWidth(2);  //�����Ŀ̶�
//			//glColor3f(0.0, 0.0, 1.0);
//			glBegin(GL_LINES);
//			glVertex2f(cx + (R - ship2) * sin(2 * PI / lines * i), cy + (R - ship2) * cos(2 * PI / lines * i));
//			glVertex2f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i));
//			glEnd();
//		}
//	}
//
//	// 3 ����ʱ �� ���ϵ����ĵ�С�ڵ�
//	glBegin(GL_POLYGON);
//	for (i = 0; i < n; ++i)
//		glVertex2i(cx + 5 * cos(2 * PI / n * i), cy + 5 * sin(2 * PI / n * i));
//	glEnd();
//
//	// 4 ����ʱ �� ���룬����ֱ�ߣ����̴�ϸ��һ��
//	int h_len = R - 3 * ship1;
//	int m_len = R - ship1;
//	int s_len = R - ship1 + 2 * ship1;
//
//	float s_Angle = s / 60.0;
//	float m_Angle = (m * 60 + s) / 3600.0;
//	float h2 = h >= 12 ? (h - 12) : h;
//	float h_Angle = (h2 * 60 * 60 + m * 60 + s) / (12 * 60 * 60);
//
//	glLineWidth(1); // ��
//	glBegin(GL_LINES);
//	glVertex2f(cx - 2 * ship1 * sin(2 * PI * s_Angle), cy - 2 * ship1 * cos(2 * PI * s_Angle));
//	glVertex2f(cx + (R - ship2) * sin(2 * PI * s_Angle), cy + (R - ship2) * cos(2 * PI * s_Angle));
//	glEnd();
//
//	glLineWidth(5); // ʱ
//	glBegin(GL_LINES);
//	glVertex2f(cx, cy);
//	glVertex2f(cx + h_len * sin(2 * PI * h_Angle), cy + h_len * cos(2 * PI * h_Angle));
//	glEnd();
//
//	glLineWidth(3); // ��
//	glBegin(GL_LINES);
//	glVertex2f(cx, cy);
//	glVertex2f(cx + m_len * sin(2 * PI * m_Angle), cy + m_len * cos(2 * PI * m_Angle));
//	glEnd();
//
//	// ˢ��
//	glFlush();
//}
//
///*
//�ص�����
//*/
//void timerFunc(int value)
//{
//	s += 1;
//	int carry1 = 0;
//	if (s >= 60)
//	{
//		s = 0;
//		carry1 = 1;
//	}
//	m += carry1;
//	int carry2 = 0;
//	if (m >= 60)
//	{
//		m = 0;
//		carry2 = 1;
//	}
//	h += carry2;
//	if (h >= 24)
//		h = 0;
//
//	glutPostRedisplay(); // �ػ�
//
//	glutTimerFunc(1000, timerFunc, 1); // ÿһ����ִ��һ��
//}
//
///*
//��ʼ������
//���ñ�������ȡʱ��
//*/
//void SetupRC(void)
//{
//	// ���ô���Ϊ��ɫ
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//	// ��ȡ���ص�ǰʱ��
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	h = sys.wHour;
//	m = sys.wMinute;
//	s = sys.wSecond;
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	//���ô������Ͻǵ�λ��  
//	//glutInitWindowPosition(100, 100);
//	//���ô��ڵĿ��  
//	glutInitWindowSize(Width, Height);
//
//	glutCreateWindow("ʱ�ӳ���");
//
//	//�۲������x����ֵ��0��200��y�Ǵ�0��150  
//	gluOrtho2D(0.0, Width, 0.0, Height);
//
//	SetupRC();
//
//	glutDisplayFunc(&myDisplay);
//	glutTimerFunc(1000, timerFunc, 1);
//
//	glutMainLoop(); // glut�¼�����ѭ��
//
//	return 0;
//}