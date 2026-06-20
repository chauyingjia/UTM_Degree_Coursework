## ⚡ Reflection: Apache Spark Education Data ETL Pipeline

Through this tutorial, I gained a clearer understanding of how **Apache Spark** can be used to process large-scale datasets efficiently. The project focused on building an ETL pipeline using Brazilian Basic Education Census data from 2010 to 2021, where raw CSV files were extracted, transformed into Parquet format, modelled into a star schema, loaded into PostgreSQL, and visualized through dashboards.

### 💡 What I Gained

I learned how Spark handles large datasets better than traditional tools such as Pandas, especially when the data size is too large to process smoothly on a local machine. This tutorial helped me understand important data engineering concepts such as **data extraction**, **CSV-to-Parquet transformation**, **manual type casting**, **data modelling**, and **database loading**.

I also gained experience in designing a **star schema** for analytical queries. Instead of only storing data in a normal relational format, I learned how fact tables and dimension tables can support faster aggregation and dashboard analysis.

### 🛠 Technical Experience

This project gave me hands-on practice with **PySpark**, **PostgreSQL**, **Parquet**, **Adminer**, and **Metabase**. I also learned how to handle real technical issues, such as Windows path problems, encoding mismatches, missing values, and Spark environment configuration.

One important lesson I gained was that data engineering is not only about writing code. It also involves preparing the environment, understanding the dataset, designing the data structure, and making sure the pipeline works from raw data until final visualization.

### 🔧 Suggested Improvements

This project could be improved by adding more automated data validation steps to check missing values, incorrect data types, and inconsistent records before loading the data into the database. The pipeline could also be improved by scheduling automatic runs and adding better error handling.

Besides that, the dashboard could include more interactive filters and clearer visual summaries to help users explore education trends by year, state, city, and school facilities more easily.

### 🌟 Overall Reflection

Overall, this tutorial was meaningful because it helped me understand how a real data engineering pipeline is built step by step. It strengthened my knowledge in big data processing, ETL workflow, data warehouse design, and dashboard preparation. This experience also made me more confident in using Apache Spark for large-scale data processing tasks.
