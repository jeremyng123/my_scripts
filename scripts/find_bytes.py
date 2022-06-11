import re
import argparse
import os

SIXTEEN_UNICODE_BYTES = r"[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00[\x01-\xff]\x00"


def search(filepath, token):
    with open(filepath, 'rb') as file:
        bs = file.read()
    matches = re.findall(token.encode('utf-8'), bs)
    for match in matches:
        print(match.decode('latin-1'))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description='Using regex to find a sequence of bytes in a file')
    parser.add_argument('-f',
                        '--file',
                        metavar='FILE',
                        type=str,
                        required=True,
                        help='Target file to grep')

    parser.add_argument('-t',
                        '--token',
                        metavar='TOKEN',
                        type=str,
                        default=SIXTEEN_UNICODE_BYTES,
                        help='Regexp tokenized string to search')
    args = parser.parse_args()
    filepath = os.path.join(os.getcwd(), args.file)
    search(filepath, args.token)