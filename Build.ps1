# Set Java Includes and Right Fielder Object Library Path
$JavaIncludeDirectory1 = "C:\Program Files\Java\jdk-20\include"
$JavaIncludeDirectory2 = "C:\Program Files\Java\jdk-20\include\win32"
$RFLibraryPath = $PSScriptRoot

# Run cl command
& 'cl' -I"$RFLibraryPath" -I"$JavaIncludeDirectory1" -I"$JavaIncludeDirectory2" -Fe'mdRightFielderJavaWrapper.dll' 'mdRightFielderJavaWrapper.cpp' -link -DLL -LIBPATH:"$RFLibraryPath" -DEFAULTLIB:'mdRightFielder.lib'

# Remove files
Remove-Item 'mdRightFielderJavaWrapper.exp' -ErrorAction SilentlyContinue
Remove-Item 'mdRightFielderJavaWrapper.obj' -ErrorAction SilentlyContinue
Remove-Item 'mdRightFielderJavaWrapper.lib' -ErrorAction SilentlyContinue

