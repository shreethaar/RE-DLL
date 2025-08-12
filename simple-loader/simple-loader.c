#include <windows.h>
#include <stdio.h>
#include <string.h>

// Function pointer typedefs
typedef int (*add_func_t)(int, int);
typedef void (*processData_func_t)(char*, int);

int main(void) {
    char string[] = "Hello from EXE";
    printf("%s\n", string);

    const char* dllName = "simple-dll.dll"; /* the DLL filename */
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

    /* Call add function */
    int a = 7, b = 5;
    int result = add(a, b);
    printf("add(%d, %d) = %d\n", a, b, result);
    /* Get address of processData function */
    processData_func_t processData = (processData_func_t)GetProcAddress(h, "processData");
    if (!processData) {
        printf("GetProcAddress for processData failed.\n");
    }
    else {
        char testData[] = "yappare is the best hacker";
        printf("Original: %s\n", testData);
        processData(testData, 6);
        printf("Processed: %s\n", testData);
    }
    FreeLibrary(h);
    return 0;
}

// compile:
// cl.exe simple-loader.c / Od / Oi - / GS -  kernel32.lib user32.lib msvcrt.lib / link / NOLOGO