#include <控制台.h>
#include <进程.hpp>
#include <stdio.h>
int main()
{
	进程::取模块路径((HMODULE)(-1));
	输出信息("Hello Word\n");
	输出警告("Hello Word\n");
	输出调试("Hello Word\n");
	输出错误("Hello Word\n");
	system("pause");
}
