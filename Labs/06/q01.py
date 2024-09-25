import pandas as pd

data = {
    'title': ['Movie A', 'Movie B', 'Movie C', 'Movie D', 'Movie E', 'Movie F', 'Movie G', 'Movie H'],
    'revenue': [2500000, 1500000, 3000000, 700000, 1000000, 5000000, 800000, 2000000],
    'budget': [900000, 200000, 500000, 800000, 300000, 750000, 400000, 600000]
}

df = pd.DataFrame(data)

print("Original Dataframe")
print(df)

filteredMovies = df[(df['revenue'] > 2000000) & (df['budget'] < 1000000)]

print("\nFiltered Movies")
print(filteredMovies)
