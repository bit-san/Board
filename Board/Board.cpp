#include "bits/stdc++.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define WW 500	//ウインドウの幅
#define WH 500	//ウインドウの高さ

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//バッファのクリア
	//ラインを描く
	glColor3f(0, 0, 0);//線の色の指定
	glLineWidth(3);//線幅の指定。省略可。指定しなければ1。
	glBegin(GL_LINES);	//直線
	for (int i = 0; i < 9; i++) {
		//ウインドウサイズをx:0~800,y:0~800に分けている
		glVertex2i(80 + 80 * i, 720);//縦線上端
		glVertex2i(80 + 80 * i, 80);//縦線下端
		glVertex2i(80, 80 + 80 * i);//横線左端
		glVertex2i(720, 80 + 80 * i);//横線右端
	}
	glEnd();
	glutSwapBuffers();	//ダブルバッファリング

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv); //ウィンドウを表示させるためにGLUTを初期化
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE); //GLUTのディスプレイモードを設定
	glutInitWindowSize(WW, WH);			//ウィンドウの画面の幅と高さを指定
	glutInitWindowPosition(300, 100);	//ウィンドウの場所を指定
	glutCreateWindow("Othello");		//ウィンドウの名前
	glClearColor(0, 0.7, 0, 1);			//オセロ盤の色
	gluOrtho2D(0, 800, 800, 0);			//座標系の設定
	glutDisplayFunc(display);			//描画関数を指定
	glutMainLoop();						//イベント処理
	return 0;
}
