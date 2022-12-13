#pragma once

class Console
{
	FILE* f;
public:
	void create();
	void close();
};

extern Console* console;

