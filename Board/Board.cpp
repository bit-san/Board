#include "bits/stdc++.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define WW 500	//�E�C���h�E�̕�
#define WH 500	//�E�C���h�E�̍���

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�o�b�t�@�̃N���A
	//���C����`��
	glColor3f(0, 0, 0);//���̐F�̎w��
	glLineWidth(3);//�����̎w��B�ȗ��B�w�肵�Ȃ����1�B
	glBegin(GL_LINES);	//����
	for (int i = 0; i < 9; i++) {
		//�E�C���h�E�T�C�Y��x:0~800,y:0~800�ɕ����Ă���
		glVertex2i(80 + 80 * i, 720);//�c����[
		glVertex2i(80 + 80 * i, 80);//�c�����[
		glVertex2i(80, 80 + 80 * i);//�������[
		glVertex2i(720, 80 + 80 * i);//�����E�[
	}
	glEnd();
	glutSwapBuffers();	//�_�u���o�b�t�@�����O

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv); //�E�B���h�E��\�������邽�߂�GLUT��������
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE); //GLUT�̃f�B�X�v���C���[�h��ݒ�
	glutInitWindowSize(WW, WH);			//�E�B���h�E�̉�ʂ̕��ƍ������w��
	glutInitWindowPosition(300, 100);	//�E�B���h�E�̏ꏊ���w��
	glutCreateWindow("Othello");		//�E�B���h�E�̖��O
	glClearColor(0, 0.7, 0, 1);			//�I�Z���Ղ̐F
	gluOrtho2D(0, 800, 800, 0);			//���W�n�̐ݒ�
	glutDisplayFunc(display);			//�`��֐����w��
	glutMainLoop();						//�C�x���g����
	return 0;
}
