/*! \file doc_0.cpp
	\brief ��������0 ��򵥵�Ӧ��
*/

#include <locale.h>
#include <iostream>
#include "D:\Users\Azk\Desktop\���}\���ڷ���\CnComm\CnComm\Src\CnComm.h"


//! ��������0
class HelloComm : public CnComm
{	//! \sa CnComm::OnReceive()
	void OnReceive()
	{
		TCHAR buffer[1024];
		setlocale(LC_ALL, "chs");// Unicode��������ʾ���� ����һ�� CBC ��֧�� "chs"
		_tprintf(_T("\nRecv:%s\n"), ReadString(buffer, 1024));
	}
};
//! Main()  COM1 ---�ַ���----> COM4 (������9600)
int main()
{
	HelloComm Com;//! Ĭ��ģʽ �ص�IO �����߳�
	int CP = 4;
	Com.Open(CP, 9600);

	std::cout << "Com:" << CP <<"�Ѵ�"<< std::endl;
	system("pause");//��ͣ
	Com.Write(_T("Hello world �����쪴��1"));


	system("pause");//��ͣ

	return 0;
}

