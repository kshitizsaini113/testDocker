# /proc/[pid]/stat

              Status information about the process.  This is used by
              ps(1).  It is defined in the kernel source file
              fs/proc/array.c.

              The fields, in order, with their proper scanf(3) format
              specifiers, are listed below.  Whether or not certain of
              these fields display valid information is governed by a
              ptrace access mode
              PTRACE_MODE_READ_FSCREDS | PTRACE_MODE_NOAUDIT check
              (refer to ptrace(2)).  If the check denies access, then
              the field value is displayed as 0.  The affected fields
              are indicated with the marking [PT].

              (0) pid  %d
                     The process ID.

              (1) comm  %s
                     The filename of the executable, in parentheses.
                     Strings longer than TASK_COMM_LEN (16) characters
                     (including the terminating null byte) are silently
                     truncated.  This is visible whether or not the
                     executable is swapped out.

              (2) state  %c
                     One of the following characters, indicating process
                     state:

                     R  Running

                     S  Sleeping in an interruptible wait

                     D  Waiting in uninterruptible disk sleep

                     Z  Zombie

                     T  Stopped (on a signal) or (before Linux 2.6.33)
                        trace stopped

                     t  Tracing stop (Linux 2.6.33 onward)

                     W  Paging (only before Linux 2.6.0)

                     X  Dead (from Linux 2.6.0 onward)

                     x  Dead (Linux 2.6.33 to 3.13 only)

                     K  Wakekill (Linux 2.6.33 to 3.13 only)

                     W  Waking (Linux 2.6.33 to 3.13 only)

                     P  Parked (Linux 3.9 to 3.13 only)

              (3) ppid  %d
                     The PID of the parent of this process.

              (4) pgrp  %d
                     The process group ID of the process.

              (5) session  %d
                     The session ID of the process.

              (6) tty_nr  %d
                     The controlling terminal of the process.  (The
                     minor device number is contained in the combination
                     of bits 31 to 20 and 7 to 0; the major device
                     number is in bits 15 to 8.)

              (7) tpgid  %d
                     The ID of the foreground process group of the
                     controlling terminal of the process.

              (8) flags  %u
                     The kernel flags word of the process.  For bit
                     meanings, see the PF_* defines in the Linux kernel
                     source file include/linux/sched.h.  Details depend
                     on the kernel version.

                     The format for this field was %lu before Linux 2.6.

              (9) minflt  %lu
                     The number of minor faults the process has made
                     which have not required loading a memory page from
                     disk.

              (10) cminflt  %lu
                     The number of minor faults that the process's
                     waited-for children have made.

              (11) majflt  %lu
                     The number of major faults the process has made
                     which have required loading a memory page from
                     disk.

              (12) cmajflt  %lu
                     The number of major faults that the process's
                     waited-for children have made.

              (13) utime  %lu
                     Amount of time that this process has been scheduled
                     in user mode, measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).  This includes guest time,
                     guest_time (time spent running a virtual CPU, see
                     below), so that applications that are not aware of
                     the guest time field do not lose that time from
                     their calculations.

              (14) stime  %lu
                     Amount of time that this process has been scheduled
                     in kernel mode, measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

              (15) cutime  %ld
                     Amount of time that this process's waited-for
                     children have been scheduled in user mode, measured
                     in clock ticks (divide by sysconf(_SC_CLK_TCK)).
                     (See also times(2).)  This includes guest time,
                     cguest_time (time spent running a virtual CPU, see
                     below).

              (16) cstime  %ld
                     Amount of time that this process's waited-for
                     children have been scheduled in kernel mode,
                     measured in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

              (17) priority  %ld
                     (Explanation for Linux 2.6) For processes running a
                     real-time scheduling policy (policy below; see
                     sched_setscheduler(2)), this is the negated
                     scheduling priority, minus one; that is, a number
                     in the range -2 to -100, corresponding to real-time
                     priorities 1 to 99.  For processes running under a
                     non-real-time scheduling policy, this is the raw
                     nice value (setpriority(2)) as represented in the
                     kernel.  The kernel stores nice values as numbers
                     in the range 0 (high) to 39 (low), corresponding to
                     the user-visible nice range of -20 to 19.

                     Before Linux 2.6, this was a scaled value based on
                     the scheduler weighting given to this process.

              (18) nice  %ld
                     The nice value (see setpriority(2)), a value in the
                     range 19 (low priority) to -20 (high priority).

              (19) num_threads  %ld
                     Number of threads in this process (since Linux
                     2.6).  Before kernel 2.6, this field was hard coded
                     to 0 as a placeholder for an earlier removed field.

              (20) itrealvalue  %ld
                     The time in jiffies before the next SIGALRM is sent
                     to the process due to an interval timer.  Since
                     kernel 2.6.17, this field is no longer maintained,
                     and is hard coded as 0.

              (21) starttime  %llu
                     The time the process started after system boot.  In
                     kernels before Linux 2.6, this value was expressed
                     in jiffies.  Since Linux 2.6, the value is
                     expressed in clock ticks (divide by
                     sysconf(_SC_CLK_TCK)).

                     The format for this field was %lu before Linux 2.6.

              (22) vsize  %lu
                     Virtual memory size in bytes.

              (23) rss  %ld
                     Resident Set Size: number of pages the process has
                     in real memory.  This is just the pages which count
                     toward text, data, or stack space.  This does not
                     include pages which have not been demand-loaded in,
                     or which are swapped out.  This value is
                     inaccurate; see /proc/[pid]/statm below.

              (24) rsslim  %lu
                     Current soft limit in bytes on the rss of the
                     process; see the description of RLIMIT_RSS in
                     getrlimit(2).

              (25) startcode  %lu  [PT]
                     The address above which program text can run.

              (26) endcode  %lu  [PT]
                     The address below which program text can run.

              (27) startstack  %lu  [PT]
                     The address of the start (i.e., bottom) of the
                     stack.

              (28) kstkesp  %lu  [PT]
                     The current value of ESP (stack pointer), as found
                     in the kernel stack page for the process.

              (29) kstkeip  %lu  [PT]
                     The current EIP (instruction pointer).

              (30) signal  %lu
                     The bitmap of pending signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (31) blocked  %lu
                     The bitmap of blocked signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (32) sigignore  %lu
                     The bitmap of ignored signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (33) sigcatch  %lu
                     The bitmap of caught signals, displayed as a
                     decimal number.  Obsolete, because it does not
                     provide information on real-time signals; use
                     /proc/[pid]/status instead.

              (34) wchan  %lu  [PT]
                     This is the "channel" in which the process is
                     waiting.  It is the address of a location in the
                     kernel where the process is sleeping.  The
                     corresponding symbolic name can be found in
                     /proc/[pid]/wchan.

              (35) nswap  %lu
                     Number of pages swapped (not maintained).

              (36) cnswap  %lu
                     Cumulative nswap for child processes (not
                     maintained).

              (37) exit_signal  %d  (since Linux 2.1.22)
                     Signal to be sent to parent when we die.

              (38) processor  %d  (since Linux 2.2.8)
                     CPU number last executed on.

              (39) rt_priority  %u  (since Linux 2.5.19)
                     Real-time scheduling priority, a number in the
                     range 1 to 99 for processes scheduled under a real-
                     time policy, or 0, for non-real-time processes (see
                     sched_setscheduler(2)).

              (40) policy  %u  (since Linux 2.5.19)
                     Scheduling policy (see sched_setscheduler(2)).
                     Decode using the SCHED_* constants in
                     linux/sched.h.

                     The format for this field was %lu before Linux
                     2.6.22.

              (41) delayacct_blkio_ticks  %llu  (since Linux 2.6.18)
                     Aggregated block I/O delays, measured in clock
                     ticks (centiseconds).

              (42) guest_time  %lu  (since Linux 2.6.24)
                     Guest time of the process (time spent running a
                     virtual CPU for a guest operating system), measured
                     in clock ticks (divide by sysconf(_SC_CLK_TCK)).

              (43) cguest_time  %ld  (since Linux 2.6.24)
                     Guest time of the process's children, measured in
                     clock ticks (divide by sysconf(_SC_CLK_TCK)).

              (44) start_data  %lu  (since Linux 3.3)  [PT]
                     Address above which program initialized and
                     uninitialized (BSS) data are placed.

              (45) end_data  %lu  (since Linux 3.3)  [PT]
                     Address below which program initialized and
                     uninitialized (BSS) data are placed.

              (46) start_brk  %lu  (since Linux 3.3)  [PT]
                     Address above which program heap can be expanded
                     with brk(2).

              (47) arg_start  %lu  (since Linux 3.5)  [PT]
                     Address above which program command-line arguments
                     (argv) are placed.

              (48) arg_end  %lu  (since Linux 3.5)  [PT]
                     Address below program command-line arguments (argv)
                     are placed.

              (49) env_start  %lu  (since Linux 3.5)  [PT]
                     Address above which program environment is placed.

              (50) env_end  %lu  (since Linux 3.5)  [PT]
                     Address below which program environment is placed.

              (51) exit_code  %d  (since Linux 3.5)  [PT]
                     The thread's exit status in the form reported by
                     waitpid(2).