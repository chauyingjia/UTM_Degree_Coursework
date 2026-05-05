# 📝 Smart Digital Attendance System (Backend SQL)

## 📌 Project Overview
Developed for the **SECP3623 Database Programming** course at **Universiti Teknologi Malaysia (UTM)**, this project replaces traditional paper-based attendance with a structured, centralized SQL backend. The system is designed to manage complex relationships between students, lecturers, courses, and sessions, ensuring data integrity and high retrieval performance.

---

## 📽️ Project Demonstration
[![Watch the Demo](https://img.youtube.com/vi/a-kKAvEAQF4/0.jpg)](https://youtu.be/a-kKAvEAQF4)
<br>
*Click the image above to watch our presentation video on YouTube.*

---

## 🛠️ Tech Stack & SQL Features
- **Database Engine:** MySQL
- **Core Tables:** Students, Lecturers, Courses, Enrollments, Sessions, AttendanceRecords.
- **Key Implementation Details:**
  - **DDL & Constraints:** Implemented PRIMARY KEY, FOREIGN KEY, UNIQUE, and CHECK constraints to ensure zero data redundancy.
  - **Advanced DQL:** Developed complex queries using **JOINs** (Natural, Inner, Left, Self), **Subqueries** (Correlated and Multi-row), and **Conditional Logic** (CASE WHEN).
  - **Set Operations:** Used **UNION** and **NOT EXISTS** for advanced record filtering.

---

## 📂 Database Schema
The system architecture includes six interconnected tables designed for university-scale attendance management.



---

## 📈 Performance Optimization & Indexing
To ensure scalability, the system was optimized using specific indexing strategies. We analyzed the performance before and after optimization using the `EXPLAIN` command:

| Optimization Type | Column Target | Performance Gain |
| :--- | :--- | :--- |
| **BTREE Index** | `EnrollmentDate` | Reduced rows examined from **9 to 1**[cite: 4]. |
| **FULLTEXT Index** | `SFirstName`, `SLastName` | Reduced rows examined from **10 to 1**[cite: 4]. |

---

## 💻 SQL Code Highlights

### Complex Joining & Aggregation
```sql
-- Retrieves student attendance rate, showing only those with significant presence
SELECT 
    StudentID, 
    COUNT(*) AS TotalRecords, 
    SUM(Status = 'Present') AS PresentCount
FROM AttendanceRecords
GROUP BY StudentID
HAVING SUM(Status = 'Present') > 0;



