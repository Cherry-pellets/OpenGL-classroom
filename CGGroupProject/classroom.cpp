//#include<gl/glut.h>
//#include<windows.h>
//#include<math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<time.h>
//#pragma warning(disable:4996)
///*******************************������������õĳ�������******************************************/
//GLfloat light_position1[] = { 0,28,0,1.0 };
//GLfloat model_ambient[] = { 0.05f,0.05f,0.05f,1.0f };
//GLfloat mat_specular[] = { 0.8,1.0,1.0,1.0 };
//GLfloat mat_shininess[] = { 5.0 };
//GLfloat mat_ambient[] = { 0.1,0.1,0.1,1 };
//GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
//GLfloat light[] = { 1.0,1.0,1.0,1 };
//GLfloat light_position0[] = { 0,28,20,1.0 };
//GLfloat light_Diffuse[] = { 1.0f, 1.0f, 0.45f, 1.0f };//{0.1,0.1,0.1,0.1};
//GLfloat	no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//GLfloat	mat_diffuse1[] = { 1.0f, 1.0f, 1.0f, 1.0f };//{ 0.1f, 0.5f, 0.8f, 1.0f };
//GLfloat	no_shininess[] = { 0.0f };
//GLfloat sound[] = { 0.9,0.9,0.9,1 };
//GLint	WinWidth;
//GLint	WinHeight;
//
//GLUquadricObj* qobj;
//int           fantheta = 0;
//BOOL          TurnOn = FALSE;
//
//// ��ǰʱ�䣬ʱ �� ��
//float h = 0.0f;
//float m = 0.0f;
//float s = 0.0f;
//const GLfloat PI = 3.141592653f;
///************************�����ӵ�ṹ*********************************************************/
//typedef struct EyePoint
//{
//	GLfloat	x;
//	GLfloat y;
//	GLfloat z;
//}EyePoint;
//EyePoint 	myEye;
//EyePoint    vPoint;
//EyePoint    up;
//GLfloat pro_up_down = 29.0f;//ͶӰ��
//GLfloat vAngle = 0;
///****************************����λͼ��Ϊ�������غ���************************************/
//#define BMP_Header_Length 54
////void grab(void)
////
////{
////	//BMP�ļ�������һ�֡��� �롱�Ļ��ƣ�ÿһ���������ݵĳ���������4�ı����������һЩ����ʹ����4�ı���
////	//Windows ��ʹ�õ�BMP�ļ����ڿ�ʼ����һ���ļ�ͷ����СΪ54�ֽڡ������˰����ļ���ʽ��ʶ����ɫ����ͼ���С��ѹ����ʽ����Ϣ
////	//��һ����ȷ��BMP�ļ��ж�ȡǰ54���ֽڣ��޸����еĿ�Ⱥ͸߶���Ϣ���Ϳ��Եõ��µ��ļ�ͷ
////	FILE* pDummyFile; FILE* pWritingFile;
////	GLubyte* pPixelData;
////	GLubyte BMP_Header[BMP_Header_Length];
////	GLint    i, j;
////	GLint    PixelDataLength;
////	// �����������ݵ�ʵ�ʳ���
////
////	i = WinWidth * 3;  // �õ�ÿһ�е��������ݳ���
////	//ÿ�����ݳ��ȴ���Ϊͼ���ȳ���ÿ���ص��ֽ���
////	while (i % 4 != 0)      // �������ݣ�ֱ�� i ��4�ı���
////		++i;	                      // �������и�����㷨��
////	PixelDataLength = i * WinHeight;// �������׷��ֱ�ۣ����ٶ�û��̫��Ҫ��
////	//�����ܳ�=ÿ�г���*ͼ��߶�
////	pPixelData = (GLubyte*)malloc(PixelDataLength);// �����ڴ�ʹ��ļ��������������
////	if (pPixelData == 0)
////		exit(0);
////	pDummyFile = fopen("dummy.bmp", "rb");
////	if (pDummyFile == 0)
////		exit(0);
////	pWritingFile = fopen("grab.bmp", "wb");
////	if (pWritingFile == 0)
////		exit(0);
////	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);//���������ֽں���������BMP�ļ��С����롱������Ӱ�죬4�ֽڶ���
////	glReadPixels(0, 0, WinWidth, WinHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);
////	/* �� dummy.bmp ���ļ�ͷ����Ϊ���ļ����ļ�ͷ
////	glReadPixels��ȡ���غ�����һ����������ʾ���ε����½Ǻ������꣬���ĸ�������ʾ���еĿ�Ⱥ͸߶ȣ�
////	GL_BGR_EXT���ζ�ȡ���ص������̡�������(��Ϊ��bmp�ļ�)��GL_UNSIGNED_BYTE��Ѷ�ȡ�ĸ������ݱ���
////	���ڴ�ʱ����ΪΪGLubyte��pPixelData��ʾһ��ָ�룬�������ݱ���ȡ�󣬽������浽���ָ������ʾ�ĵ�ַ��*/
////
////	//�Ѷ����bmp�ļ����ļ�ͷ����Ϣͷ���ݸ��ƣ����޸Ŀ������
////	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);//��ȡdummy.bmp�е�ͷ54���ֽڵ�����
////	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);//����������д�뵽�µ�BMP�ļ�
////	fseek(pWritingFile, 0x0012, SEEK_SET);/*�ƶ���0x0012λ�ã�SEEK_SET:�ļ���ͷ,
////	��Ϊͼ��Ŀ�ȵĵ�ַ��0x0012,�߶���0x0016*/
////	i = WinWidth;
////	j = WinHeight;
////	fwrite(&i, sizeof(i), 1, pWritingFile);
////	fwrite(&j, sizeof(j), 1, pWritingFile);//�޸����еĴ�С��Ϣ
////	fseek(pWritingFile, 0, SEEK_END);//�ƶ����ļ�ĩβ��
////	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);//��������bmp�ļ�����д��
////	fclose(pDummyFile); fclose(pWritingFile); free(pPixelData);
////}
//
////�ж�һ�����Ƿ���2�������η�
//int power_of_two(int n)
//{
//	if (n <= 0)
//		return 0;
//	return (n & (n - 1)) == 0;
//}
///****************************����һ��λͼ��Ϊ�������ص���������**********************************************/
//GLuint load_texture(const char* file_name)
//{
//	/*��BMP�ļ�����ȡ���еĸ߶ȺͿ����Ϣ����������������ռ���ֽ�����
//	Ϊ�������ݷ���ռ䡢��ȡ������ �ݡ�������ͼ��������ţ������Ҫ�Ļ�����
//	�����µ������š���д�����������������*/
//	GLint width, height, total_bytes;
//	GLubyte* pixels = 0;//����
//	GLint last_texture_ID = 0;
//	GLuint texture_ID = 0;
//	// ���ļ������ʧ�ܣ�����
//	FILE* pFile = fopen(file_name, "rb");
//	if (pFile == 0) {
//		//printf("error\n");
//		return 0;
//	}
//
//	// ��ȡ�ļ���ͼ��Ŀ�Ⱥ͸߶�
//	fseek(pFile, 0x0012, SEEK_SET);
//	fread(&width, 4, 1, pFile);
//	fread(&height, 4, 1, pFile);
//	fseek(pFile, BMP_Header_Length, SEEK_SET);
//	// ����ÿ��������ռ�ֽ����������ݴ����ݼ����������ֽ���
//	{
//		GLint line_bytes = width * 3;
//		while (line_bytes % 4 != 0)
//			++line_bytes;
//		total_bytes = line_bytes * height;
//	}
//	// �����������ֽ��������ڴ�
//	pixels = (GLubyte*)malloc(total_bytes);
//	if (pixels == 0)
//	{
//		fclose(pFile);
//		return 0;
//	}
//	// ��ȡ��������
//	if (fread(pixels, total_bytes, 1, pFile) <= 0)
//	{
//		free(pixels);
//		fclose(pFile);
//		return 0;
//	}
//	// �ھɰ汾�� OpenGL ��
//	// ���ͼ��Ŀ�Ⱥ͸߶Ȳ���2�������η�������Ҫ��������
//	// ���ﲢû�м�� OpenGL �汾�����ڶ԰汾�����ԵĿ��ǣ����ɰ汾����
//	// ���⣬�����Ǿɰ汾�����°汾��
//	// ��ͼ��Ŀ�Ⱥ͸߶ȳ�����ǰ OpenGL ʵ����֧�ֵ����ֵʱ��ҲҪ��������
//	{
//		GLint max;
//		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);//���OpenGL��֧�ֵ��������
//
//		if (!power_of_two(width) || !power_of_two(height) || width > max || height > max)
//		{
//			const GLint new_width = 256;
//			const GLint new_height = 256; // �涨���ź��µĴ�СΪ�߳���������
//			GLint new_line_bytes, new_total_bytes;
//			GLubyte* new_pixels = 0;
//			// ����ÿ����Ҫ���ֽ��������ֽ���
//			new_line_bytes = new_width * 3;
//			while (new_line_bytes % 4 != 0)
//				++new_line_bytes;
//			new_total_bytes = new_line_bytes * new_height;
//			// �����ڴ�
//			new_pixels = (GLubyte*)malloc(new_total_bytes);
//			if (new_pixels == 0)
//			{
//				free(pixels);
//				fclose(pFile);
//				return 0;
//			}
//			// ������������
//			gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels, new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);
//			// �ͷ�ԭ�����������ݣ��� pixels ָ���µ��������ݣ����������� width �� height
//			free(pixels);
//			pixels = new_pixels;
//			width = new_width;
//			height = new_height;
//		}
//	}
//	// ����һ���µ�������
//	glGenTextures(1, &texture_ID);
//	if (texture_ID == 0)
//	{
//		free(pixels);
//		fclose(pFile);
//		return 0;
//	}
//	// ���µ������������������������
//	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID);//�Ȼ��ԭ���󶨵������ţ��Ա��������лָ�
//	glBindTexture(GL_TEXTURE_2D, texture_ID);//��һ������������󶨵�һ������Ŀ����
//
//	/*������˺�����GL_TEXTURE_2D��ʾ����2D�����ڶ�������ָ����Ӧ��ģʽ
//	GL_TEXTURE_WRAP_S��S�����ϵ���ͼģʽ��GL_TEXTURE_WRAP_T��T�����ϵ���ͼģʽ
//	GL_TEXTURE_MAG_FILTER���Ŵ���ˣ�TEXTURE_MIN_FILTER����С���ˣ�
//	����������ָ��Ӧģʽ�ķ�����GL_LINEAR�����Թ���, ʹ�þ��뵱ǰ��Ⱦ�������������4�����ؼ�Ȩƽ��ֵ��
//	�ٶȽ����޾�ݣ�GL_REPEAT���ظ��߽������*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//		/*������������ʵ��ںϷ�ʽ��������ֻ������������ģ�͵Ĳ���*/
//		//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//
//		/*��������һ����ά��������һ��0����ͼ�����ϸ�̶ȣ��ڶ���0����
//		�߿��ֵ��GL_BGR_EXT����OpenGLͼ�������������̡�����ɫ������ɣ�pixels�������ݵ���Դ*/
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
//
//	glBindTexture(GL_TEXTURE_2D, last_texture_ID);
//	// ֮ǰΪ pixels ������ڴ����ʹ�� glTexImage2D �Ժ��ͷ�
//	// ��Ϊ��ʱ���������Ѿ��� OpenGL ���б�����һ�ݣ����ܱ����浽ר�ŵ�ͼ��Ӳ���У�
//	free(pixels);
//	return texture_ID;
//}
///**********************************�������������������************************************/
//GLuint texblackboard, texwindow, texdesk, texsound;
//GLuint texceiling, texdoor, texfloor, texbackwall, texpole;
//GLuint texairfro, texairback, texhighland, texsdesk, texclock;
///*******************************������غ���**************************************************/
//
////���ƽ�������󳡾�
//void drawscence()
//{
//	//���ò�����ز���
//	/*ָ�����ʶ������ķ����ʣ���һ�����������ò���������ͼԪ�����滹�Ƿ���
//	�ڶ���������ʾ�Ժ��ֹ�������ã�GL_AMBIENT(������)��GL_DIFFUSE(�����)��
//	GL_AMBIENT_AND_DIFFUSE(������������)��GL_SPECULAR(ƽ��/����⣬
//	������������һ����ά���飬������������˷����ʵ�RGBAֵ��ÿһ��ȡֵ��Ϊ0-1֮��*/
//	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
//	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
//	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
//
//	//���Ȼ����컨��
//	glEnable(GL_TEXTURE_2D);//����2D������
//
//	glBindTexture(GL_TEXTURE_2D, texceiling);//������
//	//glColor3f(0.3, 0.3, 0.3);//������ɫ����ɫ
//	//glColor3f(255, 255, 255);
//	glBegin(GL_QUADS);//���ı���
//
//	glNormal3f(0.0f, -1.0f, 0.0f);//���ڶ��巨������
//	/*glTexCoord2f����ͼ��ʱָ����������꣬��һ����X�����꣬0.0���������࣬0.5��������е㣬1.0��������Ҳ࣬
//	�ڶ�����Y�����꣬0.0������ĵײ���0.5��������е㣬1.0������Ķ�����
//	Ϊ�˽�������ȷ��ӳ�䵽�ı����ϣ������뽫��������Ͻ�ӳ�䵽�ı��ε����Ͻǣ���������Ͻ�ӳ�䵽�ı��ε����Ͻǣ�
//	��������½�ӳ�䵽�ı��ε����½ǣ���������½�ӳ�䵽�ı��ε����½ǣ����������������X��0.0��Y��1.0f���ı��ε����϶�����X��-1.0��Y��1.0��*/
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, 30.0f, 30.0f);//�ı��εĵ�
//	glTexCoord2f(0.0f, 3.0f); glVertex3f(-40.0f, 30.0f, -30.0f);
//	glTexCoord2f(6.0f, 3.0f); glVertex3f(40.0f, 30.0f, -30.0f);
//	glTexCoord2f(6.0f, 0.0f); glVertex3f(40.0f, 30.0f, 30.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//
//	//................................����................................................//
//	GLuint m = 0;
//
//
//	qobj = gluNewQuadric();//��ʼ���������沢����һ��ָ����������ָ�� 
//
////...............................�ұߵķ���.............................//
//	glPushMatrix();//ѹ���ջ����֤�˴�����任��Ӱ���ⲿ�󻷾� 
//	glTranslatef(20.0, 5.0, -10.0 - 40 * m);  //���ȵ�λ��
//	if (TurnOn == TRUE)  //���TurnOnΪ1
//	{
//		fantheta += 10;  //����ת���ĽǶ�fantheta��������
//
//
//	}
//	glRotatef(fantheta, 0, 1, 0);        //������ת
//
////..........�����м�ı�Բ��....................//
//
//	glPushMatrix();//ѹ���ջ
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0.0, 20.0, 0.0);//ƽ�Ʊ任
//	glScalef(1, 0.3, 1);//���ű任
//	gluSphere(qobj, 2, 20, 20);//����һ���뾶Ϊ2������
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);//������ʹ���
//	glPopMatrix();//������ջ
////............������ת120�ȵ���Ҷ...............//	
//
//	glPushMatrix();//ѹ���ջ
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0, 20, 0.0);//ƽ�Ʊ任
//	glScalef(1, 0.05, 1);//���ű任
//	glRotatef(120, 0, 1, 0);//��y����ת120��
//	gluCylinder(qobj, 1, 3, 10, 20, 20);//����һ������Բ�뾶Ϊ1������Բ�뾶Ϊ2����Ϊ10��Բ׶��
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);//������ʹ���
//	glPopMatrix();//������ջ
////............���Ȳ�����ת����Ҷ.................//
//
//	glPushMatrix();//ѹ���ջ
//	glColor3f(0.7, 0.7, 0.7);
//
//	glTranslatef(0, 20, 0.0);//ƽ�Ʊ任
//	glScalef(1, 0.05, 1);//���ű任
//	gluCylinder(qobj, 1, 3, 10, 20, 20);//����һ������Բ�뾶Ϊ1������Բ�뾶Ϊ2����Ϊ10��Բ׶��
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);//������ʹ���
//	glPopMatrix();//������ջ
////.............������ת240�ȵ���Ҷ...............//
//
//	glPushMatrix();//ѹ���ջ
//	glColor3f(0.7, 0.7, 0.7);
//
//	glTranslatef(0, 20, 0.0);//ƽ�Ʊ任
//	glScalef(1, 0.05, 1);//���ű任
//	glRotatef(240, 0, 1, 0);//��y����ת240��	
//	gluCylinder(qobj, 1, 3, 10, 20, 20);//����һ������Բ�뾶Ϊ1������Բ�뾶Ϊ2����Ϊ10��Բ׶��
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);//������ʹ���
//	glPopMatrix();//������ջ
////.............���ȵĸ�...........................//
//
//	glPushMatrix();//ѹ���ջ
//	glTranslatef(0, 33, 0.0);//ƽ�Ʊ任
//	glRotatef(90, 1, 0, 0);//���ű任
//	gluCylinder(qobj, 0.5, 0.5, 13, 10, 10);//����һ���뾶Ϊ0.5����Ϊ13��Բ׶��
//	glPopMatrix();//������ջ
//
//	glPopMatrix();//������ջ
//
////................��ߵķ���...........................................//
//
//	glPushMatrix();
//	glTranslatef(-20.0, 5.0, -10.0 - 40 * m);
//	if (TurnOn == TRUE)
//	{
//		fantheta += 10;
//		
//
//	}
//
//	glRotatef(fantheta, 0, 1, 0);
//	//..........�����м�ı�Բ��....................//
//
//	glPushMatrix();//�����м�ı�Բ��
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0.0, 20.0, 0.0);
//	glScalef(1, 0.3, 1);
//	gluSphere(qobj, 2, 20, 20);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);
//	glPopMatrix();
//	//............������ת120�ȵ���Ҷ...............//		
//
//	glPushMatrix();//������ת120�ȵ���Ҷ
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0, 20, 0.0);
//	glScalef(1, 0.05, 1);
//	glRotatef(120, 0, 1, 0);
//	gluCylinder(qobj, 1, 3, 10, 20, 20);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);
//	glPopMatrix();
//	//............���Ȳ�����ת����Ҷ.................//
//
//	glPushMatrix();//���Ȳ�����ת����Ҷ
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0, 20, 0.0);
//	glScalef(1, 0.05, 1);
//	gluCylinder(qobj, 1, 3, 10, 20, 20);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);
//	glPopMatrix();
//	//.............������ת240�ȵ���Ҷ...............//
//
//	glPushMatrix();//������ת240�ȵ���Ҷ
//	glColor3f(0.7, 0.7, 0.7);
//	glTranslatef(0, 20, 0.0);
//	glScalef(1, 0.05, 1);
//	glRotatef(240, 0, 1, 0);
//	gluCylinder(qobj, 1, 3, 10, 20, 20);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, light_Diffuse);
//	glPopMatrix();
//	//.............���ȵĸ�...........................//
//
//	glPushMatrix();
//	glTranslatef(0, 33, 0.0);
//	glRotatef(90, 1, 0, 0);
//	gluCylinder(qobj, 0.5, 0.5, 13, 10, 10);
//	glPopMatrix();
//	glPopMatrix();
//
//
//
//
//	//���Ƶذ�
//	glColor3f(0.8f, 1.0f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f);	                  //���ڶ��巨������
//	glVertex3f(-40.0f, 0.0f, 30.0f);
//	glVertex3f(-40.0f, 0.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, 30.0f);
//	glEnd();
//
//	//�������ǽ����ߴ���
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(1.0f, 0.0f, 0.0f);	                  //���ڶ��巨������
//	glVertex3f(-40.0f, 0.0f, 30.0f);
//	glVertex3f(-40.0f, 30.0f, 30.0f);
//	glVertex3f(-40.0f, 30.0f, -30.0f);
//	glVertex3f(-40.0f, 0.0f, -30.0f);
//	glEnd();
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texwindow);
//	for (int n = 0; n <= 1; n++)
//	{
//		glBegin(GL_QUADS);
//		glNormal3f(1.0, 0.0f, 0.0f);	                  //���ڶ��巨������
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-39.9, 10, -8 + n * 18);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-39.9, 20, -8 + n * 18);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-39.9, 20, -18 + n * 18);
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-39.9, 10, -18 + n * 18);
//		glEnd();
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	//�����ұ�ǽ���ұߴ���
//	glColor3f(0.8f, 0.8f, 0.8f);
//	//glColor3f(255, 255, 255);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0f, 0.0f, 0.0f); //���ڶ��巨������
//	glVertex3f(40.0f, 0.0f, 30.0f);
//	glVertex3f(40.0f, 30.0f, 30.0f);
//	glVertex3f(40.0f, 30.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, -30.0f);
//	glEnd();
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texwindow);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0, 0.0f, 0.0f);	                  //���ڶ��巨������
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(39.5, 10, 10);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(39.5, 20, 10);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(39.5, 20, 0);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(39.5, 10, 0);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//���ƺ��ǽ
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texbackwall);
//	glColor3f(0.8f, 0.8f, 0.8f);
//	//glColor3f(255, 255, 255);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, 0.0f, 30.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 30.0f, 30.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 30.0f, 30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, 0.0f, 30.0f);
//	glEnd();
//
//	//����ǰ��ǽ
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texbackwall);
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, 0.0f, -30.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 30.0f, -30.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 30.0f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, 0.0f, -30.0f);
//	glEnd();
//
//	//����
//	glBindTexture(GL_TEXTURE_2D, texclock);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(23.0f, 18.0f, -29.8f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(23.0f, 20.0f, -29.8f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(25.0f, 20.0f, -29.8f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(25.0f, 18.0f, -29.8f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//
//
//
//
//
//	//���ƿյ����յ�������
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texairfro);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(33.0f, 0.0f, -26.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(33.0f, 15.0f, -26.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(37.0f, 15.0f, -26.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(37.0f, 0.0f, -26.0f);
//	glEnd();
//	glBindTexture(GL_TEXTURE_2D, texairback);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0f, 0.0f, 0.0f);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(33.0f, 0.0f, -26.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(33.0f, 15.0f, -26.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(33.0f, 15.0f, -29.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(33.0f, 0.0f, -29.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//���ƽ�������ʯ��ǰ������
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texpole);
//	for (int i = 0; i <= 1; i++)
//	{
//		glColor3f(1.0f, 1.0f, 1.0f);
//		//glColor3f(255, 255, 255);
//		//ʯ���ϱ���
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, -1.0f, 0.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0f + i * 78, 30.0f, -4.0f);
//		glEnd();
//		//ʯ��ǰ����
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 0.0f, -4.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 78, 0.0f, -4.0f);
//		glEnd();
//		//ʯ�������
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 0.0f, -6.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 78, 0.0f, -6.0f);
//		glEnd();
//		//ʯ���ұ���
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-38.0 + i * 76, 0.0f, -4.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0 + i * 76, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 76, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 76, 0.0f, -6.0f);
//		glEnd();
//	}
//	//���ƽ�������ʯ�����������
//	for (int j = 0; j <= 1; j++)
//	{
//
//		glColor3f(1.0f, 1.0f, 1.0f);
//		//glColor3f(255, 255, 255);
//		//ʯ���ϱ���
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, -1.0f, 0.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0f + j * 78, 30.0f, 14.0f);
//		glEnd();
//		//ʯ��ǰ����
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 0.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 78, 0.0f, 14.0f);
//		glEnd();
//		//ʯ�������
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 0.0f, 12.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 78, 0.0f, 12.0f);
//		glEnd();
//		//�ұ���
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //���ڶ��巨������
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-38.0 + j * 76, 0.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0 + j * 76, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 76, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 76, 0.0f, 12.0f);
//		glEnd();
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	//���ƺڰ�
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texblackboard);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-20.0, 8.0f, -29.9f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-20.0, 18.0f, -29.9f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 18.0f, -29.9f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 8.0f, -29.9f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//���ڰ��Ϸ��ĵ�
//	GLfloat blacklight[] = { 0.9,0.9,0.9,1 };//��ɫ(R,G,B,A),A��������ɫ��Ϻ�������֮��
//	glColor3f(1.0f, 1.0f, 1.0f);
//	//glColor3f(255, 255, 255);
//	glPushMatrix();//�ѵ�ǰ��ģ����ͼ����ѹ���ջ�б�������
//	glTranslatef(-15, 20.4, -29.5);//ƽ�ƺ������������壺λ��
//	glScalef(8.0f, 0.8, 1.0f);//���ź������������壺����
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blacklight);
//	glutSolidCube(1.0f);//���Ʊ߳�Ϊ1��ʵ�������壬�����������λ��ԭ��
//	glPopMatrix();
//	glPushMatrix();
//	glTranslatef(12, 20.4, -29.5);
//	glScalef(8.0f, 0.8, 1.0f);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blacklight);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//	//���ƽ���ǰ��һ��ߵز�������
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texhighland);
//	//������
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glEnd();
//	//�����
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-30.0f, 0, -30.0f);
//	glEnd();
//	//��ǰ��
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 0, -22.0f);
//	glEnd();
//	//���ұ�
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 0, -30.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//	//���ƽ�̨
//	//����̨����
//	glBindTexture(GL_TEXTURE_2D, texsdesk);
//	glEnable(GL_TEXTURE_2D);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 1.5f, -24.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -28.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 1.5f, -28.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -28.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -28.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -26.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -26.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glEnd();
//	//����
//	glColor3f(0.521f, 0.121f, 0.0547f);
//	//glColor3f(255, 255, 255);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texdoor);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0f, 0.0f, 0.0f); //���ڶ��巨������
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(39.9f, 0.0f, -25.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(39.9f, 14.0f, -25.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(39.9f, 14.0f, -19.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(39.9f, 0.0f, -19.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//	//��������
//	glColor3f(0.0f, 0.0f, 0.0f);
//	//glColor3f(255, 255, 255);
//	glPushMatrix();
//	glTranslatef(-37.5, 26.25f, -5.5f);
//	glScalef(1.0f, 1.5f, 1.0f);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sound);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslatef(37.5, 26.25f, -5.5f);
//	glScalef(1.0f, 1.5f, 1.0f);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sound);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//
//
//
//}
///**************************************����ͶӰ��***********************************************/
//void drawprojector()
//{
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(1.0f, 0.0f, 1.0f); //���ڶ��巨������
//	glVertex3f(-40.0f, 30.0f, -30.0 + 10 * sqrt(2));
//	glVertex3f(-40.0 + 10 * sqrt(2), 30.0f, -30.0f);//�̶���������
//	glVertex3f(-40.0 + 10 * sqrt(2), pro_up_down, -30.0f);
//	glVertex3f(-40.0f, pro_up_down, -30.0 + 10 * sqrt(2));//�½�������ʱ�ı�ĵ�
//	glEnd();
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glLineWidth(4.0f);
//	glBegin(GL_LINES);
//	glVertex3f(-25.0f, 30.0f, -15.0f);
//	glVertex3f(-25.0f, 25.0f, -15.0f);
//	glEnd();
//	glColor3f(0.5f, 0.5f, 0.5f);
//	glPushMatrix();
//	glTranslatef(-25.0f, 24.0f, -15.0f);
//	glScalef(4.0f, 2.0f, 2.0f);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//	glColor3f(0.0, 0.0, 0.0);
//	glBegin(GL_LINE_LOOP);//�����ĵ�����Ϊһ���������еĵ���β��ӣ�
//	glVertex3f(-40.0f, 30.0f, -30.0 + 10 * sqrt(2));
//	glVertex3f(-40.0 + 10 * sqrt(2), 30.0f, -30.0f);
//	glVertex3f(-40.0 + 10 * sqrt(2), pro_up_down, -30.0f);
//	glVertex3f(-40.0f, pro_up_down, -30.0 + 10 * sqrt(2));
//	glEnd();
//
//}
//void drawClock() {
//	//ʱ��
//	// �õ�ǰ���ɫ�����ɫ�����������趨���ڵı���ɫ
//	//glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f); // ��ɫ
//	// 1 ������Χͬ��Բ
//	glPushMatrix();
//	float cx = 23.5;//Width / 2; //���ĵ�
//	float cy = 18.5;//Height / 2;
//	int cz = -29.8;
//	float R = 1.0; // �뾶��
//	int n = 100;
//	int i;
//
//	//glLineWidth(0);
//	//glBegin(GL_LINE_LOOP); // ���ƶ���Σ�n�㹻��ͻ���Բ��
//	//for (i = 0; i < n; i++)
//	//{
//	//	glVertex3f(cx + (R)*cos(2 * PI / n * i), cy + (R)*sin(2 * PI / n * i), cz);
//	//}
//	//glEnd();
//	//glLineWidth(0);
//	//glBegin(GL_LINE_LOOP);
//	//for (i = 0; i < n; i++)
//	//{
//	//	//glVertex2f(cx + R*cos(2 * PI / n * i), cy + R*sin(2 * PI / n * i));
//	//	glVertex3f(cx + (R - 0.2) * cos(2 * PI / n * i), cy + (R - 0.2) * sin(2 * PI / n * i), cz);
//	//}
//	//glEnd();
//
//
//	//// 2 ����ʱ�� Բ�ϵĿ̶ȣ��̶ȴ�ϸ�����Ȳ�һ��
//	int lines = 60;
//	float ship1 = 1;// 10;
//	float ship2 = 0.5;// 5;
//	//for (i = 0; i < lines; i++)
//	//{
//	//	if (i % 5 == 0)    //  0��12��-11�Ķ���
//	//	{
//	//		glLineWidth(0.5);
//	//		//glColor3f(0.0, 1.0, 0.0);
//	//		glBegin(GL_LINES);
//	//		glVertex3f(cx + (R - 0.8 * ship1) * sin(2 * PI / lines * i), cy + (R - 0.8 * ship1) * cos(2 * PI / lines * i), cz);
//	//		glVertex3f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i), cz);
//	//		glEnd();
//	//	}
//	//	else
//	//	{
//	//		glLineWidth(0.3);  //�����Ŀ̶�
//	//		//glColor3f(0.0, 0.0, 1.0);
//	//		glBegin(GL_LINES);
//	//		glVertex3f(cx + (R - ship2) * sin(2 * PI / lines * i), cy + (R - ship2) * cos(2 * PI / lines * i), cz);
//	//		glVertex3f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i), cz);
//	//		glEnd();
//	//	}
//	//}
//
//	// 3 ����ʱ �� ���ϵ����ĵ�С�ڵ�
//	/*glBegin(GL_POLYGON);
//	for (i = 0; i < n; ++i)
//		glVertex3i(cx + 5 * cos(2 * PI / n * i)-15, cy + 5 * sin(2 * PI / n * i)-15,cz);
//	glEnd();*/
//
//	// 4 ����ʱ �� ���룬����ֱ�ߣ����̴�ϸ��һ��
//	float h_len = 0.3;// R - 5 * ship1;
//	float m_len = 0.6;// R - 3 * ship1;
//	float s_len = 2;//R - 3*ship1 + 2 * ship1;
//
//	float s_Angle = s / 60.0;
//	float m_Angle = (m * 60 + s) / 3600.0;
//	float h2 = h >= 12 ? (h - 12) : h;
//	float h_Angle = (h2 * 60 * 60 + m * 60 + s) / (12 * 60 * 60);
//
//	glLineWidth(1); // ��
//	glBegin(GL_LINES);
//	glVertex3f(24, 19, -29.8);
//	//glVertex3f(cx - ship1 * sin(2 * PI * s_Angle), cy - ship1 * cos(2 * PI * s_Angle), cz);
//	glVertex3f(24 + 1.2 * (R - ship2) * sin(2 * PI * s_Angle), 19 + 1.2 * (R - ship2) * cos(2 * PI * s_Angle), -29.7);
//	glEnd();
//
//	glLineWidth(3); // ʱ
//	glBegin(GL_LINES);
//	glVertex3f(24, 19, -29.8);
//	glVertex3f(24 + h_len * sin(2 * PI * h_Angle), 19 + h_len * cos(2 * PI * h_Angle), -29.7);
//	glEnd();
//
//	glLineWidth(2); // ��
//	glBegin(GL_LINES);
//	glVertex3f(24, 19, -29.8);
//	glVertex3f(24 + 0.8 * m_len * sin(2 * PI * m_Angle), 19 + 0.8 * m_len * cos(2 * PI * m_Angle), -29.7);
//	glEnd();
//	glPopMatrix();
//}
//void drawdesks()
//{//{ 1.0f, 1.0f, 0.45f, 1.0f };
//	//������
//	GLfloat desk[] = { 1,0.9647,0.56078 };
//	for (int y = 0; y <= 4; y++)
//	{
//		for (int x = 0; x <= 1; x++)
//		{
//			//�����ϱ�
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 8.1, -17.5 + y * 8);
//			glScalef(10, 0.2, 3);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//�����±�
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 6.1, -17.5 + y * 8);
//			glScalef(9, 0.2, 3);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//����ǰ��
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 7, -18.9 + y * 8);
//			glScalef(10, 2, 0.2);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//����
//			glColor3f(0.0, 0.0, 0.0);
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-25.0 + x * 40, 6.0f, -19 + y * 8);
//			glVertex3f(-25.0 + x * 40, 0.0f, -19 + y * 8);
//			glEnd();
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-15.0 + x * 40, 6.0f, -19 + y * 8);
//			glVertex3f(-15.0 + x * 40, 0.0f, -19 + y * 8);
//			glEnd();
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-25.0 + x * 40, 0.0f, -18 + y * 8);
//			glVertex3f(-25.0 + x * 40, 0.0f, -20 + y * 8);
//			glEnd();
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-15.0 + x * 40, 0.0f, -18 + y * 8);
//			glVertex3f(-15.0 + x * 40, 0.0f, -20 + y * 8);
//			glEnd();
//		}
//		//���м�һ������
//		//�����ϱ�
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 8.1, -17.5 + y * 8);
//		glScalef(20, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//�����±�
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 6.1, -17.5 + y * 8);
//		glScalef(19, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//����ǰ��
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 7, -18.9 + y * 8);
//		glScalef(20, 2, 0.2);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//����
//		glColor3f(0.0, 0.0, 0.0);
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(-10.0, 6.0f, -19 + y * 8);
//		glVertex3f(-10.0, 0.0f, -19 + y * 8);
//		glEnd();
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(10.0, 6.0f, -19 + y * 8);
//		glVertex3f(10.0, 0.0f, -19 + y * 8);
//		glEnd();
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(-10.0, 0.0f, -18 + y * 8);
//		glVertex3f(-10, 0.0f, -20 + y * 8);
//		glEnd();
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(10, 0.0f, -18 + y * 8);
//		glVertex3f(10, 0.0f, -20 + y * 8);
//		glEnd();
//	}
//}
////��������
//void drawchairs()
//{
//	GLfloat chair[] = { 1.0f, 1.0f, 0.45f, 1.0f };// { 0.1, 0.67, 0.62 };
//	for (int j = 0; j <= 4; j++)
//	{
//		for (int i = 0; i <= 1; i++)
//		{
//			//�����ӵײ�
//			glColor3f(0.1, 0.67, 0.62);
//			glPushMatrix();
//			glTranslatef(-20 + i * 40, 3.1, -14.5 + j * 8);
//			glScalef(10, 0.2, 3);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//�����ӿ���
//			glColor3f(0.1, 0.67, 0.62);
//			glPushMatrix();
//			glTranslatef(-20 + i * 40, 5, -13 + j * 8);
//			glScalef(10, 4, 0.2);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//��������
//			glColor3f(0.0, 0.0, 0.0);
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-25 + i * 40, 3.0f, -13 + j * 8);
//			glVertex3f(-25 + i * 40, 0.0f, -13 + j * 8);
//			glEnd();
//			glColor3f(0.0, 0.0, 0.0);
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-15.0 + i * 40, 3.0f, -13 + j * 8);
//			glVertex3f(-15.0 + i * 40, 0.0f, -13 + j * 8);
//			glEnd();
//			glColor3f(0.0, 0.0, 0.0);
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-25.0 + i * 40, 0.0f, -12.5 + j * 8);
//			glVertex3f(-25 + i * 40, 0.0f, -13.5 + j * 8);
//			glEnd();
//			glColor3f(0.0, 0.0, 0.0);
//			glBegin(GL_LINES);
//			glLineWidth(3.0f);
//			glVertex3f(-15 + i * 40, 0.0f, -12.5 + j * 8);
//			glVertex3f(-15 + i * 40, 0.0f, -13.5 + j * 8);
//			glEnd();
//
//		}
//		//�����ӵײ�
//		glColor3f(0.1, 0.67, 0.62);
//		glPushMatrix();
//		glTranslatef(0, 3.1, -14.5 + j * 8);
//		glScalef(20, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//�����ӿ���
//		glColor3f(0.1, 0.67, 0.62);
//		glPushMatrix();
//		glTranslatef(0, 5, -13 + j * 8);
//		glScalef(20, 4, 0.2);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//��������
//		glColor3f(0.0, 0.0, 0.0);
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(-10, 3.0f, -13 + j * 8);
//		glVertex3f(-10, 0.0f, -13 + j * 8);
//		glEnd();
//		glColor3f(0.0, 0.0, 0.0);
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(10, 3.0f, -13 + j * 8);
//		glVertex3f(10, 0.0f, -13 + j * 8);
//		glEnd();
//		glColor3f(0.0, 0.0, 0.0);
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(-10, 0.0f, -12.5 + j * 8);
//		glVertex3f(-10, 0.0f, -13.5 + j * 8);
//		glEnd();
//		glColor3f(0.0, 0.0, 0.0);
//		glBegin(GL_LINES);
//		glLineWidth(3.0f);
//		glVertex3f(10, 0.0f, -12.5 + j * 8);
//		glVertex3f(10, 0.0f, -13.5 + j * 8);
//		glEnd();
//
//	}
//
//}
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
//	//// ���ô���Ϊ��ɫ
//	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//	// ��ȡ���ص�ǰʱ��
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	h = sys.wHour;
//	m = sys.wMinute;
//	s = sys.wSecond;
//}
///*********************************************����ˢ�º���**********************************************/
//void reshape(int we, int he)
//{
//
//	WinWidth = we;
//	WinHeight = he;
//	glViewport(0, 0, (GLsizei)we, (GLsizei)he);/*0 0ָ���˴��ڵ����½�λ��
//	//width,height��ʾ�ӿھ��εĿ�Ⱥ͸߶ȣ����ݴ��ڵ�ʵʱ�仯�ػ洰�ڡ�*/
//	glMatrixMode(GL_PROJECTION);//������һ������ΪͶӰ
//	glLoadIdentity();//�ָ���ʼ����ϵ
//	//͸��ͶӰͨ��ָ��һ��ƽ��ͷ���������Ӽ���ķ�Χ 
//	gluPerspective(90.0f, (GLfloat)we / (GLfloat)he, 0.01f, 100.0f);/*͸��ͶӰ
//	/*90.0f���ü�ƽ����Զ�ü�ƽ����������ӵ�ĽǶ�,Ҳ���ӳ���,0.01f���ü��浽���(�ӵ�)�ľ���,100.0fԶ�ü��浽���(�ӵ�)�ľ���*/
//	glMatrixMode(GL_MODELVIEW);//������һ��Ϊ��ģ����ͼ�Ĳ���
//	glLoadIdentity();
//	/*��һ��eyex, eyey,eyez ��������������λ��(�ӵ�)
//	�ڶ���centerx,centery,centerz �����ͷ��׼�����������������λ��
//	������upx,upy,upz ������ϵķ��������������еķ���
//	����������Ϊ���Լ����Դ���
//	��һ�����ݾ����Դ���λ��
//	�ڶ������ݾ����۾����������λ��
//	���������ͷ������ķ�����Ϊ���������ͷ��ͬһ�����壩*/
//	gluLookAt(myEye.x, myEye.y, myEye.z, vPoint.x + 30 * sin(vAngle), vPoint.y, -30 * cos(vAngle), up.x, up.y, up.z);//0.0f, 1.0f, 0.0f);
//}
///**************************����ͶӰ���������Ч��*******************************************************/
//void projectup()
//{
//	pro_up_down = pro_up_down + 1.0f;
//	if (pro_up_down >= 28.0f)
//		pro_up_down = 28.0f;
//	glutPostRedisplay();//glutPostRedisplay�������ǵ�ǰ������������ʾ��ָʾglutMainLoop()������ע�����ʾ�ص�����
//
//}
//void projectdown()
//{
//	pro_up_down = pro_up_down - 1.0f;
//	if (pro_up_down <= 10.0f)
//		pro_up_down = 10.0f;
//	glutPostRedisplay();
//
//}
///*********************************************��ʾ����*****************************************************/
//void myDisplay()
//{
//	// �����Ļ
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//���û��ƺ���
//	drawscence();
//	drawprojector();
//	drawdesks();
//	drawClock();
//	drawchairs();
//	glFlush();//��ջ�����
//}
///*******************************************��Ӧ��ͨ���̲�����w��s��a��d�Լ��˳�esc��*******************************/
//GLvoid OnKeyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 97://a ����
//		myEye.x -= 0.5;
//		vPoint.x -= 0.5;
//		if (myEye.x <= -38)
//			myEye.x = -38;
//		break;
//	case 100://d ����
//		myEye.x += 0.5;
//		vPoint.x += 0.5;
//		if (myEye.x >= 38)
//			myEye.x = 38;
//		break;
//	case 119://w ��ǰ
//		myEye.z -= 0.5;
//		if (myEye.z <= -28)
//			myEye.z = -28;
//		break;
//	case 115://s ���
//		myEye.z += 0.5;
//		if (myEye.z >= 28)
//			myEye.z = 28;
//		break;
//	case 27://esc
//		exit(0);
//
//	}
//	reshape(WinWidth, WinHeight);//����ˢ��
//	glutPostRedisplay();
//
//}
///****************************************��Ӧ������̲���******************************************************/
//GLvoid OnSpecial(int key, int x, int y)//��������
//{
//	switch (key)
//	{
//	case GLUT_KEY_LEFT:
//		vAngle -= 0.05;
//		break;
//	case GLUT_KEY_RIGHT:
//		vAngle += 0.05;
//		break;
//	case GLUT_KEY_UP:
//		myEye.y += 0.05;
//		if (myEye.y >= 30)
//			myEye.y = 30;
//
//		break;
//	case GLUT_KEY_DOWN:
//		myEye.y -= 0.5;
//		if (myEye.y <= 0)
//			myEye.y = 30;
//		break;
//	case GLUT_KEY_PAGE_DOWN://PageDown��
//		myEye.z += 0.5;
//		if (myEye.z >= 30)
//			myEye.z = 30;
//		break;
//	case GLUT_KEY_PAGE_UP://PageUp��
//		myEye.z -= 0.5;
//		if (myEye.z <= -30)
//			myEye.z = -30;
//		break;
//	case GLUT_KEY_F1:
//		projectup();
//		break;
//	case GLUT_KEY_F2:
//		projectdown();
//		break;
//	case GLUT_KEY_F3:
//		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//		glEnable(GL_LIGHT1);
//		break;
//	case GLUT_KEY_F4:
//		//glDisable(GL_TEXTURE_2D);
//		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//		glDisable(GL_LIGHT1);
//		break;
//	case GLUT_KEY_F5:
//		TurnOn = true;
//		break;
//	case GLUT_KEY_F6:
//		TurnOn = false;
//		break;
//	}
//	reshape(WinWidth, WinHeight);
//	glutPostRedisplay();
//}
//GLvoid OnIdle()
//{
//	glutPostRedisplay();
//}
///*************************************��ʼ���������Ը���������г�ʼ��*********************************************/
//void initial()
//{
//	glClearColor(0, 0, 0, 0);
//	glEnable(GL_TEXTURE_2D);
//
//	/*������������ʵ��ںϷ�ʽ��������ֻ������������ģ�͵Ĳ���*/
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//	/*********************************************�Եƹ���г�ʼ��****************************************************/
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);//���������趨Ϊȫ��ֵ
//	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);//������Զ�Ĺ۲���Ϊ�ֲ��۲��
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//ָ������ǰ�澵�淴�����ɫ
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//ָ������ǰ�澵�淴���ָ��
//	/*���õ��Դ*/
//	/*GL_POSITIONָ����Դλ�ã�GL_AMBIENT��ʾ���ֹ������䵽�ò����ϣ������ܶ�η�������������ڻ����еĹ���ǿ�ȣ���ɫ����
//	�Ա��������������й��ס�GL_DIFFUSE��ʾ�������䵽�ò����ϣ�������������γɵĹ���ǿ�ȣ���ɫ����
//	GL_SPECULAR��ʾ�������䵽�ò����ϣ��������淴����γɵĹ���ǿ�ȣ���ɫ����ͨ����GL_AMBIENT��GL_DIFFUSE��ȡ��ͬ��ֵ��
//	���Դﵽ�Ƚ���ʵ��Ч����ʹ��GL_AMBIENT_AND_DIFFUSE����ͬʱ����GL_AMBIENT��GL_DIFFUSE���ԡ�*/
//	/*glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light);*/
//
//	/*����ƽ�й�Դ*/
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT1);
//	glEnable(GL_COLOR_MATERIAL);//����
//
//	/**********************************************************************************************/
//	/*glShadeModel�������ڿ���opengl�л���ָ���������������ɫ�Ĺ���ģʽ��
//	GL_SMOOTH��Ĭ�ϣ����ƶ���������ɫ���в�ֵ������֮���������*/
//	glShadeModel(GL_SMOOTH);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//ָ��������ɫ����
//	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);	//ָ�����϶Ծ����ķ���
//	glEnable(GL_DEPTH_TEST);//	
//}
//void print()
//{
//	printf("**************************************************** \n");
//	printf(" \n");
//	printf("����������Ϣ��ʾ�� \n");
//	printf("�ϼ����¼��ֱ�����ӽ����º����� \n");
//	printf("������Ҽ��ֱ���������Ӻ����һ��� \n");
//	printf("w,s,a,d���ֱ��ʾ��ǰ�������ң�����ƽ�ƣ�ע����̴�Сд��\n");
//	printf("pgup��pgdn�ֱ������ǰ���κ�������� \n");
//	printf("F3��F4���ֱ���ƿ��ơ��ص� \n");
//	printf("F1��F2���ֱ����ͶӰ�Ƿ��º����� \n");
//	printf("ESC���˳����� \n");
//	printf(" \n");
//}
//int main(int argc, char* argv[])
//{
//	myEye.x = 0;
//	myEye.y = 15;
//	myEye.z = 25;
//	vPoint.x = 0;
//	vPoint.y = 15;
//	vPoint.z = -30;
//	up.x = 0;
//	up.y = 1;
//	up.z = 0;
//	vAngle = 0;
//	/*������֮��OpenGL�ڻ��Ƶ�ʱ��ͻ��飬��ǰ����ǰ���Ƿ��б�����أ�
//	���������ص��������������Ͳ�����ƣ�Ҳ����˵��OpenGL��ֻ������ǰ���һ�㡣*/
//	glEnable(GL_DEPTH_TEST);
//	glutInit(&argc, argv);
//	/*������ʾ��ʽ��GLUT_RGBAָ��һ��RGBA���ڣ�GLUT_SINGLE.������������*/
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//
//	glutInitWindowPosition(400, 0);//���ó�ʼ���ڵ�λ��(�������Ͻ��������������(x,y))
//	glutInitWindowSize(800, 600);//���ô��ڴ�С
//	glutCreateWindow("classroom");
//	initial();//������ʾ����
//	SetupRC();//��2��
//	glutDisplayFunc(&myDisplay);
//	glutTimerFunc(1000, timerFunc, 1);//��1��
//	//glutDisplayFunc(&myDisplay);//ע����ʾ�ص�����,�����ػ泡����������д���
//	glutReshapeFunc(reshape);//ע�ᴰ�ڸı�ص�����
//	glutKeyboardFunc(OnKeyboard);
//	glutSpecialFunc(OnSpecial);
//	glutIdleFunc(OnIdle);//ע��������Ӧ����,�ú������÷���������main()�У�ͨ����������ʵ�ּ򵥶�����
//	///***************************************��������***********************************************/
//	texblackboard = load_texture("blackboard.bmp");
//		texwindow = load_texture("window.bmp");
//		texsound = load_texture("sound.bmp");
//		texceiling = load_texture("ceiling.bmp");
//		texdoor = load_texture("door.bmp");
//		texfloor = load_texture("floor.bmp");
//		texbackwall = load_texture("backwall.bmp");
//		texpole = load_texture("pole.bmp");
//		texairfro = load_texture("airconditionfront.bmp");
//		texairback = load_texture("airconditionback.bmp");
//		texhighland = load_texture("gaodi.bmp");
//		texsdesk = load_texture("sdesk.bmp");
//		texclock = load_texture("clock.bmp");
//	///************************************************************************************************/
//	print();
//	//��ʼ��ʾ
//	glutMainLoop();//�����¼�����ѭ��
//	return 0;
//}