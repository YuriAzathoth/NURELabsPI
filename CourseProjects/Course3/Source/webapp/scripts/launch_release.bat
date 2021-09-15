@echo off

cd ../dist

call serve -l 443 --https --ssl-cert certificate/cert.pem --ssl-key certificate/privkey.pem
