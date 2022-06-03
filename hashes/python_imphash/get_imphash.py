import pefile
import argparse
import os


def getimphash(filepath):
    file = filepath.split('/')[-1]
    PE = pefile.PE(filepath)
    imphash = PE.get_imphash()
    print(filepath)
    print(f"{file} is a dll with: {imphash}", end="") if PE.is_dll() else None
    print(f"{file} is a driver with: {imphash}",
          end="") if PE.is_driver() else None
    print(f"{file} is a exe with: {imphash}", end="") if PE.is_exe() else None
    return


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description='Get all malware\'s imphash found in target folder')
    parser.add_argument('-f',
                        '--file',
                        metavar='FILE',
                        type=str,
                        default='malwares',
                        help='Get imphash of file')
    args = parser.parse_args()
    filepath = os.path.join(os.getcwd(), args.file)
    getimphash(filepath)