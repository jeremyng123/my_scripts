import collections
import sys
import json


def sliding_window(file_content, window_size):
    for i in range(len(file_content) - window_size + 1):
        yield file_content[i:i + window_size]


def calculate_pattern_frequency(binary_file, max_pattern_chunk_size):
    # Read the file
    with open(binary_file, 'rb') as f:
        content = f.read()

    # Initialize a dictionary to hold the most common pattern for each size
    most_common_patterns = {}

    # Cycle through the range of pattern_chunk_size values
    for pattern_chunk_size in range(1, max_pattern_chunk_size + 1):
        # Count patterns occurrences
        pattern_counts = collections.Counter(
            sliding_window(content, pattern_chunk_size))

        # Get the most common pattern and its count
        most_common_pattern, count = pattern_counts.most_common(1)[0]

        # Store the most common pattern (formatted as a string of hex values), its count, and its percentage of total patterns
        most_common_patterns[pattern_chunk_size] = {
            'pattern':
            f"0x{''.join(f'{byte:02x}'for byte in most_common_pattern)}",
            'count': count,
            'percentage': count / sum(pattern_counts.values()) * 100,
        }

    return most_common_patterns


# Inputs
binary_file = sys.argv[1]
max_pattern_chunk_size = int(sys.argv[2])

# Calculate and print the most common pattern for each chunk size
most_common_patterns = calculate_pattern_frequency(binary_file,
                                                   max_pattern_chunk_size)

json_formatted_str = json.dumps(most_common_patterns, indent=2)
print(json_formatted_str)