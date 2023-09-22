#include <windows.h>

HWND hLeftPanel, hRightPanel;
HWND hTaoDoThiButton, hThemMotDinhButton, hThayDoiButton, hThemCanhButton;
HWND hTextBox, hButtonInRightPanel;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            // Create a text box
            CreateWindow("BUTTON", "Ma tran ke", WS_VISIBLE | WS_CHILD, 50, 70, 150, 50, hwnd, (HMENU)1, NULL, NULL);
            CreateWindow("BUTTON", "Ma tran lien ket", WS_VISIBLE | WS_CHILD, 250, 70, 150, 50, hwnd, (HMENU)2, NULL, NULL);
            CreateWindow("BUTTON", "Ma tran trong so", WS_VISIBLE | WS_CHILD, 450, 70, 150, 50, hwnd, (HMENU)3, NULL, NULL);
            CreateWindow("BUTTON", "Danh sach lien ket", WS_VISIBLE | WS_CHILD, 650, 70, 150, 50, hwnd, (HMENU)4, NULL, NULL);
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1:
                case 2:
                case 3:
                case 4:
                    ShowWindow(GetDlgItem(hwnd, 1), SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, 2), SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, 3), SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, 4), SW_HIDE);
                    hLeftPanel = CreateWindow("STATIC", NULL, WS_VISIBLE | WS_CHILD | SS_SUNKEN, 50, 50, 200, 500, hwnd, NULL, NULL, NULL);
                    hRightPanel = CreateWindow("STATIC", NULL, WS_VISIBLE | WS_CHILD | SS_SUNKEN, 300, 50, 500, 500, hwnd, NULL, NULL, NULL);
                    // Tạo ra hai nút mới
                    hTaoDoThiButton = CreateWindow("BUTTON", "Tao do thi", WS_VISIBLE | WS_CHILD, 10, 10, 150, 30, hLeftPanel, (HMENU)5, NULL, NULL);
                    hThemMotDinhButton = CreateWindow("BUTTON", "Them mot dinh", WS_VISIBLE | WS_CHILD, 10, 50, 150, 30, hLeftPanel, (HMENU)6, NULL, NULL);
                    hThayDoiButton = CreateWindow("BUTTON", "Thay doi thong tin 1 dinh", WS_VISIBLE | WS_CHILD, 10, 90, 150, 30, hLeftPanel, (HMENU)7, NULL, NULL);
                    hThemCanhButton = CreateWindow("BUTTON", "Them canh", WS_VISIBLE | WS_CHILD, 10, 130, 150, 30, hLeftPanel, (HMENU)8, NULL, NULL);
                    break;
                case 5:
                    // Hide the "Tao do thi" button
                    ShowWindow(hTaoDoThiButton, SW_HIDE);
                    
                    // Create a textbox in the right panel
                    hTextBox = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL, 10, 10, 150, 30, hRightPanel, (HMENU)9, NULL, NULL);
                    
                    // Create a button in the right panel
                    hButtonInRightPanel = CreateWindow("BUTTON", "Submit", WS_VISIBLE | WS_CHILD, 10, 50, 150, 30, hRightPanel, (HMENU)10, NULL, NULL);
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Define the window class
    WNDCLASS wc = {0};
    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WndProc;
    wc.lpszClassName = "MyWindowClass";

    // Register the window class
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Failed to register window class!", "Error", MB_ICONERROR);
        return 1;
    }
    
    // Create a window
    HWND hwnd = CreateWindow("MyWindowClass", "Chuong trinh Graph", WS_OVERLAPPEDWINDOW, 300, 200, 900, 600, NULL, NULL, hInstance, NULL);
    if (!hwnd) {
        MessageBox(NULL, "Failed to create window!", "Error", MB_ICONERROR);
        return 1;
    }

    // Show the window
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
