#pragma once
#include"_disk.h"
class _diskInode {
public:
	int d_size;
	int d_addr[10];
	int padding[5];//���
};//64�ֽ�һ��diskinode


class _superBlock {
public:
	int s_isize;//���inode��ռ�õ��̿���
	int s_fsize;//�̿�����

	int s_nfree;//ֱ�ӹ���Ŀ����̿�����
	int s_free[50];

	int s_ninode;//ֱ�ӹ���Ŀ������inode����
	int s_inode[50];

	int padding[24];//��䵽512�ֽ�
};

void s_init(_superBlock *s);
