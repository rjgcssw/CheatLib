// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include <Console.hpp>
#include <ImGuiDx11Hook.hpp>
using namespace DX11Hook;

void draw() {
    ImGui::Begin("HookTest");
    ImGui::Text("FPS:%f", ImGui::GetIO().Framerate);
    ImGui::End();
}
BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Console::StartConsole("Console", false);
        LOGINFO("Start D3D11HOOK!");
        if (installDX11Hook(&draw, hModule, ".\\ImGui.ini", 13, nullptr, NULL, NULL, NULL, NULL)) {
            LOGINFO("HOOKD3D11 Done!");
        }
        else {
            LOGERROR("HOOKD3D11 ERROR!");
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

