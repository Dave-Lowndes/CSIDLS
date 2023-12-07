// CSIDLS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <shlobj.h>

typedef struct SYSFOLDERS_tag {
	int val;
	LPCTSTR str;
} SYSFOLDERS;

#define FX(x) x , #x

static const SYSFOLDERS SysFolders[] = {
	FX( CSIDL_ADMINTOOLS )
	, FX( CSIDL_ALTSTARTUP )
	, FX( CSIDL_APPDATA )
	, FX( CSIDL_BITBUCKET )
	, FX( CSIDL_CDBURN_AREA )
	, FX( CSIDL_COMMON_ADMINTOOLS )
	, FX( CSIDL_COMMON_ALTSTARTUP )
	, FX( CSIDL_COMMON_APPDATA )
	, FX( CSIDL_COMMON_DESKTOPDIRECTORY )
	, FX( CSIDL_COMMON_DOCUMENTS )
	, FX( CSIDL_COMMON_FAVORITES )
	, FX( CSIDL_COMMON_MUSIC )
	, FX( CSIDL_COMMON_OEM_LINKS )
	, FX( CSIDL_COMMON_PICTURES )
	, FX( CSIDL_COMMON_PROGRAMS )
	, FX( CSIDL_COMMON_STARTMENU )
	, FX( CSIDL_COMMON_STARTUP )
	, FX( CSIDL_COMMON_TEMPLATES )
	, FX( CSIDL_COMMON_VIDEO )
	, FX( CSIDL_COMPUTERSNEARME )
	, FX( CSIDL_CONNECTIONS )
	, FX( CSIDL_CONTROLS )
	, FX( CSIDL_COOKIES )
	, FX( CSIDL_DESKTOP )
	, FX( CSIDL_DESKTOPDIRECTORY )
	, FX( CSIDL_DRIVES )
	, FX( CSIDL_FAVORITES )
	, FX( CSIDL_FONTS )
	, FX( CSIDL_HISTORY )
	, FX( CSIDL_INTERNET )
	, FX( CSIDL_INTERNET_CACHE )
	, FX( CSIDL_LOCAL_APPDATA )
	, FX( CSIDL_MYDOCUMENTS )
	, FX( CSIDL_MYMUSIC )
	, FX( CSIDL_MYPICTURES )
	, FX( CSIDL_MYVIDEO )
	, FX( CSIDL_NETHOOD )
	, FX( CSIDL_NETWORK )
	, FX( CSIDL_PERSONAL )
	, FX( CSIDL_PRINTERS )
	, FX( CSIDL_PRINTHOOD )
	, FX( CSIDL_PROFILE )
	, FX( CSIDL_PROGRAM_FILES )
	, FX( CSIDL_PROGRAM_FILESX86 )
	, FX( CSIDL_PROGRAM_FILES_COMMON )
	, FX( CSIDL_PROGRAM_FILES_COMMONX86 )
	, FX( CSIDL_PROGRAMS )
	, FX( CSIDL_RECENT )
	, FX( CSIDL_RESOURCES )
	, FX( CSIDL_RESOURCES_LOCALIZED )
	, FX( CSIDL_SENDTO )
	, FX( CSIDL_STARTMENU )
	, FX( CSIDL_STARTUP )
	, FX( CSIDL_SYSTEM )
	, FX( CSIDL_SYSTEMX86 )
	, FX( CSIDL_TEMPLATES )
	, FX( CSIDL_WINDOWS )
};


int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
	puts( "Displays a list of the CSIDL_* values and their associated folders" );

	for ( auto item : SysFolders )
	{
		TCHAR szSystemPath[_MAX_PATH];

		HRESULT hRes;

		hRes = SHGetFolderPath( NULL, item.val, NULL, SHGFP_TYPE_CURRENT, szSystemPath );

		if ( hRes == S_OK )
		{
			if ( szSystemPath[0] != '\0' )
			{
				printf( "%s\t%s\n", item.str, szSystemPath );
			}
			else
			{
				printf( "%s\t%s\n", item.str, "*** EMPTY STRING ***" );
			}
		}
		else if ( hRes == S_FALSE )
		{
				printf( "%s\t%s\n", item.str, "*** DOESN'T EXIST ***" );
		}
		else
		{
			printf( "%s\t%s\n", item.str, "*** INVALID PARAMETER ***" );
		}
	}

	return 0;
}

