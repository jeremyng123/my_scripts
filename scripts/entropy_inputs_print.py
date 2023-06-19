import collections
import sys

def read_file(file_name):
    with open(file_name, 'rb') as f:
        return f.read()

def partition_bytes(bytes_data, window):
    partitions = [[] for _ in range(window)]
    for i, byte in enumerate(bytes_data):
        partitions[i % window].append(byte)
    return partitions

def print_top_bytes(partitions):
    concat = ""
    for i, partition in enumerate(partitions):
        counter = collections.Counter(partition)
        top_byte = counter.most_common(1)[0][0]
        concat += f"{top_byte:02x}"
        # print(f'The top byte in partition {i + 1} is: {hex(top_byte)[2:]}')
    print(f"concatenated bytes: 0x{concat}")

def main():
    if len(sys.argv) != 3:
        print('Usage: python script.py [filename] [window size]')
        return
    file_name = sys.argv[1]
    window = int(sys.argv[2])
    bytes_data = read_file(file_name)
    partitions = partition_bytes(bytes_data, window)
    print_top_bytes(partitions)

if __name__ == '__main__':
    main()
