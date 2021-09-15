@echo off
openssl req -x509 -days 365 -newkey rsa:2048 -keyout any.pem -out any.pem
openssl req -new -key any.pem -out server.csr
openssl x509 -req -in server.csr -signkey any.pem -out rootcert.pem