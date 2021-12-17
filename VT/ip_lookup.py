import requests
import json
from dotenv import dotenv_values
import progressbar
import pandas as pd

config = dotenv_values(".env")
headers = {"Accept": "application/json", "x-apikey": config['API_KEY']}

result = "count\tip\t\tcountry\tASN{number}\t{ASN Organisation}\n"
lines = 0
percent = 0
MAX_BAR = 30
with progressbar.ProgressBar(max_value=MAX_BAR) as bar:
    with open("lookup_ips.txt", 'r') as f:
        for line in f:
            lines += 1
        f.seek(0)
        for i, ip in enumerate(f):
            url = f"https://www.virustotal.com/api/v3/ip_addresses/{ip.strip()}"

            response = requests.request("GET", url, headers=headers)
            print(response.text)
            ip_resp = json.loads(response.text)['data']['attributes']
            if ip_resp['country'] == "SG":
                result += f"{ip.strip():18}{ip_resp['country']:5}ASN{ip_resp['asn']:<8}{ip_resp['as_owner']:>25}\n"
            if i % (int(round(lines / MAX_BAR, 0))) == 0:
                percent += 1
                bar.update(percent)
print(result)