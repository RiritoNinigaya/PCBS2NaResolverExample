// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <NaResolver/NaResolver.h>
void* save = nullptr;
class CarrerStatus {
public:
    CLASS("Assembly-CSharp", "", "CarrerStatus");

    void AddCash(int value1, int value2) {
        static auto invoker = NaMethodInvoker<void, int, int, bool>(METHOD_ADDRESS("System.Void", "AddCash", "int", "int"));
        printf("%p", METHOD_ADDRESS("System.Void", "AddCash", "int", "int"));
        return invoker.Invoke(value1, value2, false);
    }
};
DWORD WINAPI Thread() {
    uint32_t unknown = 0x7;
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    NaResolver nares = NaResolver();
    if (nares.Setup())
    {
        printf("Unity3D Is Initializated!!!");
    }
    NaResolver::Class klass = nares.GetClass((std::string)"Assembly-CSharp.dll", (std::string)"", (std::string)"CarrerStatus");
    CarrerStatus carrerst = CarrerStatus();
    carrerst.AddCash(999999, 7);
    /*
            NaResolver::Method method_addcash = nares.GetMethod(klass, "void", "AddCash", { "void*", "int", "int", "void*", "bool", "void*"});
            NaMethodInvoker<void, void*, int, int, void*, bool, void*>(method_addcash.method.GetInvokeAddress()).Invoke(__this, 9999999, 0x7, save, false, MethodInfo);
    */
    return TRUE;
    
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

