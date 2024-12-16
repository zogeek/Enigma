import pandas as pd
df = pd.read_csv('students.csv')
numeric_df = df.select_dtypes(include='number')
df_grouped = df.groupby("Gender")[numeric_df.columns].mean()
df_grouped.to_csv('student_grades_avg.csv', index=False)
print(df_grouped)