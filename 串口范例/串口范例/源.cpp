/*! \file doc_0.cpp
	\brief 样例程序0 最简单的应用
*/

#include <locale.h>
#include <iostream>
#include "D:\Users\Azk\Desktop\專題\串口范例\CnComm\CnComm\Src\CnComm.h"


//! 样例程序0
class HelloComm : public CnComm
{	//! \sa CnComm::OnReceive()
	void OnReceive()
	{
		TCHAR buffer[1024];
		setlocale(LC_ALL, "chs");// Unicode下中文显示不出 配置一下 CBC 不支持 "chs"
		_tprintf(_T("\nRecv:%s\n"), ReadString(buffer, 1024));
	}
};
//! Main()  COM1 ---字符串----> COM4 (波特率9600)
int main()
{
	HelloComm Com;//! 默认模式 重叠IO 监视线程
	int CP = 4;
	Com.Open(CP, 9600);

	std::cout << "Com:" << CP <<"已打开"<< std::endl;
	system("pause");//暂停
	Com.Write(_T("Hello world 爱的飒飒大大1"));


	system("pause");//暂停

	return 0;
}

