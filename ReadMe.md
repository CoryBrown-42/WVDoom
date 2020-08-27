# !!!
If pulling changes, first Delete Saved, Intermediate, .vs, Binaries folders, and the .sln file.

After pulling the project -> Right-Click on the .uproject file -> select "Generate Visual Studio project files" -> open .uproject

Errors we've had so far:

The Folder that the project is in isn't named WVDoom. This is the folder above your .uproject file

You don't have .NET 4.6 SDK or up installed - This can be found in Individual Components inside Visual Studio Installer

You also might need to right-click and "Switch Unreal Engine version to clear the cache.

