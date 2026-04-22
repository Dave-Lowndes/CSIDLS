# CSIDLS

A Windows command-line utility that enumerates all legacy `CSIDL_*` special folder values and displays their resolved paths on the current system.

## Output

Each line of output is tab-separated in the format:
````````
<numeric value>    <CSIDL name>    <resolved path>
````````

Folders that do not exist on the current system are flagged as:

`*** DOESN'T EXIST ***`.

## Notes

- The `CSIDL_*` API and `SHGetFolderPath` are deprecated since Windows Vista in favour of `SHGetKnownFolderPath`, but are used here intentionally to document the CSIDL values themselves.
- `CSIDL_MYDOCUMENTS` and `CSIDL_PERSONAL` share the same numeric value (`0x0005`) and will resolve to the same path. Both are listed for completeness.

## Requirements

- Windows
- Visual Studio (C++14 or later)

## Background

This program was originally written to illustrate a quirk encountered when using the `SHGetFolderPath` API under different platforms.

It was published in association with an item titled "SHGetFolderPath() Platform Differences" in the "Tech Tips" column of **Windows Developer's Journal**, March 2002, Volume 13, Number 3.

For anyone wondering, here was the quirk:

> "Windows 2000 and XP natively implement SHGetFolderPath(), and behave as documented. But under NT4 and Windows 9x, it exhibits a quirk for some CSIDL values: it returns S_OK with an empty string for the folder path."

The [current documentation (Dec 2023)](https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetfolderpatha) does imply that the string may be empty despite the API returning success — so this behaviour is now at least acknowledged by Microsoft.
