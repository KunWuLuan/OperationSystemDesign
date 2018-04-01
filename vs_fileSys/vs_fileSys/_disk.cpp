#include"_disk.h"
#include<stdio.h>
const int Disk::diskCapacity = 512 * 2 * 1024;
string Disk::fileSysPath="D:/fileSys.vd";
fstream Disk::fileSys;

void Disk::init()
{
	logger logger("Disk");
	cout << "--�ļ�ϵͳ��ʼ��ʼ��" << endl;
	while (1) {
		cout << "--���봴�����̵�λ��(�ļ�λ�ò�Ҫ����ո�)\nĬ������yes(Ĭ��ΪD:/fileSys.vd):" << endl;
		string path;
		cin >> path;
		if ("yes" != path)
			fileSysPath = path;
		cout << "--��ʼΪ���̷���ռ�" << endl;
		fileSys.open(fileSysPath, ios::in);
		if (fileSys) {
			logger.debug("�ļ��Ѵ��ڣ�Ҫ������?[no]/[yes](������Ϊno)");
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
		logger.error("���ļ�ʧ��");
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
				string msg = "ɾ��ʧ�ܣ����ֶ�ɾ���ļ�[";
				msg += fileSysPath;
				msg += ']';
			}
			exit(-1);
		}
		pos=fileSys.tellp();
		stringstream ss;
		ss << "���" << (pos / diskCapacity)*100<<'%';
		string tmp;
		ss >> tmp;
		logger.debug(tmp);
	}

	logger.debug("��ʼ���ɹ�");
}