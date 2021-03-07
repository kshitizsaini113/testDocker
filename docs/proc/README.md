# proc filesystem
### proc - process information pseudo-filesystem

The proc filesystem is a pseudo-filesystem which provides an interface to kernel data structures. It is commonly mounted at /proc. It is mounted automatically by the system.

> Most of the files in the proc filesystem are read-only, but some files are writable, allowing kernel variables to be changed.

## Understanding the proc

The proc filesystem is further devided to:

1. [/proc/[pid]](proc-pid.md)
2. [/proc/[pid]/stat](proc-pid-stat.md)
3. [/proc/[pid]/status](proc-pid-status.md)
4. [/proc/uptime](proc-uptime.md)
