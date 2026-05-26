# 🐧 Linux Administration & Systems Programming Study Repository

Welcome to the **Linux Administration and Systems Programming** learning repository. This project is a structured educational resource designed to take a developer from fundamental operating system concepts to low-level Unix systems programming, kernel-user space architectures, storage management, networking, and scripting automation.

---

## 🌟 Repository Overview & Architecture

The content is organized into two distinct sections to balance theoretical system architecture with practical command-line and programming skills:

1.  **Programming & Automation Labs (Directories `01` - `02`)**: Contains source code files written in C, C++, and Python implementing system programming tasks and cron job automation. Each folder contains a local `README.md` with instructions on compilation, execution, and API details.
2.  **Theoretical & Administrative Stacks (Directories `03` - `08`)**: Derived from curated lectures and study materials. Each stack contains:
    *   `writen notes/`: The original scanned handwritten notes and diagrams showing logic flows.
    *   `study guide/`: A highly detailed, transcribed Markdown study guide featuring text explanations, conceptual tables, and **Mermaid architecture diagrams**.

---

## 📅 Interactive Table of Contents

| Directory / Stack | Focus Area | Core Concepts Covered | Quick Links |
| :--- | :--- | :--- | :--- |
| [📁 **01_System_Calls**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/01_System_Calls) | **Systems Programming** | POSIX file APIs, process spawning (`fork`/`exec`), parent-child synchronization, and terminal ioctl control. | [📂 Code Directory](file:///home/ibrahimshnouda/GitHub/Linux_Admin/01_System_Calls) |
| [📁 **02_Crontab**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab) | **Task Automation** | Background scheduling daemon, crontab expression layouts, and automatic logger scripting. | [📂 Automation Directory](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab) <br> [📝 README](file:///home/ibrahimshnouda/GitHub/Linux_Admin/02_Crontab/README.md) |
| [📁 **03_Embedded_Linux_Architecture**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture) | **OS & Kernel Foundations** | User Space vs Kernel Space (Ring 0 vs 3), bare-metal comparison, and the 5-stage booting sequence. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/03_Embedded_Linux_Architecture/writen%20notes) |
| [📁 **04_File_System_Storage**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage) | **Storage Infrastructure** | VFS layers, partition tables (`fdisk`), Ext2/3/4 journaling file systems, partition formatting, and mounting. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/04_File_System_Storage/writen%20notes) |
| [📁 **05_Process_Management**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management) | **Runtime Execution** | Process lifecycle states (Running, Sleeping, Zombie), priorities (Nice/Renice), foregrounding, and signal handling. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/05_Process_Management/writen%20notes) |
| [📁 **06_Networking_Diagnostics**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics) | **Network Stack** | OSI/TCP-IP layers, TCP/UDP features, Ethernet frame structures, network encapsulation, and routing. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/06_Networking_Diagnostics/writen%20notes) |
| [📁 **07_User_Group_Management**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management) | **Security & Access Control** | User classifications (root/system/normal), permission triplets (`rwx`), numeric vs symbolic chmod, and ownership. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/07_User_Group_Management/writen%20notes) |
| [📁 **08_Terminal_Bash_Scripting**](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting) | **Shell Customization** | Terminal emulators vs shells, command execution lifecycle, aliases, positional parameters, and standard I/O redirection. | [📝 Study Guide](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting/study%20guide/README.md) <br> [📷 Written Notes](file:///home/ibrahimshnouda/GitHub/Linux_Admin/08_Terminal_Bash_Scripting/writen%20notes) |

---

## 📖 Curriculum Breakdown

### 1. Systems Programming & Basic Tools
*   **01_System_Calls**: Contains subdirectories detailing code files for:
    *   *File Management*: Demonstrating standard low-level I/O calls (`open`, `read`, `write`, `lseek`, `close`) in C++ alongside equivalent high-level files manipulation in Python.
    *   *Process Control*: Coding templates implementing process spawning (`fork`), loading binary images (`execvp`), and parent synchronization (`wait`/`exit`).
    *   *Disk Management*: Harnessing the generic `ioctl` driver control system call to query terminal row/column window geometry properties.
*   **02_Crontab**: Guides on scheduling scripts for automated background processes. The directory features a Python script logging timestamps that triggers automatically via cron jobs.

### 2. Architecture & Operating System Foundations
*   **03_Embedded_Linux_Architecture**: Compares bare-metal designs to OS abstractions. Details the CPU Rings execution permissions, user space safety boundaries, kernel mode systems (scheduler, VFS, drivers), and details the boot chain phases (ROM Boot Code -> SPL -> U-Boot -> Kernel -> Init).
*   **04_File_System_Storage**: Traces how logical files are mapped to hardware block sectors. Discusses partitioning tables, comparing raw formats (Ext2, Ext3, Ext4, FAT), journaling for recovery, and mounting device pathways.
*   **05_Process_Management**: Details how the scheduler maps tasks. Explains PID metadata, process states, multitasking using foreground/background triggers (`&`, `jobs`, `fg`, `bg`), priorities (Nice/Renice), and process control signals.

### 3. Network Administration & Multi-User Security
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