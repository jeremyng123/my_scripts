#!/usr/bin/zsh
# create a certificate
openssl req -x509 -newkey rsa:4096 -keyout lumen_key.pem -out lumen_crt.pem -days 365 -nodes

# convert to pkcs12 for lumen; used for `lumen.tls` in config
openssl pkcs12 -export -out lumen.p12 -inkey lumen_key.pem -in lumen_crt.pem

# export public-key for IDA; Copy hexrays.crt to IDA installation folder
openssl x509 -in lumen_crt.pem -out hexrays.crt