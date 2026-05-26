# 💾 Stack 04: File System & Storage Study Guide

This guide details the virtualization of storage, the Linux Virtual File System (VFS) stack, partitioning disks with `fdisk`, choosing file system types (Ext2/3/4 vs FAT), formatting partitions (`mkfs`), and integrating them into the system directory structure via mounting.

---

## 1. The File System Stack Architecture

In Linux, everything is modeled as a file. The operating system uses a layered file system stack to translate high-level file operations (like opening a file or writing text) into block level sector commands written to raw hardware storage devices.

```mermaid
graph TD
    User["User Application (e.g. echo 'Hello' > file.txt)"] -->|Standard Library API (fopen, fwrite)| LibC["Standard C Library (glibc)"]
    LibC -->|System Call (open, write)| VFS["Virtual File System (VFS) <br> (Unified Interface for Ext4, FAT, NTFS)"]
    VFS -->|Block Read/Write Requests| Block["Block Device Layer <br> (I/O Scheduler & Cache)"]
    Block -->|Hardware Driver Commands| Drivers["Device Driver (e.g., sd, mmc)"]
    Drivers -->|Physical I/O Commands| Hardware["Physical Storage Media <br> (SATA SSD, HDD, eMMC, SD Card)"]
    
    style User fill:#e3f2fd,stroke:#1565c0,stroke-width:2px
    style VFS fill:#e8f5e9,stroke:#2e7d32,stroke-width:2px
    style Hardware fill:#fff3e0,stroke:#e65100,stroke-width:2px
```

### The Virtual File System (VFS)
The **VFS** is an abstraction layer in the kernel. It provides a common set of system calls (like `sys_open`, `sys_read`, `sys_write`) for all file systems. 
*   **Purpose**: Applications do not need to know whether the target disk is formatted in Ext4, FAT32, or NTFS; the VFS exposes a uniform interface and delegates the filesystem-specific logic to the corresponding driver.

---

## 2. Partitioning: Splitting Disk Hardware

Before storage media can be used, it must be subdivided into logical boundaries called **partitions**.

### Why Partition a Disk?
1.  **Isolation**: Isolates system files from user files. If a user fills up their home directory partition, the root partition `/` has enough space left for critical system logs, preventing system freeze.
2.  **Multiple OS/Multi-boot**: Allows installing different operating systems on separate partitions.
3.  **Efficiency**: Limits search scope for data structures and optimizes filesystem blocks.

### Step-by-Step Walkthrough: Partitioning with `fdisk`
`fdisk` is a dialog-driven utility used to create and manipulate partition tables.

1.  **Open the device**: `sudo fdisk /dev/sdb` (where `/dev/sdb` is the raw secondary disk device).
2.  **Common Interactive Commands in `fdisk`**:
    *   `p`: Print the current partition table. Shows device name, start sector, end sector, total sectors, size, and type.
    *   `n`: Create a new partition.
        *   Prompt asks for partition type: `p` for Primary (limit 4) or `e` for Extended.
        *   Prompt asks for partition number (`1` to `4`).
        *   Prompt asks for First Sector: Press `Enter` to accept the default start sector.
        *   Prompt asks for Last Sector: Specify size (e.g., `+2G` for a 2GB partition, or `+4G` for a 4GB partition).
    *   `d`: Delete an existing partition (selects by index).
    *   `t`: Change a partition's system ID (e.g., hex `83` for standard Linux, `82` for Linux swap).
    *   `w`: Write changes to the disk partition table and exit (commit changes).
    *   `q`: Quit without saving modifications.

---

## 3. File System Types (Ext2, Ext3, Ext4, FAT)

Once a partition is created, it must be **formatted** with a file system structure. This structure defines how blocks are cataloged, files are indexed (via inodes), and metadata is stored.

| File System | Journaling | Maximum File Size | Use Case | Key Details |
| :--- | :--- | :--- | :--- | :--- |
| **FAT32** | No | 4 GB | USB flash drives, SD cards | High compatibility across Windows, Linux, and macOS. Lacks security permissions. |
| **Ext2** | No | 16 GB - 2 TB | Read-only embedded boards, Boot flash | Fast read/write performance. High risk of corruption on sudden power loss (no recovery log). |
| **Ext3** | Yes | 16 GB - 2 TB | Legacy Linux servers | Introduces a Journal to track active writes. Solves long file system check times (fsck) after crashes. |
| **Ext4** | Yes | 16 TB | Modern Linux systems | Supports file systems up to 1 Exabyte. Features performance enhancements like extents (contiguous block allocation). |

### What is Journaling?
A **Journal** is a dedicated circular buffer on the disk. Before writing blocks to the main database, the filesystem records the intended change in the journal. 
*   **Crash Recovery**: If the system loses power during a write operation, the OS reads the journal at reboot to either complete the interrupted transaction or roll it back, avoiding corrupted metadata structures.

---

## 4. Formatting and Mounting: Linking Hardware to Paths

Linux does not assign drive letters (like `C:` or `D:`) to partitions. Instead, it uses a single unified **directory tree** starting at the Root directory `/`. Connecting a storage partition to a specific path in this tree is called **mounting**.

```
       [Root Partition - /dev/sda1]
                    /
        +-----------+-----------+
        |                       |
      /etc                    /mnt
                                |
                    [Mount Point: /mnt/usb]
                                |
                    [Formatted Partition - /dev/sdb1]
                                |
                        +-------+-------+
                        |               |
                      movies/        photos/
```

### 1. Formatting a Partition (`mkfs`)
To format a newly created partition `/dev/sdb1` with an Ext4 file system, use the `mkfs` utility:
```bash
sudo mkfs -t ext4 /dev/sdb1
# Or equivalent syntax:
sudo mkfs.ext4 /dev/sdb1
```

### 2. Mounting a Partition (`mount`)
To access the files inside the formatted partition, you must bind it to an existing directory (called a **mount point**):
```bash
# 1. Create a directory to act as the mount point
sudo mkdir -p /mnt/data

# 2. Mount the partition to the path
sudo mount /dev/sdb1 /mnt/data
```
Now, any file written to `/mnt/data/` will be physically written to the secondary disk device `/dev/sdb1`.

### 3. Unmounting a Partition (`umount`)
Before unplugging or reformatting a partition, it must be unmounted to flush pending memory caches to physical sectors:
```bash
sudo umount /mnt/data
# Or unmount directly by device:
sudo umount /dev/sdb1
```
*Note*: The unmount command will fail with a `device is busy` error if a process has its working directory inside the mount path or has open file descriptors pointing to it.

---

## 5. Storage Command Reference

*   `lsblk`: Lists block devices in a tree structure, displaying name, size, type (disk/part), and current mount point.
*   `df -h`: Displays total, used, and available space on all currently mounted filesystems in human-readable format (K, M, G).
*   `du -sh <dir>`: Calculates the disk usage summary of a specific folder or file.
*   `fdisk -l`: Lists partition configurations and layouts of all connected storage controllers.
