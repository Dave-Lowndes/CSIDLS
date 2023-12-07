# CSIDLS - lists all the CSIDL values and the paths for them on the system

This is a test program that I used to illustrate a quirk I came across using the SHGetFolderPath API under different platforms.

The program was published in association with an item titled "SHGetFolderPath() Platform Differences" in the "Tech Tips" column of Windows Developer's Journal March 2002 Volume 13, Number 3.

For anyone wondering, here was the quirk:

"Windows 2000 and XP natively implement SHGetFolderPath(), and behave as documented. But under NT4 and Windows 9x, it exhibits a quirk for some CSIDL values: it returns S_OK with an empty string for the folder path."

I note that the [current documentation (Dec 2023)](https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) does imply that the string may be empty despite the API returning success.
