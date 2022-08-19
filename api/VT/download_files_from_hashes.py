from sys import argv
from config import key
# import requests
import vt

# session = requests.Session()
# session.headers = {'X-Apikey': key}

# print(key)
client = vt.Client(key)
with open(argv[1], 'r') as f:
    for sha256 in f:
        # print(sha256.strip())
        # url = f"https://www.virustotal.com/api/v3/monitor_partner/files/{sha256.strip()}/download"
        # response = session.get(url, headers=session.headers)
        # print(response.text)
        with open(f"{sha256.split('/')[0].strip()}.bin", "wb") as malware_f:
            client.download_file(sha256.split('/')[0].strip(), malware_f)