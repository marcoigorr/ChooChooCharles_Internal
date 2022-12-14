/*ChooChooCharles_Internal hack for the game (Steam version)
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

template <typename T>
void PrintOut(const char* label, uintptr_t* address)
{
    if (typeid(T) == typeid(uintptr_t))
        std::cout << "[+] " << label << " = 0x" << std::hex << std::uppercase << address << std::endl << std::endl;
    else if (typeid(T) == typeid(BYTE))
        std::cout << "[+] " << label << " = 0x" << std::hex << std::uppercase << address << std::dec << " Value = " << (unsigned int)(*(T*)address) << std::endl;
    else
        std::cout << "[+] " << label << " = 0x" << std::hex << std::uppercase << address << std::dec << " Value = " << *(T*)address << std::endl;
}

INT WINAPI MainThread(HMODULE hModule)
{
    // Create console
    console->create();

    // Get base address of module
    addr->moduleBase = (uintptr_t)GetModuleHandle(L"Obscure-Win64-Shipping.exe");
    addr->baseAddress = addr->moduleBase + 0x0505D740;    

    while (!GetAsyncKeyState(VK_HOME))
    {
        addr->CalcAddresses();

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            system("cls");
            std::cout << "[+] moduleBase - 0x" << addr->moduleBase << std::endl;
            std::cout << "[+] baseAddress - 0x" << std::hex << addr->baseAddress << std::endl;

            PrintOut<uintptr_t>("aPlayerController", (uintptr_t*)addr->aPlayerController);
            PrintOut<uintptr_t>("aCharacter", (uintptr_t*)addr->aCharacter);
            PrintOut<uintptr_t>("aCharlesRef", (uintptr_t*)addr->aCharlesRef);
            PrintOut<uintptr_t>("aTrainRef", (uintptr_t*)addr->aTrainRef);
            PrintOut<uintptr_t>("aCharacterMovement", (uintptr_t*)addr->aCharacterMovement);
            PrintOut<uintptr_t>("aCapsuleComponent", (uintptr_t*)addr->aCapsuleComponent);

            PrintOut<float>("varHealthMain", Character->varHealthMain);
            PrintOut<float>("varSprintSpeed", Character->varSprintSpeed);
            PrintOut<float>("varWalkSpeed", Character->varWalkSpeed);
            PrintOut<int>("JumpMaxCount", Character->JumpMaxCount);
            PrintOut<BYTE>("CancelFallDamageonReset", Character->CancelFallDamageonReset);
            PrintOut<BYTE>("CanMove", Character->CanMove);
            PrintOut<BYTE>("CanInventory", Character->CanInventory);
            PrintOut<BYTE>("CanJump", Character->CanJump);
        }
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

