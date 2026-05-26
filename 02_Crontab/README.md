# ⏰ Automated Time Logger (Crontab Scheduling Demo)

This directory contains a hands-on automation script demonstrating how to schedule background tasks using the **Linux Cron daemon** (`crontab`). The provided Python script runs automatically at defined intervals to append system timestamps to a log file.

---

## 📂 Files in this Directory
*   **`current_time.py`**: A Python script that executes the system command `date` using sub-process pipes and appends the resulting string to a target log file.
*   **`date_log.txt`**: The generated output log file where the timestamp entries are stored.

---

## 🛠️ The Linux Crontab System

The **cron** daemon is a built-in Linux background service that executes scheduled scripts. Configurations are managed in a per-user file called **crontab**.

### Crontab Syntax Layout

```text
  * * * * * /usr/bin/python3 /absolute/path/to/script.py
  │ │ │ │ │
  │ │ │ │ └── Day of Week (0 - 6) (Sunday=0 or 7)
  │ │ │ └──── Month (1 - 12)
  │ │ └────── Day of Month (1 - 31)
  │ └──────── Hour (0 - 23)
  └────────── Minute (0 - 59)
```

### Common Scheduling Examples

| Expression | Meaning |
| :--- | :--- |
| `* * * * *` | Run every single minute. |
| `*/2 * * * *` | Run every 2 minutes (used in this demo). |
| `0 * * * *` | Run at the beginning of every hour (e.g. 1:00, 2:00). |
| `0 0 * * *` | Run once daily at midnight. |
| `0 9 * * 1` | Run at 9:00 AM every Monday. |
| `@reboot` | Run once automatically at system startup. |

---

## 🚀 How to Set Up and Run

1.  **Grant Execution Permissions** (optional, if calling script directly):
    ```bash
    chmod +x current_time.py
    ```
2.  **Open your Crontab file** in edit mode:
    ```bash
    crontab -e
    ```
    *(If prompted, select your preferred command line text editor, e.g., Nano).*
3.  **Add the scheduling line** at the bottom of the file (replace with your absolute script file path):
    ```text
    */2 * * * * /usr/bin/python3 /home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab/current_time.py
    ```
4.  **Save and exit**. The cron daemon will automatically reload the configurations and begin execution.
5.  **Monitor the logs**:
    ```bash
    tail -f /home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab/date_log.txt
    ```
