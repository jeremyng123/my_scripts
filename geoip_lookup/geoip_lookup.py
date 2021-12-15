import geoip2.database

# This reader object should be reused across lookups as creation of it is
# expensive.
citycount = 0
countrycount = 0
result = "count\tip\t\tcountry\tASN{number}\t{ASN Organisation}\n"
with open('lookup_ips.txt', 'r') as f:
    for ip in f:
        with geoip2.database.Reader("GeoLite2-City.mmdb") as city:
            with geoip2.database.Reader("GeoLite2-ASN.mmdb") as asn:
                with geoip2.database.Reader(
                        "GeoLite2-Country.mmdb") as country:
                    City = city.city(ip.strip()).country.iso_code
                    Asn = asn.asn(ip.strip())
                    Country = country.country(ip.strip())
                    if City == "SG" or Country.country.iso_code == "SG":
                        citycount += 1
                        result += f"{citycount:<5}:{ip.strip():18}{City:8}ASN{Asn.autonomous_system_number:<8}{Asn.autonomous_system_organization:>30}\n"

                    # if Country.registered_country.iso_code == "SG":
                    #     countrycount += 1
                    # # if City == "SG":
                    # #     print("SG", end='')
                    # #     print(Country)
                    # print(citycount, countrycount)

print(result)