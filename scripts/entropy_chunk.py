import collections
from itertools import islice
import sys  #
from binascii import hexlify


def read_in_chunks(file_object, chunk_size):
    while True:
        data = tuple(islice(file_object, chunk_size))
        if not data:
            break
        yield data


# Count 50-byte chunk occurrences
with open(sys.argv[1], 'rb') as f:
    chunk_counts = collections.Counter(read_in_chunks(f, 50))

# Calculate total chunk count
total_chunks = sum(chunk_counts.values())

print(chunk_counts)

# Calculate percentage for each chunk and filter out 0%, sort by percentage
# Format byte values as hexadecimal strings
chunk_percentages = {
    ','.join(f'0x{byte:02x}'
             for byte in map(int, chunk)): count / total_chunks * 100
    for chunk, count in chunk_counts.items() if count / total_chunks * 100 > 0
}
sorted_chunk_percentages = {
    k: v
    for k, v in sorted(
        chunk_percentages.items(), key=lambda item: item[1], reverse=True)
}

print(sorted_chunk_percentages)