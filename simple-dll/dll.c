#include <windows.h>

/* Export a very small function */
__declspec(dllexport) int add(int a, int b) {
    return a+b;
}

__declspec(dllexport) char* getString() {
    static char buffer[] = "Hello from DLL";
    return buffer;
}

__declspec(dllexport) void processData(char* input, int length) {
    for(int i=0;i<length;i++) {
        input[i]^=0x42;
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {        // perform actions based on the reason of calling 
        case DLL_PROCESS_ATTACH:    // initialize once for each new process
            OutputDebugStringA("DLL Loaded\n");
            break;
        case DLL_THREAD_ATTACH:     // do thread-specific initialization
            break;
        case DLL_THREAD_DETACH:     // do thread-specific cleanup
            break;
        case DLL_PROCESS_DETACH:    // do not do cleanup if process termination scenario
        OutputDebugStringA("DLL Unloaded\n");
            break;
        }
        return TRUE;
}


