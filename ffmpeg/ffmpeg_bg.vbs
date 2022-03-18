Set objShell = CreateObject("Shell.Application")
objShell.ShellExecute "ffmpeg.bat", "/c lodctr.exe /r" , "", "runas", 0
