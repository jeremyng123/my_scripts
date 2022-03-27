import os
import argparse
import fnmatch
import re
import tlsh
import pprint

written_result = {}
all_sha1_hashes = {}
sha1hash_list_order = []

def getTlsh(filepath):
    return tlsh.hash(open(filepath, 'rb').read())


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
                written_result[curr_family][file] = getTlsh(os.path.join(dirpath, file))
                all_sha1_hashes[file] = written_result[curr_family][file]
                sha1hash_list_order.append(file)
            else:
                print("WTF?!@#?!@?#!!@?\n\n\n\n")

# This is my own version. lazy to learn some libraries rn
def write_csv():
    with open(f"summary.csv", 'w') as F:
        for family, v in written_result.items():
            F.write('\n')
            with open(f"{family}.csv", 'w') as f:
                f.write(f"{family}\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
                F.write(f"{family}\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n")
                for file, tlshash in v.items():
                    f.write(f"{file},{tlshash}\n")
                    F.write(f"{file},{tlshash}\n")


def iterate_malware_folder(folder_name):
    dir = os.path.join(os.getcwd(), folder_name)
    walk(dir)
    write_csv()


def compare_hashes():
    tlsh_diff_results = {}
    for sha1hash in sha1hash_list_order:
        tlsh_diff_results[sha1hash] = []
        for SHA1hash in sha1hash_list_order:
            tlsh_diff_results[sha1hash].append(str(tlsh.diff(all_sha1_hashes[sha1hash], all_sha1_hashes[SHA1hash])))
    return tlsh_diff_results


def write_csv_diff(tlsh_diff_results):
    with open("diff_summary.csv", 'w') as f:
        # writing column headers
        f.write(',')
        for sha1hash in sha1hash_list_order:
            f.write(sha1hash+',')
        f.write('\n')
        # writing difference between row header and column header
        for sha1hash in sha1hash_list_order:
            f.write(sha1hash+',')
            for tlsh_diff in tlsh_diff_results[sha1hash]:
                f.write(tlsh_diff + ',')
            f.write('\n')



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
    write_csv_diff(compare_hashes())