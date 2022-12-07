#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#pragma comment (lib, "D3dcompiler.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
namespace DX11钩子 {
	bool 安装DX11钩子(void (*绘制循环)(), HMODULE 模块句柄, std::string ImGui配置目录, float 字体大小, unsigned char* 字体, ID3D11Device* DX11设备指针, ID3D11DeviceContext* DX11设备描述, ID3D11RenderTargetView* DX11主渲染目标视图, IDXGISwapChain* DX11交换链);
}