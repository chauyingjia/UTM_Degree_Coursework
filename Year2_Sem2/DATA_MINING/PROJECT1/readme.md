# 📊 Student Performance Prediction in Secondary Education

## 📝 Project Overview
This project was developed for the **SECP2753 Data Mining** course at **Universiti Teknologi Malaysia (UTM)**. The goal is to predict whether a student will **Pass** or **Fail** based on their demographic, social and school-related background. 

To simulate a real-world **early intervention** scenario, we intentionally removed all prior period grades (G1 and G2) from the model. This allows educators to identify at-risk students before the first exams even take place.

---

## 🛠️ Tech Stack & Tools
- **Language:** Python
- **Libraries:** Pandas, Scikit-learn, Matplotlib, Seaborn
- **Algorithms:** K-Nearest Neighbors (KNN), Gaussian Naive Bayes

---

## 📂 Dataset Information
- **Source:** Data from two Portuguese secondary schools (Mathematics and Portuguese subjects).
- **Instances:** 1,044 students (combined).
- **Attributes:** 33 features (including age, family size, parent education, study time, absences, etc.).
- **Target Variable:** Binary classification (Pass/Fail).

---

## ⚙️ Machine Learning Pipeline
1. **Data Integration:** Merged Math and Portuguese datasets into one master dataframe.
2. **Preprocessing:** 
   - **Discretization:** Converted numerical final grades (0-20) into "Pass" (>=10) or "Fail" (<10).
   - **Data Reduction:** Removed G1 and G2 columns to avoid data leakage and focus on socio-economic predictors.
   - **Transformation:** Applied Label Encoding for categorical data and Standard Scaling for numerical features.
3. **Training:** Split data into 70% training and 30% testing sets.
4. **Modeling:** Implemented KNN ($k=5$) and Gaussian Naive Bayes.

---

## 📈 Model Performance & Results
Both models achieved an identical accuracy, but their internal metrics show different strengths:

| Metric | K-Nearest Neighbors (KNN) | Naive Bayes |
| :--- | :---: | :---: |
| **Accuracy** | **76.43%** | **76.43%** |
| **Precision** | 77.85% | **82.59%** |
| **Recall** | **95.74%** | 86.81% |
| **F1-Score** | **85.88%** | 84.65% |

### Key Takeaways:
- **KNN** is the superior model for **early intervention** due to its high **Recall (95.74%)**, meaning it correctly identifies almost all students who will pass.
- **Naive Bayes** is more conservative, offering higher **Precision (82.59%)** with fewer false positive predictions.

---

## 🎯 Conclusion
The project proves that student success can be predicted with reasonable accuracy using non-academic attributes. This data-driven approach helps institutions provide timely support to students who need it most.

---

## 👥 Contributors
- **Chau Ying Jia** (A23CS0213)
- **Gui Kah Sin** (A23CS0080)
- **Sabrina Heng Wei Qi** (A23CS0265)

**Instructor:** Prof. Madya Dr. Roliana Binti Ibrahim
