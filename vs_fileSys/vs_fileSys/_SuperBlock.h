#pragma once
#include"_disk.h"
class _diskInode {
public:
	int d_size;
	int d_addr[10];
	int padding[5];//填充
};//64字节一个diskinode


class _superBlock {
public:
	int s_isize;//外存inode区占用的盘块数
	int s_fsize;//盘块总数

	int s_nfree;//直接管理的空闲盘块数量
	int s_free[50];

	int s_ninode;//直接管理的空闲外存inode数量
	int s_inode[50];

	int padding[24];//填充到512字节
};

void s_init(_superBlock *s);
