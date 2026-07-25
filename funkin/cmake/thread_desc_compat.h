#pragma once
#ifdef _WIN32
#include <windows.h>
#if !defined(_MSC_VER)
    #ifndef DILIGENT_HAS_SETTHREADDESCRIPTION_DECL
    #define DILIGENT_HAS_SETTHREADDESCRIPTION_DECL
    extern "C" WINBASEAPI HRESULT WINAPI SetThreadDescription(HANDLE hThread, PCWSTR lpThreadDescription);
#endif
#endif
#endif