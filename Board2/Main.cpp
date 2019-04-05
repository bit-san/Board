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
	//�Ֆʂɔz�u���ꂽ�΂̕`��
	glPointSize(60);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == BLACK) {
				//���΂̕`��
				glColor3d(0, 0, 0);
				glBegin(GL_POINTS);
				glVertex2i(120 + 80 * i, 120 + 80 * j);
				glEnd();
			}
			else if (board[i][j] == WHITE) {
				//���΂̕`��
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
		//�E�B���h�E�����N���b�N�����Ƃ��̏���
		std::cout << "(x, y) == (" << x << "," << y << ")" << std::endl;

		//�N���b�N�����ӏ����Տ�łȂ����������I��
		if (x < 80 || x > 720 || y < 80 || y > 720) {
			return;
		}
		else {
			//�N���b�N���ꂽ���W(x, y)����Տ�̍��W(i, j)�ւ̕ϊ�
			i = x/80;
			j = y/70;

			std::cout << "(i, j) == (" << i << "," << j << ")" << std::endl;

			//�N���b�N���ꂽ�ӏ��ɐV�K�ɐ΂�z�u����
			//��^�[���ł���΍��A�����^�[���ł���Δ�
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

			//�`����s
			showStone();
			glFlush();
		}
	}

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//�Ֆʂ̃}�X�ڍ쐬
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

	//�Ֆʏ��4�_�̕`��
	glColor3d(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(240, 240);
	glVertex2i(240, 560);
	glVertex2i(560, 240);
	glVertex2i(560, 560);
	glEnd();

	showStone();
	glFlush(); //�`����s


}

void setup() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 5);
	glutInitWindowSize(screenWidth, screenHeight);
	glutCreateWindow("Othello");
	gluOrtho2D(0, screenWidth, screenHeight, 0); //���W�n�w��

	//�����Ֆʐ���
	glClearColor(0, 0.5, 0, 1); //�w�i�F�ݒ�

	//�ȉ��΂̏����z�u
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