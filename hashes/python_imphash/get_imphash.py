import pefile
import re


def getimphash(filepath, file):
    PE = pefile.PE(filepath)
    print(filepath)
    print(f"{file} is a dll with: ", end="") if PE.is_dll() else None
    print(f"{file} is a driver with: ", end="") if PE.is_driver() else None
    print(f"{file} is a exe with: ", end="") if PE.is_exe() else None
    return PE.get_imphash()
