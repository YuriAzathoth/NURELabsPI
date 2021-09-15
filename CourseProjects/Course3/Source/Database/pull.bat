@echo off
set PGPASSWORD=42364632
pg_dump -h localhost -c -C -U postgres ark-db > dump.sql