#https://stackoverflow.com/questions/34489772/python-access-denied-to-mmap-file-created-by-local-system

import mmap
import sys

print(sys.argv[1])
shm = mmap.mmap(-1, 512, sys.argv[1])
if shm:
    print(shm.readline())
