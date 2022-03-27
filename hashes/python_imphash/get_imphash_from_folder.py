import os
import argparse
from get_imphash import *
import fnmatch
import re

written_result = {}


def walk(folder):
    for dirpath, dirnames, files in os.walk(folder):
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
    dir = os.path.join(os.getcwd(), folder_name)
    walk(dir)
    write_csv()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description='Get all malware\'s imphash found in target folder')
    parser.add_argument('-f',
                        '--folder',
                        metavar='FOLDER',
                        type=str,
                        default='malwares',
                        help='folder to iterate from. Recursive action')
    args = parser.parse_args()
    iterate_malware_folder(args.folder)