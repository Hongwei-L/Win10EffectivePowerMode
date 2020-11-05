// Hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include <windows.h>
#include <powersetting.h>

#pragma comment(lib, "Powrprof.lib")


const TCHAR* Effective_PowerMode[]{
    __TEXT("BatterySaver"),
    __TEXT("BetterBattery"),
    __TEXT("Balanced"),
    __TEXT("HighPerformance"),
    __TEXT("MaxPerformance"), // v1 last supported
    __TEXT("GameMode"),
    __TEXT("MixedReality"), // v2 last supported
};

VOID
WINAPI
Effective_powermode_CB(
    _In_ EFFECTIVE_POWER_MODE Mode,
    _In_opt_ VOID* Context
)
{
    std::wcout << L"Mode changed to:" << Effective_PowerMode[Mode] << std::endl;
}

EFFECTIVE_POWER_MODE_CALLBACK;

int main()
{

    VOID* pCBHandle = NULL;

    PowerRegisterForEffectivePowerModeNotifications(
        EFFECTIVE_POWER_MODE_V2,
        Effective_powermode_CB,
        NULL,
        &pCBHandle
        );

    std::cout << "enter to quite!\n";

    char ch;

    do {

        std::cin >> ch;

        if (ch == 'q')
            break;
    } while (true);
    
}

