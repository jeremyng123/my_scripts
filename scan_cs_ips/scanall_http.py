from tek import scan

"""
c2_ips_country.txt contains a textfile with {ip},{country},
delimited with `\n`
"""
with open("c2_ips_country.txt", 'r') as f:
    for ip_country in f:
        ip = ip_country.split(',')[0].strip()
        print(f"{ip}\n######################################################\n{scan.tek_scan('http://'+str(ip))}\n\n\n\n\n\n\n\n\n")