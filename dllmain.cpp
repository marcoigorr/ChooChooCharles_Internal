/*
ChooChooCharles_Internal hack for the game (Steam version) 
Copyright (C) 2022  marcoigorr

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/

#include "pch.h"

#include "console.h"
#include "address.h"


INT WINAPI MainThread(HMODULE hModule)
{
    // Create console
    console->create();

    // Get base address of module
    addr->moduleBase = (uintptr_t)GetModuleHandle(L"Obscure-Win64-Shipping.exe");
    std::cout << "moduleBase - 0x" << addr->moduleBase << std::endl;

    addr->baseAddress = addr->moduleBase + 0x0505D740;
    std::cout << "BaseAddress - 0x" << std::hex << addr->baseAddress << std::endl;

    while (!GetAsyncKeyState(VK_HOME))
    {
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            addr->CalcAddresses();
            std::cout << "varHealthMain = 0x" << std::hex << Character->varHealthMain << std::dec << " Value = " << *(float*)Character->varHealthMain << std::endl;
            std::cout << "varSprintSpeed = 0x" << std::hex << Character->varSprintSpeed << std::dec << " Value = " << *(float*)Character->varSprintSpeed << std::endl;
            std::cout << "varWalkSpeed = 0x" << std::hex << Character->varWalkSpeed << std::dec << " Value = " << *(float*)Character->varWalkSpeed << std::endl;
        }

        // ...
    }

    // Cleanup
    console->close();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (PTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

