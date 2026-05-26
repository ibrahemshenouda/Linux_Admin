# 🐧 Linux Administration & Systems Programming Study Repository

Welcome to the **Linux Administration and Systems Programming** learning repository. This project is a structured educational resource designed to take a developer from fundamental operating system concepts to low-level Unix systems programming, kernel-user space architectures, storage management, networking, and scripting automation.

---

## 🌟 Repository Overview & Architecture

The content is organized into three distinct sections to balance original notes, theoretical system architecture, and practical coding labs:

1.  **Written Notes Archive (`00_Writen_Notes/`)**: Contains consolidated PDF files of the original scanned handwritten lecture notes and diagrams.
2.  **Programming & Automation Labs (Directories `01` - `02`)**: Contains source code files written in C, C++, and Python implementing system programming tasks and cron job automation.
3.  **Theoretical & Administrative Stacks (Directories `03` - `08`)**: The core study guides. Each directory contains a comprehensive `README.md` study guide directly inside the folder, complete with explanations, tables, and **Mermaid architecture diagrams**.

---

## 📅 Interactive Table of Contents

| Directory / Stack | Focus Area | Original Handwritten Notes | Theoretical Study Guide |
| :--- | :--- | :--- | :--- |
| **01. System Calls** | **Systems Programming** | *N/A (Code Lab)* | [📁 01_System_Calls](file:///home/ibrahimshnouda/GitHub/Linux_Admin/01_System_Calls) |
| **02. Crontab** | **Task Automation** | *N/A (Code Lab)* | [📁 02_Crontab](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab) <br> [📝 README](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab/README.md) |
| **03. Embedded Linux & Architecture** | **OS & Kernel Foundations** | [📄 01_Introduction.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/01_Introduction.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture/README.md) |
| **04. File System & Storage** | **Storage Infrastructure** | [📄 02_File_System_Stack.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/02_File_System_Stack.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage/README.md) |
| **05. Process Management** | **Runtime Execution** | [📄 03_Process_Management_Stack.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/03_Process_Management_Stack.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management/README.md) |
| **06. Networking & Diagnostics** | **Network Stack** | [📄 04_Network_Stack.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/04_Network_Stack.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics/README.md) |
| **07. User & Group Management** | **Security & Access Control** | [📄 05_User_Management_Stack.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/05_User_Management_Stack.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management/README.md) |
| **08. Terminal & Bash Scripting** | **Shell Customization** | [📄 06_Terminal&Bash_Scripting.pdf](file:///home/ibrahimshnouda/GitHub/Linux_Admin/00_Writen_Notes/06_Terminal%26Bash_Scripting.pdf) | [📝 README Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting/README.md) |

---

## 📖 Curriculum Breakdown

### 1. Written Notes Archive
*   **00_Writen_Notes**: Features 6 topic-specific PDF compilations of original handwritten notes containing structural diagrams, logical maps, and quick references.

### 2. Systems Programming & Basic Tools
*   **01_System_Calls**: Contains subdirectories detailing code files for:
    *   *File Management*: Demonstrating standard low-level I/O calls (`open`, `read`, `write`, `lseek`, `close`) in C++ alongside equivalent high-level file manipulation in Python.
    *   *Process Control*: Coding templates implementing process spawning (`fork`), loading binary images (`execvp`), and parent synchronization (`wait`/`exit`).
    *   *Disk Management*: Harnessing the generic `ioctl` driver control system call to query terminal row/column window geometry properties.
*   **02_Crontab**: Guides on scheduling scripts for automated background processes. The directory features a Python script logging timestamps that triggers automatically via cron jobs.

### 3. Architecture & Operating System Foundations
*   **03_Embedded_Linux_Architecture**: Compares bare-metal designs to OS abstractions. Details CPU Ring execution permissions, user space safety boundaries, kernel mode systems (scheduler, VFS, drivers), and the boot chain phases (ROM Boot Code -> SPL -> U-Boot -> Kernel -> Init).
*   **04_File_System_Storage**: Traces how logical files are mapped to hardware block sectors. Discusses partitioning tables, comparing raw formats (Ext2, Ext3, Ext4, FAT), journaling for recovery, and mounting device pathways.
*   **05_Process_Management**: Details how the scheduler maps tasks. Explains PID metadata, process states, multitasking using foreground/background triggers (`&`, `jobs`, `fg`, `bg`), priorities (Nice/Renice), and process control signals.

### 4. Network Administration & Multi-User Security
*   **06_Networking_Diagnostics**: Reviews protocol mappings across the network layers. Deep-dives into TCP connection mechanisms vs UDP speed, data encapsulation flows, Ethernet frame fields, routing subnets, and diagnosing networks using command tools.
*   **07_User_Group_Management**: Details security partitions in multi-user settings. Details user structures, shadow configuration databases, file/directory permission strings (`rwx` meanings), and user privileges manipulation.
*   **08_Terminal_Bash_Scripting**: Explores terminal emulators and interactive shells. Teaches shell alias setups, documentation helpers (`tldr`), shell script arguments, and redirection channels (stdin/stdout/stderr redirections, `/dev/null`).

---

## 🛠️ Unified System Commands Reference

Below is a categorized summary of all command line utilities studied, implemented, or detailed throughout the study guides in this repository:

| Category | Utilities Covered |
| :--- | :--- |
| **Disk & Partitioning** | `fdisk`, `mkfs.ext4`, `mount`, `umount`, `lsblk`, `df`, `du` |
| **Process Monitoring** | `ps aux`, `top`, `pstree`, `nice`, `renice`, `kill`, `killall` |
| **Network & Diagnostics** | `ifconfig`, `ip addr`, `ping`, `ss`, `nmap`, `ssh`, `wireshark`, `tcpdump` |
| **Security & Identity** | `chmod`, `chown`, `stat`, `id`, `whoami`, `adduser`, `deluser`, `usermod`, `passwd` |
| **Shell Environment** | `alias`, `source`, `tldr`, `man`, `bash` |