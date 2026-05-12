#include "Window.h"

bool applicationState = true;

Window::Window(const wchar_t* ClassName, const wchar_t* WindowText, HINSTANCE hInstance, int nCmdShow)
{
	this->WindowText = WindowText;
	this->CLASS_NAME = ClassName;
    this->hInstance = &hInstance;
    this->nCmdShow = nCmdShow;

    registerWindowClass();

    //Create window
    handler = CreateWindowEx(
        0,                              // Optional window styles.
        this->CLASS_NAME,                     // Window class
        this->WindowText,    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );
}

void Window::registerWindowClass()
{
	WindowClass.lpfnWndProc = WindowProc;
	WindowClass.hInstance = *hInstance;
	WindowClass.lpszClassName = CLASS_NAME;

	RegisterClass(&WindowClass);

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        //PostQuitMessage(0);
        applicationState = false;
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}