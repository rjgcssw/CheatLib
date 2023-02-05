#include <ImGuiDx11Draw.hpp>
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
#include <iostream>
#include <fmt/format.h>
namespace ImGuiDraw {
    static ID3D11Device* g_pd3dDevice = NULL;
    static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
    static IDXGISwapChain* g_pSwapChain = NULL;
    static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;
    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    struct
    {
        void(*Drawing_)();
        HMODULE Module_;
        std::string ImGuiInIFile_;
        float FontSize_;
        unsigned char* Font_;
        ImVec2 WindowsSize_;
        bool transparent_;
        bool canreturn;
        HWND imDrawHwnd;
        bool done_;
        ImVec4 clear_color_;
        bool vsync;
    }ImDrawInfo;
    void CreateImGui() {
        if (ImDrawInfo.transparent_)
        {
            WNDCLASSEX wc;
            wc.cbClsExtra = NULL;
            wc.cbSize = sizeof(WNDCLASSEX);
            wc.cbWndExtra = NULL;
            wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
            wc.hCursor = LoadCursor(0, IDC_ARROW);
            wc.hIcon = LoadIcon(0, IDI_APPLICATION);
            wc.hIconSm = LoadIcon(0, IDI_APPLICATION);
            wc.hInstance = GetModuleHandle(NULL);
            wc.lpfnWndProc = (WNDPROC)WndProc;
            wc.lpszClassName = "ImGui";
            wc.lpszMenuName = "ImGui Draw";
            wc.style = CS_VREDRAW | CS_HREDRAW;
            RegisterClassEx(&wc);
            ImDrawInfo.imDrawHwnd = ::CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED /*| WS_EX_TRANSPARENT*/ | WS_EX_TOOLWINDOW /*| WS_EX_NOREDIRECTIONBITMAP*/, wc.lpszClassName, wc.lpszMenuName, WS_POPUP, 0, 0, ImDrawInfo.WindowsSize_.x, ImDrawInfo.WindowsSize_.y, NULL, NULL, wc.hInstance, NULL);
            SetLayeredWindowAttributes(ImDrawInfo.imDrawHwnd, 0, 1.0f, LWA_ALPHA);
            SetLayeredWindowAttributes(ImDrawInfo.imDrawHwnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
            ImDrawInfo.clear_color_ = ImGui::ColorConvertU32ToFloat4(RGB(0, 0, 0));
        }
        else
        {
            WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, L"ImGui", NULL};
            ::RegisterClassExW(&wc);
            ImDrawInfo.imDrawHwnd = ::CreateWindowW(wc.lpszClassName, L"Dear ImGui DirectX11 Example", WS_OVERLAPPEDWINDOW, 100, 100, ImDrawInfo.WindowsSize_.x, ImDrawInfo.WindowsSize_.y, NULL, NULL, wc.hInstance, NULL);
        }
        LOGDEBUG("HWND:");
        std::cout << std::hex << ImDrawInfo.imDrawHwnd << std::endl;
        if (!CreateDeviceD3D(ImDrawInfo.imDrawHwnd))
        {
            CleanupDeviceD3D();
            ::UnregisterClassW(NULL, NULL);
            return;
        }
        if (ImDrawInfo.transparent_)//È¥³ý¿¹¾â³ÝºÚ±ß
        {
            MARGINS margins = { -1, -1, -1, -1 };
            DWM_BLURBEHIND bb = { 0 };
            DwmExtendFrameIntoClientArea(ImDrawInfo.imDrawHwnd, &margins);
            bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
            bb.fEnable = true;
            bb.hRgnBlur = NULL;
            DwmEnableBlurBehindWindow(ImDrawInfo.imDrawHwnd, &bb);
            ::ShowWindow(ImDrawInfo.imDrawHwnd, SW_SHOW);
            ::UpdateWindow(ImDrawInfo.imDrawHwnd);
        }
        else {
            ::ShowWindow(ImDrawInfo.imDrawHwnd, SW_SHOWDEFAULT);
            ::UpdateWindow(ImDrawInfo.imDrawHwnd);
        }
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImPlot::CreateContext();
        ImNodes::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        if (ImDrawInfo.Font_ != nullptr)
        {
            io.Fonts->AddFontFromMemoryTTF(ImDrawInfo.Font_, sizeof(ImDrawInfo.Font_), ImDrawInfo.FontSize_, NULL, io.Fonts->GetGlyphRangesChineseFull());
        }
        else
        {
            io.Fonts->AddFontFromMemoryTTF(Font::getallfont(), sizeof(Font::getallfont()), ImDrawInfo.FontSize_, NULL, io.Fonts->GetGlyphRangesChineseFull());
        }
        if (ImDrawInfo.ImGuiInIFile_ == "")
        {
            static const std::string imguiPath = std::string(Process::GetModuleFile(ImDrawInfo.Module_) + "\\imgui.ini");
            io.IniFilename = imguiPath.c_str();
        }
        else
        {
            static const std::string imguiPath = ImDrawInfo.ImGuiInIFile_;
            io.IniFilename = imguiPath.c_str();
        }
        io.SetPlatformImeDataFn = nullptr; // F**king bug take 4 hours of my life
        ImGui::StyleColorsDark();
        ImGui_ImplWin32_Init(ImDrawInfo.imDrawHwnd);
        ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
        ImDrawInfo.done_ = true;
        ImDrawInfo.canreturn = ImDrawInfo.done_;
        bool done = false;
        while (!done)
        {
            DWORD dwStyle = GetWindowLong(ImDrawInfo.imDrawHwnd, GWL_EXSTYLE ^ WS_EX_LAYERED);
            if (dwStyle & WS_BORDER)
            {
                //WindowRectangle.top += 23;
               // WindowHeight -= 23;
            }
            MSG msg;
            while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
            {
                ::TranslateMessage(&msg);
                ::DispatchMessage(&msg);
                if (msg.message == WM_QUIT)
                    done = true;
            }
            if (done)
                break;
            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();
            ImDrawInfo.Drawing_();
            ImGui::EndFrame();
            ImGui::Render();
            const float clear_color_with_alpha[4] = { ImDrawInfo.clear_color_.x * ImDrawInfo.clear_color_.w, ImDrawInfo.clear_color_.y * ImDrawInfo.clear_color_.w, ImDrawInfo.clear_color_.z * ImDrawInfo.clear_color_.w, ImDrawInfo.clear_color_.w };
            g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
            g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
            if(ImDrawInfo.vsync)
            {
                g_pSwapChain->Present(1, 0); // Present with vsync
            }
            else
            {
                g_pSwapChain->Present(0, 0); // Present without vsync
            }
        }
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
        CleanupDeviceD3D();
        ::DestroyWindow(ImDrawInfo.imDrawHwnd);
        ::UnregisterClassW(NULL, NULL);
        return;
    }
    HWND CreateImGuiDx11Draw(void(*Drawing)(), HMODULE Module, std::string ImGuiInIFile, float FontSize, unsigned char* Font,ImVec2 WindowsSize, ImVec4 clear_color,bool transparent,bool vsync, ID3D11Device** DX11D3D11Device, ID3D11DeviceContext** DX11D3D11DeviceContext, ID3D11RenderTargetView** DX11D3D11RenderTargetView, IDXGISwapChain** DX11SwapChain) {
        ImDrawInfo.Drawing_ = Drawing;
        ImDrawInfo.Module_ = Module;
        ImDrawInfo.ImGuiInIFile_ = ImGuiInIFile;
        ImDrawInfo.FontSize_ = FontSize;
        ImDrawInfo.Font_ = Font;
        ImDrawInfo.WindowsSize_ = WindowsSize;
        ImDrawInfo.transparent_ = transparent;
        ImDrawInfo.clear_color_ = clear_color;
        ImDrawInfo.vsync = vsync;
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)CreateImGui, NULL, NULL, NULL);
        while (!ImDrawInfo.canreturn)
        {
            Sleep(1);
        }
        try
        {
            *DX11D3D11Device = g_pd3dDevice;
            *DX11D3D11DeviceContext = g_pd3dDeviceContext;
            *DX11D3D11RenderTargetView = g_mainRenderTargetView;
            *DX11SwapChain = g_pSwapChain;
        }
        catch (...)
        {
            LOGERROR("Point Address is NULL\n");
        }
        LOGDEBUG(fmt::format("D3D11Device:{}\n", (INT64)g_pd3dDevice));
        LOGDEBUG(fmt::format("D3D11DeviceContext:{}\n", (INT64)g_pd3dDeviceContext));
        LOGDEBUG(fmt::format("D3D11RenderTargetView:{}\n", (INT64)g_mainRenderTargetView));
        LOGDEBUG(fmt::format("SwapChain:{}\n", (INT64)g_pSwapChain));
        return ImDrawInfo.imDrawHwnd;
    }
    bool CreateDeviceD3D(HWND hWnd)
    {
        DXGI_SWAP_CHAIN_DESC sd;
        ZeroMemory(&sd, sizeof(sd));
        sd.BufferCount = 2;
        sd.BufferDesc.Width = 0;
        sd.BufferDesc.Height = 0;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
        sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
        sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.OutputWindow = hWnd;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.Windowed = TRUE;
        sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
        UINT createDeviceFlags = 0;
        D3D_FEATURE_LEVEL featureLevel;
        const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
        if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext) != S_OK)
            return false;
        CreateRenderTarget();
        return true;
    }
    void CleanupDeviceD3D()
    {
        CleanupRenderTarget();
        if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = NULL; }
        if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = NULL; }
        if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    }
    void CreateRenderTarget()
    {
        ID3D11Texture2D* pBackBuffer;
        g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
        g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
        pBackBuffer->Release();
    }
    void CleanupRenderTarget()
    {
        if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL; }
    }
    LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
            return true;
        if (ImDrawInfo.done_) {
            ImGuiIO& io = ImGui::GetIO();
            POINT mPos;
            GetCursorPos(&mPos);
            ScreenToClient(hWnd, &mPos);
            ImGui::GetIO().MousePos.x = static_cast<float>(mPos.x);
            ImGui::GetIO().MousePos.y = static_cast<float>(mPos.y);
        }
        short key;
        bool keyUpEvent = true;
        switch (msg)
        {
        case WM_SIZE:
            if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
            {
                CleanupRenderTarget();
                g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);
                CreateRenderTarget();
            }
            return 0;
        case WM_LBUTTONUP:
            key = VK_LBUTTON;
            break;
        case WM_RBUTTONUP:
            key = VK_RBUTTON;
            break;
        case WM_MBUTTONUP:
            key = VK_MBUTTON;
            break;
        case WM_XBUTTONUP:
            key = GET_XBUTTON_WPARAM(wParam) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
            break;
        case WM_KEYUP:
            key = static_cast<short>(wParam);
            break;
        default:
            keyUpEvent = false;
            break;
        case WM_SYSCOMMAND:
            if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
                return 0;
            break;
        case WM_DESTROY:
            ::PostQuitMessage(0);
            return 0;
        }
        return ::DefWindowProc(hWnd, msg, wParam, lParam);
    }
}