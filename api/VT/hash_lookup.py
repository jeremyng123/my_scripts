import requests
import json
import progressbar
import datetime
import pandas as pd

# relative import
import os, sys

currentdir = os.path.dirname(os.path.realpath(__file__))
parentdir = os.path.dirname(currentdir)
print(parentdir)
sys.path.append(parentdir)

from api.config import *

headers = {"Accept": "application/json", "x-apikey": API_KEY}

result = "count\tip\t\tcountry\tASN{number}\t{ASN Organisation}\n"
lines = 0
percent = 0
"""
# https://github.com/trendmicro/tlsh: fuzzy matching library to compare similar objects
import tlsh

h1 = tlsh.hash(data)
h2 = tlsh.hash(similar_data)
score = tlsh.diff(h1, h2)

h3 = tlsh.Tlsh()
with open('file', 'rb') as f:
    for buf in iter(lambda: f.read(512), b''):
        h3.update(buf)
    h3.final()
# this assertion is stating that the distance between a TLSH and itself must be zero
assert h3.diff(h3) == 0
score = h3.diff(h1)
"""
TLSHs = []
"""
https://github.com/trendmicro/telfhash#requirements
"""
TELFHashes = []
INPUTHashes = []

# TODO: vHASH is VirusTotal inhouse hashing to compare similarly connected files
# https://github.com/arieljt/VTvHash-Maltego/blob/master/VTvHash.py
# VHASHes = []
FILENAMEs = []
FILETYPEs = []  # HeaderClass:CPUByteOrder
FILESIZEs = []
FILEMAGICs = []
# TODO: sectionlist as investigated by VT?
# ELF_INFOs = [{}]
TIMESSUBMITTEDs = []
FIRSTSEENITWs = []  # int, convert to datetime using pandas
FIRSTSUBMITTEDs = []  # int, convert to datetime using pandas
LASTSUBMTTEDs = []  # int, convert to datetime using pandas
LASTANALYSISDATEs = []  # int, convert to datetime using pandas
TOTALVOTEs = [
]  # last_analysis_stats['harmless']:last_analysis_stats['malicious']
SUGGESTEDTHREATLABELs = [
]  # popular_threat_classification['suggested_threat_label']

# hostbased IOCs?
AUTOSTARTLOCATIONs = []  # autostart_locations['entry']

# error_ips = ""
with progressbar.ProgressBar(max_value=MAX_BAR) as bar:
    with open("lookup_hashes.txt", 'r') as f:
        for line in f:
            lines += 1
        f.seek(0)
        for i, hash in enumerate(f):
            url = f"https://www.virustotal.com/api/v3/files/{hash.strip()}"

            response = requests.request("GET", url, headers=headers).text
            # test
            with open(f"hash{i+1}.example.json", 'w') as F:
                F.write(response)
            hash_resp = json.loads(response)['data']
            INPUTHashes.append(hash)
            # file exif
            FILENAMEs.append('\n'.join(hash_resp['attributes'].get(
                'names', 'na')))
            exiftool = hash_resp['attributes'].get('exiftool', 'na')
            if exiftool != 'na':
                FILETYPEs.append('\n'.join(
                    [k + ':' + v for k, v in exiftool.items()]))
            else:
                FILETYPEs.append('na')
            FILESIZEs.append(hash_resp['attributes']['size'])
            FILEMAGICs.append(hash_resp['attributes']['magic'])

            # hashes
            TLSHs.append(hash_resp['attributes']['tlsh'])
            TELFHashes.append(hash_resp['attributes'].get('telfhash', 'na'))

            # analysis related
            TIMESSUBMITTEDs.append(hash_resp['attributes']['times_submitted'])
            FIRSTSEENITWs.append(hash_resp['attributes'].get(
                'first_seen_itw_date', 'na'))
            if FIRSTSEENITWs[-1] != 'na':
                FIRSTSEENITWs[-1] = datetime.datetime.fromtimestamp(
                    FIRSTSEENITWs[-1]).strftime("%Y-%m-%d")
            FIRSTSUBMITTEDs.append(
                hash_resp['attributes']['first_submission_date'])
            FIRSTSUBMITTEDs[-1] = datetime.datetime.fromtimestamp(
                FIRSTSUBMITTEDs[-1]).strftime("%Y-%m-%d")
            LASTSUBMTTEDs.append(
                hash_resp['attributes']['last_submission_date'])
            LASTSUBMTTEDs[-1] = datetime.datetime.fromtimestamp(
                LASTSUBMTTEDs[-1]).strftime("%Y-%m-%d")
            LASTANALYSISDATEs.append(
                hash_resp['attributes']['last_analysis_date'])
            LASTANALYSISDATEs[-1] = datetime.datetime.fromtimestamp(
                LASTANALYSISDATEs[-1]).strftime("%Y-%m-%d")
            TOTALVOTEs.append(
                f"{hash_resp['attributes']['last_analysis_stats']['harmless']}-{hash_resp['attributes']['last_analysis_stats']['malicious']}"
            )
            SUGGESTEDTHREATLABELs.append(
                hash_resp['attributes']['popular_threat_classification']
                ['suggested_threat_label'])

            # possible IOCs
            entries = '\n'.join([
                entry_loc['entry'] if type(entry_loc) == type(dict) else 'na'
                for entry_loc in hash_resp['attributes'].get(
                    'autostart_locations', 'na')
            ])
            AUTOSTARTLOCATIONs.append(entries)

            if i % (int(round(lines / MAX_BAR, 0))) == 0:
                percent += 1
                try:
                    bar.update(percent)
                except ValueError:
                    # just a minor math problem.
                    continue
# header = ["ip", "country", "ASN", "ASN Organisation"]

df = pd.DataFrame({
    'Hash': INPUTHashes,
    'Filename': FILENAMEs,
    'File type': FILETYPEs,
    'File size': FILESIZEs,
    'magic': FILEMAGICs,
    'Suggest threat label': SUGGESTEDTHREATLABELs,
    'Autostart locations': AUTOSTARTLOCATIONs,
    'TLSH': TLSHs,
    'TELF hash': TELFHashes,
    'Number of submissions': TIMESSUBMITTEDs,
    'First seen itw': FIRSTSEENITWs,
    'First submitted': FIRSTSUBMITTEDs,
    'Last submitted': LASTSUBMTTEDs,
    'Last analyzed': LASTANALYSISDATEs,
    'Total votes (harmless-malicious)': TOTALVOTEs,
})

pd.set_option("display.max_rows", None, "display.max_columns", None,
              'display.width', 1100, 'display.colheader_justify', 'center')
# df['First seen itw'] = pd.to_datetime(df['First seen itw'], format='%Y%m%d')
# df['First submitted'] = pd.to_datetime(df['First submitted'],
#                                        format='%Y-%m-%d')
# df['Last submitted'] = pd.to_datetime(df['Last submitted'], format='%Y-%m-%d')
# df['Last analyzed'] = pd.to_datetime(df['Last analyzed'], format='%Y-%m-%d')

df.to_csv("results_hash.csv")
print(df)

# print("Error IP addresses found:\n" + error_ips)