#include "bits/stdc++.h"
#include "GL/glut.h"
#include "GL/gl.h"

namespace {
	const int BOARD_SIZE = 8;
	const int NONE = 0;
	const int BLACK = 1;
	const int WHITE = 2;

	int screenWidth = 800, screenHeight = 800, turn = 0;
	char board[BOARD_SIZE][BOARD_SIZE];
}

void showStone() {
	//盤面に配置された石の描画
	glPointSize(60);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == BLACK) {
				//黒石の描画
				glColor3d(0, 0, 0);
				glBegin(GL_POINTS);
				glVertex2i(120 + 80 * i, 120 + 80 * j);
				glEnd();
			}
			else if (board[i][j] == WHITE) {
				//白石の描画
				glColor3d(1, 1, 1);
				glBegin(GL_POINTS);
				glVertex2i(120 + 80 * i, 120 + 80 * j);
				glEnd();
			}
		}
	}
}


void mouse(int button, int state, int x, int y) {
	int i = 0, j = 0;
	std::cout << "turn : " << turn << std::endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//ウィンドウ内をクリックしたときの処理
		std::cout << "(x, y) == (" << x << "," << y << ")" << std::endl;

		//クリックした箇所が盤上でない時→処理終了
		if (x < 80 || x > 720 || y < 80 || y > 720) {
			return;
		}
		else {
			//クリックされた座標(x, y)から盤上の座標(i, j)への変換
			i = x/80;
			j = y/70;

			std::cout << "(i, j) == (" << i << "," << j << ")" << std::endl;

			//クリックされた箇所に新規に石を配置する
			//奇数ターンであれば黒、偶数ターンであれば白
			if (turn % 2 == 0) {
				board[i-1][j-1] = WHITE;
				std::cout << "WHITE" << std::endl;
			}
			else {
				board[i-1][j-1] = BLACK;
				std::cout << "BLACK" << std::endl;
			}

			std::cout << std::endl;

			turn++;

			//描画実行
			showStone();
			glFlush();
		}
	}

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//盤面のマス目作成
	glColor3d(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);

	for (int i = 0; i <= BOARD_SIZE; i++) {
		glVertex2i(80 + 80 * i, 720);
		glVertex2i(80 + 80 * i, 80);

		glVertex2i(80, 80 + 80 * i);
		glVertex2i(720, 80 + 80 * i);
	}
	glEnd();

	//盤面上の4点の描画
	glColor3d(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(240, 240);
	glVertex2i(240, 560);
	glVertex2i(560, 240);
	glVertex2i(560, 560);
	glEnd();

	showStone();
	glFlush(); //描画実行


}

void setup() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 5);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("Othello");
	gluOrtho2D(0, screenWidth, screenHeight, 0); //座標系指定

	//初期盤面生成
	glClearColor(0, 0.5, 0, 1); //背景色設定

	//以下石の初期配置
	for (int i=0; i < BOARD_SIZE * BOARD_SIZE; i++)
		board[i / BOARD_SIZE][i % BOARD_SIZE] = NONE;

	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = BLACK;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = BLACK;

	board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = WHITE;
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	setup();
	glutMouseFunc(mouse);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}