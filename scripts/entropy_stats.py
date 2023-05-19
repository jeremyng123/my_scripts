import collections
import sys

stats = {i: 0 for i in range(256)}
with open(sys.argv[1], 'rb') as f:
    content = f.read()
byte_counts = collections.Counter(content)
total_bytes = sum(byte_counts.values())
for byte, count in byte_counts.items():
    stats[byte] = count / total_bytes * 100
print(stats)
