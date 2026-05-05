# 🛵 Food Delivery Record System (NoSQL Database Design)

## 📌 Project Overview
This project demonstrates the design and implementation of a high-performance NoSQL database using **MongoDB**. Unlike traditional relational databases, this system utilizes a flexible document model to handle the dynamic, semi-structured data of customers, riders, and real-time delivery tracking.

---

## 📽️ Project Presentation
[![Watch the Presentation](https://img.youtube.com/vi/hHRB7bEAvjk/0.jpg)](https://youtu.be/hHRB7bEAvjk)
<br>
*Click the image above to watch our presentation video on YouTube.*

---

## 🏗️ NoSQL Data Model
The system is built around four primary collections using a mix of **embedding** and **referencing** strategies to optimize read/write performance:

- **Customers:** Stores demographics with embedded address objects and arrays for multiple phone numbers
- **Riders:** Manages rider profiles and vehicle details via embedded objects.
- **Deliveries:** Tracks real-time status history using an array of embedded status timestamps.

---

## 🛠️ Advanced MongoDB Operations
This project moves beyond basic storage to implement advanced data engineering features:

### 1. Aggregation Pipelines
- **Revenue Analytics:** Groups orders by payment method to calculate total revenue, sorted by popularity.
- **Performance Tracking:** Filters for "Delivered" status and groups by `riderId` to count successful completions for incentive calculations.

### 2. Indexing & Optimization
- **Single-Field Index:** Optimized `orderDate` for fast chronological reporting.
- **Compound Index:** Created a `customerId_1_totalAmount_-1` index to instantly retrieve a specific customer's most expensive orders.
- **Performance Gain:** Transitioned from **Collection Scans** (slow/CPU-intensive) to **Index Scans** (instant B-Tree traversal).

---

## ⚖️ Distributed Systems & Security
- **CAP Theorem:** The system is configured for **Consistency & Partition Tolerance (CP)**, ensuring every read receives the most recent write.
- **Consistency Tuning:** 
    - Used `w: "majority"` for high-stakes **Order Placement** to ensure data integrity.
    - Used `readPreference: "secondaryPreferred"` for **Menu Browsing** to reduce primary node load.
- **Security:** Addressed vulnerabilities such as NoSQL Injection and JavaScript Injection through input validation logic.

---

## 💻 CRUD Implementation Highlights
As a core contributor, I was responsible for the full lifecycle of data operations:
- **Insert:** Implemented `insertOne` and `insertMany` for complex documents with nested arrays.
- **Query:** Utilized advanced operators including `$gt`, `$lt`, `$and`, `$or`, and `$in`.
- **Update:** Managed dynamic status updates using `$push` for arrays and `$inc` for automated tax calculations.
- **Delete:** Implemented targeted deletions using `$ne` and `ObjectId` targeting.

---

## 👥 Contributors
- **Chau Ying Jia** (A23CS0213) - CRUD Implementation & Documentation.
- **Ng Yu Hin** (A23CS0148) - NoSQL Data Model & JSON Structure.
- **Tan Zhi Ming** (A23CS0189) - Advanced Operations & Aggregation.
- **Elijah She Yu Sheng** (A23CS0073) - Security, CAP Theorem & Final Editing.

**Instructor:** Prof. Madya Dr. Roliana Binti Ibrahim
