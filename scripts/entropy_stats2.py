import collections
import sys
# Count byte occurrences
with open(sys.argv[1], 'rb') as f:
    content = f.read()
byte_counts = collections.Counter(content)

# Calculate total byte count
total_bytes = sum(byte_counts.values())

# Calculate percentage for each byte and filter out 0%, sort by percentage
# Format byte values as hexadecimal strings
byte_percentages = {
    f'0x{byte:02x}': count / total_bytes * 100
    for byte, count in byte_counts.items() if count / total_bytes * 100 > 0
}
sorted_byte_percentages = {
    k: v
    for k, v in sorted(
        byte_percentages.items(), key=lambda item: item[1], reverse=True)
}

print(sorted_byte_percentages)
