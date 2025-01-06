import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression

def read_data():
    return pd.read_csv("data.csv")

def linear_regression(data):
    lireg = LinearRegression()

    learnData = data[['km']]
    target = data[['price']]
    print(learnData)
    lireg.fit(learnData, target)
    result = lireg.predict([[100000]])
    print(f"Le prix du céhicule sera{result[0][0]}")
def main():
    data = read_data()
    linear_regression(data)

main()