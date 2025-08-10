// simple-loader.c
#include <windows.h>
#include <stdio.h>

typedef int (*add_func_t)(int, int);

int main(void) {
    const char* dllName = "simple-dl.dll"; /* the DLL filename */

    HMODULE h = LoadLibraryA(dllName);
    if (!h) {
        DWORD err = GetLastError();
        printf("LoadLibraryA failed (error %lu). Make sure %s is in the same folder.\n", err, dllName);
        return 1;
    }

    /* Get address of exported function "add" */
    add_func_t add = (add_func_t)GetProcAddress(h, "add");
    if (!add) {
        DWORD err = GetLastError();
        printf("GetProcAddress failed (error %lu).\n", err);
        FreeLibrary(h);
        return 1;
    }

    /* Call it */
    int a = 7, b = 5;
    int result = add(a, b);
    printf("add(%d, %d) = %d\n", a, b, result);

    /* Done */
    FreeLibrary(h);
    return 0;
}
