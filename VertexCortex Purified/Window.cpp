#include "Window.h"

Window::Window(const wchar_t* ClassName, const wchar_t* WindowText, HINSTANCE hInstance, int nCmdShow)
{

    mainBuffer = nullptr;
    timer = Clock();

	this->WindowText = WindowText;
	this->CLASS_NAME = ClassName;
    //this->hInstance = hInstance;
    //this->nCmdShow = nCmdShow;

    // this is where windowProc is set etc
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
        this   // <--- allows us to access window!
    );

    isRunning = true;

}

Window::~Window()
{

}

void Window::display()
{
    HDC hdc = GetDC(handler);
    mainBuffer->present(hdc);
    ReleaseDC(handler, hdc);
}

void Window::registerWindowClass()
{
	WindowClass.lpfnWndProc = WindowProc;
	WindowClass.hInstance = hInstance;
	WindowClass.lpszClassName = CLASS_NAME;

	RegisterClass(&WindowClass);

}

LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    Window* window = nullptr;

    if (uMsg == WM_NCCREATE)
    {
        // The struckt with window info!
        CREATESTRUCT* cs = (CREATESTRUCT*)lParam;
        window = (Window*)cs->lpCreateParams;

        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)window);

        window->handler = hwnd;
        return TRUE;
    }

    window = (Window*)GetWindowLongPtr(hwnd, GWLP_USERDATA);

    switch (uMsg)
    {
	    case WM_DESTROY:
		    //PostQuitMessage(0);
		    window->isRunning = false;
		    return 0;

	    case WM_SETCURSOR:
	    {
		    if (LOWORD(lParam) == HTCLIENT)
		    {
			    SetCursor(LoadCursor(NULL, IDC_ARROW));
			    return TRUE;
		    }
		    return DefWindowProc(hwnd, uMsg, wParam, lParam);
	    }
	    case WM_SIZE:
	    {
		    size_t width = LOWORD(lParam);
		    size_t height = HIWORD(lParam);

            // instead of resizing here, just toggle a resize flag and then resize in the main loop.

            if (width == 0 || height == 0) return 0;

		    delete window->mainBuffer;
		    window->mainBuffer = new frameBuffer(width, height);

		    return 0;
	    }

	    case WM_PAINT:
	    {
		    if (window->mainBuffer != nullptr) {

			    PAINTSTRUCT ps;
			    HDC hdc = BeginPaint(hwnd, &ps);

			    window->mainBuffer->present(hdc);

			    EndPaint(hwnd, &ps);
		    }
		    return 0;

	    }

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
