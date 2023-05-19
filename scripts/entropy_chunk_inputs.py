import collections
import sys


def sliding_window(file_content, window_size):
    for i in range(len(file_content) - window_size + 1):
        yield file_content[i:i + window_size]


def calculate_pattern_percentage(binary_file, pattern_chunk_size, threshold):
    # Read the file
    with open(binary_file, 'rb') as f:
        content = f.read()

    # Count patterns occurrences
    pattern_counts = collections.Counter(
        sliding_window(content, pattern_chunk_size))

    # Calculate total pattern count
    total_patterns = sum(pattern_counts.values())

    # Calculate percentage for each pattern, filter by threshold, and sort by percentage
    # Format byte values as hexadecimal strings
    pattern_percentages = {
        f"0x{''.join(f'{byte:02x}'for byte in pattern)}":
        count / total_patterns * 100
        for pattern, count in pattern_counts.items()
    }
    filtered_pattern_percentages = {
        k: v
        for k, v in pattern_percentages.items() if v >= threshold
    }
    sorted_pattern_percentages = {
        k: v
        for k, v in sorted(filtered_pattern_percentages.items(),
                           key=lambda item: item[1],
                           reverse=True)
    }

    return sorted_pattern_percentages


# Inputs
binary_file = sys.argv[1]
pattern_chunk_size = int(sys.argv[2])
threshold = float(sys.argv[3])

# Calculate and print pattern percentages
pattern_percentages = calculate_pattern_percentage(binary_file,
                                                   pattern_chunk_size,
                                                   threshold)
print(pattern_percentages)
