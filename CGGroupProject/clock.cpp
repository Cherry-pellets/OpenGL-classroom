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
//// 当前时间，时 分 秒
//float h = 0.0f;
//float m = 0.0f;
//float s = 0.0f;
//
///*
//画时钟的函数
//*/
//void myDisplay(void)
//{
//	// 用当前清除色清除颜色缓冲区，即设定窗口的背景色
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(0.1f, 0.2f, 0.1f); // 黑色
//
//
//	// 1 绘制外围同心圆
//	int cx = 600; Width / 2; //中心点
//	int cy = 400;// Height / 2;
//	int R = 50; // 半径长
//	int n = 50;
//	int i;
//
//	glBegin(GL_LINE_LOOP); // 绘制多边形，n足够大就会变成圆形
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
//	// 2 绘制时钟 圆上的刻度，刻度粗细，长度不一样
//	int lines = 60;
//	float ship1 = 10;
//	float ship2 = 5;
//	for (i = 0; i < lines; i++)
//	{
//		if (i % 5 == 0)    //  0（12）-11的短线
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
//			glLineWidth(2);  //其他的刻度
//			//glColor3f(0.0, 0.0, 1.0);
//			glBegin(GL_LINES);
//			glVertex2f(cx + (R - ship2) * sin(2 * PI / lines * i), cy + (R - ship2) * cos(2 * PI / lines * i));
//			glVertex2f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i));
//			glEnd();
//		}
//	}
//
//	// 3 绘制时 分 秒结合的中心的小黑点
//	glBegin(GL_POLYGON);
//	for (i = 0; i < n; ++i)
//		glVertex2i(cx + 5 * cos(2 * PI / n * i), cy + 5 * sin(2 * PI / n * i));
//	glEnd();
//
//	// 4 绘制时 分 秒针，三条直线，长短粗细不一样
//	int h_len = R - 3 * ship1;
//	int m_len = R - ship1;
//	int s_len = R - ship1 + 2 * ship1;
//
//	float s_Angle = s / 60.0;
//	float m_Angle = (m * 60 + s) / 3600.0;
//	float h2 = h >= 12 ? (h - 12) : h;
//	float h_Angle = (h2 * 60 * 60 + m * 60 + s) / (12 * 60 * 60);
//
//	glLineWidth(1); // 秒
//	glBegin(GL_LINES);
//	glVertex2f(cx - 2 * ship1 * sin(2 * PI * s_Angle), cy - 2 * ship1 * cos(2 * PI * s_Angle));
//	glVertex2f(cx + (R - ship2) * sin(2 * PI * s_Angle), cy + (R - ship2) * cos(2 * PI * s_Angle));
//	glEnd();
//
//	glLineWidth(5); // 时
//	glBegin(GL_LINES);
//	glVertex2f(cx, cy);
//	glVertex2f(cx + h_len * sin(2 * PI * h_Angle), cy + h_len * cos(2 * PI * h_Angle));
//	glEnd();
//
//	glLineWidth(3); // 分
//	glBegin(GL_LINES);
//	glVertex2f(cx, cy);
//	glVertex2f(cx + m_len * sin(2 * PI * m_Angle), cy + m_len * cos(2 * PI * m_Angle));
//	glEnd();
//
//	// 刷新
//	glFlush();
//}
//
///*
//回调函数
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
//	glutPostRedisplay(); // 重画
//
//	glutTimerFunc(1000, timerFunc, 1); // 每一秒中执行一次
//}
//
///*
//初始化函数
//设置背景，获取时间
//*/
//void SetupRC(void)
//{
//	// 设置窗口为白色
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//	// 获取本地当前时间
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
//	//设置窗口左上角的位置  
//	//glutInitWindowPosition(100, 100);
//	//设置窗口的宽高  
//	glutInitWindowSize(Width, Height);
//
//	glutCreateWindow("时钟程序");
//
//	//观察参数：x坐标值从0到200，y是从0到150  
//	gluOrtho2D(0.0, Width, 0.0, Height);
//
//	SetupRC();
//
//	glutDisplayFunc(&myDisplay);
//	glutTimerFunc(1000, timerFunc, 1);
//
//	glutMainLoop(); // glut事件处理循环
//
//	return 0;
//}