import os
import argparse
from get_imphash import *
import fnmatch
import re

written_result = {}


# the reason why i chose to look at imphash found in System32 and SysWOW64 because the
# site below posits the difference in imphash values when placed at different folder.
# https://superuser.com/questions/1643201/different-imphash-for-same-pe-file/1643202#1643202
def walk(bit_type):
    for dirpath, dirnames, files in os.walk(bit_type):
        print(f"##################\n{dirpath}\n##################")
        curr_family = re.split('/|\\\\', dirpath)[-1]
        if curr_family not in written_result.keys():
            written_result[curr_family] = {}
        for file in files:
            if fnmatch.fnmatch(file, "*.pdf"):
                continue
            if file not in written_result[curr_family].keys():
                written_result[curr_family][file] = [
                    getimphash(os.path.join(dirpath, file))
                ]
                continue
            written_result[curr_family][file].append(
                getimphash(os.path.join(dirpath, file)))


# This is my own version. lazy to learn some libraries rn
def write_csv():
    with open(f"summary.csv", 'w') as F:
        for family, v in written_result.items():
            F.write('\n')
            with open(f"{family}.csv", 'w') as f:
                f.write(f"{family}\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
                F.write(f"{family}\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
                for file, imphash in v.items():
                    f.write(f"{file},{imphash[0]},{imphash[1]}\n"
                            ) if imphash[1] else f.write(
                                f"{file},{imphash[0]},-\n")
                    F.write(f"{file},{imphash[0]},{imphash[1]}\n"
                            ) if imphash[1] else f.write(
                                f"{file},{imphash[0]},-\n")


def iterate_malware_folder(folder_name):
    X64 = os.path.join(os.environ["SYSTEMROOT"], "System32", folder_name)
    X32 = os.path.join(os.environ["SYSTEMROOT"], "SysWOW64", folder_name)
    walk(X32)
    walk(X64)
    write_csv()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description=
        'Get all malware\'s imphash found in System32/SysWOW64 folder')
    parser.add_argument('-f',
                        '--folder',
                        metavar='FOLDER',
                        type=str,
                        default='malwares',
                        help='folder inside System32/SysWOW64 to iterate from')
    args = parser.parse_args()
    iterate_malware_folder(args.folder)