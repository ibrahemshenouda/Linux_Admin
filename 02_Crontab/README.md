Automated Time Logger (Crontab Demo)

A simple automation project that demonstrates how to schedule a Python script using **Linux Crontab**. The script runs automatically in the background every 2 minutes to log the current system time (or uptime).

## Files
* **`current_time.py`**: The Python script that fetches the time.
* **`time_log.txt`**: The output file where the logs are appended.

---

## How to Use
```text
  * * * * * /path/to/command_or_script_to_execute
  │ │ │ │ │
  │ │ │ │ └── Day of Week (0 - 6) (Sunday=0 or 7)
  │ │ │ └──── Month (1 - 12)
  │ │ └────── Day of Month (1 - 31)
  │ └──────── Hour (0 - 23)
  └────────── Minute (0 - 59)

  Examples:

  Schedule      | Meaning 
   * * * * *    | Run every minute. 
   0 * * * *    | Run at the start of every hour (e.g., 1:00, 2:00). 
   0 0 * * *    | Run once a day at midnight. 
   0 9 * * 1    | Run at 9:00 AM every Monday. 
   */5 * * * *  | Run every 5 minutes. 
   @reboot`     | Run once at system startup. 

```

1.**Open the crontab :**
   ```
   crontab -e
```
2.**Write your line... (ex):**
   ```
    */2 * * * * /usr/bin/python3 /home/ibrahimshnouda/DATA/Embinux/Module_01/02_Linux_Admin/Session_02/current_time.py
```
