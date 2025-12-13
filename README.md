# ☠️ Multi-Threaded Log Processor (C++)

> *"This project was not written to run fast. It was written to **think correctly**."*

This repository marks a turning point in my C++ journey — the moment I stopped writing *programs* and started building **systems**.

This project is a **low-level concurrent log processing system** designed to deeply explore how threads communicate, synchronize, shut down, and survive in shared memory without tearing reality apart.

It is intentionally **over-engineered for learning**.

---

## 🧠 What This Project Really Is

At surface level, this is a **producer–consumer system**:

* Logs are **generated**
* Logs are **queued**
* Logs are **consumed, printed, and counted**
* The system **shuts down cleanly** after work is complete

But underneath… this is a **mental model training ground** for concurrency.

This project answers questions like:

* *Who owns shared data?*
* *Who is allowed to touch it?*
* *Who wakes whom?*
* *Who decides when the system dies?*
* *What happens if threads wake up for no reason?*

---

## ⚙️ Architecture Overview

The system is built from **isolated components**, each with a single responsibility:

### 🧱 Core Components

| Component  | Responsibility                               |
| ---------- | -------------------------------------------- |
| `LogQueue` | Thread-safe queue for log transport          |
| `Counter`  | Atomic counter tracking system progress      |
| `Shutdown` | Atomic shutdown switch shared across threads |
| `Vectors`  | Log templates and generators                 |
| `System`   | Orchestrates thread lifecycles               |

Each component:

* Owns its own data
* Protects itself internally
* Exposes **behavior**, not raw state

---

## 🧵 Thread Model

The system runs **multiple concurrent threads**, each with a clear role:

### 🔹 Producer Thread

* Generates logs
* Pushes logs into the queue
* Increments the counter
* Triggers shutdown when the limit is reached

### 🔹 Consumer Thread

* Waits for logs
* Pops logs safely
* Processes output

### 🔹 Monitor / Observer Thread

* Reacts to counter updates
* Displays registration progress

Threads **never directly share data**.
They communicate **only through protected objects**.

---

## 🔒 Synchronization Rules (The Law)

This project follows **hard concurrency rules**:

### ✅ Mutexes

* Every shared structure owns its own `std::mutex`
* No external locking allowed
* RAII only (`std::lock_guard`, `std::unique_lock`)

### ✅ Condition Variables

* Used to *wait*, not to signal blindly
* Always paired with a **predicate**
* Always re-check state after waking

```cpp
cv.wait(lock, [&] {
    return shutdown.getShutdownState() || !logsQueue.empty();
});
```

This line ensures:

* No busy waiting
* No spurious wake damage
* No race conditions

### ✅ Atomics

* Used only for **simple state**
* No atomics for complex structures
* Encapsulated inside classes

---

## ☠️ The Dark Side (What This Project Teaches)

This system exists to expose **concurrency lies**:

❌ Threads do **not** run in order
❌ Notifications do **not** guarantee execution
❌ `notify_one()` does **not** mean "one log"
❌ Reading without locking is **undefined behavior**

What *does* work:

✔ Waiting on **state**, not signals
✔ Encapsulating shared data
✔ Designing shutdown paths first
✔ Letting threads die naturally

---

## 🧨 Shutdown Philosophy

Shutdown is not an event.

It is **state**.

* A shared atomic flag
* Checked by every thread
* Used in every wait predicate

No thread is force-killed.
Each thread **chooses to exit**.

This mirrors real operating systems.

---

## 📚 What I Learned

This project taught me:

* How real producer–consumer systems work
* Why queues dominate concurrent design
* How condition variables actually behave
* How to reason about time without clocks
* How to design systems that **do not panic**

Most importantly:

> **Concurrency is not about speed. It is about control.**

---

## 🧠 Who This Project Is For

* C++ developers moving beyond syntax
* Anyone learning threads, mutexes, and CVs
* Engineers who want to *think in systems*

Not recommended if you only want quick results.

Highly recommended if you want **mastery**.

---

## 🕯️ Final Words

This repository is not the end.

It is the **beginning of disciplined concurrency thinking**.

If you understand this project,
operating systems stop feeling like magic.

They start feeling **inevitable**.

---

☠️ *Written in C++. Learned in pain. Remembered forever.*
