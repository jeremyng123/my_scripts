import requests

base_url = "https://hashdb.openanalysis.net/hash"


def crc32_hash_lookup(crc):
    uri = f"/crc32/{crc}"
    url = base_url + uri
    response = requests.get(url)
    # This parses the response text as JSON and returns the data representation.
    return response.json()["hashes"][0]["string"]["string"]


#### From Andromeda list of process hash arrays #####
with open("allProcessHashesCRC32.txt", 'r') as f:
    for crc in f:
        print(f"0x{crc.strip()}:\t{crc32_hash_lookup(int(crc, 16))}")
