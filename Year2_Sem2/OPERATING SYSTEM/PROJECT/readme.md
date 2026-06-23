
# 🖥️ Operating System Project Reflection

## Project Overview

This project was developed for the **SECR2043 Operating System** course. The project focused on **Fixed and Dynamic Memory Management**, specifically comparing two memory allocation strategies: **Next Fit** and **Worst Fit**.

The main objective of this project was to understand how operating systems allocate memory to processes and how different allocation strategies affect memory usage, fragmentation, and allocation success.

To make the concept easier to understand, our group used a **parking lot analogy**. In this analogy, the parking lot represents system memory, parking slots represent memory blocks, and cars represent processes that require memory allocation.

---

## What We Did

In this project, we developed a simulation using **Python** to demonstrate how memory allocation works under different conditions.

The simulation covered four main scenarios:

1. **Fixed Partitioning with Next Fit**
2. **Fixed Partitioning with Worst Fit**
3. **Dynamic Partitioning with Next Fit**
4. **Dynamic Partitioning with Worst Fit**

For the fixed partitioning model, memory was represented as predefined parking slot sizes. Each car had to fit into an available fixed slot. This helped show how internal fragmentation can occur when the slot is larger than the process size.

For the dynamic partitioning model, memory was treated as one continuous block. When a car was parked, the memory block was split based on the car size. When a car left, the space became a free hole that could be reused later. This helped demonstrate external fragmentation and memory reuse.

---

## Tools and Technologies Used

- Python
- Command-line interface
- Operating system memory management concepts
- Next Fit algorithm
- Worst Fit algorithm
- Fixed partitioning
- Dynamic partitioning
- Animaker for visual explanation

---

## My Learning Experience

Through this project, I gained a clearer understanding of how memory management works in an operating system. Before this project, concepts such as fragmentation, fixed partitioning, dynamic partitioning, Next Fit, and Worst Fit were quite abstract. However, by using the parking lot analogy, I was able to visualize how memory blocks are allocated, split, reused, or wasted.

I learned that **Next Fit** searches from the last allocated position and continues forward. This can make allocation faster, but it may skip suitable memory blocks and cause allocation failure even when free space still exists.

I also learned that **Worst Fit** searches for the largest available block before allocation. This strategy can be useful in dynamic partitioning because it may leave larger reusable spaces, but it can also waste large blocks if small processes are allocated too early.

---

## Reflection

This project helped me understand that memory allocation is not only about finding free space, but also about choosing the right strategy to use memory efficiently. Different algorithms can produce different results even when the same memory size and process sizes are used.

The simulation also showed me the difference between fixed and dynamic partitioning. Fixed partitioning is simpler, but it can waste memory because each block has a fixed size. Dynamic partitioning is more flexible because memory can be split based on process size, but it may still cause fragmentation when processes leave and create scattered holes.

One of the most meaningful parts of this project was implementing the logic using Python. Writing the allocation code helped me understand how the algorithms actually work step by step. It also improved my problem-solving skills because the program needed to handle allocation, deallocation, free blocks, and final memory states.

---

## Challenges Faced

One challenge faced in this project was understanding the difference between internal and external fragmentation. At first, it was easy to confuse why memory could still be wasted even when there was free space available.

Another challenge was implementing the dynamic partitioning logic because the system needed to track free blocks, allocated blocks, and merge free spaces after deallocation. This required careful logic to make sure the simulation output was correct and understandable.

---

## Overall Learning

Overall, this project strengthened my understanding of operating system memory management. It helped me connect theoretical concepts with a practical simulation.

Through this project, I learned that choosing the correct memory allocation strategy is important because it affects system performance, memory utilization, and fragmentation. The project also showed me that visual analogies, such as the parking lot example, can make complex operating system concepts easier to understand and explain.

