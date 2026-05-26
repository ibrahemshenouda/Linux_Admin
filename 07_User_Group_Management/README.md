# 👥 Stack 07: User & Group Management Study Guide

This guide covers the Linux multi-user model, user classes (normal, system, superuser), password database systems, security administration commands, and file permissions structure (`rwx`).

---

## 1. Multi-User Architecture of Linux

Linux was designed from the ground up as a multi-user, multi-tasking operating system. 
*   **Purpose**: Multiple users can connect to the system simultaneously (e.g., via SSH). The system uses User IDs (UIDs) and Group IDs (GIDs) to isolate files and processes between users, preventing unauthorized data modification.

---

## 2. User Classes

| User Class | UID Range | Description |
| :--- | :--- | :--- |
| **Superuser (root)** | `0` | Has complete, unrestricted control of the entire operating system, kernel configurations, and files. |
| **System Users** | `1` to `999` | Non-interactive shell accounts created by the OS to run background daemons (e.g., `bin`, `mail`, `syslog`, `www-data`). They do not have login shell privileges. |
| **Normal Users** | `1000`+ | Interactive login accounts created for human administrators or users (e.g., `ibrahimshnouda`). |

---

## 3. Core Database Configurations

User and group configurations are managed in standard flat database files inside `/etc/`:

*   **`/etc/passwd`**: Holds user account information (excluding passwords). Each line follows:
    `username:x:UID:GID:Full Name:Home Directory:Login Shell`
    (The `x` denotes that passwords are delegated to the shadow file).
*   **`/etc/shadow`**: Holds highly encrypted user password strings and account expiration policies. Accessible only by root.
*   **`/etc/group`**: Lists all system groups and their member users.
*   **`/etc/sudoers`**: Configures which users or groups can execute commands with superuser privileges using the `sudo` command.

---

## 4. User and Group Management Commands

*   **`adduser <username>`**: Interactive high-level script to create a user, home directory, set password, and copy default configuration profiles.
*   **`deluser --remove-home <username>`**: Deletes a user account and deletes their home directory.
*   **`usermod`**: Modifies user account settings.
    *   `sudo usermod -aG sudo username`: Appends (`-a`) the user to the supplementary group (`-G`) `sudo`, granting administrative rights.
*   **`passwd <username>`**: Changes user passwords.
*   **`id <username>`**: Prints the active UID, primary GID, and supplementary groups for a specific user.
*   **`whoami`**: Displays the active login username.

---

## 5. File Permissions Structure (`rwx`)

Every file and directory in Linux has an associated owner and access control permission string. The string is divided into three triplets representing **User/Owner**, **Group**, and **Others**:

```
File Type: (-) File, (d) Directory, (l) Symbolic Link
 |
 |    User/Owner Permissions (rwx)
 |     |
 |     |        Group Permissions (r-x)
 |     |         |
 |     |         |        Others Permissions (r-x)
 |     |         |         |
 -    r w x     r - x     r - x      1 owner group 4096 May 26 12:00 file.txt
```

### Numerical Representation (Octal)
Permissions can be defined using binary sums:
*   **Read (`r`)** = `4`
*   **Write (`w`)** = `2`
*   **Execute (`x`)** = `1`
*   **No Permission (`-`)** = `0`

*Examples*:
*   `7` = `4 + 2 + 1` (rwx)
*   `6` = `4 + 2` (rw-)
*   `5` = `4 + 1` (r-x)

### File vs. Directory Permission Meanings

| Permission | Meaning on a File | Meaning on a Directory |
| :---: | :--- | :--- |
| **`r`** | Can read/view file contents (e.g. `cat`). | Can list the files inside the directory (e.g. `ls`). |
| **`w`** | Can modify/write to the file. | Can create, delete, or rename files inside the directory. |
| **`x`** | Can execute the file as a program/script. | Can enter the directory (e.g. `cd /path`). |

---

## 6. Modifying Permissions and Ownership

*   **`chmod`**: Changes file access permissions.
    *   *Numeric Mode*:
        ```bash
        chmod 755 script.sh   # Sets User to rwx, Group and Others to r-x
        chmod 600 private.key # Sets User to rw-, Group and Others to ---
        ```
    *   *Symbolic Mode*:
        ```bash
        chmod u+x script.sh   # Adds execute permission to the user/owner
        chmod g-w data.txt    # Removes write permission from the group
        chmod o=r config.conf # Sets others to read-only
        ```
*   **`chown`**: Changes file ownership.
    *   ```bash
        sudo chown ibrahim:users file.txt   # Changes owner to ibrahim and group to users
        sudo chown -R ibrahim /mnt/data     # Recursively changes ownership of a directory
        ```
*   **`stat <file>`**: Displays detailed filesystem metadata of a file, including block details, inode index, links, ownership, and permissions.
