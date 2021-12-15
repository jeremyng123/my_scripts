#!/bin/bash

IP_REGEX="((25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?)"
URL_REGEX="(https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|www\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9]+\.[^\s]{2,}|www\.[a-zA-Z0-9]+\.[^\s]{2,})"

echo "grep -E -o $IP_REGEX ./*.txt"
grep -E -o $IP_REGEX ./*.txt
echo "grep -E -o $URL_REGEX ./*.txt"
grep -E -o $URL_REGEX ./*.txt
