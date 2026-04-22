// CSIDLS
//
// Enumerates the legacy CSIDL_* special folder values and their resolved paths.
// Note: SHGetFolderPath and the CSIDL_* API are deprecated since Windows Vista
// in favour of SHGetKnownFolderPath, but are used here intentionally to document
// the CSIDL values themselves.
//

#include "stdafx.h"
#include <windows.h>
#include <shlobj.h>

struct SYSFOLDERS
{
	int val;
	LPCTSTR str;
};

#define FX(x) x , _T(#x)

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
	, FX( CSIDL_MYDOCUMENTS )	// Same value (0x0005) as CSIDL_PERSONAL
	, FX( CSIDL_MYMUSIC )
	, FX( CSIDL_MYPICTURES )
	, FX( CSIDL_MYVIDEO )
	, FX( CSIDL_NETHOOD )
	, FX( CSIDL_NETWORK )
	, FX( CSIDL_PERSONAL )		// Same value (0x0005) as CSIDL_MYDOCUMENTS
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


static constexpr LPCTSTR fmtstr = _T("%d\t%s\t%s\n");

int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
	_putts( _T("Displays a list of the CSIDL_* values and their associated folders") );

	for ( const auto & item : SysFolders )
	{
		TCHAR szSystemPath[MAX_PATH];

		const HRESULT hRes = SHGetFolderPath( NULL, item.val, NULL, SHGFP_TYPE_CURRENT, szSystemPath );

		if ( hRes == S_OK )
		{
			_tprintf( fmtstr, item.val, item.str,
						szSystemPath[0] != _T('\0') ?
							szSystemPath :
							_T("*** EMPTY STRING ***") );
		}
		else
		{
			_tprintf( fmtstr, item.val, item.str,
				hRes == S_FALSE ?
					_T("*** DOESN'T EXIST ***") :
					_T("*** INVALID PARAMETER ***") );
		}
	}

	return 0;
}

