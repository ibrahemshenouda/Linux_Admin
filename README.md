# 🐧 Linux Administration Study Notes & Labs

Welcome to the Linux Administration repository. This repository organizes core operating system topics, system call lab exercises, process execution concepts, networking diagnostics, and shell scripting guides.

---

## 📂 Repository Structure

The curriculum is divided into sequential directories. Each directory (from Stack 03 to Stack 08) contains:
*   **`writen notes/`**: The original scanned handwritten notes covering the lectures.
*   **`study guide/`**: A comprehensive, detailed Markdown study guide transcribing and expanding upon the lecture concepts.

### Table of Contents

| Topic / Stack | Description | Directory Links |
| :--- | :--- | :--- |
| **01. System Calls** | Hands-on programming labs implementing system calls for files, processes, and disk management. | [📁 01_System_Calls](file:///home/ibrahimshnouda/GitHub/Linux_Admin/01_System_Calls) |
| **02. Crontab** | Automating script scheduling and background execution tasks. | [📁 02_Crontab](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab) |
| **03. Embedded Linux & Architecture** | Separation of User vs Kernel Space, SoC architectures, and the complete 5-stage booting sequence. | [📁 03_Embedded_Linux_Architecture](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture/study%20guide/README.md) |
| **04. File System & Storage** | Physical blocks representation, partitioning with `fdisk`, Ext4 vs FAT, formatting, and mounting disk partitions. | [📁 04_File_System_Storage](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage/study%20guide/README.md) |
| **05. Process Management** | Process states, foreground vs background multitasking, priorities (nice/renice), signaling, and monitoring tools. | [📁 05_Process_Management](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management/study%20guide/README.md) |
| **06. Networking & Diagnostics** | OSI/TCP-IP models, Ethernet frame structure, packet encapsulation, subnets, routing, and diagnostic commands. | [📁 06_Networking_Diagnostics](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics/study%20guide/README.md) |
| **07. User & Group Management** | Multi-user isolation, UIDs/GIDs, password configurations, chown, and symbolic/octal `rwx` permissions. | [📁 07_User_Group_Management](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management/study%20guide/README.md) |
| **08. Terminal & Bash Scripting** | Shell interpreters, terminal emulation lifecycle, aliases, help utilities (`tldr`), shell scripting, and I/O redirections. | [📁 08_Terminal_Bash_Scripting](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting) <br> [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting/study%20guide/README.md) |

---

## 🛠️ Requirements & Tools Covered
*   **Disk management**: `fdisk`, `mkfs`, `mount`, `umount`, `lsblk`, `df`
*   **Process management**: `ps`, `top`, `nice`, `renice`, `kill`, `killall`
*   **Networking & diagnostics**: `ping`, `ss`, `ifconfig`, `ip`, `nmap`, `ssh`, `wireshark`
*   **Permissions & identity**: `chmod`, `chown`, `stat`, `id`, `adduser`, `deluser`
*   **Terminal & Shell**: `alias`, `source`, `tldr`, `bash`