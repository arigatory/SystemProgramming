#include <stdio.h>
#include <tchar.h>

#define BUILD_WINDOWS
#include <Windows.h>


#include <windows.h>

int main()
{
	printf("INFORMATION about the computer:\n\n");

	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);

	printf("Number of Logical Processors: %d\n", si.dwNumberOfProcessors);
	printf("Page size: %d Bytes\n", si.dwPageSize);
	printf("Processor Mask: 0x%p\n", (PVOID) si.dwActiveProcessorMask);
	printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
	printf("Maximum process address: 0x%p\n\n", si.lpMaximumApplicationAddress);
	
	char systemPath[MAX_PATH];
	GetSystemDirectoryA(systemPath, sizeof(systemPath));
	printf("System path: %s\n",systemPath);



	#define INFO_BUFFER_SIZE 32767
	DWORD i;
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
 
	// Get and display the name of the computer. 
	bufCharCount = INFO_BUFFER_SIZE;
	if( !GetComputerName( infoBuf, &bufCharCount ))
		printf("GetComputerName error\n");
	else
		_tprintf( TEXT("\nComputer name:      %s\n"), infoBuf ); 


	 if( !GetWindowsDirectory( infoBuf, INFO_BUFFER_SIZE ) )
		printf("GetWindowsDirectory error"); 
	_tprintf( TEXT("\nWindows Directory:  %s\n"), infoBuf );

	LARGE_INTEGER ticks;
    if (!QueryPerformanceCounter(&ticks))
    {
		printf("QueryPerformanceCounter error"); 
    } else {
		printf("%llu\n", ticks.QuadPart);
	}

	OSVERSIONINFO vi = {sizeof(vi)};
	::GetVersionEx(&vi);

	DWORD mjv = vi.dwMajorVersion;
	DWORD miv = vi.dwMinorVersion;
	DWORD mis = 0;
	DWORD mjs = 0;
	PDWORD product_type = NULL;

	if (!GetProductInfo(mjv, miv, mjs, mis, product_type))
		printf("GetProductInfo error");
	else
		printf("Product type: %d\n", product_type); 



	return 0;
}
