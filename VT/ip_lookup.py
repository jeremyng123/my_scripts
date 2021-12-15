import requests
import json
from dotenv import dotenv_values

config = dotenv_values(".env")
result = "count\tip\t\tcountry\tASN{number}\t{ASN Organisation}\n"
counts = 0
lines = 0
percent = 0
with open("lookup_ips.txt", 'r') as f:
    for line in f:
        lines += 1
    f.seek(0)
    for i, ip in enumerate(f):
        url = f"https://www.virustotal.com/api/v3/ip_addresses/{ip.strip()}"
        headers = {"Accept": "application/json", "x-apikey": config['API_KEY']}
        response = requests.request("GET", url, headers=headers)
        ip_resp = json.loads(response.text)['data']['attributes']
        if ip_resp['country'] == "SG":
            counts += 1
            result += f"{counts:<4}{ip.strip():18}{ip_resp['country']:5}ASN{ip_resp['asn']:<8}{ip_resp['as_owner']:>25}\n"
        if i % (lines // 100) == 0:
            percent += 1
            print(f"{percent}% done")

print(result)