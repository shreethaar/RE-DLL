#include <windows.h>


/* Export a very small function */
__declspec(dllexport) int add(int a, int b) {
    return a + b;
}
// DllMain as entrypoint 
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {        // perform actions based on the reason of calling 
    case DLL_PROCESS_ATTACH:    // initialize once for each new process
        break;

    case DLL_THREAD_ATTACH:     // do thread-specific initialization
        break;

    case DLL_THREAD_DETACH:     // do thread-specific cleanup
        break;

    case DLL_PROCESS_DETACH:    // do not do cleanup if process termination scenario
        break;
    }
    return TRUE;
}
