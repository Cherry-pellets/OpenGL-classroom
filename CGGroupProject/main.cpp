//#include<gl/glut.h>
//#include<windows.h>
//#include<math.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include<time.h>
//#pragma warning (disable: 4996)
///*******************************定义程序中所用的常数变量******************************************/
//GLfloat light_position1[] = { 0,28,-20,1.0 };//灯位置
//GLfloat model_ambient[] = { 0.05f,0.05f,0.05f,1.0f };//环境模式
//GLfloat mat_specular[] = { 0.8,1.0,1.0,1.0 };//镜面反射
//GLfloat mat_shininess[] = { 5.0 };//光泽
//GLfloat mat_ambient[] = { 0.1,0.1,0.1,1 };
//GLfloat white_light[] = { 1.0,1.0,1.0,1.0 };
//GLfloat light[] = { 1.0,1.0,1.0,1 };
//GLfloat light_position0[] = { 0,28,20,1.0 };
//GLfloat	no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//GLfloat	mat_diffuse1[] = { 0.1f, 0.5f, 0.8f, 1.0f };
//GLfloat	no_shininess[] = { 0.0f };
//GLfloat sound[] = { 0.9,0.9,0.9,1 };
//GLint	WinWidth;//窗口的宽
//GLint	WinHeight;//窗口的高
//
////时钟
////const int Width = 800;
////const int Height = 600;
//
//const GLfloat PI = 3.141592653f;
//
//// 当前时间，时 分 秒
//float h = 0.0f;
//float m = 0.0f;
//float s = 0.0f;
//
//////.....................................时钟有关变量...................................................//
////GLfloat       cx = 28.0, cy = 15.0, cz = -29.9, radius = 5.0;
////GLfloat       hradius = 2.0, mradius = 3.0, sradius = 4.0;
////GLfloat       sangle, mangle, hangle;
////GLuint        second, miniter, hour;
////char          timebuffer[9];
//
//
///************************定义视点结构*********************************************************/
//typedef struct EyePoint
//{
//	GLfloat	x;
//	GLfloat y;
//	GLfloat z;
//}EyePoint;
//EyePoint 	myEye;//眼睛
//EyePoint    vPoint;//视角点
//GLfloat pro_up_down = 29.0f;//投影仪
//GLfloat vAngle = 0;
///****************************载入位图作为纹理的相关函数************************************/
//#define BMP_Header_Length 54
////void grab(void)
////
////{
////	//BMP文件采用了一种“对 齐”的机制，每一行像素数据的长度若不是4的倍数，则填充一些数据使它是4的倍数
////	//Windows 所使用的BMP文件，在开始处有一个文件头，大小为54字节。保存了包括文件格式标识、颜色数、图象大小、压缩方式等信息
////	//从一个正确的BMP文件中读取前54个字节，修改其中的宽度和高度信息，就可以得到新的文件头
////	FILE* pDummyFile; FILE* pWritingFile;
////	GLubyte* pPixelData;
////	GLubyte BMP_Header[BMP_Header_Length];
////	GLint    i, j;
////	GLint    PixelDataLength;
////	// 计算像素数据的实际长度
////
////	i = WinWidth * 3;  // 得到每一行的像素数据长度
////	//每行数据长度大致为图象宽度乘以每像素的字节数
////	while (i % 4 != 0)      // 补充数据，直到 i 是4的倍数
////		++i;	                      // 本来还有更快的算法，
////	PixelDataLength = i * WinHeight;// 但这里仅追求直观，对速度没有太高要求
////	//数据总长=每行长度*图象高度
////	pPixelData = (GLubyte*)malloc(PixelDataLength);// 分配内存和打开文件，获得像素数据
////	if (pPixelData == 0)
////		exit(0);
////	pDummyFile = fopen("dummy.bmp", "rb");
////	if (pDummyFile == 0)
////		exit(0);
////	pWritingFile = fopen("grab.bmp", "wb");
////	if (pWritingFile == 0)
////		exit(0);
////	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);//对齐像素字节函数，消除BMP文件中“对齐”带来的影响，4字节对齐
////	glReadPixels(0, 0, WinWidth, WinHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);
////	/* 把 dummy.bmp 的文件头复制为新文件的文件头
////	glReadPixels读取像素函数，一二个参数表示矩形的左下角横纵坐标，三四个参数表示举行的宽度和高度，
////	GL_BGR_EXT依次读取像素的蓝、绿、红数据(因为是bmp文件)，GL_UNSIGNED_BYTE会把读取的各种数据保存
////	到内存时保存为为GLubyte，pPixelData表示一个指针，像素数据被读取后，将被保存到这个指针所表示的地址。*/
////
////	//把读入的bmp文件的文件头和信息头数据复制，并修改宽高数据
////	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);//读取dummy.bmp中的头54个字节到数组
////	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);//把数组内容写入到新的BMP文件
////	fseek(pWritingFile, 0x0012, SEEK_SET);/*移动到0x0012位置，SEEK_SET:文件开头,
////	因为图象的宽度的地址是0x0012,高度是0x0016*/
////	i = WinWidth;
////	j = WinHeight;
////	fwrite(&i, sizeof(i), 1, pWritingFile);
////	fwrite(&j, sizeof(j), 1, pWritingFile);//修改其中的大小信息
////	fseek(pWritingFile, 0, SEEK_END);//移动到文件末尾，
////	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);//把完整的bmp文件数据写入
////	fclose(pDummyFile); fclose(pWritingFile); free(pPixelData);
////}
//
////判断一个数是否是2的整数次方
//int power_of_two(int n)
//{
//	if (n <= 0)
//		return 0;
//	return (n & (n - 1)) == 0;
//}
///****************************载入一副位图作为纹理，返回的是纹理编号**********************************************/
//GLuint load_texture(const char* file_name)
//{
//	/*打开BMP文件、读取其中的高度和宽度信息、计算像素数据所占的字节数、
//	为像素数据分配空间、读取像素数 据、对像素图象进行缩放（如果必要的话）、
//	分配新的纹理编号、填写纹理参数、载入纹理*/
//	GLint width, height, total_bytes;
//	GLubyte* pixels = 0;//像素
//	GLint last_texture_ID = 0;
//	GLuint texture_ID = 0;
//	// 打开文件，如果失败，返回
//	FILE* pFile = fopen(file_name, "rb");
//	if (pFile == 0)
//		return 0;
//	// 读取文件中图象的宽度和高度
//	fseek(pFile, 0x0012, SEEK_SET);
//	fread(&width, 4, 1, pFile);
//	fread(&height, 4, 1, pFile);
//	fseek(pFile, BMP_Header_Length, SEEK_SET);
//	// 计算每行像素所占字节数，并根据此数据计算总像素字节数
//	{
//		GLint line_bytes = width * 3;
//		while (line_bytes % 4 != 0)
//			++line_bytes;
//		total_bytes = line_bytes * height;
//	}
//	// 根据总像素字节数分配内存
//	pixels = (GLubyte*)malloc(total_bytes);
//	if (pixels == 0)
//	{
//		fclose(pFile);
//		return 0;
//	}
//	// 读取像素数据
//	if (fread(pixels, total_bytes, 1, pFile) <= 0)
//	{
//		free(pixels);
//		fclose(pFile);
//		return 0;
//	}
//	// 在旧版本的 OpenGL 中
//	// 如果图象的宽度和高度不是2的整数次方，则需要进行缩放
//	// 这里并没有检查 OpenGL 版本，出于对版本兼容性的考虑，按旧版本处理
//	// 另外，无论是旧版本还是新版本，
//	// 当图象的宽度和高度超过当前 OpenGL 实现所支持的最大值时，也要进行缩放
//	{
//		GLint max;
//		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max);//获得OpenGL所支持的最大纹理
//
//		if (!power_of_two(width) || !power_of_two(height) || width > max || height > max)
//		{
//			const GLint new_width = 256;
//			const GLint new_height = 256; // 规定缩放后新的大小为边长的正方形
//			GLint new_line_bytes, new_total_bytes;
//			GLubyte* new_pixels = 0;
//			// 计算每行需要的字节数和总字节数
//			new_line_bytes = new_width * 3;
//			while (new_line_bytes % 4 != 0)
//				++new_line_bytes;
//			new_total_bytes = new_line_bytes * new_height;
//			// 分配内存
//			new_pixels = (GLubyte*)malloc(new_total_bytes);
//			if (new_pixels == 0)
//			{
//				free(pixels);
//				fclose(pFile);
//				return 0;
//			}
//			// 进行像素缩放
//			gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels, new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);
//			// 释放原来的像素数据，把 pixels 指向新的像素数据，并重新设置 width 和 height
//			free(pixels);
//			pixels = new_pixels;
//			width = new_width;
//			height = new_height;
//		}
//	}
//	// 分配一个新的纹理编号
//	glGenTextures(1, &texture_ID);
//	if (texture_ID == 0)
//	{
//		free(pixels);
//		fclose(pFile);
//		return 0;
//	}
//	// 绑定新的纹理，载入纹理并设置纹理参数
//	glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID);//先获得原来绑定的纹理编号，以便在最后进行恢复
//	glBindTexture(GL_TEXTURE_2D, texture_ID);//将一个命名的纹理绑定到一个纹理目标上
//
//	/*纹理过滤函数，GL_TEXTURE_2D表示操作2D纹理，第二个参数指定响应的模式
//	GL_TEXTURE_WRAP_S：S方向上的贴图模式，GL_TEXTURE_WRAP_T：T方向上的贴图模式
//	GL_TEXTURE_MAG_FILTER：放大过滤，TEXTURE_MIN_FILTER：缩小过滤，
//	第三个参数指对应模式的方法，GL_LINEAR：线性过滤, 使用距离当前渲染像素中心最近的4个纹素加权平均值，
//	速度较慢无锯齿，GL_REPEAT：重复边界的纹理*/
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	/*设置纹理跟材质的融合方式，这里是只是用纹理，覆盖模型的材质*/
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//
//	/*用于载入一个二维的纹理，第一个0代表图象的详细程度，第二个0代表
//	边框的值，GL_BGR_EXT告诉OpenGL图像数据由蓝、绿、红三色数据组成，pixels纹理数据的来源*/
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
//
//	glBindTexture(GL_TEXTURE_2D, last_texture_ID);
//	// 之前为 pixels 分配的内存可在使用 glTexImage2D 以后释放
//	// 因为此时像素数据已经被 OpenGL 另行保存了一份（可能被保存到专门的图形硬件中）
//	free(pixels);
//	return texture_ID;
//}
///**********************************定义各个纹理对象的名称************************************/
//GLuint texblackboard, texwindow, texdesk, texsound;
//GLuint texceiling, texdoor, texfloor, texbackwall, texpole;
//GLuint texairfro, texairback, texgaodi, texsdesk, texclock;
///*******************************绘制相关函数**************************************************/
//
////绘制教室这个大场景
//void drawscence()
//{
//	//设置材质相关参数
//	/*指定材质对漫射光的反射率，第一个参数决定该材质运用于图元的正面还是反面
//	第二个参数表示对何种光进行设置，GL_AMBIENT(环境光)、GL_DIFFUSE(漫射光)、
//	GL_AMBIENT_AND_DIFFUSE(环境光和漫射光)、GL_SPECULAR(平行/镜面光，
//	第三个参数是一个四维数组，这个数组描述了反光率的RGBA值，每一项取值都为0-1之间*/
//	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
//	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
//	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
//
//	//首先绘制天花板
//	glEnable(GL_TEXTURE_2D);//开启2D纹理功能
//	glBindTexture(GL_TEXTURE_2D, texceiling);//绑定纹理
//	glColor3f(0.3, 0.3, 0.3);//设置颜色，黑色
//	glBegin(GL_QUADS);//画四边形
//
//	glNormal3f(0.0f, -1.0f, 0.0f);//用于定义法线向量
//	/*glTexCoord2f绘制图形时指定纹理的坐标，第一个是X轴坐标，0.0是纹理的左侧，0.5是纹理的中点，1.0是纹理的右侧，
//	第二个是Y轴坐标，0.0是纹理的底部，0.5是纹理的中点，1.0是纹理的顶部，
//	为了将纹理正确的映射到四边形上，您必须将纹理的右上角映射到四边形的右上角，纹理的左上角映射到四边形的左上角，
//	纹理的右下角映射到四边形的右下角，纹理的左下角映射到四边形的左下角，纹理的左上坐标是X：0.0，Y：1.0f，四边形的左上顶点是X：-1.0，Y：1.0。*/
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, 30.0f, 30.0f);//四边形的点
//	glTexCoord2f(0.0f, 3.0f); glVertex3f(-40.0f, 30.0f, -30.0f);
//	glTexCoord2f(6.0f, 3.0f); glVertex3f(40.0f, 30.0f, -30.0f);
//	glTexCoord2f(6.0f, 0.0f); glVertex3f(40.0f, 30.0f, 30.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//绘制地板
//	glColor3f(0.8f, 1.0f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f);	                  //用于定义法线向量
//	glVertex3f(-40.0f, 0.0f, 30.0f);
//	glVertex3f(-40.0f, 0.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, 30.0f);
//	glEnd();
//
//	//绘制左边墙加左边窗户
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(1.0f, 0.0f, 0.0f);	                  //用于定义法线向量
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
//		glNormal3f(1.0, 0.0f, 0.0f);	                  //用于定义法线向量
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-39.9, 10, -8 + n * 18);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-39.9, 20, -8 + n * 18);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-39.9, 20, -18 + n * 18);
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-39.9, 10, -18 + n * 18);
//		glEnd();
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	//绘制右边墙加右边窗户
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0f, 0.0f, 0.0f); //用于定义法线向量
//	glVertex3f(40.0f, 0.0f, 30.0f);
//	glVertex3f(40.0f, 30.0f, 30.0f);
//	glVertex3f(40.0f, 30.0f, -30.0f);
//	glVertex3f(40.0f, 0.0f, -30.0f);
//	glEnd();
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texwindow);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0, 0.0f, 0.0f);	                  //用于定义法线向量
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(39.5, 10, 10);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(39.5, 20, 10);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(39.5, 20, 0);
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(39.5, 10, 0);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//绘制后边墙
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texbackwall);
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f);
//	glVertex3f(-40.0f, 0.0f, 30.0f);
//	glTexCoord2f(0.0f, 1.0f);
//	glVertex3f(-40.0f, 30.0f, 30.0f);
//	glTexCoord2f(1.0f, 1.0f);
//	glVertex3f(40.0f, 30.0f, 30.0f);
//	glTexCoord2f(1.0f, 0.0f);
//	glVertex3f(40.0f, 0.0f, 30.0f);
//	glEnd();
//
//	//绘制前边墙
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texbackwall);
//	glColor3f(0.8f, 0.8f, 0.8f);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f);
//	glVertex3f(-40.0f, 0.0f, -30.0f);
//	glTexCoord2f(0.0f, 1.0f);
//	glVertex3f(-40.0f, 30.0f, -30.0f);
//	glTexCoord2f(1.0f, 1.0f);
//	glVertex3f(40.0f, 30.0f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f);
//	glVertex3f(40.0f, 0.0f, -30.0f);
//	glEnd();
//
//	//画钟
//	//glBindTexture(GL_TEXTURE_2D, texclock);
//	//glBegin(GL_QUADS);
//	//glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//	//glTexCoord2f(0.0f, 0.0f);
//	//glVertex3f(23.0f, 18.0f, -29.8f);
//	//glTexCoord2f(0.0f, 1.0f);
//	//glVertex3f(23.0f, 20.0f, -29.8f);
//	//glTexCoord2f(1.0f, 1.0f);
//	//glVertex3f(25.0f, 20.0f, -29.8f);
//	//glTexCoord2f(1.0f, 0.0f);
//	//glVertex3f(25.0f, 18.0f, -29.8f);
//	//glEnd();
//	//glDisable(GL_TEXTURE_2D);
//	//........................................时钟..........................................................//
//	//_strtime(timebuffer);//取系统时间到timebuffer数组中
//	//hour = ((int)timebuffer[0] - 48) * 10 + ((int)timebuffer[1] - 48);//从timebuffer数组中得到小时的值
//	//miniter = ((int)timebuffer[3] - 48) * 10 + ((int)timebuffer[4] - 48);//从timebuffer数组中得到分钟的值
//	//second = ((int)timebuffer[6] - 48) * 10 + ((int)timebuffer[7] - 48);//从timebuffer数组中得到秒钟的值
//	//sangle = (float)(3.1415 / 2 - (float)second * 2 * 3.1415 / 60);//算得秒针走过的角度       
//	//mangle = (float)3.1415 / 2 - (float)(miniter + (float)second / 60) / 60 * 2 * 3.1415;//算得分针走过的角度  
//	//hangle = (float)3.1415 / 2 - (float)(hour + (float)(miniter + (float)second / 60) / 60) * 2 * 3.1415 / 12;//算得时针走过的角度
//
// // //..............钟面上的时刻点............................//
//	//int array[13][2];//12个大点
//	//int arr[60][2];//60个小点
//	//float angle1, angle2;
//	//angle1 = 2 * 3.1415 / 12;//将圆周分成12份
//	//angle2 = 2 * 3.1415 / 60;//将圆周分成60份
//	//for (int q = 0; q < 60; q++)
//	//{
//	//	arr[q][0] = cx + radius * cos(q * angle2);//求得x轴坐标
//	//	arr[q][1] = cy + radius * sin(q * angle2);//求得y轴坐标
//	//	glBegin(GL_POINTS);//绘制点
//	//	glPointSize(1.0);//制定点的大小
//	//	glVertex3f(arr[q][0] + 0.4, arr[q][1] + 0.4, cz);//确定点的位置
//	//	glEnd();
//	//}
//	//for (int w = 0; w < 12; w++)
//	//{
//	//	array[w][0] = cx + radius * cos(w * angle1);//求得x轴坐标
//	//	array[w][1] = cy + radius * sin(w * angle1);//求得y轴坐标
//	//	glPointSize(1.5);//绘制点
//	//	glBegin(GL_POINTS);//制定点的大小
//	//	glVertex3f(array[w][0] + 0.4, array[w][1] + 0.4, cz);//确定点的位置
//	//	glEnd();
//	//}
//	////.....................时钟的轮廓...........................//
//	//float x, y, d;
//	//float bradius = 5.2;//时钟轮廓的半径
//	//y = bradius;
//	//d = 10 - 0.1 * bradius;
//	//x = 0;
//	//while (x <= y)
//	//{
//	//	glColor3f(1.0, 0.0, 1.0);
//	//	glBegin(GL_POINTS);
//	//	glVertex3f(cx + x, cy + y, cz);
//	//	glVertex3f(cx + x, cy - y, cz);
//	//	glVertex3f(cx - x, cy + y, cz);
//	//	glVertex3f(cx - x, cy - y, cz);
//	//	glVertex3f(cx + y, cy + x, cz);
//	//	glVertex3f(cx + y, cy - x, cz);
//	//	glVertex3f(cx - y, cy + x, cz);
//	//	glVertex3f(cx - y, cy - x, cz);
//	//	glEnd();
//	//	if (d < 0)
//	//		d += 0.1 * x + 0.2;
//	//	else
//	//	{
//	//		d += 4 * (x - y) + 10;
//	//		y = y - 0.1;
//	//	}
//	//	x = x + 0.1;
//	//}
//	////....................秒针..................................//
//	//float harr1[2];
//	//harr1[0] = cx + sradius * cos(sangle);//求得x轴坐标
//	//harr1[1] = cy + sradius * sin(sangle);//求得y轴坐标
//	//glBegin(GL_LINES);//绘制线段
//	//glVertex3f(harr1[0], harr1[1], cz);//线段终点
//	//glVertex3f(cx, cy, cz);//线段起点
//	//glEnd();
//	////.....................分针..................................//
//	//float harr2[2];
//	//harr2[0] = cx + mradius * cos(mangle);//求得x轴坐标
//	//harr2[1] = cy + mradius * sin(mangle);//求得y轴坐标
//	//glBegin(GL_LINES);//绘制线段
//	//glVertex3f(harr2[0], harr2[1], cz);//线段终点
//	//glVertex3f(cx, cy, cz);//线段起点
//	//glEnd();
//	////......................时针..................................//
//	//float harr3[2];
//	//harr3[0] = cx + hradius * cos(hangle);//求得x轴坐标
//	//harr3[1] = cy + hradius * sin(hangle);//求得y轴坐标
//	//glBegin(GL_LINES);//绘制线段
//	//glVertex3f(harr3[0], harr3[1], cz);//线段终点
//	//glVertex3f(cx, cy, cz);//线段起点
//	//glEnd();
//	//...........................................................//
//
//
//	//绘制空调给空调贴纹理
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
//	//绘制教室两边石柱前边两根
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texpole);
//	for (int i = 0; i <= 1; i++)
//	{
//		glColor3f(1.0f, 1.0f, 1.0f);
//		//石柱上表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, -1.0f, 0.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0f + i * 78, 30.0f, -4.0f);
//		glEnd();
//		//石柱前表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 0.0f, -4.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 78, 0.0f, -4.0f);
//		glEnd();
//		//石柱后表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + i * 78, 0.0f, -6.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 78, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 78, 0.0f, -6.0f);
//		glEnd();
//		//石柱右表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-38.0 + i * 76, 0.0f, -4.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0 + i * 76, 30.0f, -4.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + i * 76, 30.0f, -6.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + i * 76, 0.0f, -6.0f);
//		glEnd();
//	}
//	//绘制教室两边石柱，后边两根
//	for (int j = 0; j <= 1; j++)
//	{
//		glColor3f(1.0f, 1.0f, 1.0f);
//		//石柱上表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, -1.0f, 0.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0f + j * 78, 30.0f, 14.0f);
//		glEnd();
//		//石柱前表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 0.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 78, 0.0f, 14.0f);
//		glEnd();
//		//石柱后表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0 + j * 78, 0.0f, 12.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 78, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 78, 0.0f, 12.0f);
//		glEnd();
//		//右表面
//		glBegin(GL_QUADS);
//		glNormal3f(0.0f, 0.0f, -1.0f); //用于定义法线向量
//		glTexCoord2f(0.0f, 0.0f); glVertex3f(-38.0 + j * 76, 0.0f, 14.0f);
//		glTexCoord2f(0.0f, 1.0f); glVertex3f(-38.0 + j * 76, 30.0f, 14.0f);
//		glTexCoord2f(1.0f, 1.0f); glVertex3f(-38.0 + j * 76, 30.0f, 12.0f);
//		glTexCoord2f(1.0f, 0.0f); glVertex3f(-38.0 + j * 76, 0.0f, 12.0f);
//		glEnd();
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	//绘制黑板
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texblackboard);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-20.0, 8.0f, -29.9f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-20.0, 18.0f, -29.9f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0, 18.0f, -29.9f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0, 8.0f, -29.9f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	//画黑板上方的灯
//	GLfloat blacklight[] = { 0.9,0.9,0.9,1 };
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glPushMatrix();
//	glTranslatef(-15, 20.4, -29.5);
//	glScalef(8.0f, 0.8, 1.0f);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blacklight);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//	glPushMatrix();
//	glTranslatef(12, 20.4, -29.5);
//	glScalef(8.0f, 0.8, 1.0f);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blacklight);
//	glutSolidCube(1.0f);
//	glPopMatrix();
//	//绘制教室前边一块高地并贴纹理
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texgaodi);
//	//贴上面
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glEnd();
//	//贴左边
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 0.0f, 1.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-30.0f, 0, -30.0f);
//	glEnd();
//	//贴前边
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 0, -22.0f);
//	glEnd();
//	//贴右边
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(30.0f, 0, -22.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(30.0f, 1.5f, -22.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(30.0f, 1.5f, -30.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(30.0f, 0, -30.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//	//绘制讲台
//	//贴讲台纹理
//	glBindTexture(GL_TEXTURE_2D, texsdesk);
//	glEnable(GL_TEXTURE_2D);
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 1.5f, -24.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -28.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 1.5f, -28.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -28.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(-7.5f, 1.5f, -28.0f);
//	glEnd();
//	glBegin(GL_QUADS);
//	glNormal3f(0.0f, 1.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-7.5f, 9.5f, -24.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-7.5f, 9.5f, -26.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(7.5f, 9.5f, -26.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(7.5f, 9.5f, -24.0f);
//	glEnd();
//	//画门
//	glColor3f(0.521f, 0.121f, 0.0547f);
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, texdoor);
//	glBegin(GL_QUADS);
//	glNormal3f(-1.0f, 0.0f, 0.0f); //用于定义法线向量
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(39.9f, 0.0f, -25.0f);
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(39.9f, 14.0f, -25.0f);
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(39.9f, 14.0f, -19.0f);
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(39.9f, 0.0f, -19.0f);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//	//绘制音响
//	glColor3f(0.0f, 0.0f, 0.0f);
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
///**************************************绘制投影仪***********************************************/
//void drawprojector()
//{
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_QUADS);
//	glNormal3f(1.0f, 0.0f, 1.0f); //用于定义法线向量
//	glVertex3f(-40.0f, 30.0f, -30.0 + 10 * sqrt(2));
//	glVertex3f(-40.0 + 10 * sqrt(2), 30.0f, -30.0f);
//	glVertex3f(-40.0 + 10 * sqrt(2), pro_up_down, -30.0f);
//	glVertex3f(-40.0f, pro_up_down, -30.0 + 10 * sqrt(2));
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
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(-40.0f, 30.0f, -30.0 + 10 * sqrt(2));
//	glVertex3f(-40.0 + 10 * sqrt(2), 30.0f, -30.0f);
//	glVertex3f(-40.0 + 10 * sqrt(2), pro_up_down, -30.0f);
//	glVertex3f(-40.0f, pro_up_down, -30.0 + 10 * sqrt(2));
//	glEnd();
//
//}
//void drawdesks()
//{
//	//画桌子
//	GLfloat desk[] = { 1,0.9647,0.56078 };
//	for (int y = 0; y <= 4; y++)
//	{
//		for (int x = 0; x <= 1; x++)
//		{
//			//桌子上边
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 8.1, -17.5 + y * 8);
//			glScalef(10, 0.2, 3);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//桌子下边
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 6.1, -17.5 + y * 8);
//			glScalef(9, 0.2, 3);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//桌子前边
//			glColor4f(1, 0.9647, 0.56078, 1);
//			glPushMatrix();
//			glTranslatef(-20.0 + x * 40, 7, -18.9 + y * 8);
//			glScalef(10, 2, 0.2);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//桌腿
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
//		//画中间一排桌子
//		//桌子上边
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 8.1, -17.5 + y * 8);
//		glScalef(20, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//桌子下边
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 6.1, -17.5 + y * 8);
//		glScalef(19, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//桌子前边
//		glColor3f(1, 0.9647, 0.56078);
//		glPushMatrix();
//		glTranslatef(0, 7, -18.9 + y * 8);
//		glScalef(20, 2, 0.2);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, desk);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//桌腿
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
////绘制椅子
//void drawchairs()
//{
//	GLfloat chair[] = { 0.1,0.67,0.62 };
//	for (int j = 0; j <= 4; j++)
//	{
//		for (int i = 0; i <= 1; i++)
//		{
//			//画椅子底部
//			glColor3f(0.1, 0.67, 0.62);
//			glPushMatrix();
//			glTranslatef(-20 + i * 40, 3.1, -14.5 + j * 8);
//			glScalef(10, 0.2, 3);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//画椅子靠背
//			glColor3f(0.1, 0.67, 0.62);
//			glPushMatrix();
//			glTranslatef(-20 + i * 40, 5, -13 + j * 8);
//			glScalef(10, 4, 0.2);
//			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//			glutSolidCube(1.0f);
//			glPopMatrix();
//			//画椅子腿
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
//		//画椅子底部
//		glColor3f(0.1, 0.67, 0.62);
//		glPushMatrix();
//		glTranslatef(0, 3.1, -14.5 + j * 8);
//		glScalef(20, 0.2, 3);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//画椅子靠背
//		glColor3f(0.1, 0.67, 0.62);
//		glPushMatrix();
//		glTranslatef(0, 5, -13 + j * 8);
//		glScalef(20, 4, 0.2);
//		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, chair);
//		glutSolidCube(1.0f);
//		glPopMatrix();
//		//画椅子腿
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
///*********************************************绘制时钟*********************************************/
//void drawClock() {
//	//时钟
//	// 用当前清除色清除颜色缓冲区，即设定窗口的背景色
//	//glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0f, 1.0f, 1.0f); // 黑色
//	// 1 绘制外围同心圆
//	int cx = 27;//Width / 2; //中心点
//	int cy = 17;//Height / 2;
//	int cz =-29.9;
//	float R = 2.0; // 半径长
//	int n = 100;
//	int i;
//	glLineWidth(2);
//	glBegin(GL_LINE_LOOP); // 绘制多边形，n足够大就会变成圆形
//	for (i = 0; i < n; i++)
//	{
//		glVertex3f(cx + (R) * cos(2 * PI / n * i), cy + (R) * sin(2 * PI / n * i),cz);
//	}
//	glEnd();
//	glLineWidth(1);
//	glBegin(GL_LINE_LOOP);
//	for (i = 0; i < n; i++)
//	{
//		//glVertex2f(cx + R*cos(2 * PI / n * i), cy + R*sin(2 * PI / n * i));
//		glVertex3f(cx + (R - 0.2) * cos(2 * PI / n * i), cy + (R - 0.2) * sin(2 * PI / n * i),cz);
//	}
//	glEnd();
//
//
//	// 2 绘制时钟 圆上的刻度，刻度粗细，长度不一样
//	int lines = 60;
//	float ship1 = 1;// 10;
//	float ship2 = 0.5;// 5;
//	for (i = 0; i < lines; i++)
//	{
//		if (i % 5 == 0)    //  0（12）-11的短线
//		{
//			glLineWidth(0.5);
//			//glColor3f(0.0, 1.0, 0.0);
//			glBegin(GL_LINES);
//			glVertex3f(cx + (R - 0.8*ship1) * sin(2 * PI / lines * i), cy + (R - 0.8*ship1) * cos(2 * PI / lines * i),cz);
//			glVertex3f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i),cz);
//			glEnd();
//		}
//		else
//		{
//			glLineWidth(0.3);  //其他的刻度
//			//glColor3f(0.0, 0.0, 1.0);
//			glBegin(GL_LINES);
//			glVertex3f(cx + (R -ship2) * sin(2 * PI / lines * i), cy + (R - ship2) * cos(2 * PI / lines * i),cz);
//			glVertex3f(cx + R * sin(2 * PI / lines * i), cy + R * cos(2 * PI / lines * i),cz);
//			glEnd();
//		}
//	}
//
//	// 3 绘制时 分 秒结合的中心的小黑点
//	/*glBegin(GL_POLYGON);
//	for (i = 0; i < n; ++i)
//		glVertex3i(cx + 5 * cos(2 * PI / n * i)-15, cy + 5 * sin(2 * PI / n * i)-15,cz);
//	glEnd();*/
//
//	// 4 绘制时 分 秒针，三条直线，长短粗细不一样
//	float h_len = 0.8;// R - 5 * ship1;
//	float m_len = 1.3;// R - 3 * ship1;
//	float s_len = 2;//R - 3*ship1 + 2 * ship1;
//
//	float s_Angle = s / 60.0;
//	float m_Angle = (m * 60 + s) / 3600.0;
//	float h2 = h >= 12 ? (h - 12) : h;
//	float h_Angle = (h2 * 60 * 60 + m * 60 + s) / (12 * 60 * 60);
//
//	glLineWidth(1); // 秒
//	glBegin(GL_LINES);
//	glVertex3f(cx - ship1 * sin(2 * PI * s_Angle), cy - ship1 * cos(2 * PI * s_Angle),cz);
//	glVertex3f(cx + (R - ship2) * sin(2 * PI * s_Angle), cy + (R - ship2) * cos(2 * PI * s_Angle),cz);
//	glEnd();
//
//	glLineWidth(3); // 时
//	glBegin(GL_LINES);
//	glVertex3f(cx, cy,cz);
//	glVertex3f(cx + h_len * sin(2 * PI * h_Angle), cy + h_len * cos(2 * PI * h_Angle),cz);
//	glEnd();
//
//	glLineWidth(2); // 分
//	glBegin(GL_LINES);
//	glVertex3f(cx, cy,cz);
//	glVertex3f(cx + m_len * sin(2 * PI * m_Angle), cy + m_len * cos(2 * PI * m_Angle),cz);
//	glEnd();
//}
///*********************************************窗口刷新函数**********************************************/
//void reshape(int we, int he)
//{
//	WinWidth = we;
//	WinHeight = he;
//	glViewport(0, 0, (GLsizei)we, (GLsizei)he);/*0 0指定了窗口的左下角位置
//	width,height表示视口矩形的宽度和高度，根据窗口的实时变化重绘窗口。*/
//	glMatrixMode(GL_PROJECTION);//声明下一步操作为投影
//	glLoadIdentity();//恢复初始坐标系
//	
//	//透视投影通过指定一个平截头体来定义视见体的范围 
//	/*透视投影90.0f眼睛上下睁开的幅度,0.01f近裁剪面到眼睛的距离,100.0f远裁剪面到眼睛的距离*/
//	//void gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
//	gluPerspective(90.0f, (GLfloat)we / (GLfloat)he, 0.01f, 100.0f);
//
//	   /* glMatrixMode()函数的参数，这个函数其实就是对接下来要做什么进行一下声明，
//		也就是在要做下一步之前告诉计算机我要对“什么”进行操作了，
//		这个“什么”在glMatrixMode的“()”里的选项(参数)有3种模式:
//	    GL_PROJECTION 投影, GL_MODELVIEW 模型视图, GL_TEXTURE 纹理.*/
//	glMatrixMode(GL_MODELVIEW);//声明下一步为对模型视图的操作 
//
//	//glLoadIdentity是一个计算机函数名，功能是重置当前指定的矩阵为单位矩阵.在语义上，其等同于用单位矩阵调用glLoadMatrix。
//	glLoadIdentity();
//
//	/*gluLookAt
//	第一组eyex, eyey,eyez 相机在世界坐标的位置
//	第二组centerx,centery,centerz 相机镜头对准的物体在世界坐标的位置
//	第三组upx,upy,upz 相机向上的方向在世界坐标中的方向
//	把相机想象成为你自己的脑袋：
//	第一组数据就是脑袋的位置
//	第二组数据就是眼睛看的物体的位置
//	第三组就是头顶朝向的方向（因为你可以歪着头看同一个物体）*/
//	gluLookAt(myEye.x, myEye.y, myEye.z, vPoint.x + 30 * sin(vAngle), vPoint.y, -30 * cos(vAngle), 0.0f, 1.0f, 0.0f);
//}
//
//
///**************************制造投影仪升起放下效果*******************************************************/
//void projectup()
//{
//	pro_up_down = pro_up_down + 1.0f;
//	if (pro_up_down >= 28.0f)
//		pro_up_down = 28.0f;
//	//当回调函数处理完键盘事件后,显示函数会自动被调用,屏幕会被重绘.这样，GLUT程序会过于频繁的调用显示函数，抢占cpu资源
//	glutPostRedisplay();//选择性的告诉GLUT去调用显示函数（glutPostRedisplay函数会标记当前窗体来重新显示）
//	//目的：节省cpu资源，保持我们的GLUT程序的占用行为不生效.
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
//
///*********************************************显示函数*****************************************************/
//void myDisplay()
//{
//	// 清除屏幕
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	//调用绘制函数
//	drawscence();
//	drawprojector();
//	drawdesks();
//	drawchairs();
//	//glFlush();//清空缓冲区
//	    /*不考虑信息缓存区是否放满，强制主机把命令传输出去(在单机操作系统中)。
//		在高档体系结构中，每种操作是由图形硬件的不同部分分别执行的，CPU控制，
//		这样才可以保证计算机资源的充分利用，提高作图质量和作图速度。   
//		在这个协调工作的计算机系统中，CPU是一个把命令一条一条地分送给作图硬件，
//		而是把命令放在一个缓存区中，成批成批地分送到执行硬件中。
//		这就存在着一个 如果缓存区未满情况下，强行让硬件操作的问题。
//		在特殊的情况下，可以要求作图硬件系统完成某项操作后，CPU继续做其它的事情.
//		OpenGL中提供了解决这个问题的操作。glFlush()函数就是这个用处*/
//	   /*  将指令送往缓硬件立即执行，但是它是将命令传送完毕之后立即返回，不会等待指令执行完毕。这些指令会在有限时间内执行完毕。
//		如果直接绘制到前缓冲，那么OpenGL的绘制将不会有任何延迟。
//		设想有一个复杂的场景，有很多物体需要绘制。当调用glFlush时，物体会一个一个地出现在屏幕上。
//		但是，如果使用双缓冲，这个函数将不会有什么影响，因为直到交换缓冲区的时候变化才显现出来。*/
//
//	drawClock();
//	// 刷新
//	glFlush();
//
//
//}
////时间的回调函数
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
//	//// 设置窗口为白色
//	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//	// 获取本地当前时间
//	SYSTEMTIME sys;
//	GetLocalTime(&sys);
//	h = sys.wHour;
//	m = sys.wMinute;
//	s = sys.wSecond;
//}
//
///*******************************************响应普通键盘操作，w，s，a，d以及退出esc键*******************************/
//GLvoid OnKeyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 97://a
//		myEye.x -= 0.5;
//		vPoint.x -= 0.5;
//		if (myEye.x <= -40)
//			myEye.x = -40;
//		break;
//	case 100://d
//		myEye.x += 0.5;
//		vPoint.x += 0.5;
//		if (myEye.x >= 40)
//			myEye.x = 40;
//		break;
//	case 119://w
//		myEye.z -= 0.5;
//		if (myEye.z <= -30)
//			myEye.z = -30;
//		break;
//	case 115://s
//		myEye.z += 0.5;
//		if (myEye.z >= 30)
//			myEye.z = 30;
//		break;
//	case 27://esc
//		exit(0);
//
//	}
//	reshape(WinWidth, WinHeight);//窗口刷新
//	glutPostRedisplay();
//
//}
///****************************************响应特殊键盘操作******************************************************/
//GLvoid OnSpecial(int key, int x, int y)//上下左右
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
//		break;
//	case GLUT_KEY_DOWN:
//		myEye.y -= 0.5;
//		if (myEye.y <= 0)
//			myEye.y = 30;
//		break;
//	case GLUT_KEY_PAGE_DOWN://PageDown键
//		myEye.z += 0.5;
//		if (myEye.z >= 30)
//			myEye.z = 30;
//		break;
//	case GLUT_KEY_PAGE_UP://PageUp键
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
//		glEnable(GL_LIGHT1);
//		break;
//	case GLUT_KEY_F4:
//		glDisable(GL_LIGHT1);
//	}
//	reshape(WinWidth, WinHeight);
//	glutPostRedisplay();
//}
//GLvoid OnIdle()
//{
//	glutPostRedisplay();
//}
///*************************************初始化函数，对各项参数进行初始化*********************************************/
//void initial()
//{
//	glClearColor(0, 0, 0, 0);
//	glEnable(GL_TEXTURE_2D);
//	/*设置纹理跟材质的融合方式，这里是只是用纹理，覆盖模型的材质*/
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//	/*********************************************对灯光进行初始化****************************************************/
//	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);//将背景光设定为全局值
//	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);//把无限远的观察点改为局部观察点
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//指定物体前面镜面反射的颜色
//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//指定物体前面镜面反射的指数
//	/*设置点光源*/
//	/*GL_POSITION指定光源位置，GL_AMBIENT表示各种光线照射到该材质上，经过很多次反射后最终遗留在环境中的光线强度（颜色）。
//	GL_DIFFUSE表示光线照射到该材质上，经过漫反射后形成的光线强度（颜色）。GL_SPECULAR表示光线照射到该材质上，
//	经过镜面反射后形成的光线强度（颜色）。通常，GL_AMBIENT和GL_DIFFUSE都取相同的值，可以达到比较真实的效果。*/
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light);
//
//	/*设置平行光源*/
//	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
//	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
//	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_COLOR_MATERIAL);//激活
//
//	/**********************************************************************************************/
//	/*glShadeModel函数用于控制opengl中绘制指定两点间其他点颜色的过渡模式，
//	GL_SMOOTH（默认）将制定的两点颜色进行插值，绘制之间的其他点*/
//	glShadeModel(GL_SMOOTH);
//	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);	//指定材料着色的面
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);	//指定材料对镜面光的反射
//	glEnable(GL_DEPTH_TEST);//	
//}
//void print()
//{
//	printf("**************************************************** \n");
//	printf(" \n");
//	printf("操作按键信息提示： \n");
//	printf("上键和下键分别控制视角向下和向上 \n");
//	printf("左键和右键分别控制向左环视和向右环视 \n");
//	printf("w,s,a,d键分别表示向前，后，左，右，进行平移（注意键盘大小写）\n");
//	printf("pgup和pgdn分别控制向前漫游和向后漫游 \n");
//	printf("F3、F4键分别控制开灯、关灯 \n");
//	printf("F1、F2键分别控制投影仪放下和收起 \n");
//	printf("ESC键退出窗口 \n");
//	printf(" \n");
//	printf("**************************************************** \n");
//	printf("***************最后，编者有话要说********************** \n");
//	printf("*********首先感谢网上面各种openGL的学习资料以及例子程序********** \n");
//	printf("********教室整体风格还是不够显真实,但编者是尽量模仿东大教室风格...***** \n");
//	printf("*******前面墙和后面墙以及天花板是贴的纹理,导致并没有反应出灯光的效果*** \n");
//	printf("****还有很多可改进的地方我知道，但还是花了很多很多时间...***\n");
//	printf("************************敬请老师批评指正！************************ \n");
//	printf("**************************************************** ");
//
//}
//int main(int argc, char* argv[])
//{
//	myEye.x = 0;
//	myEye.y = 15;
//	myEye.z = 25;
//	vPoint.x = 0;
//	vPoint.y = 15;
//	vPoint.z = -30;
//	vAngle = 0;
//	/*启用了之后，OpenGL在绘制的时候就会检查，当前像素前面是否有别的像素，
//	如果别的像素挡道了它，那它就不会绘制，也就是说，OpenGL就只绘制最前面的一层。*/
//	glEnable(GL_DEPTH_TEST);
//	glutInit(&argc, argv);
//
//
//	/*定义显示方式，GLUT_RGBA指定一个RGBA窗口，GLUT_SINGLE.单缓冲区窗口*/
//	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
//
//	glutInitWindowPosition(400, 0);//设置初始窗口的位置(窗口左上角相对于桌面坐标(x,y))
//	glutInitWindowSize(800, 600);//设置窗口大小
//	glutCreateWindow("classroom");
//	initial();
//	//gluOrtho2D(0.0, Width, 0.0, Height);
//	SetupRC();//（2）
//	glutDisplayFunc(&myDisplay);
//	glutTimerFunc(1000, timerFunc, 1);//（1）
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(OnKeyboard);
//	glutSpecialFunc(OnSpecial);
//	glutIdleFunc(OnIdle);//设置全局的回调函数
//
//	//glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	////设置窗口左上角的位置  
//	////glutInitWindowPosition(100, 100);
//	////设置窗口的宽高  
//	//glutInitWindowSize(Width, Height);
//
//	//glutCreateWindow("时钟程序");
//
//	////观察参数：x坐标值从0到200，y是从0到150  
//	//gluOrtho2D(0.0, Width, 0.0, Height);
//
//	//SetupRC();
//
//	//glutDisplayFunc(&myDisplay);
//	//glutTimerFunc(1000, timerFunc, 1);
//
//
//
//	/***************************************设置纹理***********************************************/
//	texblackboard = load_texture("blackboard.bmp");
//	texwindow = load_texture("window.bmp");
//	texsound = load_texture("sound.bmp");
//	texceiling = load_texture("ceiling.bmp");
//	texdoor = load_texture("door.bmp");
//	texfloor = load_texture("floor.bmp");
//	texbackwall = load_texture("backwall.bmp");
//	texpole = load_texture("pole.bmp");
//	texairfro = load_texture("airconditionfront.bmp");
//	texairback = load_texture("airconditionback.bmp");
//	texgaodi = load_texture("gaodi.bmp");
//	texsdesk = load_texture("sdesk.bmp");
//	texclock = load_texture("clock.bmp");
//	/************************************************************************************************/
//	print();
//	//开始显示
//	glutMainLoop();
//	return 0;
//}