# 🛍️ Customer Personality Analysis (Unsupervised Learning)

## 📝 Project Overview
Developed for the **SECP2753 Data Mining** course at **Universiti Teknologi Malaysia (UTM)**, this project applies unsupervised machine learning to perform customer segmentation. By analyzing demographic and behavioral data, we group customers into distinct "personas" to help businesses tailor their marketing strategies and improve engagement efficiency.

---

## 🛠️ Tech Stack & Tools
- **Language:** Python
- **Libraries:** Pandas, NumPy, Scikit-learn, Scipy (Clustering), Matplotlib, Seaborn
- **Algorithms:** K-Means Clustering, Hierarchical (Agglomerative) Clustering

---

## 📂 Dataset Overview
- **Source:** Marketing Campaign Dataset.
- **Instances:** 2,240 customers.
- **Attributes:** 29 features covering:
  - **Demographics:** Income, Age, Education, Marital Status, Family Size.
  - **Behavior:** Recency, Total Spending (Wine, Fruits, Meat, Fish, Sweets, Gold).
  - **Channels:** Web, Catalog, and Store purchases.
  - **Campaigns:** Acceptance rates for various marketing offers.

---

## ⚙️ Data Preparation & Engineering
1. **Cleaning:** Handled missing income values and removed non-informative dummy variables.
2. **Feature Engineering:** 
   - **Age:** Derived from birth year.
   - **Total_Spending:** Aggregated spending across all product categories.
   - **Family_Size:** Combined 'Kidhome' and 'Teenhome'.
   - **Customer_Since_Days:** Calculated relationship duration from enrollment dates.
3. **Transformation:** Applied **One-Hot Encoding** for categorical features and **StandardScaler** for numerical normalization.

---

## 🔬 Model Development & Evaluation

### 1. K-Means Clustering
- **Optimization:** Used the **Elbow Method** to identify **k=7** as the optimal number of clusters.
- **Result:** Successfully segmented customers into groups such as "High-income Loyalists" and "Young Low-spenders."

### 2. Hierarchical Clustering
- **Optimization:** Used **Ward's Linkage** and visualized relationships via a **Dendrogram**.
- **Result:** Identified 5 primary segments based on connectivity and data similarity.

---

## 🎯 Conclusion
This project demonstrates that clustering algorithms can effectively identify natural segments within a customer base. K-Means provided a clear partitioning for high-volume segmentation, while Hierarchical clustering offered deeper insights into the nested relationships between customer traits. These insights allow for data-driven decisions in product development and personalized marketing.

---

## 👥 Contributors
- **Chau Ying Jia** (A23CS0213)
- **Gui Kah Sin** (A23CS0080)
- **Sabrina Heng Wei Qi** (A23CS0265)

**Instructor:** Prof. Madya Dr. Roliana Binti Ibrahim
