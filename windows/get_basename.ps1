# get all the filenames without the file extension found in this current directory
Get-ChildItem *.7z | Select-Object basename