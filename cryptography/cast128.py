from Crypto.Cipher import CAST
import argparse
import os

## CONSTANTS ##
BLOCK = 8


def pad(msg, block):
    return msg + (block - (len(msg) % block)) * b'\x00'


def getbytes(hexstr):
    return bytes.fromhex(hexstr)


def _decrypt(key, ciphertext, eiv=None, output_file=None):
    if eiv is None:
        eiv = key[:8]
    # print(key)
    # print('\n')
    # print(ciphertext)
    # print('\n')
    # print(eiv)
    # print('\n')
    cipher = CAST.new(key, CAST.MODE_CBC, eiv)
    msg = cipher.decrypt(pad(ciphertext, BLOCK))
    if output_file is not None:
        with open(output_file, 'wb') as f:
            return f.write(msg)
    print(msg)

    # print(msg.decode('latin-1'))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='CAST-128 algorithm')
    parser.add_argument('-f',
                        '--file',
                        metavar='FILE',
                        type=str,
                        help='Target file to decrypt')

    parser.add_argument('-c',
                        '--ciphertext',
                        metavar='CTEXT',
                        type=str,
                        help='Ciphertext to decrypt')

    parser.add_argument('-o',
                        '--output_file',
                        metavar='OUTPUT',
                        type=str,
                        help='Filename to save results to')

    parser.add_argument('-k',
                        '--key',
                        metavar='KEY',
                        type=str,
                        required=True,
                        help='Insert key in hexadecimals')
    args = parser.parse_args()
    if args.file is not None:
        filepath = os.path.join(os.getcwd(), args.file)
        with open(filepath, 'rb') as f:
            _decrypt(getbytes(args.key),
                     f.read(),
                     output_file=args.output_file)
            quit()

    if args.ciphertext is None:
        parser.error("at least one of --file or --ciphertext required")

    _decrypt(getbytes(args.key),
             getbytes(args.ciphertext),
             output_file=args.output_file)
