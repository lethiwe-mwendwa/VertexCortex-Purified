#include "Window.h"

Window::Window(const wchar_t* ClassName, const wchar_t* WindowText, HINSTANCE hInstance, int nCmdShow)
{

    mainBuffer = nullptr;

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

		    delete window->mainBuffer;
		    window->mainBuffer = new frameBuffer(width, height);

            // Turn the window red!
		    window->mainBuffer->clear(0x00FF0000);

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

frameBuffer::frameBuffer(size_t width, size_t height)
{
    colourBuffer = new uint32_t[height * width];

    this->width = width;
    this->height = height;

    bitmapInfo = {};
    bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biWidth = width;
    bitmapInfo.bmiHeader.biHeight = -(LONG)height;
    bitmapInfo.bmiHeader.biPlanes = 1;
    bitmapInfo.bmiHeader.biBitCount = 32;
    bitmapInfo.bmiHeader.biCompression = BI_RGB;
}

frameBuffer::~frameBuffer()
{
    delete[] colourBuffer;
}

void frameBuffer::clear(uint32_t colour)
{
    for(int i = 0; i < height * width; i++){
        colourBuffer[i] = colour;
    }
}

void frameBuffer::setPixel(size_t x, size_t y, uint32_t colour)
{
    if ((y >= height) || (x >= width)){
        return;
    }
    colourBuffer[y * width + x] = colour;
}

const uint32_t* frameBuffer::getColourData()
{
    return colourBuffer;
}

void frameBuffer::present(HDC deviceContext)
{
    // win32 stuff
    StretchDIBits(
        deviceContext,  // destination
        0,              // dest x
        0 ,              // dest y
        width ,              // dest width
        height ,              // dest height
        0 ,              // source x
        0 ,              // source y
        width,              // source width
        height,              // source height
        colourBuffer ,              // your pixel data
        &bitmapInfo,              // your bitmapInfo
        DIB_RGB_COLORS,              // color format flag
        SRCCOPY               // raster operation
    );

}

uint32_t frameBuffer::packColor(uint8_t r, uint8_t g, uint8_t b)
{
    return (r) | (g << 8) | (b << 16);
}