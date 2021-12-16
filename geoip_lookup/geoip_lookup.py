import geoip2.database
import pandas as pd

# This reader object should be reused across lookups as creation of it is
# expensive.
error_ips = ""
ips = []
cities_reg = []
cities = []
asn_num = []
ASNs = []

reg_ips = []
reg_cities_orig = []
reg_cities = []
reg_asn_num = []
reg_ASNs = []

with open('lookup_ips.txt', 'r') as f:
    for ip in f:
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
                            cities_reg.append(City.registered_country.iso_code)
                            asn_num.append("ASN" +
                                           str(Asn.autonomous_system_number))
                            ASNs.append(Asn.autonomous_system_organization)
                        # if City.registered_country.iso_code == "SG" or Country.registered_country.iso_code == "SG":
                        #     reg_ips.append(ip.strip())
                        #     reg_cities.append(City.registered_country.iso_code)
                        #     reg_cities_orig.append(City.country.iso_code)
                        #     reg_asn_num.append(
                        #         "ASN" + str(Asn.autonomous_system_number))
                        #     reg_ASNs.append(Asn.autonomous_system_organization)
                    except ValueError:
                        error_ips += ip + '\n'
                    except geoip2.errors.AddressNotFoundError:
                        error_ips += ip + '\n'

header = ["ip", "country", "ASN", "ASN Organisation"]

print(City)
print()
print(Country)
df = pd.DataFrame({
    'IP': ips,
    "Original_country": cities,
    "Registered_country": cities_reg,
    "ASN": asn_num,
    "ASN Organization": ASNs
})

pd.set_option("display.max_rows", None, "display.max_columns", None,
              'display.width', 1100, 'display.colheader_justify', 'center',
              'display.precision', 3)
df.to_csv("results.csv")
print(df)

print("Error IP addresses found:\n" + error_ips)