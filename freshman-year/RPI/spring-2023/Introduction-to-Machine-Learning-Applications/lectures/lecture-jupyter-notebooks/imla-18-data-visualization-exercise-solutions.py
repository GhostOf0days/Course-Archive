# You can use matplotlib, seaborn, streamlit, or another visualization toolkit.
# If you are using streamlit you will need to do this exercise on your laptop rather than using Google Colab.
# The solutions will use streamlit.

# If you want to use streamlit and need to install it into an activated Anaconda/Miniconda environment, you can do:
#     pip install streamlit
# Do not use "conda install".
# Once you have installed streamlit, run this code in the terminal as:
#     streamlit run imla-18-data-visualization-exercises.py


import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.impute import SimpleImputer
import streamlit as st


st.set_page_config(layout="wide", page_title="Data visualization exercise")


# Load the stroke.csv dataset from last class into a DataFrame.
# Preprocess the DataFrame by:
#   - dropping the "id" cloumn
#   - imputing nulls in the "bmi" column
# You do not need to scale, discretize, or binarize the data.
@st.cache
def read_csv():
    return pd.read_csv("stroke.csv")


@st.cache
def process_csv(df):
    id_less_df = df.drop("id", axis="columns")
    non_null_df = id_less_df.copy()
    non_null_df[["bmi"]] = SimpleImputer(
        missing_values=np.nan, strategy="mean"
    ).fit_transform(non_null_df[["bmi"]])
    return non_null_df


raw_df = read_csv()
processed_df = process_csv(raw_df)


# Display the first five rows of the preprocessed DataFrame
st.header("DataFrame")
df_head_len = st.slider(
    "Number of rows to show", min_value=1, max_value=len(raw_df), value=5
)
use_raw = st.checkbox("Show raw data?", value=False)
st.write((raw_df if use_raw else processed_df).head(df_head_len))


# Separator
st.markdown("---")


# Display a histogram of ages
def histogram(df):
    fig, ax = plt.subplots()
    ax.hist(df["age"], bins=10, rwidth=0.9)
    ax.set_title("Ages")
    ax.set_xlabel("Age group")
    ax.set_ylabel("Count")
    return fig


st.pyplot(fig=histogram(processed_df))


# Separator
st.markdown("---")


# Display a box plot of BMI by gender (two boxes)
def boxplot(df):
    fig, ax = plt.subplots()
    female_bmi = df[df["gender"] == "Female"]["bmi"]
    male_bmi = df[df["gender"] == "Male"]["bmi"]
    ax.boxplot((female_bmi, male_bmi), labels=("Female", "Male"))
    ax.set_title("BMI by gender")
    return fig


st.pyplot(fig=boxplot(processed_df))


# Separator
st.markdown("---")


# Display a scatterplot of bmi vs. average glucose level
# Drop any rows with nulls first.
def scatterplot(df):
    fig, ax = plt.subplots()
    non_null_df = df.dropna()
    ax.scatter(x=non_null_df["bmi"], y=non_null_df["avg_glucose_level"])
    ax.set_xlabel("BMI")
    ax.set_title("BMI vs. average glucose level")
    ax.set_ylabel("Average glucose level")
    return fig


st.pyplot(fig=scatterplot(processed_df))


# Separator
st.markdown("---")


# Display a stacked bar chart where x = gender and y = counts of people at risk of stroke + not
def stacked_bar_chart(df):
    fig, ax = plt.subplots()
    female_total = len(df[df["gender"] == "Female"])
    male_total = len(df[df["gender"] == "Male"])
    female_stroke = len(df[(df["gender"] == "Female") & (df["stroke"] == 1)])
    male_stroke = len(df[(df["gender"] == "Male") & (df["stroke"] == 1)])

    ax.bar(["Female", "Male"], [female_stroke, male_stroke], label="At risk")
    ax.bar(
        ["Female", "Male"],
        [female_total - female_stroke, male_total - male_stroke],
        bottom=[female_stroke, male_stroke],
        label="Not at risk",
    )

    ax.set_ylabel("Count")
    ax.legend()
    ax.set_title("At-risk vs. not at-risk by gender")

    return fig


st.pyplot(fig=stacked_bar_chart(processed_df))


# Separator
st.markdown("---")


# Display a bar chart of correlations between stroke and the other features
def correlation_bar_chart(df):
    stroke_row = df.corr().loc[
        "stroke", ["age", "hypertension", "heart_disease", "avg_glucose_level", "bmi"]
    ]
    fig, ax = plt.subplots()
    ax.barh(
        list(
            map(lambda factor: " ".join(factor.split("_")), stroke_row.index.tolist())
        ),
        stroke_row,
    )
    ax.set_xlabel("Correlation")
    ax.set_ylabel("Factor")
    return fig


st.pyplot(fig=correlation_bar_chart(processed_df))
