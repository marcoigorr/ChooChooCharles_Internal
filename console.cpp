#include "pch.h"
#include "console.h"

void Console::create()
{
	AllocConsole();
	freopen_s(&this->f, "CONOUT$", "w", stdout);
}

void Console::close()
{
	fclose(this->f);
	FreeConsole();
}

Console* console = new Console();