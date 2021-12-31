import json

def pprint(c2server, watermark):
    print(f"{c2server}: {watermark}")

target_public_key_md5 = "defb5d95ce99e1ebbf421a1a38d9cb64"
unique_water_marks = {}
fails = []
with open("CobaltStrike_beacons_22092021_(827).txt", 'r') as f:
    for i,beacon_config in enumerate(f):
        # print(i,beacon_config.strip())
        try:
            beacon_config_dict = json.loads(beacon_config.strip(),strict=False)
        except json.decoder.JSONDecodeError:
            continue
        if beacon_config_dict['PublicKey_MD5'] == target_public_key_md5:
            if beacon_config_dict['Watermark'] not in unique_water_marks.keys():
                unique_water_marks[beacon_config_dict['Watermark']] = 1
                pprint(beacon_config_dict['C2Server'].strip(), str(beacon_config_dict['Watermark']).strip())
            else:
                unique_water_marks[beacon_config_dict['Watermark']] += 1
                pprint(beacon_config_dict['C2Server'].strip(), str(beacon_config_dict['Watermark']).strip())

print(unique_water_marks)