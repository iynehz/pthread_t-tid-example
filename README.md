## What

This example demos the idea of matching a thread's tid (like from obtained
from gettid()) from pthread_t.

Note that this works on Linux only and may not work on older versions of Linux.

## How

1. Build

```
make
```

1. Run `run_thread`, it will print 3 numbers: pid, tid, pthread_t

```
out/run_thread

# output is like
# pid tid pthread_t
# 4497 4498 140702623999744
```

2. Run `check` with arguments obtained from above

```
out/check 4497 4498 140702623999744

# output is like
# pid = 4497
# tid = 4498
# pthread tid = 140702623999744
# process_vm_readv result = 2400
# Found tid !!
```

