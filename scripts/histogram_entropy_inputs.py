import collections
import matplotlib.pyplot as plt
import numpy as np
import sys

def read_file(file_name):
    with open(file_name, 'rb') as f:
        return f.read()

def partition_bytes(bytes_data, window):
    partitions = [[] for _ in range(window)]
    for i, byte in enumerate(bytes_data):
        partitions[i % window].append(byte)
    return partitions

def print_histogram(partitions, threshold):
    fig, axs = plt.subplots(len(partitions), figsize=(10, 10))
    for i, partition in enumerate(partitions):
        counter = collections.Counter(partition)
        keys = np.array(list(counter.keys()))
        values = np.array(list(counter.values()))
        
        # Create a color array, set all to 'blue'
        colors = ['blue'] * len(keys)
        
        # Find the indices where values exceed the threshold and change their color to 'red'
        high_values_indices = np.where(values > threshold)[0]
        
        # Find the index of the maximum value and change its color to 'red'
        max_value_index = np.argmax(values)
        colors[max_value_index] = 'red'
        
        axs[i].bar(keys, values, color=colors)
        axs[i].set_title(f'Histogram for partition {i + 1}')

        # Show x-ticks for bars that exceed the threshold, convert to hexadecimal
        high_values_keys = keys[high_values_indices]
        axs[i].set_xticks(high_values_keys)
        axs[i].set_xticklabels([hex(key)[2:] for key in high_values_keys])

        # Set x-axis range from 0 to 0xFF
        axs[i].set_xlim([0, 0xFF])

    plt.tight_layout()
    plt.show()

def main():
    if len(sys.argv) != 4:
        print('Usage: python script.py [filename] [window size] [threshold]')
        return
    file_name = sys.argv[1]
    window = int(sys.argv[2])
    threshold = int(sys.argv[3])
    bytes_data = read_file(file_name)
    partitions = partition_bytes(bytes_data, window)
    print_histogram(partitions, threshold)

if __name__ == '__main__':
    main()
