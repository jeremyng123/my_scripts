import requests
import json
import progressbar
import pandas as pd
from ..config import *

headers = {"Accept": "application/json", "x-apikey": API_KEY}

result = "count\tip\t\tcountry\tASN{number}\t{ASN Organisation}\n"
lines = 0
percent = 0
MAX_BAR = 30

# error_ips = ""
ips = []
countries = []
asn_num = []
ASNs = []
with progressbar.ProgressBar(max_value=MAX_BAR) as bar:
    with open("lookup_ips.txt", 'r') as f:
        for line in f:
            lines += 1
        f.seek(0)
        for i, ip in enumerate(f):
            url = f"https://www.virustotal.com/api/v3/ip_addresses/{ip.strip()}"

            response = requests.request("GET", url, headers=headers)
            ip_resp = json.loads(response.text)['data']['attributes']
            if ip_resp['country'] == "SG":
                ips.append(ip.strip())
                countries.append(ip_resp['country'])
                asn_num.append("ASN" + str(ip_resp['asn']))
                ASNs.append(ip_resp['as_owner'])
                # result += f"{ip.strip():18}{ip_resp['country']:5}ASN{ip_resp['asn']:<8}{ip_resp['as_owner']:>25}\n"
            if i % (int(round(lines / MAX_BAR, 0))) == 0:
                percent += 1
                bar.update(percent)

header = ["ip", "country", "ASN", "ASN Organisation"]

# print(City)
# print()
# print(Country)
df = pd.DataFrame({
    'IP': ips,
    "Original_country": countries,
    "ASN": asn_num,
    "ASN Organization": ASNs
})

pd.set_option("display.max_rows", None, "display.max_columns", None,
              'display.width', 1100, 'display.colheader_justify', 'center')
df.to_csv("results.csv")
print(df)

# print("Error IP addresses found:\n" + error_ips)