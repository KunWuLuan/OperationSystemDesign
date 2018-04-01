#include"_disk.h"
#include<stdio.h>
const int Disk::diskCapacity = 512 * 2 * 1024;
string Disk::fileSysPath="D:/fileSys.vd";
fstream Disk::fileSys;

void Disk::init()
{
	logger logger("Disk");
	cout << "--文件系统开始初始化" << endl;
	while (1) {
		cout << "--输入创建磁盘的位置(文件位置不要输入空格)\n默认输入yes(默认为D:/fileSys.vd):" << endl;
		string path;
		cin >> path;
		if ("yes" != path)
			fileSysPath = path;
		cout << "--开始为磁盘分配空间" << endl;
		fileSys.open(fileSysPath, ios::in);
		if (fileSys) {
			logger.debug("文件已存在，要覆盖吗?[no]/[yes](其他视为no)");
			string ans;
			cin >> ans;
			if ("yes" == ans) {
				break;
			}
		}
		else
			break;
	}
	fileSys.open(fileSysPath, ios::out);
	if (!fileSys) {
		logger.error("打开文件失败");
		exit(-1);
	}
	fileSys.close();
	fileSys.open(fileSysPath, ios::out |ios::in| ios::binary);
	char *buffer=new char[1024 * 1024];
	memset(buffer, 0, sizeof(char) * 1024 * 1024);
	int pos=0;
	while (pos < diskCapacity-1) {
		try {
			fileSys.write(buffer, diskCapacity - pos);
		}
		catch (std::exception & e) {
			string msg = "exception caught: ";msg+=e.what();
			logger.error(msg);
			fileSys.close();
			int res=remove(fileSysPath.c_str());
			if (res == -1) {
				string msg = "删除失败，请手动删除文件[";
				msg += fileSysPath;
				msg += ']';
			}
			exit(-1);
		}
		pos=fileSys.tellp();
		stringstream ss;
		ss << "完成" << (pos / diskCapacity)*100<<'%';
		string tmp;
		ss >> tmp;
		logger.debug(tmp);
	}

	logger.debug("初始化成功");
}