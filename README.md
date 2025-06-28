# Cache

Trying to implement a distributed cache system from scratch using OOP and system design fundamentals.

---

## Phase 1: Core Storage System

- Create an **abstract storage interface** that can be implemented by different backends.
- Main implementation: **In-memory storage** using hash maps with thread safety.
- Build a **cache entry class** that holds:
  - Actual data
  - Metadata: creation time, TTL, access count

---

## Phase 2: Eviction Policies

- Implement the **Strategy pattern** for different eviction algorithms.
- Create an **abstract eviction policy interface**.
- Build:
  - **LRU** (using a doubly-linked list with hash map for O(1) operations)
  - **LFU** (using frequency counters with efficient data structures)
- These policies decide which keys to remove when the cache is full.

---

## Phase 3: Command System

- Build a **Command pattern** implementation:
  - Each cache operation (GET, SET, DELETE, EXPIRE) becomes a command object.
- Create a **command registry** that parses incoming requests and executes the appropriate command.
- Makes adding new operations clean and maintainable.

---

## Phase 4: Pub/Sub Messaging

- Implement the **Observer pattern** for publish-subscribe functionality.
- Create a **subscriber interface** and a **pub/sub manager** that maintains channels and their subscribers.
- When someone publishes to a channel, all subscribers get notified.
- Demonstrates event-driven architecture.

---

## Phase 5: Persistence

- Use the **Strategy pattern** for different ways to save data.
- Implement:
  - **Snapshot persistence** (save entire cache to file)
  - Potentially **append-only logging**
- The persistence strategy can be swapped without changing other components.

---

## Phase 6: Simple Networking

- Build a basic **TCP server** that accepts client connections and processes commands.
- Handle multiple clients concurrently.
- Parse a simple text protocol for commands.
- Shows how to integrate your cache with real network communication.

---

## Phase 7: Configuration and Factory

- Create a **factory pattern** for component creation based on configuration.
- Factory reads config files and creates the appropriate:
  - Storage backend
  - Eviction policy
  - Persistence strategy
- Demonstrates dependency injection and configurable architecture.