#include <windows.h>

/* Export a very small function */
__declspec(dllexport) int add(int a, int b) {
    return a + b;
}

__declspec(dllexport) void processData(char* input, int length) {
    for (int i = 0; i < length; i++) {
        input[i] ^= 0x6F;
    }
}

__declspec(dllexport) void CALLBACK getString(HWND hwnd, HINSTANCE hinst, LPSTR cmdLine, int nCmdShow) {
    MessageBoxA(hwnd, "Hello from DLL", "getString()", MB_OK | MB_ICONINFORMATION);
}


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {        // perform actions based on the reason of calling 
    case DLL_PROCESS_ATTACH:    // initialize once for each new process
        MessageBoxA(NULL, "DLL Loaded", "DLL Event", MB_OK | MB_ICONINFORMATION);
        break;
    case DLL_THREAD_ATTACH:     // do thread-specific initialization
        break;
    case DLL_THREAD_DETACH:     // do thread-specific cleanup
        break;
    case DLL_PROCESS_DETACH:    // do not do cleanup if process termination scenario
        MessageBoxA(NULL, "DLL Unloaded", "DLL Event", MB_OK | MB_ICONINFORMATION);
        break;
    }
    return TRUE;
}


// cl dll.c /LD /Od /Oi- /GS- /MT kernel32.lib user32.lib msvcrt.lib /link /ENTRY:DllMain /OPT:NOREF /OPT:NOICF /NOLOGO