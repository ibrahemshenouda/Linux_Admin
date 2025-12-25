Automated Time Logger (Crontab Demo)

A simple automation project that demonstrates how to schedule a Python script using **Linux Crontab**. The script runs automatically in the background every 2 minutes to log the current system time (or uptime).

## Files
* **`current_time.py`**: The Python script that fetches the time.
* **`time_log.txt`**: The output file where the logs are appended.

---

## How to Use
  *  *  *  *  *  command_to_execute
  │  │  │  │  │
  │  │  │  │  └── Day of Week (0 - 6) (0 is Sunday)
  │  │  │  └───── Month (1 - 12)
  │  │  └──────── Day of Month (1 - 31)
  │  └─────────── Hour (0 - 23)
  └────────────── Minute (0 - 59)

1. Open the crontab editor:
   ```bash
   crontab -e

1. Write your command:
   ```bash
    */2 * * * * /usr/bin/python3 /home/ibrahimshnouda/DATA/Embinux/Module_01/02_Linux_Admin/Session_02/current_time.py
