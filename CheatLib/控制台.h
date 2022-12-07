#pragma once
#include <Windows.h>
#include <string>
#define 输出调试(文本,...) 控制台输出::控制台输出(控制台输出::调试,文本,__FILE__,__LINE__)
#define 输出信息(文本,...) 控制台输出::控制台输出(控制台输出::信息,文本,__FILE__,__LINE__)
#define 输出警告(文本,...) 控制台输出::控制台输出(控制台输出::警告,文本,__FILE__,__LINE__)
#define 输出错误(文本,...) 控制台输出::控制台输出(控制台输出::错误,文本,__FILE__,__LINE__)
namespace 控制台输出 {
	enum 输出类型 : short int {
		信息,
		调试,
		警告,
		错误
	};
	enum 输出颜色 : short int {
		黑色,
		蓝色,
		绿色,
		浅绿色,
		红色,
		紫色,
		黄色,
		白色,
		灰色,
		淡蓝色,
		淡绿色,
		淡浅绿色,
		淡红色,
		淡紫色,
		淡黄色,
		亮白色
	};
	void 控制台输出(输出类型 类型, std::string 文本, std::string 文件, int 行号);
	HWND 开启控制台(const char* 标题, bool 是否可以关闭);
	void 关闭控制台();
}