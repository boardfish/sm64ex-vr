#include <stdio.h>

#include "openvr.h"
#include "pc/configfile.h"

#define OPENVRLIB "openvr_api.dll"

#if defined(_WIN32)
#include <windows.h>
#define dlopen(lib, flag) LoadLibrary(TEXT(lib))
#define dlerror() ""
#define dlsym(handle, func) (void *)GetProcAddress(handle, func)
#define dlclose(handle) FreeLibrary(handle)
#endif

static void* handle;

// Was going to try and base this off Discord RPC code, but I feel like I'm getting
// into specific territory for that.

void openvr_init(void) {
    // Was going to try and base this off Discord RPC code, but I feel like I'm getting
    // into specific territory for that.
        if (!configOpenVR) { return; }
        handle = dlopen(OPENVRLIB, RTLD_LAZY);
        if (!handle) {
            fprintf(stderr, "Unable to load OpenVR\n%s\n", dlerror());
        return;
    }
}
void openvr_shutdown(void) {
    if (!handle) { return; }
    dlclose(handle);
}