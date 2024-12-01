#include <windows.h>

	#define MAX_NAME_STRING 256
	#define HInstance() GetModuleHandle(NULL)

	WCHAR		WindowClass[MAX_NAME_STRING];
	WCHAR		WindowTitle[MAX_NAME_STRING];

	INT			WindowWidth;
	INT			WindowHeight;
	
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	/* - Initialize Global Variables - */
	wcscpy_s(WindowClass, TEXT("TutorialOneClass"));
	wcscpy_s(WindowTitle, TEXT("First Window"));
	WindowWidth = 1440;
	WindowHeight = 810;
	/* - Create Window Class - */
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = DefWindowProc;

	RegisterClassEx(&wcex);

	/* - Create and Display our Window - */

	HWND hwnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hwnd)
	{
		MessageBox(0, L"Failaed to Create Window!.", 0, 0);
		return 0;
	}

	ShowWindow(hwnd, SW_SHOW);

	/* - Listen for Message events - */

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		//if there are messages process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}