# Get a single hash from folder
$HashString = (Get-ChildItem C:\Temp -Recurse | Get-FileHash -Algorithm MD5).Hash | Out-String
Get-FileHash -InputStream ([IO.MemoryStream]::new([char[]]$HashString))