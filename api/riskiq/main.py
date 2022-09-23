from passivetotal import analyzer, WhoisRequest
import os
# from pathlib import Path
from dotenv import load_dotenv

import requests

# Load the environment variables
envars = '.env'
load_dotenv(envars)

username = os.getenv("_username")
api_key = os.getenv("key")
apikey_64 = os.getenv("key64")
auth = (username, api_key)
base_url = 'https://api.riskiq.net'


def passivetotal_get(path, query):
    url = base_url + path
    data = {'query': query}
    # Important: Specifying json= here instead of data= ensures that the
    # Content-Type header is application/json, which is necessary.
    response = requests.get(url,
                            auth=auth,
                            json=data,
                            headers={"Authorization": f"Basic {apikey_64}"})
    # This parses the response text as JSON and returns the data representation.
    return response.json()


def passivetotal_get_whois_email(email):
    url = base_url + f"/pt/v2/whois/search?query={email}&field=email&page=0"
    data = {"query": email}
    response = requests.get(url, auth=auth, json=data)
    return response.json()


# print(passivetotal_get_whois_email("oookkkwww@protonmail.com"))

# # pdns_results = passivetotal_get('/pt/v2/dns/passive', 'riskiq.net')
# # print(pdns_results)
# # for resolve in pdns_results['results']:
# #     print('Found resolution: {}'.format(resolve['resolve']))

# # Alias get_dns_passive to a GET to /v2/dns/passive
# from functools import partial

# get_dns_passive = partial(passivetotal_get, '/v2/dns/passive')
# pdns_results_example = get_dns_passive('example.org')


def get_emails():
    with open("interested_emails.txt", "r") as f:
        return [email.strip() for email in f]


# analyzer.init(username=username, api_key=api_key)
# client = analyzer.WhoisRequest(get_emails()[0])
# print(analyzer.WhoisRequest(get_emails()[0]))
# print(analyzer.Hostname(get_emails()[0].strip()).)
# whois_req = WhoisRequest.from_config()
# print(
#     WhoisRequest.search_whois_by_field(query="oookkkwww@protonmail.com",
#                                        field="email"))
from passivetotal.analyzer.whois import WhoisField

analyzer.init()
email = "oookkkwww@protonmail.com"
# WhoisField('email', email).records.domains
print(passivetotal_get_whois_email(email))
