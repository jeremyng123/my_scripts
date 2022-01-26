import geoip2.database
import pandas as pd
import progressbar
from ..config import *

# This reader object should be reused across lookups as creation of it is
# expensive.
error_ips = ""
ips = []
cities_reg = []
cities = []
asn_num = []
ASNs = []

lines = 0
percent = 0
with progressbar.ProgressBar(max_value=MAX_BAR) as bar:
    with open('lookup_ips.txt', 'r') as f:
        for line in f:
            lines += 1
        f.seek(0)
        for i, ip in enumerate(f):
            with geoip2.database.Reader("GeoLite2-City.mmdb") as city:
                with geoip2.database.Reader("GeoLite2-ASN.mmdb") as asn:
                    with geoip2.database.Reader(
                            "GeoLite2-Country.mmdb") as country:
                        try:
                            City = city.city(ip.strip())
                            Asn = asn.asn(ip.strip())
                            Country = country.country(ip.strip())
                            if City.country.iso_code == "SG" or Country.country.iso_code == "SG" or City.registered_country.iso_code == "SG" or Country.registered_country.iso_code == "SG":
                                ips.append(ip.strip())
                                cities.append(City.country.iso_code)
                                cities_reg.append(
                                    City.registered_country.iso_code)
                                asn_num.append(
                                    "ASN" + str(Asn.autonomous_system_number))
                                ASNs.append(Asn.autonomous_system_organization)
                        except ValueError:
                            error_ips += ip + '\n'
                        except geoip2.errors.AddressNotFoundError:
                            error_ips += ip + '\n'
            if i % (int(round(lines / MAX_BAR, 0))) == 0:
                percent += 1
                bar.update(percent)

header = ["ip", "country", "ASN", "ASN Organisation"]

# print(City)
# print()
# print(Country)
df = pd.DataFrame({
    'IP': ips,
    "Original_country": cities,
    "Registered_country": cities_reg,
    "ASN": asn_num,
    "ASN Organization": ASNs
})

pd.set_option("display.max_rows", None, "display.max_columns", None,
              'display.width', 1100, 'display.colheader_justify', 'center')
df.to_csv("results.csv")
print(df)

print("Error IP addresses found:\n" + error_ips)