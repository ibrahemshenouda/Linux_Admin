# 🌐 Stack 06: Networking & Diagnostics Study Guide

This guide covers the networking architecture, TCP/IP stack layers, the physical structure of Ethernet frames, data encapsulation step-by-step, packet routing, and key Linux diagnostic utilities.

---

## 1. Network Stack Architecture: OSI vs. TCP/IP

Computer networking relies on a modular architecture where each layer provides services to the layer above it and utilizes the services of the layer below.

```
       OSI 7-Layer Model              TCP/IP 4-Layer Model
    +----------------------+         +----------------------+
  7 |  Application Layer   |         |                      |
  6 | Presentation Layer   | ======= |  Application Layer   | (HTTP, SSH, FTP, DNS)
  5 |    Session Layer     |         |                      |
    +----------------------+         +----------------------+
  4 |   Transport Layer    | ======= |   Transport Layer    | (TCP, UDP - Port numbers)
    +----------------------+         +----------------------+
  3 |    Network Layer     | ======= |    Internet Layer    | (IP - IP Addresses, Routing)
    +----------------------+         +----------------------+
  2 |   Data Link Layer    | ======= |  Network Interface/  | (Ethernet, Wi-Fi - MACs)
  1 |    Physical Layer    | ======= |    Physical Layer    | (Cables, Bits, NICs)
    +----------------------+         +----------------------+
```

### TCP vs. UDP (Transport Layer Protocols)
*   **TCP (Transmission Control Protocol)**:
    *   *Mechanism*: Connection-oriented (requires a 3-way handshake: SYN, SYN-ACK, ACK).
    *   *Features*: Highly reliable. Includes error detection, packet retransmission, flow control, and guaranteed order delivery.
    *   *Use Cases*: Web browsing (HTTP), File transfers (FTP), Remote shell (SSH).
*   **UDP (User Datagram Protocol)**:
    *   *Mechanism*: Connectionless (packets are sent without verifying if the receiver is ready).
    *   *Features*: Fast, low overhead. Does not guarantee packet delivery, order, or error correction.
    *   *Use Cases*: Live video streaming, DNS requests, Online gaming.

---

## 2. Step-by-Step Data Encapsulation

**Encapsulation** is the process where data is wrapped with protocol headers as it travels down the network stack from user space to the physical wire.

```
User Action: Typing www.youtube.com in Google Chrome

[Application Layer]       DATA (HTTP Request: GET /)
                                |
[Transport Layer]         [TCP Header (Src Port: 54321, Dest Port: 80/443)] + DATA
                                |
[Internet Layer]          [IP Header (Src IP: 192.168.1.5, Dest IP: 172.217.16.45)] + TCP + DATA
                                |
[Link Layer]              [Ethernet Header (Src MAC, Dest MAC)] + IP + TCP + DATA + [FCS Checksum]
                                |
[Physical Layer]          1010110001010... (Electrical / Optical pulses sent via cable)
```

1.  **Application Layer**: Chrome constructs an **HTTP Get Request** (raw data).
2.  **Transport Layer**: The data passes to a socket. The socket adds a **TCP Header**, defining the source port (randomly selected client port like 54321) and destination port (standard HTTP port 80 or HTTPS port 443).
3.  **Internet Layer**: The packet passes to the IP layer. The kernel adds an **IP Header**, containing the source IP address (your machine) and destination IP address (YouTube server).
4.  **Data Link Layer**: The IP packet is passed to the network interface card (NIC). It adds an **Ethernet Header** containing the source MAC address (your NIC) and the destination MAC address (the gateway router). It also appends a **Frame Check Sequence (FCS)** checksum at the end.
5.  **Physical Layer**: The final frame is converted to electrical pulses and sent over the Ethernet cable.

---

## 3. Ethernet Frame Structure

At the Data Link layer, data is packaged into **Ethernet Frames**. The physical structure of a standard IEEE 802.3 Ethernet frame is organized as follows:

| Field | Size (Bytes) | Description |
| :--- | :--- | :--- |
| **Preamble** | 7 Bytes | Alternating 1s and 0s to synchronize receiver clocks. |
| **Start Frame Delimiter (SFD)** | 1 Byte | Denotes the actual starting boundary of the frame data (`10101011`). |
| **Destination MAC Address** | 6 Bytes | Physical hardware address of the target receiver device or router. |
| **Source MAC Address** | 6 Bytes | Physical hardware address of the transmitting network interface. |
| **EtherType / Length** | 2 Bytes | Identifies the protocol contained in the payload (e.g., `0x0800` for IPv4). |
| **Payload** | 46 - 1500 Bytes | The encapsulated IP packet (containing TCP segment and application data). |
| **Frame Check Sequence (FCS)** | 4 Bytes | A Cyclic Redundancy Check (CRC) value used to detect transmission errors. |

---

## 4. Packet Routing: Direct vs. Indirect

When a machine wants to send a packet to a target IP, it must decide how to route it:

*   **Subnet Mask**: Determines if the target IP is in the same local network or a different one.
*   **Direct Connection (Same Subnet)**:
    *   If the target IP matches the local subnet range (e.g., both are `192.168.1.x`), the sender sends an **ARP request** to resolve the target's MAC address and transmits the frame directly to that machine.
*   **Indirect Connection (Different Subnet)**:
    *   If the target IP is in a different network (e.g., `8.8.8.8`), the sender cannot connect directly. It routes the packet to its **Default Gateway** (router).
    *   The frame is addressed to the destination IP at the IP layer, but the Ethernet header's Destination MAC is set to the **Gateway Router's MAC address**. The router receives it, strips the Ethernet frame, reads the IP destination, and forwards it to the next hop.

---

## 5. Linux Network Diagnostic Commands

*   **`ifconfig` / `ip addr`**:
    *   `ifconfig`: Displays active network interfaces, IP addresses, netmasks, broadcast addresses, and hardware MACs.
    *   `sudo ifconfig eth0 down`: Disables interface `eth0`.
    *   `sudo ifconfig eth0 up`: Enables interface `eth0`.
    *   `ip a` / `ip addr show`: Modern replacement for `ifconfig`.
*   **`ping <host>`**:
    *   Sends ICMP Echo Requests to verify if a remote host is reachable and measures round-trip latency.
*   **`ss` / `netstat`**:
    *   `ss -tulpn`: Shows active TCP (`-t`) and UDP (`-u`) sockets, listening ports (`-l`), associated PIDs (`-p`), and numeric addresses (`-n`).
*   **`nmap <target>`**:
    *   Network scanning tool. Scans a range of IP addresses to find active hosts, open ports, and running operating system types.
    *   `nmap 192.168.1.1/24`: Scans the entire local subnet.
*   **`ssh <user>@<host>`**:
    *   Establishes an encrypted remote terminal terminal session to control another machine securely.
*   **`wireshark` / `tcpdump`**:
    *   Network packet sniffers. `wireshark` is a GUI utility and `tcpdump` is command-line based. They capture live traffic frames for low-level packet analysis.
