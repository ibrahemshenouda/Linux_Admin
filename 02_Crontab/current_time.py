#!/usr/bin/python3
import os

# file to write in
log_file = "/home/ibrahimshnouda/DATA/Embinux/Module_01/02_Linux_Admin/Session_02/date_log.txt"
# request to system to execute 'date' command and return output as string in datecmd
datecmd = os.popen('date').read()

# open file to append it by new time
try:
    with open(log_file, "a") as file:
        file.write(f"Current Time : {datecmd}")
except Exception as e:
    print(f"Error: {e}")
